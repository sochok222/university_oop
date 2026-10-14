#ifndef LR10_RIGHTTRIANGLE_H
#define LR10_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b) :
	Triangle(a, b, hypot(a, b)) {}
};

#endif //LR10_RIGHTTRIANGLE_H