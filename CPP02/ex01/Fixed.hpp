#ifndef FIXED_HPP
#define FIXED_HPP
#pragma once

// standard lib(stream)
#include <iostream>
#include <string>
#include <cmath>

// define the class
class Fixed {
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		/*
			think *this (actuall status of object)
		*/
		Fixed(const Fixed &rightSide); // copy constructor
		Fixed &operator=(const Fixed &rightSide); // A copy assignment operator overload.
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
