#include <stdio.h>

void matrix_chain_order(int p[], int n, int m[][n], int s[][n]) {
    int i, j, k, L, q;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = 999999; // Initialize to a large value
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parenthesization(int s[][4], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parenthesization(s, i, s[i][j]);
        print_optimal_parenthesization(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i, j;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];

    printf("Enter dimensions of matrices:\n");
    for (i = 0; i <= n; i++) {
        printf("Enter row and column size of A%d: ", i + 1);
        scanf("%d %d", &p[i], &p[i + 1]);
    }

    matrix_chain_order(p, n, m, s);

    printf("M Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    print_optimal_parenthesization(s, 1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    return 0;
}
