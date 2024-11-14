#ifndef CAT_HPP
#define CAT_HPP
#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(const Cat &rightSide);
		~Cat();

		using	Animal::operator=;
		void	makeSound(void) const;
};

#endif
