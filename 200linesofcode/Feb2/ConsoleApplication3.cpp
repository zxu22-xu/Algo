// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Some applications on vectors

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = { 5, 2, 8, 1, 3 };
    std::cout << "Vector Elements: " << std::endl;
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    //size and capacity
    std::cout << "Size: " << nums.size() << std::endl;
    std::cout << "Capacity: " << nums.size() << std::endl;

    //shows the different uses of push_back and insert
    nums.push_back(7);
    nums.insert(nums.begin() + 2, 4);

    //sorting
    std::sort(nums.begin(), nums.end());

    //displaying sorted vector
    std::cout << "Sorted vector: " << std::endl;
    for (const auto& num : nums) {
        std::cout << num << std::endl;
    }

    std::cout << std::endl;

    //erasing elements
    nums.erase(nums.begin() + 3);

    //displaying modified vector
    std::cout << "Modified vector: " << std::endl;
    for (const auto& num : nums) {
        std::cout << num << std::endl;
    }

    std::cout << std::endl;


    //clearning the vector
    nums.clear();
    std::cout << "Vector cleared. Size: " << nums.size() << std::endl;

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
