/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:14:31 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 21:13:41 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*
	Constructor
	set the type of the weapon
*/
Weapon::Weapon(std::string type) {
	this->setType(type);
}

/*
	Destructor
*/
Weapon::~Weapon() {

}

/*
	to get the type of the weapon
*/
const std::string&	Weapon::getType() {
	return (this->type);
}

/*
	setting the type of the weapon
*/
void	Weapon::setType(std::string newType) {
	this->type = newType;
}
