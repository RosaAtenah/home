#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *login){
	int k=0;
	FILE * fic=fopen("/home/mit/CGI en C/sign.txt","r");
	if(fic == NULL) {
		exit(1);
	}
	char t[50];
	char l[50];
	while(fgets(t,50,fic)!=NULL){
		sscanf(t,"%s %*s",l);
		if(strcmp(l,login)==0) k=1;
			
	}
	fclose(fic);

	return k;
}

void putLog(char * login,char * passwd){
	
	if(find(login)){
		
		FILE * fic=fopen("/home/mit/CGI en C/connected.txt","a");
		if(fic == NULL) {
			//printf("<h1>Erreur d'allocation</h1>");
			exit(1);
		}
		fprintf(fic,"%s %s\n",login,passwd);
		fclose(fic);
		
		printf("Location:http://www.cgi.com/cgi-bin/sign.cgi?login=%s&passwd=%s\n\n",login,passwd);
		
		//~ printf("Content-type: text/html\n\n");
		//~ printf("<p>ici</ici>");
	}
	else{
		printf("Location:http://www.cgi.com/cgi-bin/login.cgi\n\n");
	}	
}


int main(){
	//declaration
	char *get = (char *)malloc(40);
	get = getenv("QUERY_STRING");
	char val1[20];
	char * val2=(char *)malloc(20);;
	
	//prendre les variables login et passwd
	sscanf(get,"%*[^=]=%[^&]",val1);
	sscanf(get,"%*[^&]&%*[^=]=%s",val2);
	
	
	
	putLog(val1,val2);
	
	return 0;
}
