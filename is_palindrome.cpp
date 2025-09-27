#include <iostream>
#include <stack>

bool palindrome(std::string& input)
{
    std::stack<char> letters;
    for (int i = 0; i < input.size() / 2; i++)
    {
        letters.push(input[i]);
    }
    for (int i = (input.size() % 2 == 0) ? input.size()/2 : input.size()/2+1; i < input.size(); i++)
    {
        if (letters.empty())
            return false;

        char top = letters.top();
        letters.pop();
        if (input[i] != top)
            return false;
    }
    return letters.empty();
}

int main()
{
    std::string pali;
    std::cout << "Enter word you want to check" << std::endl;
    std::cin >> pali;
    if (palindrome(pali))
        std::cout << "Is palindrome" << std::endl;
    else
        std::cout << "Is not palindrome" << std::endl;

    return 0;
}
