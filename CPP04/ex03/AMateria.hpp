#ifndef AMETERIA_HPP
#define AMETERIA_HPP
#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string	_type;

	public:
		// AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &rightSide);
		virtual ~AMateria();

		AMateria			&operator=(const AMateria &rightSide);
		std::string const&	getType() const; //Returns the materia type
		void				setType(std::string type);
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target) = 0;
};
#endif
