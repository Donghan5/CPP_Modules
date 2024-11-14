#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string &name);
		FragTrap(const FragTrap &rightSide);
		FragTrap	&operator=(const FragTrap &rightSide);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFiveGuys(void);
};
#endif
