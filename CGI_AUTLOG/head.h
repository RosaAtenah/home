#ifndef __HEAD__
	#define __HEAD__
	
	typedef  struct {
		char times[50];
		char heures[20];
		char acts[10];
		char users[10];
	}info;

	/*type booléen*/
	typedef enum{
		FALSE , //valeur 0
		TRUE	//valeur 1
	}Bool;

		void head();
		void entrer();
		int countUser(char * result);
		int volana(char * mois);
		char * androGasy(char *jour);
		info* pushUser(int a , char * result);
		void putLog(char * login,char * passwd);
		void footer(int c,char * result,int page);
		void table();
		void user(char *val1 , char *val2);
		int trueUser(char * login,char * passwd);
#endif
