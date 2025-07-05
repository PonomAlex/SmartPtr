#ifndef SMART_PTR_H
#define SMART_PTR_H
//#include <iostream>

#include <cstddef>

template <typename T>
class SmartPtr
{
public:
    SmartPtr(T* ptr = nullptr):ptr(ptr)
    {
        if(counter == nullptr)
            counter = new size_t(0);
        *counter = *counter + 1;
    }

    SmartPtr(const SmartPtr<T> &src)
    {
        counter = src.counter;
        *counter = *counter + 1;
        ptr = src.ptr;
    }

    SmartPtr(SmartPtr<T> &&src)
    {
        counter = src.counter;
        ptr = src.ptr;
        src.counter = 0;
        src.ptr = nullptr;
    }

    ~SmartPtr()
    {
        if(counter != nullptr)
        {
            --(*counter);
            if(!(*counter)){
                delete ptr;
                delete counter;
                ptr = nullptr;
            }
        }
    }

    SmartPtr<T>& operator=(const SmartPtr<T>& src)
    {
        counter = src.counter;
        *counter = *counter + 1;
        delete ptr;
        ptr = src.ptr;
        return *this; 
    }


    size_t getCopyCount()
    {
        if(counter != nullptr) /*Ни в каком случае не равен nullptr, проверка указывает ли на что-то реальное или не указывает ни на что*/
            return *counter;
        return 0;
    }

    T* operator->() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

private:
    size_t *counter{};
    T *ptr{};
};

#endif //SMART_PTR_H
