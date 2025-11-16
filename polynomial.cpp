#include <iostream>
#include <list>

struct data
{
    int pow;
    int coef;
};

void add_data(std::list<data>& l1, data d1)
{
    auto it = l1.begin();
    for (; it != l1.end(); it++)
    {
        if (it->pow == d1.pow)
        {
            it->coef += d1.coef;
            return;
        }
        if (it->pow < d1.pow)
        {
            break;
        }  
    }
    l1.insert(it, d1);
}

void print_poly(const std::list<data>& l1)
{
    for (auto it = l1.begin(); it != l1.end(); it++)
    {
        std::cout << it->coef << "x^" << it->pow;
        if (std::next(it) != l1.end())
            std::cout << " + ";
    }
    std::cout << std::endl;
}


int main()
{
    std::list<data> l1;

    std::cout << "Enter terms as: <coef> <power>" << std::endl;
    std::cout << "Enter 0 0 to stop." << std::endl << std::endl;

    while (true)
    {
        data d;
        std::cout << "Term: ";
        std::cin >> d.coef >> d.pow;

        if (d.coef == 0 && d.pow == 0)
            break;  

        add_data(l1, d);
    }

    std::cout << std::endl;
    std::cout << "Final polynomial: ";
    print_poly(l1);

    return 0;
    
}
