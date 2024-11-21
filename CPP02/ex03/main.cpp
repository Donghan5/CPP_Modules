/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:16:18 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:16:19 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
	test cases
	a(0, 0), b(10, 30), c(30, 30)
	p (20, 10) ==> outside
	p (10, 10) ==> inside
*/
int	main(void) {
	if (bsp(Point(0, 0), Point(10, 30), Point(30, 30), Point(10, 10))) {
		std::cout << "Point is inside of triangle" << std::endl;
	}
	else {
		std::cout << "Point is outside of triangle" << std::endl;
	}
	return (0);
}
