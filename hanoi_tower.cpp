#include <iostream>
#include <stack>

void arrange_tow(int n, std::stack<int>& s1, std::stack<int>& s2, std::stack<int>& s3)
{
    if (n == 0) {
        return;
    }
    arrange_tow(n - 1, s1, s3, s2);        
    s2.push(s1.top());                    
    s1.pop();
    arrange_tow(n - 1, s3, s2, s1);        
}

int main()
{
    std::stack<int> s1, s2, s3;
    int n;

    std::cout << "Enter number of disks: ";
    std::cin >> n;
    std::cout << std::endl;

    for (int i = n; i >= 1; i--) {
        s1.push(i);
    }

    arrange_tow(n, s1, s2, s3);

    std::cout << "Final tower (s2): " <<std::endl;
    while (!s2.empty())
    {
        std::cout << s2.top() << std::endl;
        s2.pop();
    }

    return 0;
}
