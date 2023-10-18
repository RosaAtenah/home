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

int main(){
	float a = 0.0 , b=5.0;
	float s = surface(a,b);
	printf("surface = %f",s);
	return 0;
}
