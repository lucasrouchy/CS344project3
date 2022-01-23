#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  FILE *file;
  char *token;
  char str[60];
  file = fopen("prompt.txt", "r");
  if(file == NULL) {
    perror("error opening file");
    exit(1);
  }
  char *prompt = "Promt: ";
  printf("%s\n", prompt);

  fgets(str, 60, stdin);


  token = strtok(str, " ");


  if (token != NULL)
      do {
        printf("%s\n", token);

      } while ((token= strtok(NULL, " ")) !=NULL);


  char *s[128];

  s[0] = "";
  s[1] = "";
  s[3] = NULL;

  // for (int i = 0; i < 3; i++) {
  //     printf("%s\n", s[i]);
  // }

execvp(s[0], s);

}
