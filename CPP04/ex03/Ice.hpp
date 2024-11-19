#ifndef ICE_HPP
#define ICE_HPP
#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(const Ice &rightSide);
		~Ice();

		const Ice	&operator=(const Ice &rightSide);
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif
