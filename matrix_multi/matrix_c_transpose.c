#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("usage: %s N\n", argv[0]);
    return -1;
  }

  int maxN = atoi(argv[1]);
  int n;
  for (n = 1;n<=maxN;n++){
    double* a = (double*)malloc(n * n * sizeof(double)); // Matrix A
    double* b = (double*)malloc(n * n * sizeof(double)); // Matrix B
    double* c = (double*)malloc(n * n * sizeof(double)); // Matrix C

  // Initialize the matrices to some values.
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        a[i * n + j] = i * n + j; // A[i][j]
        b[i * n + j] = j * n + i; // B[i][j]
        c[i * n + j] = 0; // C[i][j]
      }
    }

    double begin = get_time();
    double result;
    double* transposeB = (double*)malloc(n * n * sizeof(double));
    for (i = 0; i < n; i++){
      for (j = 0; j < n;j++){
        transposeB[j*n + i] = b[i * n + j];
      }
    }
  /**************************************/
  /* Write code to calculate C = A * B. */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result = 0;
            for (int k = 0; k < n; k++) {
              result += a[i * n + k] * transposeB[j * n + k];
            }
            c[i * n + j] = result;
        }
    }
  /**************************************/

    double end = get_time();
    printf("%d %.6lf\n", n, end - begin);
    free(a);
    free(b);
    free(c);
  }
  return 0;
}
