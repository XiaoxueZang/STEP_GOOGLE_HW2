#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s N\n", argv[0]);
        return -1;
    }

    int maxN = atoi(argv[1]);
    int n;
    for (n = 32;n<=maxN*32;n+=32){
    double *a = (double *) malloc(n * n * sizeof(double)); // Matrix A
    double *b = (double *) malloc(n * n * sizeof(double)); // Matrix B
    double *c = (double *) malloc(n * n * sizeof(double)); // Matrix C

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
    int result;
    /**************************************/
    /* Write code to calculate C = A * B. */
    double *tempa, *tempb, *tempc;
    double partSum[4];
    int BLOCK = 16;
    //const double *ptempc;
    int k;
    //#pragma omp parallel shared(a, b, c);
    for(int i0=0; i0 < n; i0+=BLOCK) {
      for(int j0=0; j0 < n; j0+=BLOCK) {
        for(int k0=0; k0 < n; k0+=BLOCK) {
          //#pragma omp for private(i, j, k, partSum, tempa, tempb, tempc);
          for(int i=i0; i < i0+BLOCK; i+=2) {
            for(int j=j0; j < j0+BLOCK; j+=2) {
              //partSum = calloc(4,sizeof(double));
              partSum[0]=0;
              *(double *)(partSum+1)=0;
              *(double *)(partSum+2)=0;
              *(double *)(partSum+3)=0;
              for(k=k0; k < k0+BLOCK; k++) {
                tempa = &a[i*n+k];
                tempb = &b[k*n+j];
              //ptempc = &matB[k*size+j];
              *partSum += (*tempa)*(*(tempb));
              *(partSum+1) += (*(tempa+n))*(*(tempb));
              *(partSum+2) += (*(tempa))*(*(tempb+1));
              *(partSum+3) += (*(tempa+n))*(*(tempb+1));

            }
            tempc = &c[i*n+j];
            *tempc+= *partSum;
            *(double *)(tempc+n) += *(double *)(partSum+1);
            *(double *)(tempc+1) += *(double *)(partSum+2);
            *(double *)(tempc+n+1) += *(double *)(partSum+3);
          }
        }
      }
    }
  }

    /**************************************/

    double end = get_time();
    //printf("time: %.6lf sec\n", end - begin);
    printf("%d %.6lf\n", n, end - begin);
    free(a);
    free(b);
    free(c);
  }

    // Print C for debugging. Comment out the print before measuring the execution time.

    return 0;
}
