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
    class MeticRegisterTest {
    public:
        void AddMetricTest() {
            MeticRegister* reg = MeticRegister::getInstance();

            if (reg->add_metr(300, 200)) {
                if (reg->add_metr(200, 100)) {
                    if (reg->add_metr(500, 150)) {
                        if (reg->add_metr(400, 250)) {
                            if (reg->add_metr(100, 50)) {
                                if (reg->add_metr(350, 300)) {
                                    if (reg->add_metr(250, 200)) {
                                        if (reg->add_metr(150, 100)) {
                                            if (reg->add_metr(450, 400)) {
                                                if (reg->add_metr(550, 500)) {
                                                    // проверяем, что добавились все метрики
                                                    if (reg->metrics.size() == 10) {
                                                        std::cout << "All metrics were added successfully" << std::endl;
                                                    }
                                                    else {
                                                        std::cout << "Incorrect number of metrics" << std::endl;
                                                    }
                                                }
                                                else {
                                                    std::cout << "Failed to add metric 10" << std::endl;
                                                }
                                            }
                                            else {
                                                std::cout << "Failed to add metric 9" << std::endl;
                                            }
                                        }
                                        else {
                                            std::cout << "Failed to add metric 8" << std::endl;
                                        }
                                    }
                                    else {
                                        std::cout << "Failed to add metric 7" << std::endl;
                                    }
                                }
                                else {
                                    std::cout << "Failed to add metric 6" << std::endl;
                                }
                            }
                            else {
                                std::cout << "Failed to add metric 5" << std::endl;
                            }
                        }
                        else {
                            std::cout << "Failed to add metric 4" << std::endl;
                        }
                    }
                    else {
                        std::cout << "Failed to add metric 3" << std::endl;
                    }
                }
                else {
                    std::cout << "Failed to add metric 2" << std::endl;
                }
            }
            else {
                std::cout << "Failed to add metric 1" << std::endl;
            }
        }
    };
};
