#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n[3];
int main()
{
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	sort(n, n + 3);
	printf("%d %d %d", n[0], n[1], n[2]);
}