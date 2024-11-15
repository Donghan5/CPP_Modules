#ifndef DOG_HPP
#define DOG_HPP
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &rightSide);
		~Dog();

		using	Animal::operator=;
		void	makeSound(void) const;
};

#endif
