#include "iter.hpp"

template <typename T>
void print_element(const T &element) {
    std::cout << element << std::endl;
}

int main ()
{
    std::cout << "__Test_For_Integer__" << std::endl;
    int intTypeArray[] = {3, 7, 11, 15, 19};
    iter (intTypeArray, 5, print_element<int>);

    std::cout << "__Test_For_Double__" << std::endl;
    double doubleTypeArray[] = {3.7, 7.11, 11.15, 15.19, 19.3};
    iter (doubleTypeArray, 5, print_element<double>);

    std::cout << "__Test_For_String__" << std::endl;
    std::string stringTypeArray[] = {"zonguldak", "merkez", "cadde", "sokak", "ülke"};
    iter (stringTypeArray, 5, print_element<std::string>);

    return 0;
}