#ifndef COMUT_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#define COMUT_H




static char* dosyaYeri;
static char** gEnv;
void shellbaslat(int, char**, char**);
void cocukfonk(int);
int coMutcalistir(char **args, int background);
int coMut_cd(char **args);
int coMut_quit(char **args);
void noktaliVirgul(char **args[]);
void borudose(int pfd[], char *pipetler[][256],int kacli);
void DosyaGiris(char *args[], char *inputFile);
void DosyaCikis(char *args[], char *inputFile);
#endif
/*
GRUP --6--
G171210021
G171210024
G171210045
G171210084
G171210375
*/
