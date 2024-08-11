#include <iostream>
#include "arbitrary_vector.hpp"
#include "matrix.hpp"
#include "vector3d.hpp"
#include "custom_int.hpp"
#include "custom_float.hpp"
#include "complex_number.hpp"

#include <limits>

int main(){
    std::cout << "Hello World!" << std::endl;
    std::vector<std::vector<float>> matrix = {{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}};
    math::Matrix<float> m(matrix);
    math::Matrix<float> m2(matrix);
    math::Matrix<float> m3;
    math::Complex<float> c1(-1, -2);
    m3 = m + m2;
    m3.print();
    math::Vec<float> v1({1, 2, 3});
    int32_t a;
    std::cout << "Size of int32_t: " << sizeof(a) << " bytes\n";

    float b;
    std::cout << "Size of float: " << sizeof(b) << " bytes\n";

    math::c_int c = 2;
    std::cout << "Size of c_int: " << sizeof(c) << " bytes\n";
    math::Matrix <float> m4;
    m4 = v1|m3;
    std::cout << m4 << std::endl;
    std::cout << v1 << std::endl;
    std::cout << c1 << std::endl;

    return 0;
}