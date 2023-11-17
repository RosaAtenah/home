#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Site {
    char name[100];
    char state[50];
} Site;

int main() {
    char c;
    int availableCount = 0, enabledCount = 0;

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
		}
		else{
			strcpy(sites[i].state,"desactivate");
		}
	}

    // Affichage des noms des sites disponibles
    for (int i = 0; i < availableCount; i++) {
        printf("Site %d : %s -> %s \n", i + 1, sites[i].name,sites[i].state);
    }

    

    return 0;
}
