#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    PmergeMe merge;

    if(ac < 3)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    merge.start(ac, av);
    merge.process();
    return (0);
}