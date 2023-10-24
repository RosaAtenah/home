#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
#include <ctype.h>

int main(){
	//declaration
	char *get = (char *)malloc(40);
	get = getenv("QUERY_STRING");
	char val1[20];
	char * val2=(char *)malloc(20);;
	
	//prendre les variables login et passwd
	sscanf(get,"%*[^=]=%[^&]",val1);
	sscanf(get,"%*[^&]&%*[^=]=%s",val2);
	
	//~ const char *login = val1;
	//~ const char *passwd=val2;
	
	
	int a=strlen(val2);
	if(*get==0 || (trueUser(val1,val2)==0 && a>=5) ){
		printf("Location:http://www.cgi.com/cgi-bin/login.cgi\n\n");
	}
	else{
		head();
		entrer();
		//printf("<h3>%s---%s</h3>",login,passwd);
		//~ if(!isdigit(val2[0])&& *val2!=0){
			//~ putLog(val1,val2);
		//~ }

		//~ if(*val2==0){
			//~ entrer();
		//~ }
		//~ else{
			user(val1,val2);
	//	}
	
	}
	
	return 0;
}
