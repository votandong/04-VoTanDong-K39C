#include<stdio.h>
#include<stdlib.h>

struct ThueBao{
	char ten[50];
	char sdt[11];
};

struct DanhBa{
	struct ThueBao duLieu;
	struct DanhBa *lienKet;
};

void nhapThueBao(struct ThueBao *tb){
	printf("Nhap Ten: ");
	fflush(stdin);
	gets(tb->ten);
	
	printf("Nhap So Dien Thoai: ");
	fflush(stdin);
	gets(tb->sdt);
}

void inThueBao(struct ThueBao tb){
	printf("\n Ten Thue Bao: %s", tb.ten);
	printf("\n So Thue Bao: %s", tb.sdt);
}

void inDanhBa(struct DanhBa *dau){
	struct DanhBa *p;
	p = dau;
	while(p != NULL){
		inThueBao(p->duLieu);
		p = p->lienKet;
	}
}

void themDau(struct DanhBa **dau, struct ThueBao x){
	struct DanhBa *q = (struct DanhBa*)malloc(sizeof(struct DanhBa));
	q->duLieu = x;
	q->lienKet = *dau;
	*dau = q;
}

void themCuoi(struct DanhBa **dau, struct ThueBao x){
	struct DanhBa *q = (struct DanhBa*)malloc(sizeof(struct DanhBa));
	struct DanhBa *p;
	q->duLieu = x;
	q->lienKet = NULL;
	if(*dau == NULL){
		*dau = q;
	}
	else{
		p = *dau;
		while(p->lienKet != NULL){
			p =  p->lienKet;
		}
	p->lienKet = q;
	}		
}

void themSauP(struct DanhBa *p, struct ThueBao x){
	struct DanhBa *q = (struct DanhBa*)malloc(sizeof(struct DanhBa));
	if(p == NULL){
		printf("Khong The Them");
		return;
	}
	q->duLieu = x;
	q->lienKet = p->lienKet;
	p->lienKet = q;
}

void demSoThueBao(struct DanhBa *dau){
	int dem = 0;
	while(dau != NULL){
		dau = dau->lienKet;
		dem ++;
	}
	printf("\n %d", dem);
}

main(){
	struct ThueBao tb;
	struct DanhBa *db = NULL;
	
	nhapThueBao(&tb);
	themDau(&db, tb);
	
	nhapThueBao(&tb);
	themCuoi(&db, tb);
	
	nhapThueBao(&tb);
	themSauP(db, tb);
	inDanhBa(db);
	
	demSoThueBao(db);
	
}
