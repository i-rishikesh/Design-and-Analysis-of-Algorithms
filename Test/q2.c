#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longest_palindromic_subsequence(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(arr[i] - arr[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > result) {
            result = dp[i];
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int elements[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    int result = longest_palindromic_subsequence(elements, n);
    printf("The length of the longest palindromic subsequence with adjacent element difference of one is: %d\n", result);

    return 0;
}
