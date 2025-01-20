/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:01 by donghank          #+#    #+#             */
/*   Updated: 2025/01/20 00:53:38 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define RED "\033[31m"
#define END "\033[0m"

/*
	to check the validity input
	@param line --> argument line
	@return
		false --> invalid
		value (int)
*/
bool	PmergeMe::validateInput(std::string line) {
	char	*endPtr = NULL;
	double value = std::strtod(line.c_str(), &endPtr);
	if (value == 0.0 && !std::isdigit(line[0])) return false;
	if (*endPtr && str::strcmp(endPtr, "f") != 0) return false;
	return (value == static_cast<int>(value));
}

// constructor
PmergeMe::PmergeMe(int argCount, std::string argLine): _argCount(argCount), _argLine(argLine) {
	// 1. validate input with argLine
	// 2. stock Input
}

/*
	stock all element
	@param
		argCount: amount of the number
		value
*/
void	PmergeMe::stockInput(int argCount, int value) {
	std::deque<int> inputDeque;
	std::list<int> inputList;

	for (int i (0); i < argCount; i++) {
		if (value <= 0) {
			std::cout << RED << "Error: Invalid input value: " << value << " :only postive value allowed" << END << std::endl;
			exit(1);
		}
	}
}
