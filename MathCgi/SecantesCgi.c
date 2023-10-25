#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float coeff;
	float cst;
}droite;

//la fonction
float f(float x){
	return (float)log(x)-1 ;
}

//definir le coefficient directeur et la constante a l'origine
droite secante(float a,float b){
	droite sec;
	sec.coeff = (float) ( f(b) - f(a) ) / ( b - a );
	sec.cst = (float) f(a) - sec.coeff * a;
	return sec;
}
float find(float a, float b){
	printf("<p> a = %f , b = %f </p>",a,b);
	double eps = 0.000001;
	float c;
	if(f(a)*f(b)>0){
		printf("<p>Pas de solution </p>");
	}
	else if(a!=0 && b!=0){
		printf("<h3>Solution optimale : </h3>");
		while(fabs(b - a) > eps){
			droite secnte = secante(a,b);
			c = (float) (-secnte.cst/secnte.coeff);
			printf("<p>%f\n</p>",c);
			if (f(c) == 0.0)
				return c;
        
            b = c;
		}
	}
	printf("</body>");
	printf("</html>");
	return c;
}

void head(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Resolution f(x)=0</title>");
	printf("<html>");
	printf("<form action='http://www.cgi.com/cgi-bin/SolSecantes.cgi' method='get'>");
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
	
	return 0;
}


