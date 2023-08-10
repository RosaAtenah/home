#ifndef __STRUCT__H__
#define __STRUCT__H__
typedef struct{
	char mac[50];
	char label[50];
	char marque[50];
}pc;

typedef struct{
	char nom[50];
	char prenom[50];
	char tel[50];
	char email[50];
	char adresse[100];
	char github[50];
}etudiant;

pc * tri(pc *ordis , int nbr_pc);

etudiant * tri1(etudiant *etudiants,int nbr_pc);

#endif
