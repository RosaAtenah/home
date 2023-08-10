#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum{
	FALSE ,
	TRUE
}Bool;

typedef struct StackElement{
	char operation;
	struct StackElement *next;
}*StackElement;

StackElement new_stack(void){
	return NULL;
}

Bool is_empty_stack(StackElement st){
	if(st == NULL)
		return TRUE;
		
	return FALSE;
}

StackElement push_stack(StackElement st,char op){
	StackElement tmp;
	tmp = malloc(sizeof(tmp));
	tmp->operation = op;
	tmp->next = st;
	
	return tmp;
	
}

void print_stack(StackElement st){
	while (!is_empty_stack(st))
	{
		printf("[%c]\n",st->operation);
		st = st->next;
	}
}

StackElement pop_stack(StackElement st){
	StackElement tmp;
	
	if(is_empty_stack(st))
		return new_stack();
		
	tmp = st->next;
	free(st);
	
	return tmp;
}


char peek_stack(StackElement st){
	return st->operation;
}
int calcul(int a , char op , int b){
	if(op=='+')
		return a+b;
	else if(op=='-')
		return a-b;
	else if(op=='*')
		return a*b;
	else if(op=='/')
		return a/b;
	return 1;
}
int main(){
	
	StackElement pile = new_stack();
	
	int * tab;
	tab = (int *)malloc(4*sizeof(int));
	
	char eq[20]="42 2 * 6 + 5 /";
	int count=0;
	if (isdigit(eq[0])!=0)
	{
		tab[count]=atoi(&eq[0]);
		count++;
	}
	for (int i = 1; i < strlen(eq) ; i++)
	{
		if (isdigit(eq[i])!=0 && isdigit(eq[i-1])==0)
		{
				tab[count]=atoi(&eq[i]);
				count++;
		}
	}
	
	for (int i = strlen(eq)-1; i >=0; i--)
	{
		if (isdigit(eq[i])==0 && eq[i]!=' ')
		{
			pile=push_stack(pile,eq[i]);
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d\n",tab[i]);
	}
	int a=0,b=0;
	count=1;
	a=tab[0];
	while (!is_empty_stack(pile))
	{
		a=a;
		b=tab[count];
		a=calcul(a,peek_stack(pile),b);
		pile = pop_stack(pile);
		count++;
	}
	printf("ici: %d",a);
	//print_stack(pile);
	return 0;
}
