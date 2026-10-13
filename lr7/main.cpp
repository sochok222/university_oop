#include <iostream>
#include <string>

class myException : std::invalid_argument {
public:
	myException() = delete;
	explicit myException(const char *what) : std::invalid_argument(what) {}

	// I can't imagine really valuable methods for this class
	const char *what() const noexcept override
	{ return std::invalid_argument::what(); }

private:
	int _val;
};

class myException1 : std::exception {};

class myException2 {
};

double funcNoThrow(double a, double b)
{
	return a / b;
}

double funcStdThrow(double a, double b)
{
	if (b == 0) throw std::invalid_argument("denominator is zero");
	return a / b;
}

double funcStdThrow2(double a, double b)
{
	if (b == 0) throw myException("denominator is zero");
	return a / b;
}

double funcStdThrow3(double a, double b)
{
	if (b == 0) throw myException1();
	return a / b;
}

double funcStdThrow4(double a, double b)
{
	if (b == 0) throw myException2();
	return a / b;
}

int main()
{
	try { std::cout << funcNoThrow(10, 0) << '\n'; }
	catch (...) { std::cout << "Exception caught\n"; }

	try { std::cout << funcStdThrow(10, 0) << '\n'; }
	catch (const std::exception& e) { std::cout << e.what() << '\n'; }

	try { std::cout << funcStdThrow2(10, 0) << '\n'; }
	catch (const myException& e) { std::cout << e.what() << '\n'; }

	try { std::cout << funcStdThrow3(10, 0) << '\n'; }
	catch (const myException1& e) { std::cout << "myException1 caught\n"; }

	try { std::cout << funcStdThrow4(10, 0) << '\n'; }
	catch (const myException2& e) { std::cout << "myException2 caught\n"; }

	return 0;
}