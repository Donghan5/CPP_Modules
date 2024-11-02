/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:41:03 by donghank          #+#    #+#             */
/*   Updated: 2024/11/02 16:07:57 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
	getter part
*/
const std::string&	Contact::getFirstname() const {
	return (this->firstname);
}

const std::string&	Contact::getLastname() const {
	return (this->lastname);
}

const std::string&	Contact::getNickname() const {
	return (this->nickname);
}

const std::string&	Contact::getSecret() const {
	return (this->secret);
}

const std::string&	Contact::getNumber() const {
	return (this->number);
}

/*
	setter part
*/
void	Contact::setFirstname(std::string firstname) {
	this->firstname = firstname;
}

void	Contact::setLastname(std::string lastname) {
	this->lastname = lastname;
}

void	Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void	Contact::setSecret(std::string secret) {
	this->secret = secret;
}

void	Contact::setNumber(std::string number) {
	this->number = number;
}
