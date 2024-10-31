/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:02:19 by donghank          #+#    #+#             */
/*   Updated: 2024/10/31 23:50:05 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	print the strings
*/
void	print_strs(std::string str)
{
	unsigned int	j = 0;

	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		
}
