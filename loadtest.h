#pragma once

#include "smart_ptr.h"
#include <cassert>
#include <vector>
#include <chrono>
#include <iostream>

class TestObject {
public:
    TestObject() {
    }
    ~TestObject() {
    }
};

void loadTestCustomSmartPtr(size_t numObjects);
void loadTestStdSmartPtr(size_t numObjects);