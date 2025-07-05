#include "funktest.h"

void funkTest()
{ 

    // ���� 1: �������� SmartPtr
    SmartPtr<int> ptr(new int(9));
    assert(ptr.getCopyCount() == 1);
    assert(*ptr == 9);

    // ���� 2: ����������� SmartPtr
    SmartPtr<int> ptr1(ptr);
    assert(ptr.getCopyCount() == 2);
    assert(ptr1.getCopyCount() == 2);
    assert(*ptr1 == 9);

    // ���� 3: ����������� SmartPtr
    SmartPtr<int> ptr2(std::move(ptr));
    assert(ptr.getCopyCount() == 0);
    assert(ptr2.getCopyCount() == 2);
    assert(*ptr2 == 9);

    // ���� 4: ������ � ��������� ����� �������� ->
    SmartPtr<std::string> strPtr(new std::string("Test"));
    assert(strPtr->compare("Test") == 0);

    // ���� 5: ����������� ����� �������� ������������
    SmartPtr<int> ptr3(new int(10));
    ptr3 = ptr2;
    assert(ptr3.getCopyCount() == 3);
    assert(ptr2.getCopyCount() == 3);

    // ���� 6: �������� �������������
    assert(*ptr2 == 9);
    assert(*ptr3 == 9);    
}
