/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:04 by donghank          #+#    #+#             */
/*   Updated: 2025/02/04 12:22:07 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>


/*
	Using vector and list
	vector: easy to expand and treat big amount.
*/
// type definitions
typedef std::vector<int> int_vector;

template <typename Container>
class PmergeMe {
	public:
		// type definitions --> flexibility
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef std::pair <value_type, value_type> type_pair;
		typedef std::vector <type_pair> pair_vector;
	private:
		Container _data;
		value_type _last;
		double _time;

		int_vector	generateIndexes(size_t n);
		pair_vector generatePairs(Container &data);
		void		sortPairs(pair_vector &pairs);
		int			binarySearch(int target);
		int			ftStoa(const char *str);
		bool		isNum(const std::string &s);

	public:
		PmergeMe();
		explicit PmergeMe(char **data); // not to change instantly
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);


		// sorting algorithms
		void	sort();
		void	printData() const;
		void	timeTable() const;

		// Exception
		class InvalidInputException: public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
