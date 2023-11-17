#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

typedef struct statSite{
	char IP[50];
	char time[50];
	char Url[100];
}statSite;

 
int countSite(char * result){
	
	FILE * fic =NULL; 
	fic = popen("sudo cat /var/log/apache2/access.log","r");
	
	if (fic == NULL)
	{
		printf("<p>Erreur lors de l 'ouverture du fichier </p>");
		exit(EXIT_FAILURE);
	}
	char line[1000] = "";
	int count = 0;
	
	while(fgets(line,1000,fic)!=NULL){
		char url[100];
		char tmp[100];
		sscanf(line, "%*15s - - [%*49[^]]] \"%*s %199[^\"]\"",url);
		sscanf(url,"%[^?]",tmp);
		if (strstr(tmp,result))
		{
			count++;
		}
		
	}
	
	pclose(fic);
	return count;
	
}


statSite * pushsite(int a , char * result){
	statSite *statSites =(statSite *) malloc(a*sizeof(statSite));
	
	FILE * fic =NULL; 
	fic = popen("sudo cat /var/log/apache2/access.log","r");
	
	if (fic == NULL)
	{
		printf("<p>Erreur lors de l 'ouverture du fichier </p>");
		exit(EXIT_FAILURE);
	}
	char line[1000] = "";
	int count = 0;
	
	while(fgets(line,1000,fic)!=NULL){
		char url[100];
		sscanf(line, "%*15s - - [%*49[^]]] \"%*s %199[^\"]\"", url);
		
		if (strstr(url,result))
		{
			sscanf(line, "%15s - - [%49[^]]] \"%*s %199[^\"]\"", statSites[count].IP, statSites[count].time, url);
			sscanf(url,"%[^?]",statSites[count].Url);
			count++;
		}
		
	}
	
	
	return statSites;
}



void head(){
	printf("Content-type: text/html\n\n");
	//printf("type='texte/css'");
	printf("<head><meta charset=\"UTF-8\"><title>Journal access</title>"
			"<style>\n"
			"*{"
			"margin: 0;"
			"padding: 0;"
			"box-sizing: border-box;"
			"font-family: sans-serif;"
			"}"
			".head {"
				"display: flex;"
				"color: #fff;"
				"justify-content: space-between;"
				"background-color: #735F32;"
				"width: 100%%;"
				"padding: 10px;" /* Ajoutez un peu d'espacement si nécessaire */
				"box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);" /* Ajoutez une ombre si vous le souhaitez */
				"position: fixed;"
				"top: 0;"
			"}"

			".head a{"
			"	color: #fff;"
			"}"
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
			".footer{"
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
	printf("<div class='head'>"
        "<a href='http://www.acceuil.com'?azertyuiop><p>Acceuil</p></a>"
        "<a href='http://www.deconnex.mit'><p>Log Out</p></a>"
		"</div>");
	printf("<div>"
			"<h1>The goal of this program is to help you to find a site</h1>"
			//"<a href='http://www.cgi.com/cgi-bin/deconnex.cgi'><input type='button' value='se deconnecter' class='dec'></a>"
			"<form action=""http://www.cgi.com/cgi-bin/StatSite.cgi"" method=""get"">"
			"<label>Enter the name of the site</label>"
			"<input type=""text"" name=""site"">"
			"<input type=""submit"" value=""Find"">"
			"</form>"
			"</div>");
}


void footer(int c,char * result,int page){
	printf(
		"<div class='footer'>"
			"<ul>");
	int a=c/10;
	if(c%10!=0){
		a++;
	}

	if(page <=5){
		
		for (int i = 1; i <= 10; i++)
		{
			if(i==page){
				printf("<li><a href=""StatSite.cgi?name=%s&value=%d""><input type='button' value='%d' class='click'></a></li>",result,i,i);
				continue;
			}
			if(i>a)
				break;
				
			printf("<li><a href=""StatSite.cgi?name=%s&value=%d""><input type='button' value='%d' ></a></li>",result,i,i);
		}		
	}
	
	else{
		for (int i = page - 4; i < page+6; i++)
		{
			if(i==page){
				printf("<li><a href=""StatSite.cgi?name=%s&value=%d""><input type='button' value='%d' class='click'></a></li>",result,i,i);
				continue;
			}
			if(i>a)
				break;
				
			printf("<li><a href=""StatSite.cgi?name=%s&value=%d""><input type='button' value='%d' ></a></li>",result,i,i);
			
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
			printf("<td>IP</td>\n"
					"<td>Date</td>\n"
					"<td>Site</td>\n"
					);
	printf("</tr>\n");
		
}

void site(char *val1 , char *val2){
	if(*val1!=0){
		int c = countSite(val1);
		int page=1;	
		page=atoi(val2);
		printf("<h1>%d</h1>",c);
			if(page==0)
				page=1;
				
			if(c==0){
				printf("<p>The site that you entered does not exist</p>");
			}
			else{
			
				printf("<p>You are at the page of  %d  for the site ""%s""</p>",page,val1);
				table();
				statSite * siteInfo =(statSite*)malloc(c*sizeof(statSite));
				siteInfo = pushsite(c,val1);
			
				for(int i=(page-1)*10;i<10*page;i++)
				{
					if(i==c) break;
					printf("<tr bgcolor=""#FDF0F0"">\n"
						   "<td>%s</td>\n"
							"<td>%s</td>\n"
							"<td>%s</td>\n"
							"</tr>\n"
					,siteInfo[i].IP, siteInfo[i].time,siteInfo[i].Url);
					
				}
				
				printf("</table>\n");
				footer(c,val1,page);
			}
		
			printf("</body>");
	}
}

int trueUser(char * login,char * passwd){

	FILE * fic=fopen("/home/mit/CGI/connected.txt","r");
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

int main(){
	//declaration
	char *get = (char *)malloc(40);
	get = getenv("QUERY_STRING");
	char val1[20];
	char * val2=(char *)malloc(20);;
	
	//prendre les variables login et passwd
	sscanf(get,"%*[^=]=%[^&]",val1);
	sscanf(get,"%*[^&]&%*[^=]=%s",val2);
	
	if(*get==0 || (trueUser(val1,val2)==0 && strlen(val2)>=5)) {
		printf("Location:http://www.acceuil.com\n\n");
	}
	else{

		head();
		entrer();
		site(val1,val2);
	
	}
	return 0;
}

