#include <stdio.h>
int n, sum;
int main() {
    scanf("%d", &n);
    while (n != 0)
    {
        sum = 0;
        for (int i = 1; i <= n; i++) sum += i;
        printf("%d\n", sum);
        scanf("%d", &n);
    }
}