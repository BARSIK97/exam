#pragma once

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <map>

class MeticRegister {
private:
    std::map<int, std::pair<int, int>> metrics; // ассоциативный массив дл€ хранени€ метрик
    static MeticRegister* instance; // указатель на единственный экземпл€р класса

    MeticRegister() {} // приватный конструктор
    ~MeticRegister() {} // приватный деструктор

    // приватные методы копировани€ и присваивани€
    MeticRegister(const MeticRegister&);
    const MeticRegister& operator=(const MeticRegister&);

public:
    static MeticRegister* getInstance() { // метод дл€ получени€ единственного экземпл€ра класса
        if (!instance) {
            instance = new MeticRegister();
        }
        return instance;
    }
public:
    int get_first_key() const { // публичный метод дл€ получени€ первого ключа
        if (!metrics.empty()) { // если ассоциативный массив не пустой
            return metrics.begin()->first;
        }
        return 0;
    }
    bool add_metr(int resp_t, int wait_t) { // метод дл€ добавлени€ метрики
        int key = time(nullptr); // текущее врем€ в качестве ключа
        std::pair<int, int> val = std::make_pair(resp_t, wait_t); // врем€ отклика и врем€ ожидани€ как значение
        metrics[key] = val; // сохранение в ассоциативном массиве
        return true;
    }

    bool show_metr() { // метод дл€ вывода метрик на экран
        for (auto& metric : metrics) {
            std::cout << "Key: " << metric.first << "; Response time: " << metric.second.first << "; Wait time: " << metric.second.second << std::endl;
        }
        return true;
    }

    int count_cometr(int key) { // метод дл€ вычислени€ вспомогательной метрики
        if (metrics.count(key)) { // если ключ присутствует в ассоциативном массиве
            auto& val = metrics[key];
            return val.first + val.second; // сумма времени отклика и времени ожидани€
        }
        return 0;
    }
};

MeticRegister* MeticRegister::instance = nullptr; // инициализаци€ указател€ на экземпл€р класса
#endif // SINGLETON_H
