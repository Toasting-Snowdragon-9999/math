#ifndef DIFFERENTIATION_HPP
#define DIFFERENTIATION_HPP
#include <iostream>
#include <vector>
#include <complex>
#include <functional>
#include <cmath>
#include "math_exceptions.hpp"
#include "general_math.hpp" 
#include "transform.hpp"

namespace math{
    

    class CalcSolver {
        private:
            std::vector<double> _result;

            std::vector<double> get_finite_difference_coefficients(int order) {
                switch(order) {
                    case 1:
                        return { -1.0, 0.0, 1.0 }; // Central difference for first derivative
                    case 2:
                        return { 1.0, -2.0, 1.0 }; // Central difference for second derivative
                    case 3:
                        return { -1.0, 3.0, -3.0, 1.0 }; // Central difference for third derivative
                    case 4:
                        return { -1.0, 16.0, -30.0, 16.0, -1.0 }; // Central difference for fourth derivative
                    case 5:
                        return { -1.0, 5.0, -10.0, 0.0, 10.0, -5.0, 1.0 }; // Central difference for fifth derivative (6-point stencil)
                    default:
                        throw std::invalid_argument("Higher-order finite differences not implemented for order > 5");
            }
            }
        public: 
            /**
             * @brief Default constructor for the Transform class
             * 
             */
            CalcSolver();
            /**
             * @brief Default destructor for the Transform class
             * 
             */
            ~CalcSolver();
            
            /**
             * @brief Fast fourier transform
             * 
             * @param data std::vector<std::complex<double>> data
             * 
             */
            void diff_fft(std::function<double(double)> func, double start, double end, int num_points);
            void num_diff(std::function<double(double)> func, double start, double end, int num_points);
            void higher_order_diff(std::function<double(double)> func, double start, double end, int num_points, int order = 2);

            std::vector<double> get_result() const{return _result;};

    };

};

#endif