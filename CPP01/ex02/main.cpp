/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:14:02 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:14:03 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
	reference == alias
*/
int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str: " << str << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "&str: " << &str << std::endl;
	std::cout << "&stringREF: " << &stringREF << std::endl;

	std::cout << "----------- Just to check ------------" << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}
