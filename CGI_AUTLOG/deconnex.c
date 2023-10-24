#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE * fic=fopen("/home/mit/CGI en C/connected.txt","w");
	fclose(fic);
	printf("Location:http://www.cgi.com/cgi-bin/login.cgi\n\n");
	return 0;
}
