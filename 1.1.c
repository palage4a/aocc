#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE* fd = fopen("./1.input", "r");
  if (!fd) perror("");

  char buf[2048];
  int incs = 0,
      prev = 0;
  while(fgets(buf, sizeof(buf), fd) != NULL) {
    int cur = atoi(buf);
    if(prev > 0 && prev < cur ) incs++;
    prev = cur;
  }
  printf("incs: %d\n", incs);
  return 0;
}
