#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter {
	protected:
		std::string	_name;
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &rightSide);
		~Character();

		Character	&operator=(const Character &rightSide);
		std::string const	&getName(void) const;
		void				setName(const std::string &name);
		virtual void		equipe(AMateria *m);
		virtual void		unequipe(in idx);
		virtual void		use(int idx, ICharacter &target);
		int					inInventory(AMateria *m);
};

#endif
