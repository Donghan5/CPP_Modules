#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include "ICharacter.hpp"

class AMateria; // forward declaration

class Character: public ICharacter {
	protected:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &rightSide);
		~Character();

		Character	&operator=(const Character &rightSide);
		std::string const	&getName(void) const;
		void				setName(const std::string &name);
		virtual void		equip(AMateria *m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter &target);
};

#endif
