#include <iostream>
#include <singleton.h>
int main() {
    MeticRegister* reg = MeticRegister::getInstance();
    reg->add_metr(300, 200);
    reg->show_metr();

    // получаем первый ключ из ассоциативного массива метрик
    int first_key = reg->get_first_key();
    std::cout << "Cometr for key " << first_key << ": " << reg->count_cometr(first_key) << std::endl;

    return 0;
}
