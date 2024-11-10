#ifndef POINT_HPP
#define POINT_HPP
#pragma once

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		~Point();

		Point	&operator=(const Point &rightSide);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
