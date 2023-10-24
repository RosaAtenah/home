#include <stdio.h>
#include <stdlib.h>

void putLog(char * login,char * passwd){
	FILE * fic=fopen("/home/mit/CGI en C/sign.txt","a+");
	if(fic == NULL) {
		printf("<h1>Erreur d'allocation</h1>");
		exit(1);
	}
	fprintf(fic,"%s %s\n",login,passwd);
	fclose(fic);
}

void form(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>Log In</title>"
			"<style>\n"
			"body{"
				"justify-content: center;"
				"text-align: center;"
				"background-color: #E3CCAE;"
			"}"
			"label,h3{"
				"display: block;"
				"padding: 1.5vw;"
			"}"
			"input{"
				"display: block;"
				"margin: auto;"
				"width: 30vw;"
				"height: 2vw;"
				"border-radius: 10px;"
				"padding:1vw;"
			"}"
			"a{"
				"background-color:#B8621B;"
				"padding: 1vw;"
				"margin: 3vw;"
				"border-radius: 2vw;"
				"color:white;"
			"}"
			"div{"
				"background-color: #262A56;"
				"width: 50vw;"
				"height: 30vw;"
				"margin: auto;"
				"margin-top: 10vw;"
				"justify-content: center;"
				"text-align: center;"
				"border-radius: 2vw;"
				"box-shadow:10px 10px black ;"
				"padding-bottom:3vw;"
			"}"
			"label,h3{"
				"color:white;"
			"}"
			".submit{"
				"margin-top: 3vw;"
				"width:10vw;"
				"padding-bottom: 2vw;"
				"margin-bottom: 2vw;"
			"}"
        
			"</style>"
			"</head>"
			"<body>"
			"<form action=""http://www.cgi.com/cgi-bin/connex.cgi"" method=""get"">"
			"<div>"
				"<h3>complete your information here to create a count</h3>"
				"<a href=""http://www.andrana.com/sign.html"">sign in</a>"
				"<a href=""http://www.cgi.com/cgi-bin/login.cgi"">log in</a>"
				"<label for="">Login</label>"
				"<input type=""text"" name=""login"" required>"
				"<label for="""">Password</label>"
				"<input type=""password"" name=""password"" id=""pwd"" pattern=""{5,}"" required>"
				"<input type=""submit"" value=""Send"" class=""submit"">"
				"<p><a href='http://www.andrana.com/passwd.html'>Click here if you forgot your password</a></p>"
			"</div>"
			"</form>"
			"</body>"
			"</html>"
			);	
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
	
	putLog(val1,val2);
	
	form();
	return 0;
}

