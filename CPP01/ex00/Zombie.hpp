# ifndef ZOMBIE_HPP
#  define ZOMBIE_HPP

# pragma once
/* standard header file */
#include <iostream>

/* define class */
class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		Zombie	*newZombie(std::string name);
		void	ramdomChump(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

# endif
