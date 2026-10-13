#ifndef LR8_DATE_H
#define LR8_DATE_H

#include "triad.h"

class Date : public Triad {
public:
	Date() = delete;
	explicit Date(long year, long month, long day) : Triad(year, month, day) {}

	void setDate(long year, long month, long day)
	{
		_first = year;
		_second = month;
		_third = day;
	}
};


#endif //LR8_DATE_H