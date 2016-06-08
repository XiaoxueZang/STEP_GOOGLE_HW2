class Matrix {
  public static void main(String args[])
  {
    if (args.length != 1) {
      System.out.println("usage: java Matrix N");
      return;
    }
    int maxN = Integer.parseInt(args[0]);
    int n;
    for(n = 0; n <= maxN; n++){
      double[][] a = new double[n][n]; // Matrix A
      double[][] b = new double[n][n]; // Matrix B
      double[][] c = new double[n][n]; // Matrix C

    // Initialize the matrices to some values.
      int i, j;
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          a[i][j] = i * n + j;
          b[i][j] = j * n + i;
          c[i][j] = 0;
        }
      }

      long begin = System.currentTimeMillis();
      int k;

    /**************************************/
    /* Write code to calculate C = A * B. */
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          for (k = 0; k < n; k++){
            c[i][j]=c[i][j]+a[i][k]*b[k][j];
          }
        }
      }
      long end = System.currentTimeMillis();
      System.out.printf("%d %.6f\n", n,(end - begin)/1000.0);
    }
  }
}
