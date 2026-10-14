#ifndef SOURCES_TRIANGLEBYPOINTS_H
#define SOURCES_TRIANGLEBYPOINTS_H

#include "Triangle.h"

struct Point {
	double x = 0, y = 0;
};

class TriangleByPoints : public Triangle {
public:
	TriangleByPoints(Point A, Point B, Point C)
			: Triangle(distance(B, C), distance(A, C), distance(A, B)) {
		double twiceArea = fabs(
			(B.x - A.x) * (C.y - A.y) -
			(B.y - A.y) * (C.x - A.x));

		if (twiceArea < 1e-12)
			throw std::invalid_argument("Collinear vertices");
	}

protected:
	static double distance(const Point &a, const Point &b) {
		return hypot(a.x - b.x, a.y - b.y);
	}
};

#endif //SOURCES_TRIANGLEBYPOINTS_H