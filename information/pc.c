#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main(){
	int nbr_pc=20;
	pc *ordis;
	ordis = (pc *)malloc(nbr_pc*sizeof(pc));
	FILE * fic = fopen("info_pc.csv","a");
	fputs("MAC,LABEL,Marque\n",fic);
	for (int i = 0; i < nbr_pc; i++)
	{
		printf("entrer pc n° %d :\n",i+1);
		printf("addresse mac : "); scanf("%s",ordis[i].mac);
		printf("label : "); scanf("%s",ordis[i].label);
		printf("marque : "); scanf("%s",ordis[i].marque);
			
	}
	ordis = tri(ordis,nbr_pc);
	for (int i = 0; i < nbr_pc; i++){
		fprintf(fic,"%s,%s,%s\n",ordis[i].mac,ordis[i].label,ordis[i].marque);
	}

	fclose(fic);
	
	etudiant *etudiants;
	etudiants = (etudiant *)malloc(nbr_pc*sizeof(etudiant));
	fic = fopen("info_etudiant.csv","a");
	fputs("nom,prenom,tel,mail,adresse,github\n",fic);
	nbr_pc = 43;
	for (int i = 0; i < nbr_pc; i++)
	{
		printf("entrer etudiant n° %d :\n",i+1);
		printf("nom : ");scanf("%s",etudiants[i].nom);
		
		printf("prenom : ");
		scanf("\n");
		fgets(etudiants[i].prenom,50,stdin);
		
		printf("tel : ");scanf("%s",etudiants[i].tel);
		printf("mail : ");scanf("%s",etudiants[i].email);
		printf("adresse : ");scanf("\n");fgets(etudiants[i].adresse,50,stdin);
		printf("github : ");scanf("%s",etudiants[i].github);
		
			
	}
	etudiants = tri1(etudiants,nbr_pc);
		
	for (int i = 0; i < nbr_pc; i++){
		int n = strlen(etudiants[i].prenom) -1;
		etudiants[i].prenom[n]='\0';
		n=strlen(etudiants[i].adresse) -1;
		etudiants[i].adresse[n]='\0';
		fprintf(fic,"%s;%s;%s;%s;%s;%s\n",etudiants[i].nom,etudiants[i].prenom,etudiants[i].tel,etudiants[i].email,etudiants[i].adresse,etudiants[i].github);
	}

	fclose(fic);
	
	return 0;
}

