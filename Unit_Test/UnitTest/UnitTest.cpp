#include "singleton.h"
#include <cassert>

int main() {
    MeticRegister* register1 = MeticRegister::getInstance();
    assert(register1->add_metr(10, 20));
    assert(register1->add_metr(15, 25));
    assert(register1->add_metr(20, 30));
    assert(register1->add_metr(25, 35));
    assert(register1->add_metr(30, 40));
    assert(register1->add_metr(35, 45));
    assert(register1->add_metr(40, 50));
    assert(register1->add_metr(45, 55));
    assert(register1->add_metr(50, 60));
    assert(register1->add_metr(55, 65));

    MeticRegister* register2 = MeticRegister::getInstance();
    assert(register1 == register2);
    assert(register2->show_metr());
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}