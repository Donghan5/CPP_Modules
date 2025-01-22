/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:04 by donghank          #+#    #+#             */
/*   Updated: 2025/01/21 23:56:06 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#pragma once

#include <iostream>
#include <sstream>
#include <deque>
#include <list>
#include <cstdlib>

class PmergeMe {
	private:
		std::string	_argLine;
		int	_argCount;
		std::deque<int>	inputDeque;
		std::list<int>	inputList;
		PmergeMe();

		// default function to stock the values
		void validateInput(std::string argLine);
		void stockInput(int argCount, std::string argLine);

	public:
		PmergeMe(int argCount, std::string argLine);
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		// to show the element which stock in container
		// to show deque and list
		template < typename T >
		void	display(const T &container) {
			typename T::const_iterator it;
			for (it = container.begin(); it != container.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl; // add the new line
		}

		// sorting algorithms
		void	sortDequeValues(std::deque<int> &arr);
		void	sortListValues(std::list<int> &arr);

		void	showResults(int argCount, std::deque<int> inputDeque, std::list<int> inputList);

		void	play(int argc, char **argv);
		// Exception
		class InvalidInputException: public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
