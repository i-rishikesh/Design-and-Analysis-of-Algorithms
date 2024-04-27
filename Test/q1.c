//WAP a program to find the longest palindromic subsequences in a given string.(hINT:subsequence is obtained by deleting some of the charachter from a string without reordering the remaining characters,which is also palindrome)
#include<stdio.h>
#include<string.h>
 int max(int a,int b)
 {
     return (a>b)?a:b;
}
int lps(char *str)
{
    int n=strlen(str);
    int i,j,cl;
    int L[n][n];
    for(i=0;i<n;i++)
        L[i][i]=1;
    for(cl=2;cl<=n;cl++)
    {
        for(i=0;i<n-cl+1;i++)
        {
            j=i+cl-1;
            if(str[i]==str[j] && cl==2)
                L[i][j]=2;
            else if(str[i]==str[j])
                L[i][j]=L[i+1][j-1]+2;
            else
                L[i][j]=max(L[i][j-1],L[i+1][j]);
        }
    }
    return L[0][n-1];
}
int main()
{
    char seq[100];
    printf("Enter the sequence: ");
    scanf("%s",seq);
    int n=strlen(seq);
    printf("The length of the longest palindromic subsequence is: %d",lps(seq));
    return 0;
}

