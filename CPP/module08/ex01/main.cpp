#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "----------MY TEST----------\n" << std::endl;
    try {
        Span s(2);

        s.addNumber(3);
        s.addNumber(5);
        s.addNumber(7);
        
        std::cout << s.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n" << std::endl;
    }
    try {
        Span s1(1);

        s1.addNumber(2);
        std::cout << s1.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n" <<std::endl;
    }

    std::vector <int> v1;

    srand(time(0));
    for (int i = 0; i < 10000; ++i) {
        v1.push_back(rand() % 25000);
    }
    try {
        Span s2(10000);

        s2.addNumber(v1.begin(), v1.end());
        std::cout << s2.longestSpan() << std::endl;
        std::cout << s2.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }




    std::cout << "----------SUBJECT TEST----------\n" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}