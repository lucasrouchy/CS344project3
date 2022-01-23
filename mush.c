#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  FILE *file;
  file = fopen("prompt.txt", "r");
  if(file == NULL) {
    perror("error opening file");
    exit(1);
  }
  char *token;
  char prompt[60];
  // printf("%s\n", prompt);
  if (fgets(prompt, 60, file)!=NULL){
    puts(prompt);
  }
  fclose(file);

  return(0);
  token = strtok(prompt, ",");

  while (token != NULL) {
    printf("%s\n", token);
  }
  return(0);


}
