#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool is_balanced(std::string& input) 
{
    std::stack<char> braces;
    std::unordered_map<char, char> key_opening;
    std::unordered_map<char, char> key_closing;
    key_opening = { {'[' , ']'}, {'(', ')'}, {'{', '}'} };
    key_closing = { {']' , '['}, {')', '('}, {'}', '{'} };
    
    for (int i = 0; i < input.size(); i++)
    {
        char seq_item = input[i];
        if (key_opening.find(seq_item) != key_opening.end())
            braces.push(seq_item);
        else if (key_closing.find(seq_item) != key_closing.end())
        {
            if (braces.empty())
                return false;
            char top = braces.top();
            braces.pop();
            if (top != key_closing[seq_item])
                return false;
        }

    }
    return braces.empty();
}

int main()
{
    std::string braces_seq;
    std::cout << "Enter sequence of braces you want to check" << std::endl;
    std::cin >> braces_seq;
    if (is_balanced(braces_seq))
        std::cout << "Is balanced" << std::endl;
    else
        std::cout << "Is not balanced" << std::endl;

    return 0;
}
