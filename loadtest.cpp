#include "loadtest.h"
#include <memory>

void loadTestCustomSmartPtr(size_t numObjects) {
    std::vector<SmartPtr<TestObject>> vPtrs;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < numObjects; ++i) {
        vPtrs.push_back(SmartPtr<TestObject>(new TestObject));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "�������� " << numObjects << " �������� � SmartPtr ������ " << duration.count() << " ������.\n";
}

void loadTestStdSmartPtr(size_t numObjects) {
    std::vector<std::shared_ptr<TestObject>> vPtrs;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < numObjects; ++i) {
        vPtrs.push_back(std::shared_ptr<TestObject>(new TestObject));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "�������� " << numObjects << " �������� � SharedPtr ������ " << duration.count() << " ������.\n";
}