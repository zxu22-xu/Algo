// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <utility>
#include <iostream>

class myObject {

private:
    size_t size_;
    int* data_;

public:
    myObject(size_t size) : size_(size), data_(new int[size]) {
        std::cout << "Constructor: Allocated memory for " << size_ << " integers" << std::endl;
    }

    myObject (myObject&& other) noexcept {
        std::cout << "Move constructor: moving resources from another object." << std::endl;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
    }

    //move assignment operator
    myObject& operator = (myObject&& other) noexcept {
        std::cout << "Move assignment operator: moving resources from another object." << std::endl;
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }

        return *this;
    }

    ~myObject() {
        delete[] data_;
        std::cout << "Destructor: deallocated memory." << std::endl;
    }
  
};

int main()
{
    myObject obj1(5);

    //using std::move to transfer ownership
    myObject obj2 = std::move(obj1);

    //using std::move assignment
    myObject obj3(3);
    obj3 = std::move(obj2);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
