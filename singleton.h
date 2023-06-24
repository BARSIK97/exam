
#ifndef SINGLETON_H
#define SINGLETON_H

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

public:
    static MeticRegister* getInstance() { // метод для получения единственного экземпляра класса
        if (!instance) {
            instance = new MeticRegister();
        }
        return instance;
    }
public:
    int get_first_key() const { // публичный метод для получения первого ключа
        if (!metrics.empty()) { // если ассоциативный массив не пустой
            return metrics.begin()->first;
        }
        return 0;
    }
    bool add_metr(int resp_t, int wait_t) { // метод для добавления метрики
        int key = time(nullptr); // текущее время в качестве ключа
        std::pair<int, int> val = std::make_pair(resp_t, wait_t); // время отклика и время ожидания как значение
        metrics[key] = val; // сохранение в ассоциативном массиве
        return true;
    }

    bool show_metr() { // метод для вывода метрик на экран
        for (auto& metric : metrics) {
            std::cout << "Key: " << metric.first << "; Response time: " << metric.second.first << "; Wait time: " << metric.second.second << std::endl;
        }
        return true;
    }

    int count_cometr(int key) { // метод для вычисления вспомогательной метрики
        if (metrics.count(key)) { // если ключ присутствует в ассоциативном массиве
            auto& val = metrics[key];
            return val.first + val.second; // сумма времени отклика и времени ожидания
        }
        return 0;
    }
};

MeticRegister* MeticRegister::instance = nullptr; // инициализация указателя на экземпляр класса
#endif // SINGLETON_H
