#include "funktest.h"

void funkTest()
{ 

    // Тест 1: Создание SmartPtr
    SmartPtr<int> ptr(new int(9));
    assert(ptr.getCopyCount() == 1);
    assert(*ptr == 9);

    // Тест 2: Копирование SmartPtr
    SmartPtr<int> ptr1(ptr);
    assert(ptr.getCopyCount() == 2);
    assert(ptr1.getCopyCount() == 2);
    assert(*ptr1 == 9);

    // Тест 3: Перемещение SmartPtr
    SmartPtr<int> ptr2(std::move(ptr));
    assert(ptr.getCopyCount() == 0);
    assert(ptr2.getCopyCount() == 2);
    assert(*ptr2 == 9);

    // Тест 4: Доступ к элементам через оператор ->
    SmartPtr<std::string> strPtr(new std::string("Test"));
    assert(strPtr->compare("Test") == 0);

    // Тест 5: Объединение через оператор присваивания
    SmartPtr<int> ptr3(new int(10));
    ptr3 = ptr2;
    assert(ptr3.getCopyCount() == 3);
    assert(ptr2.getCopyCount() == 3);

    // Тест 6: Операция разыменования
    assert(*ptr2 == 9);
    assert(*ptr3 == 9);    
}
