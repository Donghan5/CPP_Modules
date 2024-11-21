/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:15:25 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:15:26 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#pragma once

// standard lib(stream)
#include <iostream>
#include <string>

// define the class
class Fixed {
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &rightSide); // copy constructor
		Fixed &operator = (const Fixed &rightSide); // A copy assignment operator overload.
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
