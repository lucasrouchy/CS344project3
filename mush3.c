#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
  if( argc == 0){
    return -1;
  }

  while (1) {
    printf("prompt: ");
    char *token;

    char str[2048];
    fgets(str, 2048, stdin);

    if (feof(stdin)) {
      exit(0);
    }

    char *s[128];
    int commandcount = 0;

    token = strtok(str, " \t\n\r");
    if (token != NULL){
      do {
        s[commandcount] =  malloc(sizeof(token));
        strcpy(s[commandcount], token);
        commandcount = commandcount + 1;


      } while ((token= strtok(NULL, " \t\n\r")) !=NULL);
      }
      s[commandcount] = NULL;

      execvp(s[0], s);
    }

  }
