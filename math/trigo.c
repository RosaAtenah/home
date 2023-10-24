#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	FILE * fic = fopen("trigo.csv" , "w");
	if(fic == NULL){
		printf("erreur lors de l'ouverture du fichier \n");
		exit(1);
	}
	char x[]="x";
	char s[8]="sinx";
	char c[8]="cosx";
	char t[8]="tanx";
	fprintf(fic,"%s,%s,%s,%s\n",x,s,c,t);
	
	for (int i = 0; i <=360; i++)
	{
		fprintf(fic,"%d°,%.2lf,%.2lf,%.2lf\n",i,(double)sin((i*M_PI/180.0)),(double)cos((i*M_PI/180.0)),(double)tan((i*M_PI/180.0)));
	}
	fclose(fic);
	return 0;
}
