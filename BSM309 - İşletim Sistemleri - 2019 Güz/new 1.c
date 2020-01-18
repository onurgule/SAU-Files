#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include "program.h"

char *situations[]={
	"cd",
	"help",
	"quit"
};

int (sit_func[])(char*) = {
	&cd,
	&help,
	&quit
};

int cd(char **args)
{
	if (args[1]==NULL)
	{
		fprintf(stderr,"expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1])!=0)
		{
			perror("error");
		}
	}
	return 1;
}

int help(char **args)
{
	int i;
	printf("Isletım Sistemleri Odevi\n");
	for (i=0;i<builtins();i++)
	{
		printf("  %s\n",situations[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return 1;
}

int quit(char **args)
{
	int status;
	while (!waitpid(-1,&status,WNOHANG)){}
	exit(0);
}

int builtins()
{
	return sizeof(situations)/sizeof(char *);
}

#define WORDMAX 256
int commandHandler(char * args[])
{
    char *word[WORDMAX];
	int i=0;
    int k=0;
	int k;
	int background = 0;
	
	while(args[i] != NULL)
	{
		if ((strcmp(args[i],">") == 0) || (strcmp(args[i],"<") == 0) || (strcmp(args[i],"&") == 0))
		{
			break;
		}
		word[i] = args[i];
		i++;
	}
	word[i]=NULL;

	if (args[0] == NULL)
	{
		return 1;
	}
	for (j = 0 ; j < builtins() ; m++)
	{
		if (strcmp(args[0],situations[j])==0)
		{
			(*sit_func[j])(args);
			return 1;
		}
	}
	while (args[k] != NULL && background == 0)
	{
		if (strcmp(args[k],"&") == 0)
		{
			background = 1;
		}
		else if (strcmp(args[k],"<") == 0)
		{
			if (args[k+1] == NULL )
			{
				printf ("Arguman Yok\n");
			}
			inputRD(word,args[k+1]);
			return 1;
		}
		else if (strcmp(args[k],">") == 0)
		{
			if (args[k+1] == NULL )
			{
				printf ("Arguman Yok\n");
			}
			outputRD(word,args[k+1]);
			return 1;
		}
		k++;
	}
	word[k]==NULL;
	saush_launch(word,background);
	return 1;
}

void inputRD(char args[],char inputFile)
{
	pid_t pid;
	if (!(access (inputFile,F_OK) != -1))
	{	
		printf("%s adinda bir dosya bulunamadi\n",inputFile);
		return;
	}
	int err=-1;
	int fileDescriptor;
	if((pid=fork()) == -1)
	{
		printf("child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		fileDescriptor=open(inputFile, O_RDONLY, 0600);
		dup2(fileDescriptor,STDIN_FILENO);
		close(fileDescriptor);

		if (execvp(args[0],args)==err)	
		{
			printf("error");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}

void outputRD(char args[],char outputFile)
{
	pid_t pid;
	int err=-1;
	int fileDescriptor;
	if((pid=fork()) == -1)
	{
		printf("child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		fileDescriptor=open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		dup2(fileDescriptor,STDOUT_FILENO);
		close(fileDescriptor);

		if (execvp(args[0],args)==err)	
		{
			printf("error");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}

int launchbg(char **args)
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
		//exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("saush");
	}
	else
	{
		printf("Proses PID:%d Degeriyle Olusturuldu\n",pid);
	}
	return 1; 
}

int launch(char **args,int background)
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
			perror("saush");
		}
		else
		{
			waitpid(pid,NULL,0);
		}
	}
	else
	{
		launchbg(args);
	}
	return 1; 
}

void sig_chld(int signo) 
{
    int status, child_val,chid;
	chid = waitpid(-1, &status, WNOHANG);
	if (chid > 0)//Arkaplanda çalışmayan processler için bu değer -1 olacağından bu kontrol yapılmıştır.
	{
		if (WIFEXITED(status))	//Çocuk Normal Bir Şekilde mi Sonlandı ?
	    {
	        child_val = WEXITSTATUS(status); // Çocuğun durumu alındı.
	        printf("[%d] retval : %d \n",chid, child_val); //Çocuğun pid'i ve durumu ekrana yazdırılır.
	    }
	}
}

void welcomeScreen(){
        printf("\n\t============================================\n");
        printf("\t                   C Shell  \n");
        printf("\t--------------------------------------------\n");
        printf("\t                                  \n");
        printf("\t============================================\n");
        printf("\n\n");
}

void PromptBas()
{
	char hostn[1204] = "";
	gethostname(hostn, sizeof(hostn));
	printf(YEL "%s@%s:"RESET RED "%s > " RESET, getenv("LOGNAME"), hostn, getcwd(currentDirectory, 1024));
}

int main (int argc, char **argv, char **envp)
{
	welcomeScreen();
	char line[MAXLINE];
	char *tokens[LIMIT];
	int numTokens;
	environ=envp;
	
	while(true)
	{
		PromptBas();
		memset(line, '\0',MAXLINE);
		fgets(line,MAXLINE,stdin);
		if((tokens[0] = strtok(line," \n\t")) == NULL) continue;
		numTokens = 1;
		while((tokens[numTokens] = strtok(NULL, " \n\t")) != NULL) numTokens++;
		commandHandler(tokens);
	}
}