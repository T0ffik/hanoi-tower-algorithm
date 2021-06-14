#include <stdio.h>
#include <stdlib.h>

int take(int a, int n, int K[n][3], int L[])
{
    L[a]--;
    int help=K[n-L[a]-1][a];
    K[n-L[a]-1][a]=0;
    return help;
}
void give(int disc, int b, int n, int K[n][3], int L[])
{
    L[b]++;
    K[n-L[b]][b]=disc;
}
void print(int n, int K[n][3])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(K[i][j]==0)
                printf("   ");
            else
                printf("%d  ", K[i][j]);
        }
        printf("\n");
    }
    printf("-------\n1  2  3\n\n");
}
void tower(int n, int a, int b, int c, int K[n][3], int L[], int help)
{
    int disc;
    if(n==1)
    {
        disc = take(a, help, K, L);
        give(disc, b, help, K, L);
        print(help, K);
    }
    else
    {
        tower(n-1, a, c, b, K, L, help);
        disc = take(a, help, K, L);
        give(disc, b, help, K, L);
        print(help, K);
        tower(n-1, c, b, a, K, L, help);
    }
}
int main ()
{
    int n,help,a=0,b=1,c=2;
    printf("Enter number of discs:  ");
    scanf("%d", &n);
    int K[n][3], L[3]={n,0,0};
    for(int i=0; i<n; i++)
    {
        K[i][0]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<3; j++)
        {
            K[i][j]=0;
        }
    }
    help=n;
    tower(n, a, b, c, K, L, help);
    system("pause");
    return 0;
}
