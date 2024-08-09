#include <iostream>
#include "matrix.hpp"
#include "vector3d.hpp"
#include "custom_int.hpp"
#include <limits>

int main(){
    std::cout << "Hello World!" << std::endl;
    std::vector<std::vector<float>> matrix = {{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}};
    math::Matrix<float> m(matrix);
    math::Matrix<float> m2(matrix);
    math::Matrix<float> m3;
    m3 = m + m2;
    m3.print();
    math::Vec3d<float> v({1.0, 2.0, 3.0});
    math::Vec3d<float> v2({1.0, 2.0, 3.0});
    math::Vec3d<float> v3;
    v3 = v + v2;
    v3.print();

    int32_t a;
    std::cout << "Size of int32_t: " << sizeof(a) << " bytes\n";

    float b;
    std::cout << "Size of float: " << sizeof(b) << " bytes\n";

    math::c_int c = 2;
    std::cout << "Size of c_int: " << sizeof(c) << " bytes\n";
    std::cout << m3 << std::endl;

    return 0;
}