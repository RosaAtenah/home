#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return (float)log(x)-1;
}

float find(float a, float b){
	float milieu = 0;
	double eps = 0.0001;
	
	if(f(a)*f(b)>0){
		printf("<p>Pas de solution </p>");
	}
	else if(a!=0 && b!=0){
		printf("<h3>Solution optimale : </h3>");
	
		while((fabs(a-b))>eps){
			milieu = (float)((a+b)/2);
			printf("<p>%f</p>",milieu);
			if((f(a)*f(milieu))<0){
				a=a;
				b=milieu;
			}
			else if((f(milieu)*f(b))<0){
				b=b;
				a=milieu;
			}
		}
	}
	return milieu;
}

void head(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Resolution f(x)=0</title>");
	printf("<html>");
	printf("<form action='http://www.cgi.com/cgi-bin/Dichotomie.cgi' method='get'>");
	printf("<h3>Fonction : f(x) = log(x)-1</h3>");
	printf("<p>Entrer l'intervalle : </p>");
	printf("<p> a : <input type='number' name='a'> b :  <input type='number'name='b'></p><br><br>");
	printf("<input type='submit' value='resoudre'>");
	printf("</form>");
	printf("<body>");
}

int main(){
	float a=0,b=0;
	head();
	char * get = malloc(10);
	get = getenv("QUERY_STRING");
	sscanf(get,"%*[^=]=%f",&a);
	sscanf(get,"%*[^&]&%*[^=]=%f",&b);
	float s=find(a,b);
	//printf("%f\n",s);
	return 0;
}


