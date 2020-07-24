#include <string.h>
#include <stdio.h>

#define max 100
struct SinhVien
{
	char hoTen[max];
	int	namSinh;
	float dtb;
	int sl; 
}; 
void khoiTao(struct SinhVien *sv){
	sv->sl = 0;
}

// Ham nhap 1 sinh viên
void nhapSV(struct SinhVien *s)
{ 
  	fflush(stdin);
  	printf("Nhap ho ten ");
	gets(s->hoTen);
	
  	printf("Nhap nam sinh: "); 
	scanf("%d", &s->namSinh);
	
  	printf("Nhap dtb: "); 
	scanf("%f",&s->dtb);
}

//Ham in sinh viên
void inSV(struct SinhVien s)
{
  	printf("%s\t %d\t %.2f \n", s.hoTen, s.namSinh, s.dtb);
}

//Ham nhap mot mang n sinh vien
void nhapDSSV(struct SinhVien ds[], int n)
{
    int i;
    for(i = 0; i < n ; i++)
        nhapSV(&ds[i]);
}

//Ham in danh sach sinh vien
void inDSSV(struct SinhVien ds[], int n){
	int i;
    for(i = 0; i <  n ; i++){
    	inSV(ds[i]);
	}
}

//Ham tim 1 sinh vien theo ten
int timSV(struct SinhVien ds[], int n, char *x)
{
	int i;
	for(i = 0; i < n; i++)
	   if(strcmp(ds[i].hoTen, x) == 0)
		return i;
	return -1;	
}

//Ham liet ke cac sinh vien co diem >=8
void lietKeSV8(struct SinhVien ds[], int n){
	int i;
	for(i = 0; i < n; i++){
		if(ds[i].dtb >= 8){
			inSV(ds[i]);
		}
	}
}

//Ham them 1 sv vao cuoi mang
void themSV(struct SinhVien *sv, char ht[], int ns, float d)
{  
	if(sv->sl < max){
		strcpy(sv->hoTen, ht); //strcpy dung de sao chep toan bo ky tu cua chuoi nay qua chuoi khac.
		sv->namSinh = ns;
		sv->dtb = d;
		sv->sl ++;
	}
}
//ham lay ho 
char layHo(){
	
} 
//ham dem sinh vien
int demSinhVien(){
}
//Sap xep
void sapxep(struct SinhVien sv[], int n)
{
    int i, j;
   	struct SinhVien temp;
   	for(i = 0; i < n-1; i++)
    for(j = i + 1; j < n; j++)
    {
        if(strcmp(sv[i].hoTen,sv[j].hoTen) > 0) //strcpm sanh 2 chuoi voi nhau
         {
            temp = sv[i]; 						// sv[i].hoTen > sv[j].hoTen) return 1
            sv[i] = sv[j];						// sv[i].hoTen = sv[j].hoTen) return 0
            sv[j] = temp;						// sv[i].hoTen < sv[j].hoTen) return -1
         }
    }
    inDSSV(sv, n);
}

// Ham main()
void main()
{
	struct SinhVien  m[100];
	char ht[30];
	int k;
	nhapDSSV(m, 1);
	inDSSV(m, 1);
	fflush(stdin);
	printf("Nhap ho ten sinh vien can tim:"); 
	gets(ht);
	k= timSV(m, 1, ht);
	if (k==-1)
		printf("Khong tim thay");
	else
		inSV(m[k]);
	
	printf("\n Danh sach sinh vien co diem trung binh >=8:\n");	
	lietKeSV8(m, 1);
	
	themSV(m, "AbC",1998, 9.00);
	inDSSV(m, 2);
}


