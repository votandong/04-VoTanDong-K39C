#include<stdio.h>
#include<conio.h>
#define max 10
#define VC 1000

struct Canh
{
	int dinhDau, dinhCuoi;
	float trongSo;
};

struct DoThi
{
	int soDinh, soCanh;
	struct Canh dsCanh[max];
};
int tp[max]; 

void docTep(char *tenTep, struct DoThi *g)
{
	FILE *f; int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f,"%d", &g->soDinh);
	
	g->soCanh = 0;
	for(i = 0;i < g->soDinh; i++)
		for(j = 0; j < g->soDinh; j++)
		{
			fscanf(f, "%d", &tg);
			if(tg != VC && i < j)
			{ 
				g->dsCanh[g->soCanh].dinhDau = i;
	 			g->dsCanh[g->soCanh].dinhCuoi = j;
	 			g->dsCanh[g->soCanh].trongSo = tg;
				g->soCanh++;
			}		
		}	
	fclose(f);
}

void inDoThi(struct DoThi g)
{ 
	int i;
	printf("So dinh: %d, so canh: %d \n", g.soDinh, g.soCanh);
	for(i = 0; i < g.soCanh; i++)
	{
		printf("%d %d %f \n", g.dsCanh[i].dinhDau, g.dsCanh[i].dinhCuoi, g.dsCanh[i].trongSo);
	}
}

void sort(struct DoThi *g)
{
	int i , j; 
	struct Canh tg;
	
	for(i = 0; i < g->soCanh-1; i++)
		for(j = i+1; j < g->soCanh; j++)
			if(g->dsCanh[i].trongSo > g->dsCanh[j].trongSo)
			{
				tg = g->dsCanh[i];
				g->dsCanh[i] = g->dsCanh[j];
				g->dsCanh[j] = tg;
			}
}

void ghepTPLT(int a, int b)
{
	int tg, i;
 	if(a > b)
	{
		tg = a; 
		a = b; 
		b = tg;
	}
 	for(i = 1; i < max; i++) 
	 	if(tp[i] == b) 
			tp[i] = a;
}

struct DoThi cayKhungNN(struct DoThi g)
{
	struct DoThi h;
	int i, k, dd, dc;
	
	h.soDinh = g.soDinh;
	h.soCanh = 0;
	sort(&g);
	
	for(i = 0; i < g.soDinh; i++) 
	tp[i] = i; 
	k = 0; 
	while (h.soCanh < h.soDinh - 1)
	{
		dd = g.dsCanh[k].dinhDau;
		dc = g.dsCanh[k].dinhCuoi;
		if (tp[dd] != tp[dc])
		{
			h.dsCanh[h.soCanh] = g.dsCanh[k];
			h.soCanh++;
			ghepTPLT(tp[dd], tp[dc]);
		}
		k++; 
	}
	return h;
}
void main()
{
	struct DoThi g, h;
	
	docTep("DT1.txt", &g);
	inDoThi(g);
	
	h = cayKhungNN(g);
	inDoThi(h);
} 
