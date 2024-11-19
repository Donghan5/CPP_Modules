#ifndef CURE_HPP
#define CURE_HPP
#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(const Cure &rightSide);
		~Cure();

		Cure	&operator=(const Cure &rightSide);
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif
