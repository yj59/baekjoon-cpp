#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int temp;
int a[100010];

void binarySearch(int k) {
    int start = 0;
    int end = N - 1;
    int mid;

    while (end >= start) {
        mid = (start + end) / 2;

        if (a[mid] == k) {
            cout << 1 << "\n";
            return;
        }
        else if (a[mid] > k) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << 0 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        a[i] = temp;
    }
    sort(a, a + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        binarySearch(temp);
    }

    return 0;
}