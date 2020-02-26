#include <stdio.h>

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");

  // Read array size
  int size = 0;
  fscanf(f,"%d\n", &size);
  int arr[size];

  // Read array into arr[] and count parity
  int sizeE = 0, sizeO = 0;
  for(int i = 0; i < size; i++) {
    fscanf(f,"%d\t", &arr[i]);
    if(arr[i]%2 == 0)
      sizeE++;
    else
      sizeO++;
  }

  // Split arr[] into even[] and odds[]
  int evens[sizeE], odds[sizeO];
  int nextEven = 0, nextOdd = 0;
  for(int i = 0; i < sizeE+sizeO; i++) {
    if(arr[i]%2 == 0)
      evens[nextEven++] = arr[i];
    else
      odds[nextOdd++] = arr[i];
  }

  // Sort evens in ascending order
  for(int i = 0; i < sizeE; i++) {
    for(int j=i+1; j < sizeE; j++) {
      if(evens[i] > evens[j]) {
          int temp = evens[i];
          evens[i] = evens[j];
          evens[j] = temp;
      }
    }
  }

  // Sort odds in decending order
  for(int i = 0; i < sizeO; i++) {
    for(int j=i+1; j < sizeO; j++) {
      if(odds[i] < odds[j]) {
          int temp = odds[i];
          odds[i] = odds[j];
          odds[j] = temp;
      }
    }
  }

  // Combine even and odds
  for(int i = 0; i < sizeE; i++)
    arr[i] = evens[i];
  for(int i = 0; i < sizeO; i++)
    arr[i+sizeE] = odds[i];

  // Output Result
  for (int j = 0; j < size; j++)
    printf("%d\t", arr[j]);

  return 0; // Exit sucessfully
}
