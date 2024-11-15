#ifndef CAT_HPP
#define CAT_HPP
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &rightSide);
		~Cat();

		using	Animal::operator=;
		void	makeSound(void) const;
};

#endif
