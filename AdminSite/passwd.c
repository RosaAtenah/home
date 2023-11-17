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
		FILE * fic=fopen("/home/mit/CGI en C/sign.txt","r");
		if(fic == NULL) {
			//printf("<h1>Erreur d'allocation</h1>");
			exit(1);
		}
		char ch;
		char t[50];
		int c=0, k=0;
		while((ch = fgetc(fic))!=EOF){
			if(ch=='\n')
				c++;
		}
		
		char tab[c][50];
	
		fclose(fic);
		fic=fopen("/home/mit/CGI en C/sign.txt","r");
		while(fgets(t,50,fic)!=NULL){
			char l[50];
			sscanf(t,"%s %*s",l);
			if(strcmp(l,login)!=0){
				strcpy(tab[k],t);
				k++;
			}
			
			
		}
		fclose(fic);
		
		fic=fopen("/home/mit/CGI en C/sign.txt","w");
		if(fic == NULL) {
			
			exit(1);
		}
		int i=0;
		while(i<k){
			fprintf(fic,"%s",tab[i]);
			
			i++;
		}
		fprintf(fic,"%s %s",login,passwd);
		fclose(fic);
		printf("Location:http://www.cgi.com/cgi-bin/sign.cgi\n\n");
	}
	else{
		printf("Location:http://www.andrana.com/passwd.html\n\n");
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
