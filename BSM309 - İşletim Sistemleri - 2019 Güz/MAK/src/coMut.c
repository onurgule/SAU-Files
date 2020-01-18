#include "coMut.h"


void baslat(){
printf("\033[2J");
printf("\n\t\t*************");
printf("\n\t\t****coMut****");
printf("\n\t\t****GRUP6****");
printf("\n\t\t*************\n\n");
}

char *chEkkomut[]={
	"cd",
	"quit"
};

int (*fonkEkkomut[])(char**) = {
	&coMut_cd,
	&coMut_quit
};

int ekKomutsayisi()
{
	return sizeof(chEkkomut)/sizeof(char *);
}

int coMut_cd(char **args)
{
	if (args[1]==NULL)
	{
		fprintf(stderr,"coMut: beklenen \"cd\"\n");
	}
	else
	{
		if (chdir(args[1])!=0)
		{
			perror("coMut");
		}
	}
	return 1;
}


int coMut_quit(char **args)
{
	int status;
	while (!waitpid(-1,&status,WNOHANG)){}
	exit(0);
}

#define USTDEGER 256
int yurutucu(char * args[])
{
	int i=0;
	int j=0;
	int p=0;
	int n=0;
	int pd = 0;
	int parantezindex=0;
	int dosya;
	char *args_aux[USTDEGER];
	int aindex=0;
	int k;
	int background = 0;
	char *komutlar[USTDEGER];
	int altKabuk = 0;
	char *parantezici[USTDEGER];
	int parantez=0;
	char *pipetler[15][USTDEGER];
	int pipet = 0;
	int status;
	
	while(args[j] != NULL)
	{
		if((strcmp(args[j],"(") == 0))
		{
			parantez = 1;
		}
		else if((strcmp(args[j],")") == 0))
		{
			parantez=0;
			parantezindex=0;
			yurutucu(parantezici);
		}
		else if(parantez==1)
		{
			parantezici[parantezindex]=args[j];
			parantezindex++;
		}
		else if((strcmp(args[j],">") == 0)){
			args_aux[j]=NULL;
			DosyaCikis(args_aux,args[j+1]);
			aindex=0;
			j++;
			continue;
		}
		else if(strcmp(args[j],"<") == 0){
			args_aux[j]=NULL;
			DosyaGiris(args_aux,args[j+1]);
			aindex=0;
			j++;
			continue;
		}
		else if((strcmp(args[j],"&") == 0))
		{
			break;
		}
		else if((strcmp(args[j],";") == 0)){
			altKabuk = 1;
			char *argyeni[j*sizeof(char*)];
			for (int o = n; o < j; o++)
			{
				argyeni[o-n] = args[o];
				if(o==j-1) {
					yurutucu(argyeni);
				}				
			}
			n=j+1;
		}
		else if((strcmp(args[j],"|") == 0)){
			pipet = 1;
			for (int o = p; o < j; o++)
			{
					pipetler[pd][o-p] = args[o];
			}
			p=j+1;
			pd++;
			
		}
		args_aux[aindex] = args[j];
		j++;
		aindex++;
	}
	
	if(altKabuk == 1 ){
		yurutucu((&args[n]));
		return 1;
	} 
	if(pipet == 1){
		for (int o = p;; o++)
			{
				if(args[o] == NULL) break;
				pipetler[pd][o-p] = args[o];	
				//printf("\nuu:[%d][%d] = %s",pd,(o-p),args[o]);
			}
		pd++;
		int pid, status;
		int fd[pd];
		pipe(fd);
		switch (pid = fork()) {
		case 0: /* child */
			borudose(fd,pipetler,pd);
		default: /* parent */
			while ((pid = wait(&status)) != -1)
				fprintf(stderr, " %d prosesi %d dondurdu.\n", pid, WEXITSTATUS(status));
			break;

		case -1:
			perror("fork");
		}
		return 1;
	}
	args_aux[j]=NULL;

	int m;
	if (args[0] == NULL)
	{
		return 1;
	}
	for (m = 0 ; m < ekKomutsayisi() ; m++)
	{
		if (strcmp(args[0],chEkkomut[m])==0)
		{
			(*fonkEkkomut[m])(args);
			return 1;
		}
	}	
	while (args[i] != NULL && background == 0)
	{
		if (strcmp(args[i],"&") == 0)
		{
			background = 1;
		}
		i++;
	}
	coMutcalistir(args_aux,background);
	return 1;
}
void borudose(int pfd[], char *pipetler[][256], int kacli)
{
	int pid;
	
	switch (pid = fork()) {
		//Burada cogullama yapilabilir
	case 0: /* child */
		for (int i = kacli-1; i > 0; i--)
		{
			dup2(pfd[i-1], i-1);
			execvp(pipetler[i][0], pipetler[i]);
		}
	default: /* parent */
		dup2(pfd[kacli-1], kacli-1);
		execvp(pipetler[0][0], pipetler[0]);
	case -1:
		perror("fork");
	}
}
//Dosya Giris Islemleri
void DosyaGiris(char *args[],char* inputFile)
{
	pid_t pid;
	if (!(access (inputFile,F_OK) != -1))
	{	
		printf("coMut: %s adinda bir dosya bulunamadi\n",inputFile);
		return;
	}
	int err=-1;
	int dosya;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		dosya=open(inputFile, O_RDONLY, 0600);
		dup2(dosya,STDIN_FILENO);
		close(dosya);

		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}
