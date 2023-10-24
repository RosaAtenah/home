#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>

 
int countUser(char * result){
	int a=0;
	FILE * fic =fopen("/var/log/auth.log","r");
	
	if(fic==NULL){
		printf("erreur d'allocation\n");
		return 1;
	}
	char * tmp = (char *)malloc(500);
	while(fgets(tmp,500,fic)!=NULL){
			if( (strstr(tmp,"session opened"))|| (strstr(tmp,"session closed") )){
				char date[20];
				strncpy(date,tmp,15);
				char session[50];
				char user[10];
				char action[10];
				sscanf(tmp,"%*s %*s %*s %*s %*s %*s %[^\n]",session);
				sscanf(session,"%*[^ ] %s %*[^ ] %*[^ ] %[^(] %*[^ ]",action,user);
				if(strcmp(user,result)==0){
					a++;
				}
				
			}
			
		}
		
	
	fclose(fic);
	return a;
	
}

char * androGasy(char *jour){
	char * andro = (char *)malloc(20);
	char * tmp = (char *)malloc(25);
	char mois[5];
	char jrs[5];
	sscanf(jour,"%s %*s",mois);
	sscanf(jour,"%*s %s",jrs);
	
	int m = volana(mois);
	int j=atoi(jrs);
	
	int jr=0;
		
	for(int i=1; i<m;i++){
			if(i!=2 && i<8 && i%2!=0)
				jr+=31;
			else if(i==2)
				jr+=28;
			else if(i!=2 && i<8 && i%2==0)
				jr+=30;
			else if(i!=2 && i>=8 && i%2==0)
				jr+=31;
			else if(i!=2 && i>=8 && i%2!=0)
				jr+=30;	
	}
		
	jr+=j;
	jr=jr%7;
	switch(jr){
			case (1):strcpy(andro,"alahady");break;
			case (2):andro="alatsinainy";break;
			case (3):andro="talata";break;
			case (4):andro="alarobia";break;
			case (5):andro="alakamisy";break;
			case (6):andro="zoma";break;
			case (0):andro="sabotsy";break;
	}
	
	sprintf(tmp,"%s %d %s",andro,j,mois);
	return tmp;
}

info* pushUser(int a , char * result){
	info * userInfo=(info*)malloc(a*sizeof(info));
	
	FILE * fic =fopen("/var/log/auth.log.1","r");
	
		if(fic==NULL){
			printf("erreur d'allocation\n");
			exit(1);
		}
		char * tmp = (char *)malloc(500);
					int c=0;
					

		while(fgets(tmp,500,fic)!=NULL){
			if( (strstr(tmp,"session opened"))|| (strstr(tmp,"session closed") )){
				char * date = (char *)malloc(50);
				strncpy(date,tmp,15);
				char temp[20];
				sscanf(date,"%*s %*s %s",temp);
				char jour[10];
				strncpy(jour,date,6);
				
				date = androGasy(jour);
				
				char session[50];
				char user[10];
				char action[10];
				sscanf(tmp,"%*s %*s %*s %*s %*s %*s %[^\n]",session);
				sscanf(session,"%*[^ ] %s %*[^ ] %*[^ ] %[^(] %*[^ ]",action,user);
				
				if(strcmp(user,result)==0){
					strcpy(userInfo[c].times,date);
					strcpy(userInfo[c].heures,temp);
					strcpy(userInfo[c].acts,action);
					strcpy(userInfo[c].users,user);
					c++;
				}
				

				
			}
			
		}
		
		
	return userInfo;
	
}


int volana(char * mois){
	
	if(strcmp(mois,"Jan")==0)
		return 1;
	else if(strcmp(mois,"Feb")==0)
		return 2;
	else if(strcmp(mois,"Mar")==0)
		return 3;
	else if(strcmp(mois,"Apr")==0)
		return 4;
	else if(strcmp(mois,"May")==0)
		return 5;
	else if(strcmp(mois,"Jon")==0)
		return 6;
	else if(strcmp(mois,"Jol")==0)
		return 7;
	else if(strcmp(mois,"Aog")==0)
		return 8;
	else if(strcmp(mois,"Sep")==0)
		return 9;
	else if(strcmp(mois,"Okt")==0)
		return 10;
	else if(strcmp(mois,"Nov")==0)
		return 11;
	else if(strcmp(mois,"Des")==0)
		return 12;

	return 0;
}

//rgba(136, 136, 206, 0.7);"
void head(){
	printf("Content-type: text/html\n\n");
	//printf("type='texte/css'");
	printf("<head><meta charset=\"UTF-8\"><title>Authentification des utilisateurs</title>"
			"<style>\n"
			"body{"
				"background-color:#132043;"    
				"justify-content:center;"
				"text-align:center;"
			"}"
			"table{"
				"border-collapse : collapse;"
				//"width: 00px;"
				"empty-cells:hide;"
				"margin:auto;"
			"}"
			"tr,td{"
				"border:2px solid black;"
				"padding : 15px;"
			"}"
			"input{"
				"border-radius: 1vw;"
				"height: 2.5vw;"
				"margin:1vw"
			"}"
			"ul{"
				"display: flex;"
				
			"}"
			"li{"
				"text-align: center;"
				"display: flex;"
				"justify-content: center;"
				"align-items: center;"
				"margin: 2vw;"
			"}"
			"p,h1,label{"
				"color:white;"
			"}"
			"div{"
				"justify-content: center;"
				"background-color:#FDF0F0;"
				//"overflow-x: scroll;"
				"margin : 2vw;"
				"padding-right:5vw;"
				//"opacity:0.5;"
				
			"}"
			"a{"
				"border-radius: 1vw;"
				"margin-right:auto;"
				
			"}"
			"h1{"
				"display: inline;"
			"}"
			".dec{"
				"margin-left: 15vw;"
			"}"
			"input[button]{"
				"border-radius:2vw;"
			"}"
			".click{"
				"background-color:#1F4172;"
				"color:white;"
			"}"
			"</style>\n"
			"</head>\n");
	printf("<html><body>");
	
}

