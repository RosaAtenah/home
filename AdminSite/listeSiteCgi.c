#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Site {
    char name[100];
    char state[50];
    char notState[50];
} Site;

int main(){
	char c;
    int availableCount = 0, enabledCount = 0;
	char * get;
	char site[50];
	char notState[50];
	char cmd[200];
	
	get = getenv("QUERY_STRING");
	sscanf(get,"%[^=]=%*s",site);
	sscanf(get,"%*[^=]=%s",notState);
	
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Mettre en ligne vos fichiers</title></head><body>\n");
	
	if(*get!=0){
		
	if(strcmp(notState,"desactivate")==0){
		int i=0;
		sprintf(cmd,"sudo a2dissite %s",site);
		popen(cmd,"w");
		if(i==0){
			printf("<meta http-equiv='refresh' content='0; url=http://www.cgi.com/cgi-bin/listeSite.cgi'>");

		}
		i++;
		sprintf(cmd,"sudo systemctl reload apache2");
		popen(cmd,"w");
		
	}
	else{
		int i=0;
		sprintf(cmd,"sudo a2ensite %s",site);
		popen(cmd,"w");
		if(i==0){
			printf("<meta http-equiv='refresh' content='0; url=http://www.cgi.com/cgi-bin/listeSite.cgi'>");
		}
		i++;
	
		sprintf(cmd,"sudo systemctl reload apache2");
		popen(cmd,"w");
		
		
	}
	}
	
	
    // Compter les listes valables
    FILE *cmdlist = popen("ls /etc/apache2/sites-available", "r");
    while (1) {
        c = fgetc(cmdlist);
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            availableCount++;
        }
    }
    pclose(cmdlist);

    // Mettre dans un tableau les sites valables
    cmdlist = popen("ls /etc/apache2/sites-available", "r");
    Site sites[availableCount];
    int count = 0;
    while (fgets(sites[count].name, 100, cmdlist) != NULL) {
        sites[count].name[strcspn(sites[count].name, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
        count++;
    }
    pclose(cmdlist);

    // Compter les sites activés
    cmdlist = popen("ls /etc/apache2/sites-enabled", "r");
    while (1) {
        c = fgetc(cmdlist);
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            enabledCount++;
        }
    }
    pclose(cmdlist);

    // Mettre dans un tableau les sites activés
    cmdlist = popen("ls /etc/apache2/sites-enabled", "r");
    count = 0;
    char activate[enabledCount][100];
    while (fgets(activate[count], 100, cmdlist) != NULL) {
        activate[count][strcspn(activate[count], "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
        count++;
    }
    pclose(cmdlist);

    // Votre code pour déterminer l'état des sites (activés/désactivés) peut être ajouté ici.
    
	for (int i = 0; i < availableCount; i++){
		int t = 0;
		for (int j = 0; j < count; j++)
		{
			if((strstr(sites[i].name,activate[j]))){
				t = 1;
					
				break;
			}
		}
		if(t==1){
			strcpy(sites[i].state,"activate");
			strcpy(sites[i].notState,"desactivate");
		}
		else{
			strcpy(sites[i].state,"desactivate");
			strcpy(sites[i].notState,"activate");
		}
	}
	
	
	printf("<p>%s        %s</p>",site,notState);
	printf("<table>\n");
	printf("<thead>\n"
			"<tr>\n"
				"<th>N°</th>\n"
				"<th>SITES</th>\n"
				"<th>STATES</th>\n"
				"<th>BOTTON</th>\n"
			"</tr>\n"
			"</thead>\n");
				
	printf("<tboby>\n");
	
    // Affichage des noms des sites disponibles
    for (int i = 0; i < availableCount; i++) {
		printf("<tr>\n");
        printf("<th>Site %d </th>"
			   "<th>%s</th>"
			   "<th>%s</th>\n"
			   "<th><a href='http://www.cgi.com/cgi-bin/listeSite.cgi?%s=%s'><input type='button' value='%s'></a>"
			   , i + 1, sites[i].name,sites[i].state, sites[i].name,sites[i].notState,sites[i].notState);
		printf("</tr>");
    }
	printf("</tboby>\n");
	printf("</table>\n");
	return 0;
}
