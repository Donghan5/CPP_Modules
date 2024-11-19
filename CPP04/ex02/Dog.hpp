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

		Animal	&operator=(const Animal &rightSide);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif
