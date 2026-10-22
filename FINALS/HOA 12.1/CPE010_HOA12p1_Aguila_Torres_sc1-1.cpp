#include <iostream>
#include <algorithm>

int memo[10001];

int getMinSteps(int n)
{
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int r = 1 + getMinSteps(n - 1);
    if (n % 2 == 0)
        r = std::min(r, 1 + getMinSteps(n / 2));
    if (n % 3 == 0)
        r = std::min(r, 1 + getMinSteps(n / 3));
    memo[n] = r;

    return r;
}

int main()
{
    int n;

    std::fill(memo, memo + 10001, -1);
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 1 || n > 10000) {
        std::cout << "Enter a number from 1 to 10000.";
        return 0;
    }
    std::cout << "Minimum Steps: " << getMinSteps(n);

    return 0;
}