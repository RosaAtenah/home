#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct statSite{
	char IP[50];
	char time[50];
	char Url[100];
}statSite;

// void printCss(){
// 	char line[255];
// 	FILE *file = fopen("Stat.css","r");
// 	while (fgets(line,255,file) != NULL){
// 		printf("\t%s",line);
// 	}
// 	fclose(file);
// }

int countStat(){
	char count[10];
	//~ char cmd[200];

	FILE *fic = NULL;
	
	//sprintf(cmd,"cat /var/log/apache2/access.log|wc -l");
	fic = popen("sudo cat /var/log/apache2/access.log|wc -l","r");
	fgets(count,10,fic);
	pclose(fic);
	return atoi(count);
}

statSite *completeStatSite(int nbrLigne){
	statSite *statSites =(statSite *) malloc(nbrLigne*sizeof(statSite));
	
	FILE * fic =NULL; 
	fic = popen("sudo cat /var/log/apache2/access.log","r");
	
	if (fic == NULL)
	{
		printf("<p>Erreur lors de l 'ouverture du fichier </p>");
		exit(EXIT_FAILURE);
	}
	char line[1000] = "";
	int count = 0;
	
	while(fgets(line,1000,fic)!=NULL){
		char url[100];
		sscanf(line, "%15s - - [%49[^]]] \"%*s %199[^\"]\"", statSites[count].IP, statSites[count].time, url);
		sscanf(url,"%[^?]",statSites[count].Url);
		count++;
	}
	
	
	return statSites;
}
int main(){
	int nbrLigne = 0;
	
	nbrLigne = countStat();
	
	printf("Content-type: text/html\n\n");
	printf(
		"<head>"
			"<meta charset=\"UTF-8\">"
			"<title>Mettre en ligne vos fichiers</title>"
			"<link rel=\"stylesheet\" href=\"Stat.css\" >"
	// 		"<style>"
	// );
	// printCss();
	// printf(		
			"</style>"
		"</head>"
		"<body>\n"
	);
	
	statSite *statSites =(statSite *) malloc(nbrLigne*sizeof(statSite));
	statSites = completeStatSite(nbrLigne);
	printf("<table>");
	printf("<tr><td>IP</td><td>Date</td><td>URL</td></tr>");
	for (int i = 0; i < nbrLigne; i++)
	{
		printf("<tr class=\"%s\"><td>%s</td><td>%s</td><td>%s</td></tr>",i%2?"paire":"impaire",statSites[i].IP, statSites[i].time, statSites[i].Url);
	}
	printf("</table>");
	return 0;
}