#include <iostream>
#include <map>

class MeticRegister {
private:
    std::map<int, std::pair<int, int>> metrics; // ассоциативный массив для хранения метрик
    static MeticRegister* instance; // указатель на единственный экземпляр класса

    MeticRegister() {} // приватный конструктор
    ~MeticRegister() {} // приватный деструктор

    // приватные методы копирования и присваивания
    MeticRegister(const MeticRegister&);
    const MeticRegister& operator=(const MeticRegister&);

    bool add_metr(int resp_t, int wait_t) { // метод для добавления метрики
        int key = time(nullptr); // текущее время в качестве ключа
        std::pair<int, int> val = std::make_pair(resp_t, wait_t); // время отклика и время ожидания как значение
        metrics[key] = val; // сохранение в ассоциативном массиве
        return true;
    }

public:
    static MeticRegister* getInstance() { // метод для получения единственного экземпляра класса
        if (!instance) {
            instance = new MeticRegister();
        }
        return instance;
    }
};
