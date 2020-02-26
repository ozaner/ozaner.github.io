#include <stdio.h>

char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};

int main(int argc, char **argv) {
  for(int i = 1; i < argc; i++) {
    int j = 0;
    while(argv[i][j] != '\0') {
      for(int k = 0; k < 10; k++) {
        if(argv[i][j] == vowels[k]) {
          printf("%c",argv[i][j]);
          break;
        }
      }
      j++;
    }
  }

  return 0; //Exit Successfilly
}
