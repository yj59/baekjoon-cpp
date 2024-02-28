#include <iostream>
#include <vector>

int d[100][100];

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &d[i][j]);
        }
    }

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (d[i][k] == 1 && d[k][j] == 1) 
                {
                    d[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}