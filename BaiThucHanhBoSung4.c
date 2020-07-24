#include<stdio.h>
#include<stdlib.h>
#define max 100
struct ThueBao{
	char tenTB[30];
	char diaChi[50];
	char soDT[10];
	int soSoDT;
};
struct DanhBa{
	struct ThueBao db[max]; 
	int soTB;
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
		printf("\nSo thue bao thu %d %s \t", i,x.soDT);
	}
}

void nhapDanhBa(struct DanhBa *d){
	int i;
	printf("Nhap so thue bao:");
	scanf("%d", &d->soTB);
	fflush(stdin);
	for(i = 0; i < d->soTB; i++){
		nhapThueBao(&d->db[i]);
	}
}

void inDanhBa(struct DanhBa d){
	int i;
	for(i = 0; i < d.soTB; i++)
	{
		inMotThueBao(d.db[i]);
	}
}
//Them mot thue bao vao vi tri bat ki trong danh ba
void themThueBao(struct DanhBa *d, struct ThueBao x, int k){
	int i;
	d->soTB++;
	i = d->soTB-1;
	while(i != k){
		d->db[i] = d->db[i-1];
		i--;
	}
	d->db[k] = x;
}

void xoa(struct DanhBa *d, int k){
	int i;
	if(k == d->soTB - 1)
		d->soTB--;
	else if(k >= 0 && k < d->soTB - 1)
	{
		for (i = k; i < d->soTB - 1; i++)
			d->db[i] = d->db[i+1];
		d->soTB--;
	}

}

//Tim ten can tim
int timTen(struct DanhBa d, char tenTB[]){
	int i = 0;
	while(i < d.soTB){
		if(strcmp(d.db[i].tenTB) == 0 )
			return i;
		i++;
	}
	return -1;
} 

main(){
	struct ThueBao t;
	struct DanhBa db;
	int k;
	
	nhapDanhBa(&db);
	inDanhBa(db);
	printf("\n DS sau khi them");
	
	printf("Them thue bao tai vi tri bat ki: \n");
	printf("nhap vi tri k can them thue bao: "); 
	scanf("%d",&k);	
	printf("nhap thue bao can them: \n");
	nhapThueBao(&t);
	themThueBao(&db ,t , k);
	printf("danh sach thue bao sau khi them: \n");
	inDanhBa(db);
	
	xoa(&db, 1);
	printf("\n Danh sach sau khi xoa");
	inDanhBa(db);
	
}
