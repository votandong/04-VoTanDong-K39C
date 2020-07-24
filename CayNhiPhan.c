#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Nguoi{
	char hoTen[50];
	int namSinh;
};

struct CGP{
	struct Nguoi duLieu;
	struct CGP *trai, *phai;
};

struct CGP* taoNut(struct Nguoi ng, struct CGP *tr, struct CGP *ph)
{
 	struct CGP *p;
	p = (struct CGP*) malloc(sizeof(struct CGP));
	p->duLieu = ng;
	p->trai = tr;
	p->phai = ph;
	return p;
}

struct CGP* taoCay()
{
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6;
	struct CGP *n1, *n2, *n3, *n4, *n5, *n6;
	
	strcpy(ng1.hoTen, "Nguyen D"); 
	ng1.namSinh = 1960;
	n1= taoNut(ng1, NULL, NULL);
	
	strcpy(ng2.hoTen, "Nguyen F"); 
	ng2.namSinh = 1970;
	n2= taoNut(ng2, NULL, NULL);
	
	strcpy(ng3.hoTen, "Nguyen E"); 
	ng3.namSinh = 1965;
	n3= taoNut(ng3, NULL, NULL);
	
	strcpy(ng4.hoTen, "Nguyen C"); 
	ng4.namSinh = 1935;
	n4= taoNut(ng4, n3, n2);
	
	strcpy(ng5.hoTen, "Nguyen B"); 
	ng5.namSinh = 1930;
	n5= taoNut(ng5, n1, NULL);	
	
	strcpy(ng6.hoTen, "Nguyen A");
	ng6.namSinh = 1900;
	n6 = taoNut(ng6, n5, n4);
	return n6;
}

void inTruoc(struct CGP *r)
{
	if(r != NULL)
	{
		printf("\n %s %d",r->duLieu.hoTen, r->duLieu.namSinh); 
		inTruoc(r->trai);
		inTruoc(r->phai);
	}
}

int demNamSinh(struct CGP *r, int x)
{ 
	int d1, d2;
	if (r==NULL) return 0;
	else
	if (r->duLieu.namSinh < x)
	{
		d1=demNamSinh(r->trai, x);
		d2=demNamSinh(r->phai, x);
		return d1+d2+1;
	}
	else return 0;
}

struct CGP* timHoTen(struct CGP *r, char *ht)
{
	struct CGP *p;
	if (r==NULL) return NULL;
	else
	{
		if (strcmp(r->duLieu.hoTen, ht) == 0)
			return r;
		else
		{
			p = timHoTen(r->trai, ht);
			if (p != NULL) return p;
			else
			return timHoTen(r->phai, ht);
		}
	}
}

int timTheHe(struct CGP *r, char *ht)
{
	struct CGP *t, *p;
	int th;
	if (r == NULL) {
		th = 0;
	}
	else{
		if (strcmp(r->duLieu.hoTen, ht) == 0)
			th += 1;
		else
		{
			t = timHoTen(r->trai, ht);
			if (p != NULL) {
				th += 2;	
			}
			else{
				p = timHoTen(r->phai, ht);
				th += 2;
			}
		}
	}
	return th;
}


main()
{
	struct CGP *c, *kq;
	int d, th;
	char ht[30], theHe[30];
	c = taoCay();
	inTruoc(c);
	
	d = demNamSinh(c, 1960);
	printf("\n Nguoi sinh truoc nam 1960: %d", d);
	
	printf("\n Nhap ho ten nguoi can tim:"); 
	gets(ht);
	kq = timHoTen(c, ht);
	if(kq == NULL)
		printf("Khong tim thay");
	else
		printf("Tim thay ho ten: %s, nam sinh: %d", kq->duLieu.hoTen, kq->duLieu.namSinh);
	printf("\n Nhap ho ten nguoi can tim the he:"); 
	gets(theHe);
	th = timTheHe(c, theHe);
	printf("\n The He: %d", th);
}

















