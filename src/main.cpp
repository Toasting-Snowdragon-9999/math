#include <iostream>
#include "general_math.hpp"
// #include "general_vector.hpp"
// #include "matrix.hpp"
// #include "vector3d.hpp"
// #include "custom_int.hpp"
// #include "custom_float.hpp"
// #include "complex_number.hpp"
#include "transform.hpp"
#include "differentiation.hpp"

#include <limits>

// namespace CorrectValues{
//     math::Matrix<float> correct_f_m1({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
//     math::Matrix<float> correct_f_m2({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
//     math::Matrix<float> correct_f_m3({{2.2, 4.2, 6.0}, {8.2, 10.4, 13.0}, {14.2, 16.4, 19.8}});

//     math::Matrix<double> correct_d_m1({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
//     math::Matrix<double> correct_d_m2({{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}});
//     math::Matrix<double> correct_d_m3({{2.2, 4.2, 6.0}, {8.2, 10.4, 13.0}, {14.2, 16.4, 19.8}});

//     math::Matrix<int> correct_i_m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
//     math::Matrix<int> correct_i_m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
//     math::Matrix<int> correct_i_m3({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});

//     math::Vec<float> correct_f_v1({1, 2, 3});
//     math::Vec<float> correct_f_v2({1, 2, 3});
//     math::Vec<float> correct_f_v3({2, 4, 6});

//     math::Vec<double> correct_d_v1({1, 2, 3});
//     math::Vec<double> correct_d_v2({1, 2, 3});
//     math::Vec<double> correct_d_v3({2, 4, 6});

//     math::Vec<int> correct_i_v1({1, 2, 3});
//     math::Vec<int> correct_i_v2({1, 2, 3});
//     math::Vec<int> correct_i_v3({2, 4, 6});

// }


// bool test_fmatrix(math::Matrix<float> m, math::Matrix<float> m2){
//     if (m*m2 == CorrectValues::correct_f_m1){
//         return true;
//     }
// }

// bool test_dmatrix(math::Matrix<double> m, math::Matrix<double> m2){
//     return true;
// }

// bool test_imatrix(math::Matrix<int> m, math::Matrix<int> m2){
//     return true;
// }


// bool test_fvector(math::Vec<float> v, math::Vec<float> v2){
//     return true;
// }

// bool test_dvector(math::Vec<double> v, math::Vec<double> v2){
//     return true;
// }

// bool test_ivector(math::Vec<int> v, math::Vec<int> v2){
//     return true;
// }

double f(double x){
    return x*x*x*x*x;
}

double exponential_decay(double x) {
    return std::exp(-1 * x);  // std::exp calculates e^(-lambda * x) where lambda = 1
}

int main(){
    // std::cout << "Hello World!" << std::endl;
    // math::c_float c = 10.5;
    // std::vector<std::vector<double>> matrix = {{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}};
    // math::Matrix<double> m(matrix);
    // math::Matrix<double> m2(matrix);
    // math::Matrix<double> m3;
    // math::Matrix<double> m4;
    // math::Complex<double> c1(-1, -2);
    // m3 = m + m2;
    // double a = m3.det();
    // math::Vec<double> v1({1, 2, 3});
    // math::Vec<math::c_float> v2({c, 9.22, 2.45, math::PI});
    // std::cout << v2 << std::endl;
    // std::cout << sizeof(c) << std::endl;
    // m4 = m3^-1;
    // std::cout << m3 << std::endl;
    // std::cout << m4 << std::endl;

    math::Transform t;
    std::vector<std::complex<double>> data = {
        std::complex<double>(5.5, 0),
        std::complex<double>(8.3, 0),
        std::complex<double>(7.2, 0),
        std::complex<double>(14.0, 0)
    };
    t.FFT(data);
    std::cout << "DATA: " << std::endl;
    for (int i = 0; i < data.size(); i++){
        std::cout << data[i] << std::endl;
    }
    std::cout << "FFT: " << std::endl;
    for(int i = 0; i < t.get_result().size(); i++){
        std::cout << t.get_result()[i] << std::endl;
    }
    std::vector<std::complex<double>> data2 = t.get_result();
    t.IFFT(data2);
    std::cout << "INVERSE: " << std::endl;
    for(int i = 0; i < t.get_result().size(); i++){
        std::cout << t.get_result()[i] << std::endl;
    }
    
    
    math::CalcSolver c;
    c.num_diff(f, 0, 6, 600000);
    std::vector<double> res = c.get_result();
    std::cout << "DIFF: " << std::endl;
    for (int i = 0; i < res.size(); i+=100000){
        std::cout << res[i] << std::endl;
    }

    math::CalcSolver c2;
    c2.higher_order_diff(f, 0, 5, 5000, 1);
    std::vector<double> res2 = c2.get_result();
    std::cout << "DIFF: " << std::endl;
    for (int i = 0; i < res2.size(); i+=1000){
        std::cout << res2[i] << std::endl;
    }

    // math::CalcSolver c3;
    // c3.diff_fft(exponential_decay,0, 5, 1024);
    // std::vector<double> res3 = c3.get_result();
    // std::cout << "DIFF: " << std::endl;
    // for (int i = 0; i < res3.size(); i+=64){
    //     std::cout << res3[i] << std::endl;
    // }

    return 0;
}