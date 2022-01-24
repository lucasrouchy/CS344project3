#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
  if(argc == 0){
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


      // execvp(s[0], s);
      if (strcmp(s[0],"exit")== 0){
        exit(0);
      }

      if (strcmp(s[0],"cd")== 0){
        int syscall = chdir(s[1]);
        if (syscall == -1) {
          perror("error with system call for chdir()");
        }
        continue;
      }

      int f = fork();
      if(f == 0){
        execvp(s[0], s);
        perror("error becuase execpv returned a value");
        exit(1);
      }
      else {
        wait(NULL);
        // perror("error becuase execpv returned a value");
      }

    }



  }
