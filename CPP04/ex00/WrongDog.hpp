#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP
#pragma once

#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
	public:
		WrongDog();
		WrongDog(const WrongDog &rightSide);
		~WrongDog();

		using	WrongAnimal::operator=;
		void	makeSound(void) const;
};

#endif
