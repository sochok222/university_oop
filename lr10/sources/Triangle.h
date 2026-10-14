#ifndef SOURCES_TRIANGLE_H
#define SOURCES_TRIANGLE_H

#include <cmath>
#include <stdexcept>

class Triangle {
public:
	virtual ~Triangle() = default;
	Triangle(double a, double b, double c, bool medians = false) {
		if (medians) {
			_sideA = sideFromMedians(a, b, c);
			_sideB = sideFromMedians(b, a, c);
			_sideC = sideFromMedians(c, a, b);

			if (not validSides(_sideA, _sideB, _sideC))
				throw std::invalid_argument("Invalid triangle sides");
			return;
		}

		if (not validSides(a, b, c))
			throw std::invalid_argument("Invalid triangle sides");
		_sideA = a;
		_sideB = b;
		_sideC = c;
	}

	virtual inline double sideA() const
	{ return _sideA; }
	virtual inline double sideB() const
	{ return _sideB; }
	virtual inline double sideC() const
	{ return _sideC; }

	enum class Side {
		A, B, C
	};

	double median(Side side) const;
	double midline(Side side) const;

	virtual inline double inradius() const {
		double p = (_sideA + _sideB + _sideC) / 2;
		return area() / p;
	}

	virtual inline double circumradius() const {
		return _sideA * _sideB * _sideC / (4 * area());
	}

	double area() const {
		double p = (_sideA + _sideB + _sideC) / 2;
		return sqrt(p * (p - _sideA) * (p - _sideB) * (p - _sideC));
	}

protected:
	double _sideA = 0;
	double _sideB = 0;
	double _sideC = 0;

	static double sideFromMedians(double ma, double mb, double mc) {
		return (2.0 / 3.0) *
			sqrt(2 * mb * mb + 2 * mc * mc - ma * ma);
	}

	static bool validSides(double a, double b, double c) {
		return a > 0 && b > 0 && c > 0 &&
			   a + b > c && a + c > b && b + c > a;
	}

	static double medianLength(double side, double other1, double other2) {
		return 0.5 * sqrt(2 * other1 * other1 +
						  2 * other2 * other2 -
						  side * side);
	}
};

#endif //SOURCES_TRIANGLE_H