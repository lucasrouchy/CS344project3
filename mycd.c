#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{

  char path [1024];

  getcwd(path, sizeof path);
  printf("%s\n", path);



  chdir(argv[1]);

  getcwd(path, sizeof path);
  printf("%s\n", path);

}
