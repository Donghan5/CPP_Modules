# ifndef HUMANA_HPP
#  define HUMANA_HPP

# pragma once
#include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;
		HumanA();

	public:
		HumanA(std::string _name, Weapon &_weapon);
		~HumanA();

	void	attack(void) const;

};

# endif