void entrer(){
	printf("<h1>The goal of this program is to help you to find a user</h1>"
			"<a href='http://www.cgi.com/cgi-bin/deconnex.cgi'><input type='button' value='se deconnecter' class='dec'></a>"
			"<form action=""http://www.cgi.com/cgi-bin/sign.cgi"" method=""get"">"
			"<label>Enter the name of the user that you like to find</label>"
			"<input type=""text"" name=""user"">"
			"<input type=""submit"" value=""Find"">"
			"</form>");
}

void putLog(char * login,char * passwd){
	FILE * fic=fopen("/home/mit/CGI en C/a.txt","a+");
	if(fic == NULL) {
		printf("<h1>Erreur d'allocation</h1>");
		exit(1);
	}
	fprintf(fic,"%s %s\n",login,passwd);
	fclose(fic);
}

void footer(int c,char * result,int page){
	printf(
		"<div>"
			"<ul>");
	int a=c/10;
	if(c%10!=0){
		a++;
	}

	if(page <=5){
		
		for (int i = 1; i <= 10; i++)
		{
			if(i==page){
				printf("<li><a href=""sign.cgi?name=%s&value=%d""><input type='button' value='%d' class='click'></a></li>",result,i,i);
				continue;
			}
			if(i>a)
				break;
				
			printf("<li><a href=""sign.cgi?name=%s&value=%d""><input type='button' value='%d' ></a></li>",result,i,i);
		}		
	}
	
	else{
		for (int i = page - 4; i < page+6; i++)
		{
			if(i==page){
				printf("<li><a href=""sign.cgi?name=%s&value=%d""><input type='button' value='%d' class='click'></a></li>",result,i,i);
				continue;
			}
			if(i>a)
				break;
				
			printf("<li><a href=""sign.cgi?name=%s&value=%d""><input type='button' value='%d' ></a></li>",result,i,i);
			
		}
	}
	
	printf(
			"</ul>"
		"</div>"
	);
}

void table(){
	printf("<h1>Information about the session opened or closed in this computer</h1><br>\n"); 

	printf("<table>\n");
	printf("<tr bgcolor=""#1F4172"">");
			printf("<td>Date</td>\n"
					"<td>Heures</td>\n"
						"<td>Action</td>\n"
						"<td>User</td>\n");
	printf("</tr>\n");
		
}

void user(char *val1 , char *val2){
		int c = countUser(val1);
			int page=1;
			page=atoi(val2);
		
			if(page==0)
				page=1;
				
			if(c==0){
				printf("<p>The user that you entered does not exist</p>");
			}
			else{
			
				printf("<p>You are at the page of  %d  for the user ""%s""</p>",page,val1);
				table();
				info * userInfo =(info*)malloc(c*sizeof(info));
				userInfo = pushUser(c,val1);
			
				for(int i=(page-1)*10;i<10*page;i++)
				{
					if(i==c) break;
					if(strcmp(userInfo[i].acts,"opened")==0){
						printf("<tr bgcolor=""#FDF0F0"">\n"
								"<td>%s</td>\n"
								"<td>%s</td>\n"
								"<td>%s</td>\n"
								"<td><a href=""Find.cgi?name=%s&page=%d"">%s</a></td>\n"
								,userInfo[i].times,userInfo[i].heures,userInfo[i].acts,userInfo[i].users,page,userInfo[i].users);
					}
					else{
						printf("<tr bgcolor=""#F1B4BB"">\n"
								"<td>%s</td>\n"
								"<td>%s</td>\n"
								"<td>%s</td>\n"
								"<td><a href=""Find.cgi?name=%s&page=%d"">%s</a></td>\n"
								,userInfo[i].times,userInfo[i].heures,userInfo[i].acts,userInfo[i].users,page,userInfo[i].users);
					}
				}
				printf("</table>\n");
				footer(c,val1,page);	
			}
		
			printf("</body>");
}

int trueUser(char * login,char * passwd){
	
	FILE * fic=fopen("/home/mit/CGI en C/connected.txt","r");
	if(fic == NULL) {
		printf("<h1>Erreur d'allocation</h1>");
		exit(1);
	}
	
	char * tmp = (char*)malloc(50);
	while(fgets(tmp,50,fic)){
		char a[25];
		char b[25];
		sscanf(tmp,"%s %s",a,b);
		if(strcmp(a,login)==0 && strcmp(b,passwd)==0){
			return 1;
			break;
		}
	}
	
	return 0;
}
