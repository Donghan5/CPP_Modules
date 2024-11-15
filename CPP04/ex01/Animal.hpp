#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		// const --> use read-only
		Animal(const std::string &type);
		Animal(const Animal &rightSide);
		Animal	&operator=(const Animal &rightSide);
		virtual ~Animal();

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const;
		// have to mod the member
		void				setType(const std::string &type);
};

#endif
