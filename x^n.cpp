#include <iostream>

double with_loop(double x, int n)
{
    int pow = 1;
    for (int i = 1; i <= n; i++) {
        pow *= x;   
    }
    return pow;
}

double recursion(double x, int n)
{        
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else
        return x * recursion(x, n - 1);    

}

double logn_version(double x, int n)
{
    if (n == 0)
        return 1;
    double half = logn_version(x , n/2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main()
{
    double x;
    int n;
    double pow;
    std::cout << "Enter the number which's power you want to calculate\n";
    std::cin >> x;
    std::cout << "Enter the power you want to calculate\n";
    std::cin >> n;
  
    // solution using loop
    pow = with_loop(x, n);
    std::cout << "Result with loop ---->   " << pow << std::endl;
  
    //solution using recursion
    pow = recursion(x, n);
    std::cout << "Result with basic recursion ---->   " << pow << std::endl;
  
    //solution with logn complexity
    pow = logn_version(x, n);
    std::cout << "Result with logn solution ---->   " << pow<<std::endl;
    return 0;
}
