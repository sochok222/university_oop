#ifndef SOURCES_TRIANGLEBYSIDES_H
#define SOURCES_TRIANGLEBYSIDES_H

#include "Triangle.h"

class TriangleBySides : public Triangle {
public:
	TriangleBySides() = delete;
	explicit TriangleBySides(double a, double b, double c) : Triangle(a, b, c) {}
};

#endif //SOURCES_TRIANGLEBYSIDES_H