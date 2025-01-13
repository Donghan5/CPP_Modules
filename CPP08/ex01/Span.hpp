/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:06:19 by donghank          #+#    #+#             */
/*   Updated: 2025/01/12 23:58:38 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

/*
	Why I chose the vector?
		- Dynamic array that can grow or shrink the size --> it depends on the N value
		= Provide random acccess --> to search shortestSpan and longest Span
		- Efficient for squential insetion/removal data
*/
class Span {
	private:
		unsigned int _N;
		std::vector<int> storage;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &rhs);
		~Span();

		Span &operator=(const Span &rhs);

		void addNumber(void);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		//Exception
		class alreadyExistException: public std::exception {
			public:
				virtual const char *what() const throw { return "Element already exist"; }
		};

		class notFoundException: public std::exception {
			public:
				virtual const char *what() const throw { return "Element Not Found"; }
		};

		// shoule I need it ?
		class noSpanException: public std::exception {
			public:
				virtual const char *what() const throw { return "There's no span"; }
		};
};

#endif
