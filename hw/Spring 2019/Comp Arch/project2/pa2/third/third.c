#include <stdio.h>
#include <stdlib.h>

unsigned short get(unsigned short x, unsigned short n) {
  return (x >> n) & 1;
}

int main(int argc, char **argv) {
  unsigned short num = atoi(argv[1]);
  unsigned short BITS = sizeof(num) * 8;
  
  for(unsigned short i = 0; i < BITS/2; i++) {
    if(get(num,i) != get(num,BITS-i-1)) {
      printf("Not-Palindrome");
      return 0;
    }
  }
  printf("Is-Palindrome");
  
  return 0; // Exit sucessfully
}
