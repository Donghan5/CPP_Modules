#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &rightSide);
		WrongAnimal	&operator=(const WrongAnimal &rightSide);
		~WrongAnimal();

		void				makeSound(void) const;
		const std::string	&getType(void) const;
		void				setType(const std::string &type);
};

#endif
