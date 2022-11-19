#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE* fd = fopen("./1.input", "r" );
  if (!fd) perror("");

  int scanned = 0,
    result = 0,
    counter = 0,
    prev = 0,
    cur = 0;
  long next_pos = 0;

  while(fscanf(fd, "%d\n", &scanned) != EOF) {
    if (counter++ == 0) {
      next_pos = ftell(fd);
    }
    cur += scanned;
    if (counter == 3) {
      if (prev > 0 && prev < cur) result++;
      prev = cur;
      cur = 0;
      counter = 0;
      fseek(fd, next_pos, SEEK_SET);
    }
  }

  printf("%d\n", result);
  return 0;
}
