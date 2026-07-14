#include <string>
#include <vector>

using namespace std;

int getGcd(int num1, int num2)
{
    if(num1 % num2 == 0) return num2;
    return getGcd(num2, num1 % num2);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int sum = numer1 * denom2 + numer2 * denom1;
    int mul = denom1 * denom2;
    
    int gcd = getGcd(sum, mul);
    
    vector<int> answer = {sum/gcd, mul/gcd};
    return answer;
}