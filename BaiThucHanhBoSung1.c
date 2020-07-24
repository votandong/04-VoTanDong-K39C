#include<stdio.h>

//Ham in day so fibonaci
void fibo(int n)
{
	int f1, f2, f3;
	f1 = 1; f2 = 1; f3 = f1 + f2;
	printf("%d %d", f1, f2);
	while (f3 <= n)
	{
		printf(" %d ", f3);
		f1 = f2; f2 = f3; f3 = f1 + f2;
	}	
}

//Ham kiem tra mot so co trong day fibonaci khong
int kiemTraFibo(int n ,int k){
	int f1, f2, f3;
	f1 = 1; f2 = 1; f3 = f1 + f2;
	
	if(k <= 0)
		return 0;
	if(k == 1)
		return 1;
	if(k == 2)
		return 1;	
		
	while (f3 <= n)
	{
		f1 = f2; f2 = f3; f3 = f1 + f2;
		if(k == f3)
			return 1;
	}
	return 0;
}

//Ham tra ve so fibonaci
int FibonaciThuN(int val){
	if(val < 0)
		return -1;
	else if(val == 0 || val == 1)
		return val;
	else
		return FibonaciThuN(val - 1) + FibonaciThuN(val - 2);	
}

void main()
{
	int k, h, a, i;
	
	//In day so fibonaci
	printf("Cac so fibonaci <= 1000: \n");
	fibo(1000);
	
	//Kiem tra 1 so co trong day fibonaci khong
	printf("\n Nhap so can kiem tra: ");
	scanf("%d", &k);
	if(kiemTraFibo(1000 , k) == 1)
	{
		printf("So %d co trong day fibonaci", k);	
	}
	else{
		printf("So %d khong co trong day fibonaci", k);
	}	
	//Ham in so fibonaci thu n
	printf("\n Nhap so fionaci thu: ");
	scanf("%d", &a);
	for(i = 0; i <= a; i++){
		if(i == a)
			printf("\n So fibonaci thu %d la: %d ", a, FibonaciThuN(i));	
	}
}

