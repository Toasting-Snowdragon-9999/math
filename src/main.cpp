#include <iostream>
#include "arbitrary_vector.hpp"
#include "matrix.hpp"
#include "vector3d.hpp"
#include "custom_int.hpp"
#include "custom_float.hpp"
#include "complex_number.hpp"

#include <limits>

namespace CorrectValues{
    math::Matrix<float> correct_f_m1({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
    math::Matrix<float> correct_f_m2({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
    math::Matrix<float> correct_f_m3({{2.2, 4.2, 6.0}, {8.2, 10.4, 13.0}, {14.2, 16.4, 19.8}});

    math::Matrix<double> correct_d_m1({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
    math::Matrix<double> correct_d_m2({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
    math::Matrix<double> correct_d_m3({{2.2, 4.2, 6.0}, {8.2, 10.4, 13.0}, {14.2, 16.4, 19.8}});

    math::Matrix<int> correct_i_m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    math::Matrix<int> correct_i_m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    math::Matrix<int> correct_i_m3({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});

    math::Vec<float> correct_f_v1({1, 2, 3});
    math::Vec<float> correct_f_v2({1, 2, 3});
    math::Vec<float> correct_f_v3({2, 4, 6});

    math::Vec<double> correct_d_v1({1, 2, 3});
    math::Vec<double> correct_d_v2({1, 2, 3});
    math::Vec<double> correct_d_v3({2, 4, 6});

    math::Vec<int> correct_i_v1({1, 2, 3});
    math::Vec<int> correct_i_v2({1, 2, 3});
    math::Vec<int> correct_i_v3({2, 4, 6});

}


bool test_fmatrix(math::Matrix<float> m, math::Matrix<float> m2){
    if (m*m2 == CorrectValues::correct_f_m1){
        return true;
    }
}

bool test_dmatrix(math::Matrix<double> m, math::Matrix<double> m2){
    
}

bool test_imatrix(math::Matrix<int> m, math::Matrix<int> m2){
    
}


bool test_fvector(math::Vec<float> v, math::Vec<float> v2){
    
}

bool test_dvector(math::Vec<double> v, math::Vec<double> v2){
    
}

bool test_ivector(math::Vec<int> v, math::Vec<int> v2){
    
}



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