#include <stdio.h>
#include <unistd.h>


int main(void)
{

  execlp("ls", "ls", "-l", NULL);

  char *new_argv[128];

  new_argv[0] = "ls";
  new_argv[1] = "-l";
  new_argv[2] = "-a";
  new_argv[3] = NULL;

  execvp(new_argv[0], new_argv);


}
