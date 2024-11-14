#ifndef DOG_HPP
#define DOG_HPP
#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(const Dog &rightSide);
		~Dog();

		using	Animal::operator=;
		void	makeSound(void) const;
};

#endif
