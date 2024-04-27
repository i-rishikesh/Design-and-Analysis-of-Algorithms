#include <stdio.h>
#include <string.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int lcs(char *X, char *Y, int m, int n) {
  int table[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else if (X[i - 1] == Y[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }

  return table[m][n];
}

int main() {
  char X[100], Y[100];

  printf("Enter the first string into an array: ");
  scanf("%s", X);

  printf("Enter the second string into an array: ");
  scanf("%s", Y);

  int m = strlen(X);
  int n = strlen(Y);

  int lcs_length = lcs(X, Y, m, n);

  printf("       LCS Length: %d\n", lcs_length);

  printf("       LCS: ");
  for (int i = 0; i < lcs_length; i++) {
    printf("%c", X[i]);
  }
  printf("\n");

  return 0;
}