//Dosya cikis islemleri burada yapılıyor. Gerekli errorler yazıldı.
void DosyaCikis(char *args[],char* outputFile)
{
	pid_t pid;
	int err=-1;
	int dosya;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		dosya=open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		dup2(dosya,STDOUT_FILENO);
		close(dosya);

		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}


int coMutcalistirbg(char **args)
{
	pid_t pid;
	int status;

	struct sigaction act;
	act.sa_handler = cocukfonk;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NOCLDSTOP;
	if (sigaction(SIGCHLD,&act,NULL)<0)
	{
		fprintf(stderr,"Sigaction hatasi.\n");
		return 1;
	}

	pid=fork();
	if (pid == 0)
	{
		if (execvp(args[0],args) == -1)
		{
			printf("Komut bulunamadi.");
			kill(getpid(),SIGTERM);
		}
	}
	else if (pid < 0)
	{
		perror("coMut");
	}
	else
	{
		printf("Proses PID:%d Degeriyle Olusturuldu\n",pid);
	}
	return 1; 
}

int coMutcalistir(char **args,int background)
{
	if (background==0)
	{
		pid_t pid;
		int status;
		pid=fork();
		if (pid == 0)
		{
			if (execvp(args[0],args) == -1)
			{
				printf("Komut bulunamadi.");
				kill(getpid(),SIGTERM);
			}
		}
		else if (pid < 0)
		{
			perror("coMut");
		}
		else
		{
			waitpid(pid,NULL,0);
		}
	}
	else
	{
		coMutcalistirbg(args);
	}
	return 1; 
}

void cocukfonk(int signo) 
{
    int status, child_val,chid;
	chid = waitpid(-1, &status, WNOHANG);
	if (chid > 0)
	{
		if (WIFEXITED(status))
	    {
	        child_val = WEXITSTATUS(status);
	        printf("[%d] retval : %d \n",chid, child_val); 
	    }
	}
}
void prompt(){
printf("%s > ",getcwd(dosyaYeri, 1024));
fflush(stdout);
}
#define SATIR 1024
void shellbaslat(int argc, char **argv, char **envp){
	baslat();
	int waiting = 0;
	char line[SATIR];
	char *harfler[USTDEGER];
	int numharfler;
	gEnv=envp;
	while(!waiting)
	{
		prompt();
		memset(line, '\0',SATIR);
		fgets(line,SATIR,stdin);
		if((harfler[0] = strtok(line," \n\t")) == NULL) continue;
		numharfler = 1;
		while((harfler[numharfler] = strtok(NULL, " \n\t")) != NULL) numharfler++;
		yurutucu(harfler);
	}

}

