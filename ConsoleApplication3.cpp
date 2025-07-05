#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <locale>
#include <string>
#include <sstream>
#include "smart_ptr.h"
#include "loadtest.h"
#include "funktest.h"

int main()
{
    std::vector<SmartPtr<int>> smartPtrVector {};
    setlocale(LC_ALL, "ru_RU");
    while (true)
    {
        short var{};
        std::cout << "1. Функциональное тестирование указателя" << std::endl;
        std::cout << "2. Нагрузочное тестирование укащателя" << std::endl;
        std::cout << "3. Добавить SmartPtr в вектор" << std::endl;
        std::cout << "4. Удалить SmartPtr из вектора" << std::endl;
        std::cout << "5. Копировать существующий SmartPtr" << std::endl;
        std::cout << "6. Вывести элементы вектора" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::string line;
        while (std::getline(std::cin, line))
        {
            std::stringstream ss(line);
            if (ss >> var)
            {
                if (ss.eof())
                {   
                    break;
                }
                std::cout << "Ошибка! Введите корректное значение!" << std::endl;
            }
        }

        switch (var) {
        case 1:
        {
            std::cout << "" << std::endl;
            funkTest();
            std::cout << "OK!" << std::endl;
            std::cout << "" << std::endl;

        }
            break;
        case 2: 
        {
            std::cout << "" << std::endl;
            size_t it{};
            std::cout << "Введите количество итераций: ";
            std::cin >> it;
            loadTestCustomSmartPtr(it);
            loadTestStdSmartPtr(it);
            std::cout << "" << std::endl;
        }
            break;
        case 3:
        {
            std::cout << "" << std::endl;
            int value{};
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            smartPtrVector.push_back(SmartPtr<int>(new int(value)));
            std::cout << "" << std::endl;
        }
            break;
        case 4:
        {
            std::cout << "" << std::endl;
            while (true) {
                unsigned int index{};
                for (int i = 0; i < smartPtrVector.size(); i++) {
                    std::cout << i << ". " << *smartPtrVector.at(i) << std::endl;
                }
                std::cout << "Введите значение для удаления: ";
                std::cin >> index;
                if ((smartPtrVector.size() - 1) < index) {
                    std::cout << "Вы указали не верное значение!" << std::endl;
                    continue;
                }
                smartPtrVector.erase(smartPtrVector.begin() + index);
                break;
            }
            std::cout << "" << std::endl;
        }
            break;
        case 5:
        {
            std::cout << "" << std::endl;
            while (true) {
                unsigned int index{};
                for (int i = 0; i < smartPtrVector.size(); i++) {
                    std::cout << i << ". " << *smartPtrVector.at(i) << std::endl;
                }
                std::cout << "Введите значение для копирования: ";
                std::cin >> index;
                if ((smartPtrVector.size() - 1) < index) {
                    std::cout << "Вы указали не верное значение!" << std::endl;
                    continue;
                }
                SmartPtr<int> newPtr(smartPtrVector[index]);
                smartPtrVector.push_back(newPtr);
                break;
            }
            std::cout << "" << std::endl;
        }
            break;
        case 6: 
        {
            std::cout << "" << std::endl;
            for (int i = 0; i < smartPtrVector.size(); i++) {
                std::cout << i << ". " << *smartPtrVector.at(i) << std::endl;
            }
            std::cout << "" << std::endl;
        }
            break;
        case 0:
        {
            return 0;
        }           
            break;
        default: std::cout << "Ошибка! Введите корректное значение!" << std::endl;
        }
    }
    return 0;
}
