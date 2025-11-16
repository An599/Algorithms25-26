#include <iostream>
#include <stack>

void arrange_tow(int n, std::stack<int>& s1, std::stack<int>& s2, std::stack<int>& s3)
{
    if (n == 0) {
        return;
    }
    arrange_tow(n - 1, s1, s3, s2); //s1i vric n-1 haty qcuma s3
    s2.push(s1.top());
    s1.pop();
    arrange_tow(n - 1, s3, s2, s1); //s3 iny qcuma s2 i vra 
}

int main()
{
    std::stack<int> s1, s2, s3;
    int n = 5;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    arrange_tow(n, s1, s2, s3);
    while (!s2.empty())
    {
        std::cout << s2.top() << std::endl;
        s2.pop();
    }

}
