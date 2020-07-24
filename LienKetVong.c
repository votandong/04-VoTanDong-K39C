#include<stdio.h>
#include<stdlib.h>

struct ThueBao{
	char ten[30];
	char sdt[11];
};

struct DanhBa{
	struct ThueBao duLieu;
	struct DanhBa *lienKet;
};

void ThemSau(struct DanhBa **l, struct ThueBao x){
	struct DanhBa *p = (struct DanhBa*)malloc(sizeof(struct DanhBa));
	p->duLieu = x;
	if(*l == NULL){
		*l = p;
		(*l)->lienKet = *l;
	}
	else{
		p->lienKet = (*l)->lienKet;
		(*l)->lienKet = p;
	}
}

void themTruoc(struct DanhBa **l, struct ThueBao x){
	ThemSau(l, x);
	*l = (*l)->lienKet;
}

void xoaSau(struct DanhBa **l)
{
	struct DanhBa *p;
	if (*l!=NULL)
	{
		p = (*l)->lienKet;
		if ((*l)->lienKet == *l) 
			*l = NULL;
		else 
			(*l)->lienKet = p->lienKet;
		free(p);
	}
}




void nhapThueBao(struct ThueBao *tb){
	printf("Nhap Ten:");
	fflush(stdin);
	gets(tb->ten);
	
	printf("Nhap SDT:");
	fflush(stdin);
	gets(tb->sdt);
}

void inThueBao(struct ThueBao tb){
	printf("\n Ten: %s", tb.ten);
	printf("\n SDT: %s", tb.sdt);
}

void inDanhBa(struct DanhBa *l){
	struct DanhBa *p;
	if(l != NULL){
		p = l;
		do{
			inThueBao(p->duLieu);
			p = p->lienKet;
		}while(p != l);
	}
	
}


main(){
	struct ThueBao tb;
	struct DanhBa *db = NULL;
	
	nhapThueBao(&tb);
	themTruoc(&db, tb);
	
	nhapThueBao(&tb);
	ThemSau(&db, tb);
	
	inDanhBa(db);
	
	
	xoaSau(&db);
	inDanhBa(db);
}
