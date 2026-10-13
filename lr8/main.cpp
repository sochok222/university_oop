#include <iostream>
#include "date.h"

int main()
{
	Date a(2025, 5, 15);
	Date b(2025, 5, 15);
	Date c(2024, 12, 31);

	std::cout << std::boolalpha;

	std::cout << (a == b) << '\n';
	std::cout << (c < a) << '\n';
	std::cout << (a > c) << '\n';

	a.setDate(2023, 1, 1);
	std::cout << (a < b) << '\n';

	return 0;

	return 0;
}