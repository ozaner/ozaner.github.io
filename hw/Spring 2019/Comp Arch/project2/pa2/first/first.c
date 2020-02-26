#include <stdio.h>
#include <string.h>

unsigned int get(unsigned int x, unsigned int n) {
  return (x >> n) & 1;
}

unsigned int set(unsigned int x, unsigned int n, unsigned int v) {
  if(get(x,n) == v)
    return (0 << n) ^ x;
  else
    return (1 << n) ^ x;
}

unsigned int comp(unsigned int x, unsigned int n) {
  return (1 << n) ^ x;
}

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");

  unsigned int val;
  fscanf(f, "%u\n", &val);
  // Read commands and execute
  char cmd[5];
  unsigned int a1, a2;
  int flag;
  
  int firstprint = 1;
  
  while(1) {
    flag = fscanf(f,"%s\t%u\t%u\n", cmd, &a1, &a2);
    if(flag == EOF)
      break;
    if(!firstprint)
      printf("\n");
    if(!strcmp("get",cmd))
      printf("%u",get(val,a1));
    else if(!strcmp("set",cmd)) {
      val = set(val, a1, a2);
      printf("%u",val);
    }
    else if(!strcmp("comp",cmd)) {
      val = comp(val, a1);
      printf("%u",val);
    }
    firstprint = 0;
  }
  fclose(f);

  return 0; // Exit sucessfully
}
