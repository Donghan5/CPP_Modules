/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:55:26 by donghank          #+#    #+#             */
/*   Updated: 2024/11/01 22:53:48 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

/*
	to verify input number value (phone number)
	@param : number --> phone number
	@return : there is 1 if not 0
*/
static int	is_valid_number(std::string number) {
	int	i = 0;
	while (number[i]) {
		if (number[i] == ' ') {
			i++;
			continue ;
		}
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv) {
	PhoneBook	phonebook;
	std::string	data[5];
	std::string	input;
	int			index;

	while (1) {
		if (input == ADD)

		else if (input == SEARCH)

		else if (input == EXIT)

	}


}
