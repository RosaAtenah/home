#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

pc * tri(pc *ordis , int nbr_pc){
	for(int i=0;i<nbr_pc;i++){
			for(int j=i+1;j<nbr_pc;j++){
				pc tmp;
				if(strcmp(ordis[i].label,ordis[j].label)>0){
					tmp =ordis[i];
					ordis[i] = ordis[j];
					ordis[j] = tmp;
					
				}
			}
		}
	return ordis;
}

etudiant * tri1(etudiant *etudiants,int nbr_pc){
	for(int i=0;i<nbr_pc;i++){
			for(int j=i+1;j<nbr_pc;j++){
				etudiant tmp;
				if(strcmp(etudiants[i].nom,etudiants[j].nom)>0){
					tmp =etudiants[i];
					etudiants[i] = etudiants[j];
					etudiants[j] = tmp;
					
				}
			}
		}
	return etudiants;
}


