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

		// comparison operators
		bool	operator>(const Fixed &rightSide) const;
		bool	operator<(const Fixed &rightSide) const;
		bool	operator>=(const Fixed &rightSide) const;
		bool	operator<=(const Fixed &rightSide) const;
		bool	operator==(const Fixed &rightSide) const;
		bool	operator!=(const Fixed &rightSide) const;

		// arithmetic operators
		Fixed	operator+(const Fixed &rightSide) const;
		Fixed	operator-(const Fixed &rightSide) const;
		Fixed	operator*(const Fixed &rightSide) const;
		Fixed	operator/(const Fixed &rightSide) const;

		// prefix increment, decrement postfix increment, decrement
		/*
			Prefix operator: Increments or decrements the value
				then returns the updated object itself.
			Postfix operator: Returns a copy of the object
				before incrementing or decrementing its value.
		*/
		Fixed	&operator++(void); //prefix
		Fixed	operator++(int); //postfix
		Fixed	&operator--(void); //prefx
		Fixed	operator--(int); //postfix

		//min max functions
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		/*
			static function --> it's possible to call without call object
			When calling --> ClassName::StaticFunction
		*/

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
