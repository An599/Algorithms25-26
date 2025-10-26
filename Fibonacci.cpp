
#include <iostream>
#include <vector>
#include <cmath>

int iterative_fibo(size_t pstn) {
    int fibo = 0;
    int sum_prev = 1;
    int sum = 0;
    for (size_t i = 1; i < pstn; i++)
    {
        sum = sum_prev + fibo;
        fibo = sum_prev;
        sum_prev = sum;
    }
    return sum;
}

int  recursive_fibo(size_t pstn) {
    if (pstn == 0)
        return 0;
    if (pstn == 1)
        return 1;
    else
        return recursive_fibo(pstn - 1) + recursive_fibo(pstn - 2);
}

int memoization_fibo(size_t pstn, std::vector<int>& memo) {
    if (pstn == 0) 
        return 0;
    if (pstn == 1) 
        return 1;

    if (memo[pstn] != -1) 
        return memo[pstn];

    memo[pstn] = memoization_fibo(pstn - 1, memo) + memoization_fibo(pstn - 2, memo);
    return memo[pstn];
}

int fi_fibo(size_t pstn) {
    double fi1 = (1 + sqrt(5)) / 2;
    double fi2 = (1 - sqrt(5)) / 2;
    double result = (pow(fi1, pstn) - pow(fi2,pstn)) / sqrt(5.0);
    return result;
}

int main()
{
    size_t position;
    std::cout << "Enter the position of number which s Fibonacci you want to see" << std::endl;
    std::cin >> position;
    std::vector<int> m(position + 1, -1);
    int iter_result = iterative_fibo(position);

    std::cout << "Result of iterative Fibonacci sequence --> " << iter_result << std::endl;
    std::cout << "Result of recursive Fibonacci sequence --> " << recursive_fibo(position) << std::endl;
    std::cout << "Result of memoziation Fibonacci sequence --> " << memoization_fibo(position, m) << std::endl;
    std::cout << "Result of fi value s Fibonacci sequence --> " << fi_fibo(position) << std::endl;
}
