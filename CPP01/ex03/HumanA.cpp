/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:14:07 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:14:08 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
	Weapon is reference, so it possible to init in list
*/
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {

}

HumanA::~HumanA() {

}

void	HumanA::attack(void) const {
	if (this->_weapon.getType() != "") {
		std::cout << _name << " attack with their " << _weapon.getType() << std::endl;
	}
	else
		std::cout << _name << " doesn't have a weapon to attack " << std::endl;
}
