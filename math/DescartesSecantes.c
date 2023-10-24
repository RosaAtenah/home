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
	
	double eps = 0.000001;
	float c;
	while(fabs(b - a) > eps){
		droite secnte = secante(a,b);
		c = (float) (-secnte.cst/secnte.coeff);
		
		if (f(c) == 0.0)
            return c;
        
            b = c;
	}
	return c;
}
int main(){
	float a=1,b=5;
	float s=find(a,b);
	printf("%f\n",s);
	return 0;
}

