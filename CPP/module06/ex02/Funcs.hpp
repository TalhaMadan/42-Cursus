#ifndef FUNCS_HPP
# define FUNCS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <exception>
#include <cstdlib>
#include <time.h>

Base	*generate(void);

void	identify(Base* p);
void	identify(Base& p);

#endif