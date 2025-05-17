#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Funcs.hpp"

int main() {
	srand(time(0));
	Base* t1 = generate();
	Base* t2 = generate();
	Base* t3 = generate();

	std::cout << "t1* = "; identify(t1);
	std::cout << "t1& = "; identify(*t1);
	std::cout << std::endl;

	std::cout << "t2* = "; identify(t2);
	std::cout << "t2& = "; identify(*t2);
	std::cout << std::endl;

	std::cout << "t3* = "; identify(t3);
	std::cout << "t3& = "; identify(*t3);
	std::cout << std::endl;

	delete t1;
	delete t2;
	delete t3;
}