/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:13:31 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:13:32 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	constructor
*/
Zombie::Zombie(void) {

}

/*
	deconstructor
*/
Zombie::~Zombie() {
	std::cout << "Zombie: " << this->_name << " has been destroyed" << std::endl;
}

/*
	basic function
*/
void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::makeZombie(std::string name) {
	this->_name = name;
}
