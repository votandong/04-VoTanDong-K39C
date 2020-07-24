#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Nguoi
{
	char hoTen[30];
	int namSinh;
};

struct CTQ
{
	struct Nguoi duLieu;
	struct CTQ *con , *em;
};

struct CTQ* taoNut(struct Nguoi ng, struct CTQ *c, struct CTQ *e)
{
	struct CTQ *p;
	p = (struct CTQ*) malloc(sizeof(struct CTQ));
	p->duLieu = ng;
	p->con = c;
	p->em = e;
	return p;
}

struct CTQ* taoCay()
{
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6, ng7, ng8;
	struct CTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	
	strcpy(ng1.hoTen, "Nguyen H"); 
	ng1.namSinh = 1970;
   	n1 = taoNut(ng1, NULL, NULL);
   	
   	strcpy(ng2.hoTen,"Nguyen G"); 
	ng2.namSinh = 1965;
   	n2 = taoNut(ng2, NULL, n1);
   	
   	strcpy(ng3.hoTen,"Nguyen C"); 
	ng3.namSinh = 1935;
   	n3 = taoNut(ng3, n2, NULL);
   	
   	strcpy(ng4.hoTen,"Nguyen F");
	ng4.namSinh = 1965;
   	n4 = taoNut(ng4, NULL, NULL);
   	
   	strcpy(ng5.hoTen,"Nguyen E");
	ng5.namSinh = 1960;
   	n5 = taoNut(ng5, NULL, n4);
   	
   	strcpy(ng6.hoTen, "Nguyen D");
	ng6.namSinh = 1955;
   	n6 = taoNut(ng6, NULL, n5);
    	
    strcpy(ng7.hoTen, "Nguyen B"); 
	ng7.namSinh = 1930;
   	n7 = taoNut(ng7, n6, n3);
   	
    strcpy(ng8.hoTen, "Nguyen A"); 
	ng8.namSinh = 1900;
   	n8 = taoNut(ng8, n7, NULL);
   	return n8;
}

// In thong tin nguoi
void inNut(struct Nguoi ng)
{
	printf("Ho ten: %s. \t Nam sinh: %d \n", ng.hoTen , ng.namSinh);
}

// In cay gia pha theo thu tu the he
void inCGP(struct CTQ *goc)
{
	struct CTQ *q[100] , *p;
	int dau, cuoi;
	if(goc != NULL)
	{
		q[0] = goc;
		dau = cuoi = 0;
	}
	while (dau <= cuoi)
	{
		p = q[dau];
		dau++;
		inNut(p->duLieu);
		p = p->con;
		while (p != NULL)
		{
			cuoi++;
			q[cuoi] = p;
			p = p->em;
		}
	}
}


int dem(struct CTQ *goc)
{
	struct CTQ *p;
	int tong;
	if (goc == NULL) return 0;
	else
	{
		tong = 1;
		p = goc->con;
		while (p != NULL)
		{
			tong = tong + dem(p);
			p = p->em;
		}
		return tong;
	}
}

struct CTQ* tim(struct CTQ *goc, char *ht)
{
    struct CTQ *p, *kq;
    if(goc == NULL) return NULL;
   	else
     	if(strcmp(goc->duLieu.hoTen,ht) == 0) return goc;
     	else
     	{
        	p = goc->con;
        	while(p != NULL)
			{
    			kq = tim(p,ht);
   				if(kq != NULL) return kq;
   				else
     			 	p = p->em;	
			}
			return NULL;
    	}	
}

void main()
{
	struct CTQ *goc, *kq;
	int d;
	char ht[30];
	
	goc = taoCay();
	inCGP(goc);
	printf("\n");
	printf("Tong so nguoi co trong cay la: %d\n",dem(goc));
	printf("\n");
	
	printf("Nhap ho ten can tim: "); gets(ht);
	kq = tim(goc,ht);
	if(kq == NULL)
		printf("Khong tim thay");
	else
		printf("Tim thay Ho ten: %s, Nam sinh: %d \n", kq->duLieu.hoTen , kq->duLieu.namSinh);
	getch();
}
