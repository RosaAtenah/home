#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return (float)log(x)-1;
}

float find(float a, float b){
	float milieu = 0;
	double eps = 0.0001;
	
	while((fabs(a-b))>eps){
		milieu = (float)((a+b)/2);
		//printf("%f\n",milieu);
		if((f(a)*f(milieu))<0){
			a=a;
			b=milieu;
		}
		else if((f(milieu)*f(b))<0){
			b=b;
			a=milieu;
		}
	}
	return milieu;
}
int main(){
	float a=1,b=10;
	float s=find(a,b);
	printf("%f\n",s);
	return 0;
}
