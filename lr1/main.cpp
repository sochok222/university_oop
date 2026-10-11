#include <iostream>
#include <string>
#include <limits>

template<typename T>
static T readInput(const std::string &request)
{
    T res;
    while (true) {
        std::cout << request;
        std::cin.clear();
        std::cin >> res;
        if (not std::cin) {
            std::cout << "Wrong input" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return res;
    }
}

struct Equation
{
public:
    explicit Equation(double a, double b) : _first(a), _second(b) {}
    ~Equation() = default;

    // Idk why we need this. This is VERY error-prone in C++.
    inline void init(double a, double b)
    { _first = a; _second = b; }

    /**
     * @return _first * @a + _second
     */
    inline double function(double x)
    { return _first * x + _second; }

    void read()
    {
        _first = readInput<double>("Enter value of A for equation: ");
        _second = readInput<double>("Enter value of B for equation: ");
    }

    void display()
    {
        std::cout << "Result of equation: " << function(5) << std::endl;
    }
private:
    double _first, _second;
};

int main()
{
    Equation eq(0, 0);

    eq.read();
    eq.display();

    return 0;
}