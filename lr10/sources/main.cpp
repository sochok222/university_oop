#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

#include "Triangle.h"
#include "TriangleByPoints.h"
#include "TriangleBySides.h"
#include "RightTriangle.h"

bool near(double a, double b, double eps = 1e-6)
{
    return std::abs(a - b) < eps;
}

int main()
{
    try {
        // 1. Triangle by sides
        {
            TriangleBySides t(3, 4, 5);

            assert(near(t.area(), 6));
            assert(near(t.inradius(), 1));
            assert(near(t.circumradius(), 2.5));

            std::cout << "TriangleBySides: OK\n";
        }

        // 2. Triangle by points
        {
            TriangleByPoints t(
                Point{0, 0},
                Point{4, 0},
                Point{0, 3}
            );

            assert(near(t.area(), 6));
            assert(near(t.inradius(), 1));
            assert(near(t.circumradius(), 2.5));

            std::cout << "TriangleByPoints: OK\n";
        }

        // 3. Medians
        {
            TriangleBySides t(3, 4, 5);

            assert(near(t.median(Triangle::Side::A), std::sqrt(73.0) / 2));
            assert(near(t.median(Triangle::Side::B), std::sqrt(52.0) / 2));
            assert(near(t.median(Triangle::Side::C), 2.5));

            std::cout << "Medians: OK\n";
        }

        // 4. Midlines
        {
            TriangleBySides t(3, 4, 5);

            assert(near(t.midline(Triangle::Side::A), 1.5));
            assert(near(t.midline(Triangle::Side::B), 2.0));
            assert(near(t.midline(Triangle::Side::C), 2.5));

            std::cout << "Midlines: OK\n";
        }

        // 5. Right triangle
        {
            RightTriangle t(3, 4);

            assert(near(t.area(), 6));
            assert(near(t.inradius(), 1));
            assert(near(t.circumradius(), 2.5));

            std::cout << "RightTriangle: OK\n";
        }

        // 6. Polymorphism
        {
            TriangleBySides t1(3, 4, 5);
            RightTriangle t2(3, 4);

            Triangle* triangles[] = {&t1, &t2};

            for (const Triangle* t : triangles) {
                assert(near(t->area(), 6));
                assert(near(t->inradius(), 1));
                assert(near(t->circumradius(), 2.5));
            }

            std::cout << "Polymorphism: OK\n";
        }

        // 7. Invalid triangle sides
        {
            bool thrown = false;

            try {
                TriangleBySides t(1, 2, 10);
            }
            catch (const std::invalid_argument&) {
                thrown = true;
            }

            assert(thrown);
            std::cout << "Invalid sides exception: OK\n";
        }

        std::cout << "\nAll tests passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: "
                  << e.what() << '\n';
        return 1;
    }

    return 0;
}