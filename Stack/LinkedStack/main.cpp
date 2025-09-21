#include <iostream>
#include "LinkedStack.h"
#include <string>

bool isOperand(char c)
{
    return std::isalpha(c) || std::isdigit;
}

bool isOperator(char c)
{
    switch (c) {
    case '+':
    case '-':
    case '^':
    case '/':
    case '*':
        return true;
    }
    return false;
}

int priority(char c)
{
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    }
    return -1;
}


int main()
{
    LinkedStack<char> st;
    std::string input;
    std::getline (std::cin, input);

    for (char c : input)
    {
        if (c == '(') {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                std::cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && priority(c) <= priority(st.top()))
            {
                std::cout << st.top();
                st.pop();
            }
            st.push(c);
        }
        else
        {
            std::cout << c;
        }
    }
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }
    return 0;
}

