#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE * fic=fopen("/home/mit/CGI/connected.txt","w");
	fclose(fic);
	printf("Location:http://www.login.mit\n\n");
	return 0;
}
