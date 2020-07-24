#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tu
{
	char tiengAnh[20];
	char tiengViet[50];
};

struct TDAV
{
	struct Tu duLieu;
	struct TDAV *trai, *phai;
};

struct TDAV* taoNut(struct Tu t, struct TDAV *tr, struct TDAV *ph)
{
 	struct TDAV *p;
	p = (struct TDAV*) malloc(sizeof(struct TDAV));
	p->duLieu = t;
	p->trai = tr;
	p->phai = ph;
	return p;
}

struct TDAV* taoCay(){
	struct Tu t1, t2, t3;
	struct TDAV *td1, *td2, *td3;
	
	strcpy(t1.tiengAnh, "Hello"); 
	strcpy(t1.tiengViet, "Xin Chao");
	td1 = taoNut(t1, NULL, NULL);
	
	strcpy(t2.tiengAnh, "Dog"); 
	strcpy(t2.tiengViet, "Con Cho");
	td2 = taoNut(t2, NULL, NULL);
	
	strcpy(t3.tiengAnh, "Hue"); 
	strcpy(t3.tiengViet, "Mau Sac");
	td3 = taoNut(t3, td1, td2);
	return td3;
} 

void inTruoc(struct TDAV *r)
{
	if(r != NULL)
	{
		printf("\n %s : %s",r->duLieu.tiengAnh, r->duLieu.tiengViet); 
		inTruoc(r->trai);
		inTruoc(r->phai);
	}
}

void them(struct TDAV **goc, struct Tu x)
{
	struct TDAV *q;
	if(*goc==NULL)
	{
		q = (struct TDAV*) malloc(sizeof(struct TDAV));
		q->duLieu=x;
		q->trai=NULL;
		q->phai=NULL;
		*goc=q;
	}
	else{
		if (strcmp((*goc)->duLieu.tiengAnh, x.tiengAnh)>0)
		{
			them(&(*goc)->trai,x);
		}
		else if (strcmp((*goc)->duLieu.tiengAnh, x.tiengAnh)<0)
		{
			them(&(*goc)->phai,x);
		}
	}
}

char* traTu(struct TDAV *goc, char ta[50])
{
	if (goc==NULL) 
		return NULL;
	else
	{
		if(strcmp(goc->duLieu.tiengAnh,ta) == 0)
				return goc->duLieu.tiengViet;
		else
			if(strcmp(goc->duLieu.tiengAnh,ta)>0)
				return traTu(goc->trai,ta);
			else return traTu(goc->phai,ta);
	}
}


main(){
	struct Tu t;
	struct TDAV *td;
	char tuTra[50], *kq;
	td = taoCay();
	inTruoc(td);
	
	printf("\n Nhap TA:");
	fflush(stdin);
	gets(t.tiengAnh);
	
	printf("\n Nhap VN:");
	fflush(stdin);
	gets(t.tiengViet);
	
	them(&td, t);
	printf("\n");
	inTruoc(td);
	
	printf("\n Nhap tu tra TA:");
	gets(tuTra);
	
	kq = traTu(td, tuTra);
	if(kq == NULL)
	{
		printf("\n Khong tim thay");
	}
	else
		printf("\n Dich sang tieng viet: %s", kq);
}
