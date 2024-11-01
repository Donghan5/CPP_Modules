/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:02:19 by donghank          #+#    #+#             */
/*   Updated: 2024/11/01 14:43:25 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	print the strings and alignment right
*/
void	print_strs(std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		for (int j = 0; j < 10 - str.length() ; j++)
			std::cout << " ";
		std::cout << str;
	}
}

/*
	to calculate the size
*/
int	PhoneBook::get_size() const {
	return (this->size);
}

/*
	add the contact data[0] --> data[5]
	each data is represent firstname lastname nickname secret and phone number
*/
void	PhoneBook::add_contact(std::string data[5]) {
	int	index;

	index = this->index;
	this->contacts[index].set_firstname(data[0]);
	this->contacts[index].set_lastname(data[1]);
	this->contacts[index].set_nickname(data[2]);
	this->contacts[index].set_secret(data[3]);
	this->contacts[index].set_number(data[4]);
	this->index = (index + 1) % 8; // to sure the range 0 to 7
	if (this->size < 8)
		this->size++;
}

/*
	to disply the contact
*/
void	PhoneBook::display_contact(int i) const {
	std::cout << "This is for the specified contact" << std::endl;

	std::cout << "First Name: " << this->contacts[i].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[i].get_lastname() << std::endl;
	std::cout << "Nick Name: " << this->contacts[i].get_nickname() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i].get_secret() << std::endl;
	std::cout << "Phone Number: " << this->contacts[i].get_number() << std::endl;
}

/*
	to display the phonebook
*/
void	PhoneBook::display_phonebook() const {

}
