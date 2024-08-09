#include <iostream>
#include "matrix.hpp"

int main(){
    std::cout << "Hello World!" << std::endl;
    std::vector<std::vector<float>> matrix = {{1.1, 2.1, 3.0}, {4.1, 5.2, 6.5}, {7.1, 8.2, 9.9}};
    math::Matrix<float> m(matrix);

    return 0;
}