#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

/*
	Pure virtual function --> have to implement in the child class (inheritance)
	declare as: virtual type	NameOfFunction(parameter) const = 0;
	We call the class which contain pure virtual function as abstract class
	to utilise in child class for the polymorphism --> must to declare --> virtual
*/
class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		// const --> use read-only
		Animal(const std::string &type);
		Animal(const Animal &rightSide);
		virtual Animal	&operator=(const Animal &rightSide);
		virtual ~Animal();

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const;
		// have to mod the member
		void				setType(const std::string &type);
		// Pure virtual function
		virtual Brain		*getBrain(void) const = 0;
};

#endif
