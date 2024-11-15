#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &rightSide);
		~WrongCat();

		using	WrongAnimal::operator=;
		void	makeSound(void) const;
};

#endif
