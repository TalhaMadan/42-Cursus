#include "easyfind.hpp"

int main ()
{
    std::vector<int> vec1;

    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(7);
    vec1.push_back(4);
    vec1.push_back(8);

    int intArray[] = {1, 3, 5, 2, 7, 8, 11, 10};
    int evenArray[] = {2, 4, 6, 8, 10, 12, 14, 16};

    std::list<int> list1(evenArray, evenArray + (sizeof(evenArray) / sizeof(int)));
    std::vector<int> vec2(intArray, intArray + (sizeof(intArray) / sizeof(int)));

    std::cout << "___TEST-FOR-VEC1___" << std::endl;
    try {
        std::cout << *easyfind(vec1, 1) << std::endl;
        std::cout << *easyfind(vec1, 4) << std::endl;
        std::cout << *easyfind(vec1, 5) << std::endl;
        std::cout << *easyfind(vec1, 3) << std::endl;
        std::cout << *easyfind(vec1, 11) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "The value was not found in the container!" << std::endl;
    }

    std::cout << "___TEST-FOR-VEC2___" << std::endl;
    try {
        std::cout << *easyfind(vec2, 7) << std::endl;
        std::cout << *easyfind(vec2, 4) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "The value was not found in the container!" << std::endl;
    }

    std::cout << "___TEST-FOR-LIST1___" << std::endl;
    try {
        std::cout << *easyfind(list1, 8) << std::endl;
        std::cout << *easyfind(list1, 9) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "The value was not found in the container!" << std::endl;
    }
    return 0;
}