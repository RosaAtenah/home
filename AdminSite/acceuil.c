#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int trueUser(char * login,char * passwd){

	FILE * fic=fopen("/home/mit/CGI/connected.txt","r");
	if(fic == NULL) {
		printf("<h1>Erreur d'allocation</h1>");
		exit(1);
	}

	char * tmp = (char*)malloc(50);
	while(fgets(tmp,50,fic)){
		char a[25];
		char b[25];
		sscanf(tmp,"%s %s",a,b);
		if(strcmp(a,login)==0 && strcmp(b,passwd)==0){
			return 1;
			break;
		}
	}

	return 0;
}


void html(char *login,char *passwd){
	char *tmp = malloc(1000);
	FILE * fic = fopen("/var/www/html4/acceuil2.html" , "r");
		if (fic == NULL)
		{
			printf("<p>erreur lors de louverture du fichier<p>");
			exit(1);
			
		}
		
		//lire le fichier html
		while (fgets(tmp,sizeof(tmp),fic)!=NULL)
		{
			printf("%s",tmp);
		}
		
		fclose(fic);
		printf("<a href='http://www.putonline.com?login=%s&passwd=%s'>read More</a>",login,passwd);
		
		fic = fopen("/var/www/html4/acceuil3.html" , "r");
		if (fic == NULL)
		{
			printf("<p>erreur lors de louverture du fichier<p>");
			exit(1);
			
		}
		
		//lire le fichier html
		while (fgets(tmp,sizeof(tmp),fic)!=NULL)
		{
			printf("%s",tmp);
		}
		
		fclose(fic);
		printf("<a href='http://www.cgi.com/cgi-bin/listeSite.cgi?login=%s&passwd=%s'>read More</a>",login,passwd);
		
		fic = fopen("/var/www/html4/acceuil4.html" , "r");
		if (fic == NULL)
		{
			printf("<p>erreur lors de louverture du fichier<p>");
			exit(1);
			
		}
		
		//lire le fichier html
		while (fgets(tmp,sizeof(tmp),fic)!=NULL)
		{
			printf("%s",tmp);
		}
		
		fclose(fic);
		printf("<a href='http://www.cgi.com/cgi-bin/StatSite.cgi?login=%s&passwd=%s'>read More</a>",login,passwd);
		printf("            </div>"
				"</div>"
				"</div>"
				"</body>"
				"</html>");
		
		free(tmp);
		
}
int main(){
	
	char * get = malloc(500);
	char * login = malloc(100);
	char * passwd = malloc(100);
	
	
	get = getenv("QUERY_STRING");
	
	//prendre les variables login et passwd
	sscanf(get,"%*[^=]=%[^&]",login);
	sscanf(get,"%*[^&]&%*[^=]=%s",passwd);
	
	if(*get==0 || (trueUser(login,passwd)==0 && strlen(passwd)>=5)) {
		printf("Location:http://www.login.mit\n\n");
	}
	else{		
		printf("Content-type: text/html\n\n");
		html(login,passwd);
	}
	return 0;
}
