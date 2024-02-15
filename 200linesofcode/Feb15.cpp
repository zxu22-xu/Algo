// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Some applications on vectors

#include <iostream>
#include <vector>
#include <algorithm>

//a C++ grid class from the original CS106L class reader 
template <typename T> class grid {
public:
    grid();
    grid(size_t rows, size_t columns);
    
    void clear();
    void resize(size_t rows, size_t columns);

    size_t numRows() const;
    size_t numCols() const;

    bool empty() const;
    size_t size() const;

    T& getAt(size_t row, size_t column);
    const T& getAt(size_t row, size_t column) const;

private:
    vector<T> elems;
    size_t rows;
    size_t columns;

};

template <typename T> grid<T>::grid() : rows(0), columns(0) {}

template <typename T> grid<T>::grid(size_t rows, size_t columns) : elems(rows*columns), rows(rows), columns(columns{}
    
template <typename T> void grid<T>::clear() { resize(0, 0); }

int main()
{
    float f = 80000023, e[16];
    double d;
    d = 80000023;
    int loopI = 0;

    for (int j = 0; loopI < 3; loopI++, j = j - 5) {
        int res = loopI * j;
        f += loopI;
        d += loopI;
        e[5] += j;
        printf("%d", res);
    }

    printf("\n %d %10.1f %10.1f %10.5f \n", loopI, f, d, e[5]);

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
