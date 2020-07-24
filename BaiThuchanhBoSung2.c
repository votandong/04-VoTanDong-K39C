#include<stdio.h>
#include <conio.h>

//Ham nhap mang n so nguyen
void  nhapMang(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++) 
	{
		printf("Nhap so thu %d ", i); 
		scanf("%d", &a[i]);
	}
}

//Ham in mang
void inMang(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	printf("%d ", a[i]);
}

//Ham tim so lon nhat
int soLonNhat(int a[], int n)
{
	int i, max;
	max = a[0];
	for(i = 1; i < n; i++)
		if(max < a[i])
			max = a[i];
	return max;
}

// Ham tao mang chua so chan tu mang a
int taoMang(int a[], int n, int b[])
{
	int i, k;
	k = 0;
	for(i = 0; i < n; i++)
		if(a[i]%2 == 0)
		{
			b[k] = a[i];
			k++;
}
	return k;
}

//Ham tinh trung binh cong
float tinhTrungBinhCong(int a[], int n){
	int i;
	int tong = 0;
	for(i = 0; i <= n ; i++){
		tong += a[i];
	}
	return tong / n;
}

//Tim mot so nguyen trong mang
int timSoNguyen(int a[], int n, int s){
	int i;
	for(i = 0; i < n; i++){
		if(s == a[i]){
			return 1;
		}
		return 0;
	}	
}

//Sap xep mang tang
void mangTangDan(int a[], int n){
    int tg, i, j;
    for( i = 0; i < n - 1; i++){
        for( j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
}

//Gop mang
void tronmang(int a[],int n,int b[],int m,int c[],int t)
{
	int i=0,j=0, k;
	t=0;
	while(i < n && j < m) 
	{	
    	if(a[i] < b[j]) 
		{
	 	  c[t++] = a[i++];
	 	  
		}
		else
   		 {
    	 	c[t++] = b[j++];
    	 	
    	 }	 						//khi so sanh se co mot mang thua phan tu
    	 							//nen ta duyet lai mang do va them vao sau mang c
		while(i < n)    			//phan tu con thua o mang a
			c[t++] = a[i++]; 
		
		while(j < m) 				//phan tu con thua o mang b
			c[t++] = b[j++];
	}
	//sap xep tang dan
	int tg, h, l;
    for( h = 0; h < t - 1; h++){
        for( l = h + 1; l < t; l++){
            if(c[h] > c[l]){
                tg = c[h];
                c[h] = c[l];
                c[l] = tg;        
            }
        }
    }
	
	printf("\nMang tang dan sau khi tron:");
	for(k = 0; k < t; k++)
	printf("\t%d", c[k]);
		
}
//Dem so lan xuat hien cua tung phan tu
void demSoXuatHienTungPhanTu(int a[], int k){
	int i, cnt[10];
	for(i = 0; i < k; i++) 
		cnt[i] = 0;
		for(i = 0; i < k; i++){
        	cnt[a[i]] ++;
    }
    for( i = 0; i < k; i++){
        if(cnt[i] > 0){
            printf("\n Gia tri %d xuat hien %d lan!\n", i, cnt[i]);
        }
	}
}

//Ham main
void main()
{
	int x[10], y[10], z[10], l[100], a, n, k, tim;
	
	//Nhap mang va in mang
	printf("\nNhap so phan tu cua mang: ");
	scanf("%d", &k);
	
	nhapMang(x, k);
	printf("\n So phan tu cua mang x la:");
	inMang(x, k);
	
	nhapMang(z, k);
	printf("\n So phan tu cua mang z la:");
	inMang(z, k);
	
	//Tim so lon nhat
	a = soLonNhat(x, k);
	printf("\nSo lon nhat cua mang x la: %d \n", a);
	
	//Mang b chua cac so chan
	n = taoMang(x, k, y);
	printf("\nMang cac so chan cua mang x la:");
	inMang(y,n);
	
	// Tinh trung binh cong
	printf("\nTrung binh cong cua mang x la %.2f", tinhTrungBinhCong(x, k));
	
	//Tim so nguyen trong mang
	tim = timSoNguyen(x, k, 7);
	if(tim == 1)
	{
		printf("\n so 7 co trong mang x");
	}
	else{
		printf("\n so 7 khong co trong mang x");
	}
	
	//Sap xep mang tang cua mang a
	printf("\nDay so tang dan mang a la:");
	mangTangDan(x, k);
	inMang(x, k);
	//Tron 2 mang
	tronmang(x, k, z, k, l, k + k);
	demSoXuatHienTungPhanTu(l, k+k);
}

