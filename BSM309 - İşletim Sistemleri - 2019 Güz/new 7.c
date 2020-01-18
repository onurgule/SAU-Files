#include "coMut.h"


void welcome(){
printf("\n\t\t*************");
printf("\n\t\t****coMut****");
printf("\n\t\t****GRUP6****");
printf("\n\t\t*************\n\n");
}

char *builtin_str[]={
	"cd",
	"help",
	"quit"
};

int (*builtin_func[])(char**) = {
	&coMut_cd,
	&coMut_help,
	&coMut_quit
};

int coMut_num_builtins()
{
	return sizeof(builtin_str)/sizeof(char *);
}

int coMut_cd(char **args)
{
	if (args[1]==NULL)
	{
		fprintf(stderr,"coMut: expected argument to \"cd\"\n");
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

int coMut_help(char **args)
{
	int i;
	printf("Isletım Sistemleri Odevi\n");
	for (i=0;i<coMut_num_builtins();i++)
	{
		printf("  %s\n",builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return 1;
}

int coMut_quit(char **args)
{
	int status;
	while (!waitpid(-1,&status,WNOHANG)){}
	exit(0);
}

#define AUXMAX 256
int commandHandler(char * args[])
{
	int i=0;
	int j=0;
	int p=0;
	int n=0;
	int altKabuk = 0;
	int fileDescriptor;
	int aux;
	char *args_aux[AUXMAX];
	int k;
	int background = 0;
	char *komutlar[AUXMAX];
	char *pipetler[AUXMAX];
	int pipet = 0;
	int status;
	
	while(args[j] != NULL)
	{
		if ((strcmp(args[j],">") == 0) || (strcmp(args[j],"<") == 0) || (strcmp(args[j],"&") == 0) || (strcmp(args[j],"|") == 0) || (strcmp(args[j],";") == 0))
		{
			break;
		}
		args_aux[j] = args[j];
		j++;
	}
	args_aux[j]=NULL;

	int m;
	if (args[0] == NULL)
	{
		return 1;
	}
	for (m = 0 ; m < coMut_num_builtins() ; m++)
	{
		if (strcmp(args[0],builtin_str[m])==0)
		{
			(*builtin_func[m])(args);
			return 1;
		}
	}
	while (args[i] != NULL && background == 0)
	{
		if (strcmp(args[i],"&") == 0)
		{
			background = 1;
		}
		else if (strcmp(args[i],"<") == 0)
		{
			if (args[i+1] == NULL )
			{
				printf ("Yeterli Arguman Yok\n");
			}
			inputRD(args_aux,args[i+1]);
			return 1;
		}
		else if (strcmp(args[i],">") == 0)
		{
			if (args[i+1] == NULL )
			{
				printf ("Yeterli Arguman Yok\n");
			}
			outputRD(args_aux,args[i+1]);
			return 1;
		}
		else if (strcmp(args[i],";") == 0 || altKabuk == 1)
		{
			if(altKabuk == 1){
				i++;
				komutlar[n] = args[i];
				n++;
				continue;
			}
			altKabuk = 1;
			if (args[i+1] == NULL )
			{
				altKabuk = 0;
				printf ("Yeterli Arguman Yok\n");
			}
			if(komutlar[0] == NULL){
				strcpy(komutlar,args_aux);
				n=i;
			}
			komutlar[n] = args[i+1];
			
			//return 1;
		}
		else if (strcmp(args[i],"|") == 0 || pipet == 1)
		{
			if(pipet ==1){
				i++;
				//pipet = 0;
				pipetler[p] = args[i];
				p++;
				continue;
			}
			pipet = 1;
			if (args[i+1] == NULL)
			{
				pipet = 0;
				printf ("Yeterli Arguman Yok\n");
				continue;
			}
			pipetler[p] = args[i+1];
			p++;
			//boruyuDose(args_aux);
			
			//return 1;
		}
		i++;
		
	}
	if(pipetler[0] != NULL) {execpipes(args_aux,pipetler); return 1; }
	if(komutlar[0] != NULL) {komutlariCalistir(komutlar); return 1;}
	args_aux[i]==NULL;
	coMut_launch(args_aux,background);

	return 1;
}
void komutlariCalistir(char *komutlar[]){
	
}
void execpipes(char *args1[], char *args2[]){

		//execpipe(args1[0]+" "+args1[1],args2[0]+" "+args2[1]);
	
}
int execpipe (char ** argv1, char ** argv2) {
    int fds[2];
    pipe(fds);
    int i;
    pid_t pid = fork();
    if (pid == -1) { //error
        printf("error fork!!\n");
        return 1;
    } 
    if (pid == 0) { // child process
        close(fds[1]);
        dup2(fds[0], 0);
        //close(fds[0]);
        execvp(argv2[0], argv2); // run command AFTER pipe character in userinput
        printf("unknown command\n");
        return 0;
    } else { // parent process
        close(fds[0]);
        dup2(fds[1], 1);
        //close(fds[1]);
        execvp(argv1[0], argv1); // run command BEFORE pipe character in userinput
        printf("unknown command\n");
        return 0;
    }
}
void inputRD(char *args[],char* inputFile)
{
	pid_t pid;
	if (!(access (inputFile,F_OK) != -1))
	{	
		printf("coMut: %s adinda bir dosya bulunamadi\n",inputFile);
		return;
	}
	int err=-1;
	int fileDescriptor;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		fileDescriptor=open(inputFile, O_RDONLY, 0600);
		dup2(fileDescriptor,STDIN_FILENO);
		close(fileDescriptor);

		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}

void outputRD(char *args[],char* outputFile)
{
	pid_t pid;
	int err=-1;
	int fileDescriptor;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		fileDescriptor=open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		dup2(fileDescriptor,STDOUT_FILENO);
		close(fileDescriptor);

		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}


int coMut_launchbg(char **args)
{
	pid_t pid;
	int status;

	struct sigaction act;
	act.sa_handler = sig_chld;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NOCLDSTOP;
	if (sigaction(SIGCHLD,&act,NULL)<0)
	{
		fprintf(stderr,"sigaction failed\n");
		return 1;
	}

	pid=fork();
	if (pid == 0)
	{
		if (execvp(args[0],args) == -1)
		{
			printf("Command not found");
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

int coMut_launch(char **args,int background)
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
				printf("Command not found");
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
		coMut_launchbg(args);
	}
	return 1; 
}

void sig_chld(int signo) 
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
void startShell(int argc, char **argv, char **envp){
	welcome();
	int waiting = 0;
	char line[MAXLINE];
	char *tokens[LIMIT];
	int numTokens;
	gEnv=envp;
	while(!waiting)
	{
		prompt();
		memset(line, '\0',MAXLINE);
		fgets(line,MAXLINE,stdin);
		if((tokens[0] = strtok(line," \n\t")) == NULL) continue;
		numTokens = 1;
		while((tokens[numTokens] = strtok(NULL, " \n\t")) != NULL) numTokens++;
		commandHandler(tokens);
	}

}

