#include <stdio.h>
#include <stdlib.h>

struct PT{
	char duLieu;
	int doUT;
};

struct HDUT{
	struct PT pt[100];
	int soPT;
};

void siftDown(struct HDUT *h, int r, int n){
	int done = 0, c = 2 * r;
	while(done == 0 && c <= n){
		if(c + 1 <= n && h->pt[c].doUT < h->pt[c+1].doUT)
			c++;
		if(h->pt[r].doUT < h->pt[c].doUT){
			struct PT tg = h->pt[r];
			h->pt[r] = h->pt[c];
			h->pt[c] = tg;
			r = c;
			c = r * 2;
		}
		else 
			done = 1;
	}
}

void siftUp(struct HDUT *h){
	int done, i, p;
	struct PT tg;
	done = 0; 
	i = h->soPT;
	while(i > 1 && done == 0){
		p = i / 2;
		if(h->pt[p].doUT < h->pt[i].doUT){
			tg = h->pt[p];
			h->pt[p] = h->pt[i];
			h->pt[i] = tg;
		}
		else done = 1;
		i = p;
	}
}

void them(struct HDUT *h,struct PT x){
	h->soPT++;
	h->pt[h->soPT] = x;
	siftUp(h);
}

struct PT lay(struct HDUT *h){
	struct PT tg = h->pt[1];
	h->pt[1] = h->pt[h->soPT];
	h->soPT--;
	siftDown(h, 1, h->soPT);
	return tg;
}

void main(){
	struct HDUT h;
	struct PT x;
	h.soPT = 0;
	
	x.duLieu = 'A'; 
	x.duLieu = 3;
	them(&h, x);
	
	x.duLieu = 'B'; 
	x.doUT = 4;
	them(&h, x);
	
	x.duLieu = 'C'; 
	x.doUT = 9;
	them(&h, x);
	
	x.duLieu = 'D'; 
	x.doUT = 7;
	them(&h, x);
	
	x.duLieu = 'E'; 
	x.doUT = 6;
	them(&h, x);
	
	x.duLieu = 'F';
	x.doUT = 5;
	them(&h, x);
	
	x.duLieu = 'G';
	x.doUT = 11;
	them(&h, x);
	
	x.duLieu = 'H'; 
	x.doUT = 2;
	them(&h, x);
	
	x.duLieu = 'I'; 
	x.doUT = 10;
	them(&h, x);
	
	x = lay(&h);
	printf("%c %d\n", x.duLieu, x.doUT);
	
	x = lay(&h);
	printf("%c %d\n", x.duLieu, x.doUT);
	
	x = lay(&h);
	printf("%c %d\n", x.duLieu, x.doUT);
}
