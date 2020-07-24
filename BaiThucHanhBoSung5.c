#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ThueBao{
	char tenTB[30];
	char diaChi[50];
	char soDT[10];
	int soSoDT;
};
struct DanhBa{
	struct ThueBao duLieu;
	struct DanhBa *lienKet;	
}; 

void nhapThueBao(struct ThueBao *x){
	int i;
	fflush(stdin);
	
	printf("Nhap ten thue bao: ");
	gets(x->tenTB);
	
	printf("Nhap dia chi thue bao: ");
	gets(x->diaChi);
	
	printf("Nhap so so dien thoai cua thue bao:");
	scanf("%d", &x->soSoDT);
	
	fflush(stdin); 
	for(i = 0; i < x->soSoDT; i++){
		printf("Nhap so dien thoai thu %d:", i);
		gets(x->soDT);
	}
	
}

void inMotThueBao(struct ThueBao x){
	printf("\n Ten Thue Bao: %s \t Dia chi: %s \t So so thue bao: %d \t", x.tenTB, x.diaChi, x.soSoDT);
	int i;
	for(i = 0; i < x.soSoDT; i++ ){
		printf("\nSo thue bao thu %d %s \t", i, x.soDT);
	}
}
void khoiTao(struct DanhBa **dau){
	*dau = NULL;
}

void themCuoi(struct DanhBa **dau, struct ThueBao x)
{
	struct DanhBa *q,*p;
	q = (struct DanhBa*) malloc(sizeof(struct DanhBa));
	q->duLieu=x; //dua x vao q
	q->lienKet=NULL; //q lien ket den null
	if(*dau==NULL)	//if dau = null
		*dau=q;		// cho phan tu dau chuyen den q
	else
	{
		p=*dau; 
		while(p->lienKet!=NULL) 
			p=p->lienKet;		
			p->lienKet=q;
	}
}

void themDau(struct DanhBa **dau, struct ThueBao x){
	struct DanhBa *q, *p;
	q = (struct DanhBa*) malloc(sizeof(struct DanhBa));// cap phat bo nho dong
	q->duLieu = x;
	if(*dau == NULL){
		*dau = q;
	}
	else{
		q->lienKet = *dau;
		*dau = q;	
	}
}


void inDanhBa(struct DanhBa *d){
	struct DanhBa *p;
	p = d;
	while(p != NULL){
		inMotThueBao(p->duLieu);
		p = p->lienKet;
	}
}
//ham xoa vi tri
void xoaTheoViTri(struct DanhBa **p, int viTri){
	int dem = 1, thongBao = 0;
	struct DanhBa *q, *r ;
	r = *p;
	while((r != NULL) && (thongBao == 0)){\
		if(dem == viTri){
			q = r->lienKet;
			r->lienKet = q->lienKet;
			q->lienKet = NULL;
			free(q);
			thongBao = 1;
		}
		dem ++;
		r = r->lienKet;
	}
	if(thongBao == 0){
		printf("Khong tim thay vi tri can xoa");
	}
	
}
//Ham tim tra ve vi tri
int TimViTri(struct DanhBa **dau, char *x)
{
	struct DanhBa *p, *r;
	int viTri = -1;
	p = *dau;
	while (p!=NULL)
	{
		viTri++;
		if(strcmp(p->duLieu.tenTB, x)==0)			
			return viTri;
		else 
		{
			p = p->lienKet;
		}
		
		
	}
	return viTri;
}

struct DanhBa* Tim(struct DanhBa *dau, char *x, struct ThueBao k)
{
	struct DanhBa *p, *q, *r;
	q = (struct DanhBa*) malloc(sizeof(struct DanhBa));
	q->duLieu = k;
	p = dau;
	while (p!=NULL)
	{
		if(strcmp(p->duLieu.tenTB, x)==0)			
			return p;
		else 
		{
			p = p->lienKet;
		}
		
	}
	return NULL;
}
void themSauP(struct DanhBa *p, struct ThueBao x)
{
	struct DanhBa *q ;
	q = (struct DanhBa*) malloc(sizeof(struct DanhBa));
	q->duLieu=x;
	q->lienKet = p->lienKet;
	p->lienKet= q;
}
int demSoThueBao(struct DanhBa *dau){
    int dem = 0;
    struct DanhBa *p;
    p = dau;
    for(p; p != NULL; p = p->lienKet){
        dem += p->duLieu.soSoDT;
    }
    return dem;
}
void xoaTheoTen(struct DanhBa **p, char *x){
	int vt;
	vt = TimViTri(p, x);
	xoaTheoViTri(p, vt);
}

main(){
	struct DanhBa *db = NULL, *p; 
	struct ThueBao x;
	char ten[100], xoa[100];
	int STB, VT;
	
	nhapThueBao(&x);
	themCuoi(&db, x);
	printf("Danh ba sau khi them cuoi: \n");
	inDanhBa(db);
	
	printf("\n");
	nhapThueBao(&x);
	themDau(&db, x);
	printf("Danh ba sau khi them vao dau: \n");
	inDanhBa(db);
	
	fflush(stdin);
	printf("\n Nhap Ten Can tim: ");
	scanf("%s", ten);
	p = Tim(db, ten, x);
	if(p != NULL){
		nhapThueBao(&x);
		themSauP(db, x);
		printf("Danh ba sau khi them sau p:");
		inDanhBa(db);
	}
	else{
		printf("Khong tim thay");
	}
	
	STB = demSoThueBao(db);
	printf("\n Tong so thue bao la: %d", STB);
	
	VT = TimViTri(&db,"dong");
	printf("\n%d", VT);
	printf("\n Nhap Ten Can Xoa: ");
	scanf("%s", xoa);
	xoaTheoTen(&db, xoa);
	inDanhBa(db);
}
