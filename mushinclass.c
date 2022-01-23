#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char s[128] = "ls -l -a";
  char *t;

  if ((t = strtok(s, ",")) != NULL)
      do {
        printf("%s\n", t);

      } while ((t= strtok(NULL, " ")) !=NULL);



  t = strtok(s,",");
  printf("s\n", t);
  printf(">>%s\n", s);



}
