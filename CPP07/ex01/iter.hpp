/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:35:23 by donghank          #+#    #+#             */
/*   Updated: 2025/01/10 14:41:50 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#pragma once

#include <iostream>

/*
	template function
*/
template < typename T >
void	iter(T *arr, size_t size, void(*f)(T &)) {
	for (size_t i = 0; i < size; i++) {
		f(arr[i]);
	}
}

template< typename T>
void	printA(T &i) {
	std::cout << i << std::endl;
}

#endif
