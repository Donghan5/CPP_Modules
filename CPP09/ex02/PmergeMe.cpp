/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:01 by donghank          #+#    #+#             */
/*   Updated: 2025/01/20 13:10:50 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define RED "\033[31m"
#define END "\033[0m"


const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Error: Invalid input";
}

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
PmergeMe::PmergeMe(int argCount, std::string argLine): _argCount(argCount), _argLine(argLine) {}

/*
	stock all element
	@param
		argCount: amount of the number
		value
*/
void	PmergeMe::stockInput(int argCount, std::string argLine) {
	int value = this->validateInput(argLine);
	if (value == false) throw PmergeMe::InvalidInputException();
	for (int i (0); i < argCount; i++) {
		if (value <= 0) {
			std::cout << RED << "Error: Invalid input value: " << value << " :only postive value allowed" << END << std::endl;
			exit(1);
		}
		this->inputDeque.push_back(value);
		this->inputList.push_back(value);
	}
}


// sorting algo

/*
	@param arr: deque array of element which from argument line
*/
void	PmergeMe::sortDequeValues(std::deque<int> &arr) {
	std::deque<int>::iterator it1, it2;

	for (it1 = arr.begin() + 1; it != arr.end(); ++it1) {
		int tmp = *it1; // store currently position
		it2 = it1;
		while (it2 != arr.begin() && *(std::prev(it2))) {
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = tmp;
	}
}

/*
	@param arr: list array of element which from argument line
*/
void	PmergeMe::sortListValues(std::list<int> &arr) {
	std::list<int>::iterator it1, it2;

	for (it1 != arr.begin() + 1; it != arr.end(); ++it1) {
		int tmp = *it1;
		it2 = it1;
		while (it2 != arr.begin() && *(std::prev(it2))) {
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = tmp;
	}
}

void	PmergeMe::showResults(int argCount, std::deque<int> inputDeque, std::list<int> inputList) {
	std::cout << "Before: ";
	display(inputDeque);
	clock_t beforeDeque = clock();
	this->sortDequeValues(inputDeque);
	clock_t afterDeque = clock();
	double timeDeque = static_cast<double>(afterDeque - beforeDeque) / CLOCKS_PER_SEC * 1000;

	clock_t beforeList = clock();
	this->sortListValues(inputList);
	clock_t afterDeque = clock();
	double timeList = static_cast<double>(afterList - beforeList) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	display(inputDeque);
	std::cout << "Time to process a range of " << argCount << " element with std::deque: " << timeDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << argCount << " element with std::list: " << timeList << " us" << std::endl;
}

void	PmergeMe::play(int argCount, std::string argLine) {
	try {
		stockInput(argCount, argLine);
		showResults(argCount, this->inputDeque, this->inputList);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
