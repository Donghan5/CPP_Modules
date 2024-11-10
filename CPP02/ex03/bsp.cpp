#include "Point.hpp"

/*
	Concept: Verifying if a point lies inside a triangle.
			Using Cross Product
	Approach:
	- Divide the triangle (ABC) into three smaller triangles using the new point (P): ABP, ACP, and BCP.
	- Check if the total area of the original triangle (ABC) equals the sum of the areas of the three smaller triangles (ABP + ACP + BCP).
	- If the areas match, the point (P) lies inside the triangle.

	Example:
	- Triangle ABC:
		A(0, 0), B(5, 0), C(0, 5)
	- Point P:
		P(1, 1)

	Calculation:
	- Area of ABC: Total area of triangle with vertices A, B, C
	- Area of ABP: Triangle formed by A, B, and P
	- Area of ACP: Triangle formed by A, C, and P
	- Area of BCP: Triangle formed by B, C, and P
	- Verify: If (Area of ABP + Area of ACP + Area of BCP == Area of ABC), then P is inside the triangle.
	- resume : |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
	Visual Representation:
		  C
		  |\
		  | \
		  |  \
		  |   \
		  |    \
		  A------B
		    (P)
*/

static Fixed	myAbs(Fixed x) {
	if (x < Fixed(0))
		return x * Fixed(-1);
	return (x);
}

static Fixed	verifyArea(Point const a, Point const b, Point const c) {
	float	area;

	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) \
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) \
			+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abc = myAbs(verifyArea(a, b, c));
	Fixed	abp = myAbs(verifyArea(a, b, point));
	Fixed	acp = myAbs(verifyArea(a, c, point));
	Fixed	bcp = myAbs(verifyArea(b, c, point));

	return (abc == (abp + acp + bcp));
}
