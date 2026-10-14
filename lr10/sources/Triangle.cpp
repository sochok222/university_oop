#include "Triangle.h"

double Triangle::median(Side side) const
{
	switch (side) {
	case Side::A:
		return medianLength(_sideA, _sideB, _sideC);
	case Side::B:
		return medianLength(_sideB, _sideA, _sideC);
	case Side::C:
		return medianLength(_sideC, _sideA, _sideB);
	default:
		throw std::invalid_argument("Unknown side");
	}
}

double Triangle::midline(Side side) const
{
	switch (side) {
	case Side::A: return _sideA / 2;
	case Side::B: return _sideB / 2;
	case Side::C: return _sideC / 2;
	default:
		throw std::invalid_argument("Unknown side");
	}
}
