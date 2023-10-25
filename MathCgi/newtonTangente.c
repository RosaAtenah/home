#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return (float)log(x)-1;
}

float derive(float x){
	return (float)1/x;
}

float find(float a){
	double eps = 0.000001;
	
	printf("<p>Solution Optimale</p>");
	while(fabs(f(a))>eps){
		a = (float)(-f(a)/derive(a))+a;
		printf("<p>%f\n</p>",a);
	}
	return a;
}

void head(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Resolution f(x)=0</title>");
	printf("<html>");
	printf("<form action='http://www.cgi.com/cgi-bin/Tangente.cgi' method='get'>");
	printf("<h3>Fonction : f(x) = log(x)-1</h3>");
	printf("<p>Entrer le point de depart : </p>");
	printf("<p> a : <input type='number' name='a'></p><br><br>");
	printf("<input type='submit' value='resoudre'>");
	printf("</form>");
	printf("<body>");
}

int main(){
	float a=1;
	char * get = malloc(10);
	get = getenv("QUERY_STRING");
	sscanf(get,"%*[^=]=%f",&a);
	head();
	
	printf("<p> a = %f </p>",a);
	
	float s=find(a);
	//printf("%f\n",s);
	return 0;
}
