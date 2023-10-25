#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float n){
	return n+1;
}

float surface(float a,float b){
	float n=10;
	float t = (float) (a+b)/n;
	float sm=0;
	
	for(float i=a; i<b ; i+=t){
		sm+=(float)f(i)*t;
	}
	return sm;
}

void head(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Surface d'un courbe</title>");
	printf("<html>");
	printf("<form action='http://www.cgi.com/cgi-bin/Rectangle.cgi' method='get'>");
	printf("<h3>Fonction : f(x) = x + 1</h3>");
	printf("<p>Entrer l'intervalle : </p>");
	printf("<p> a : <input type='number' name='a'> b :  <input type='number'name='b'></p><br><br>");
	printf("<input type='submit' value='resoudre'>");
	printf("</form>");
	printf("<body>");
}

int main(){
	float a = 1.0 , b=0.0;
	
	head();
	char * get = malloc(10);
	get = getenv("QUERY_STRING");
	sscanf(get,"%*[^=]=%f",&a);
	sscanf(get,"%*[^&]&%*[^=]=%f",&b);
	
	float s = surface(a,b);
	printf("<p>surface = %f</p>",s);
	return 0;
}

