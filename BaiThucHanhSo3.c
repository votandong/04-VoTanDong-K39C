#include<stdio.h>
#include<stdlib.h>

struct ThueBao{
	char ten[50];
	char std[11];
};

struct DanhBa{
	struct ThueBao duLieu;
	struct DanhBa *lkTruoc, *lkSau;
};

void themTruoc(struct DanhBa **dau, struct DanhBa *p, struct ThueBao x){
	struct DanhBa *q, *p1;
	q = (struct DanhBa*)malloc(sizeof(struct DanhBa));
	q->duLieu = x;
	if(*dau == NULL){
		q->lkTruoc = NULL;
		q->lkSau = NULL;
		*dau = q;
	}
	else{
		if(*dau == p){
			q->lkTruoc == NULL;
			q->lkSau = p;
			p->lkTruoc = q;
			*dau = q;
		}
		else{
			p1 = p->lkTruoc;
			q->lkTruoc = p1;
			p1->lkSau = q;
			q->lkSau = p;
			p->lkTruoc = q;
		}
	}
}

void themSau(struct DanhBa **dau, struct DanhBa *p, struct ThueBao x){
	struct DanhBa *q, *p1;
	
}

void nhapThueBao(struct ThueBao *tb){
	printf("Nhap Ten:");
	fflush(stdin);
	gets(tb->ten);
	
	printf("Nhap SDT:");
	fflush(stdin);
	gets(tb->std);
}

void inThueBao(struct ThueBao tb){
	printf("\n Ten:%s", tb.ten);
	printf("\n SDT:%s", tb.std);
}

void inDanhBa(struct DanhBa *db){
	struct DanhBa *p;
	p = db;
	while(p != NULL){
		inThueBao(p->duLieu);
		p = p->lkSau;
	}
}


main(){
	struct ThueBao tb;
	struct DanhBa *db = NULL;
	nhapThueBao(&tb);
	themTruoc(&db, db,tb);
	
	nhapThueBao(&tb);
	themTruoc(&db, db,tb);
	
	inDanhBa(db);
	
}
