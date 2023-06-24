#pragma once

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <map>

class MeticRegister {
private:
    std::map<int, std::pair<int, int>> metrics; // ������������� ������ ��� �������� ������
    static MeticRegister* instance; // ��������� �� ������������ ��������� ������

    MeticRegister() {} // ��������� �����������
    ~MeticRegister() {} // ��������� ����������

    // ��������� ������ ����������� � ������������
    MeticRegister(const MeticRegister&);
    const MeticRegister& operator=(const MeticRegister&);

public:
    static MeticRegister* getInstance() { // ����� ��� ��������� ������������� ���������� ������
        if (!instance) {
            instance = new MeticRegister();
        }
        return instance;
    }
public:
    int get_first_key() const { // ��������� ����� ��� ��������� ������� �����
        if (!metrics.empty()) { // ���� ������������� ������ �� ������
            return metrics.begin()->first;
        }
        return 0;
    }
    bool add_metr(int resp_t, int wait_t) { // ����� ��� ���������� �������
        int key = time(nullptr); // ������� ����� � �������� �����
        std::pair<int, int> val = std::make_pair(resp_t, wait_t); // ����� ������� � ����� �������� ��� ��������
        metrics[key] = val; // ���������� � ������������� �������
        return true;
    }

    bool show_metr() { // ����� ��� ������ ������ �� �����
        for (auto& metric : metrics) {
            std::cout << "Key: " << metric.first << "; Response time: " << metric.second.first << "; Wait time: " << metric.second.second << std::endl;
        }
        return true;
    }

    int count_cometr(int key) { // ����� ��� ���������� ��������������� �������
        if (metrics.count(key)) { // ���� ���� ������������ � ������������� �������
            auto& val = metrics[key];
            return val.first + val.second; // ����� ������� ������� � ������� ��������
        }
        return 0;
    }
};

MeticRegister* MeticRegister::instance = nullptr; // ������������� ��������� �� ��������� ������
#endif // SINGLETON_H
