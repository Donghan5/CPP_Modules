/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:00 by donghank          #+#    #+#             */
/*   Updated: 2025/01/11 01:00:41 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once

#include <iostream>

/*
	template class
*/
template < typename T >
class Array {
	private:
		T	*_arr;
		unsigned int	_size;

	public:
		Array(): _arr( new T() ), _size(0) {};
		Array(unsigned int n): _arr( new T[n] ), _size(n) {};
		Array(const Array &rhs): _arr( new T[rhs.size()]), _size(rhs.size()) {
			for (unsigned int i(0); i < this->_size; i++) {
				this->_arr[i] = rhs._arr[i];
			}
		};

		~Array() { delete [] _arr; };

		Array	&operator=(const Array &rhs) {
			if (this != &rhs) {
				T *tempArr = new T[rhs._size];
				for (unsigned int i (0); i < rhs._size; i++) {
					tempArr[i] = rhs._arr[i];
				}
				delete[] _arr;
				_arr = tempArr;
				_size = rhs._size;
			}
			return *this;
		}

		T	&operator[](unsigned int i) const;
		unsigned int	size(void) const { return this->_size; };

		// Exception
		class OutOfBoundException: public std::exception {
			public:
				virtual const char *what() const throw() { return "Index is out of bound"; }
		};
};

#endif
