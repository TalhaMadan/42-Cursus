#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        RPN n(av[1]);
        n.start();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}