#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int n, int bracket[][n], char *name) {
    if (i == j) {
        printf("%c", *name);
        (*name)++;
        return;
    }
    printf("(");
    printOptimalParenthesis(i, bracket[i][j], n, bracket, name);
    printOptimalParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    printf(")");
}


int matrixChainMultiplication(int dims[], int n)
{
int i,L,k;
    int m[n][n];
    int bracket[n][n];

    for ( i = 1; i < n; i++)
        m[i][i] = 0;

    for ( L = 2; L < n; L++)
    {
        for ( i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for ( k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    int bracketIndex = 0;
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, n, (int *)bracket, &name);

    printf("\nMinimum number of scalar multiplications is %d\n", m[1][n - 1]);

    return m[1][n - 1];
}

int main()
{
   int n,dims[100],i;
   printf("enter number of elements: ");
   scanf("%d",&n);
   printf("enter array: \n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&dims[i]);
   }

    matrixChainMultiplication(dims, n);

    return 0;
}

