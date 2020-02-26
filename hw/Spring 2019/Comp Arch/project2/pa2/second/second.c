#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  unsigned short num = atoi(argv[1]);
  
  unsigned int count = 0;
  unsigned short temp = num;
  while(temp) {
    count += temp%2;
    temp >>= 1;
  }
  
  if(count % 2 == 0)
    printf("Even-Parity\t");
  else
    printf("Odd-Parity\t");
  
  count = 0;
  temp = num;
  int prevBit = 0;
  while(temp) {
    if(prevBit && temp%2) {
      count++;
      prevBit = 0;
    }
    else if(prevBit && !temp%2)
      prevBit = 0;
    else if(!prevBit && temp%2)
      prevBit = 1;
    else
      prevBit = 0;
    temp >>= 1;
  }
  
  printf("%d",count);
  
  return 0; // Exit sucessfully
}
