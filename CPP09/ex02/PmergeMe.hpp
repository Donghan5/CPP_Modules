/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:04 by donghank          #+#    #+#             */
/*   Updated: 2025/01/20 00:47:18 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#pragma once

#include <iostream>
#include <sstream>
#include <deque>
#include <list>

class PmergeMe {
	private:
		std::string	_argLine;
		int	_argCount;
		PmergeMe();

		// default function to stock the values
		void validateInput(std::string argLine);
		void stockInput(int argCount, int value);

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

		void	showResults(void);

};

#endif
