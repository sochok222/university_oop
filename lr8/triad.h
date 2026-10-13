#ifndef LR8_TRIAD_H
#define LR8_TRIAD_H


class Triad {
public:
	Triad(long first, long second, long third) :
	_first(first), _second(second), _third(third) {}

	// Operators are better than methods
	inline bool operator==(const Triad &other) const
	{
		return _first == other._first and
		_second == other._second and
		_third == other._third;

	}
	inline bool operator<(const Triad &other) const
	{
		if (_first != other._first)
			return _first < other._first;

		if (_second != other._second)
			return _second < other._second;

		return _third < other._third;
	}
	inline bool operator>(const Triad &other) const
	{
		if (_first != other._first)
			return _first > other._first;

		if (_second != other._second)
			return _second > other._second;

		return _third > other._third;
	}

protected:
	long _first = 0;
	long _second = 0;
	long _third = 0;
};


#endif //LR8_TRIAD_H