#include "CyclicList.h"

int main() {
    CyclicList<int> list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(1, 15);
    list.insert(3, 25);
    list.print();  

    std::cout << "Value at pos 2: " << list.getValue(2) << std::endl;

    list.erase(1);  
    list.print();   

    std::cout << "Size: " << list.sizee() << std::endl;

    list.clear();
    list.print();   
}
