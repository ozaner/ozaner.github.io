#include <stdio.h>

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");

  //Initialize matrix 2
  int rows1, cols1;
  fscanf(f,"%d\t%d\n", &rows1, &cols1);

  //Fill matrix 1
  int mat1[rows1][cols1];
  for(int i = 0; i < rows1; i++) {
    for(int j = 0; j < cols1; j++) {
      //check if this is the last number of the row
      if(j % cols1 == 1)
        fscanf(f,"%d\n", &mat1[i][j]);
      else
        fscanf(f,"%d\t", &mat1[i][j]);
    }
  }

  //Initialize matrix 2
  int rows2, cols2;
  fscanf(f,"%d\t%d\n", &rows2, &cols2);

  //Fill matrix 2
  int mat2[rows2][cols2];
  for(int i = 0; i < rows2; i++) {
    for(int j = 0; j < cols2; j++) {
      //check if this is the last number of the row
      if(j % cols2 == 1)
        fscanf(f,"%d\n", &mat2[i][j]);
      else
        fscanf(f,"%d\t", &mat2[i][j]);
    }
  }
  fclose(f);
  //Check if valid multiply
  if(cols1 != rows2) {
    printf("bad-matrices");
    return 0;
  }

  //Initialize result matrix
  int matR[rows1][cols2];

  //Fill result matrix
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      matR[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        matR[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  //Print mat result
  for(int i = 0; i < rows1; i++) {
    for(int j = 0; j < cols2; j++)
      printf("%d\t",matR[i][j]);
    if(i != rows1-1)
      printf("\n");
  }


  return 0; //Exit Successfilly
}
