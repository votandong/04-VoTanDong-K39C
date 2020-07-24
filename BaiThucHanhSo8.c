#include<stdio.h>
#include<conio.h>
#define max 50
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
int daTham[max];

void docTep(char *tenTep, struct DoThi *g)
{
	FILE *f; 
	int i, j, tg;
	
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	
	g->soCanh = 0;
	for(i = 0; i < g->soDinh; i++)
		for(j = 0; j < g->soDinh; j++)
		{
			fscanf(f, "%d", &tg);
			if(tg == 1)
			{ 
				g->dsCanh[g->soCanh].dinhDau = i;
	 			g->dsCanh[g->soCanh].dinhCuoi = j;
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
		printf("%d %d \n", g.dsCanh[i].dinhDau, g.dsCanh[i].dinhCuoi);
	}
}

void duyetSauCK(struct DoThi g, int v, struct DoThi *h)
{
	daTham[v] = 1;
	int i, w;
	
	for(i = 0; i < g.soCanh; i++)
	{
		if(g.dsCanh[i].dinhDau == v) 
			w = g.dsCanh[i].dinhCuoi;
		else
			if(g.dsCanh[i].dinhCuoi == v) 
				w = g.dsCanh[i].dinhDau;
			else w = -1;
		if(w != -1 && daTham[w] == 0)
		{
			h->dsCanh[h->soCanh] = g.dsCanh[i];
			h->soCanh++;
			duyetSauCK(g, w, h);
		}
	}
}


struct DoThi cayKhung(struct DoThi g)
{
	struct DoThi h;
	int i;
	
	h.soDinh = g.soDinh;
	h.soCanh = 0;
	for(i = 0; i < g.soDinh; i++) daTham[i] = 0;
	duyetSauCK(g, 0, &h);
	return h;
}
void main()
{
	struct DoThi g,h;
	
	docTep("DT1.txt", &g);
	inDoThi(g);
	
	h = cayKhung(g);
	inDoThi(h);
} 
