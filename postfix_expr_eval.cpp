#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

template <typename T>
T execOperation(char op, T val1, T val2)
{
    switch (op)
    {
    case '+':
        return val1 + val2;
    case '-':
        return val1 - val2;
    case '*':
        return val1 * val2;
    case '/':
        if (val2 == 0)
        {
            std::cout << "Can t execute division to 0. Input valid expression" << std::endl;
            exit(1);
        }
        else
            return val1 / val2;
 
    default:
        throw std::runtime_error("Unknown operator");
    }
}

template <typename T>
T evalExpr(const std::string& expr)
{
    std::stack<T> operands;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && (token == "+" || token == "-" || token == "/" || token == "*")) {
            char current_op = token[0];
            if (operands.size() < 2)
            {
                std::cout << "Not enough operands for calculation" << std::endl;
                exit(1);
            }
            T val1 = operands.top();
            operands.pop();
            T val2 = operands.top();
            operands.pop();

            T result = execOperation(current_op, val1, val2);
            operands.push(result);
        }
        else
        {
            try
            {
                T num_val;
                std::stringstream convert_ss(token);
                if (!(convert_ss >> num_val))
                {
                    std::cout << "Invalid input" << std::endl;
                    exit(1);
                }
                operands.push(num_val);
            }
            catch (std::exception& e)
            {
                std::cout << "Error had happend while getting number -- " << e.what() << std::endl;
                return 0;
            }
        }
    }
    return operands.top();
}
int main()
{
    std::string expr;
    std::cout << "Provide postfix expression for calculation"<<std::endl;
    std::getline(std::cin, expr);

    try {
        int result_int = evalExpr<int>(expr);
        std::cout << "Expression: " << expr << std::endl;
        std::cout << "Result (int): " << result_int << std::endl;
    }
    catch (...) {} 

    try {
        double result_double = evalExpr<double>(expr);
        std::cout << "Expression: " << expr << std::endl;
        std::cout << "Result (double): " << result_double << std::endl;
    }
    catch (...) {}

    return 0;
}
