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
	
	while(fabs(f(a))>eps){
		a = (float)(-f(a)/derive(a))+a;
	}
	return a;
}
int main(){
	float a=1;
	float s=find(a);
	printf("%f\n",s);
	return 0;
}
