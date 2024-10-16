#include "differentiation.hpp"


math::CalcSolver::CalcSolver(){
}

math::CalcSolver::~CalcSolver(){
}

void math::CalcSolver::diff_fft(std::function<double(double)> func, double start, double end, int num_points){
    std::vector<double> x_points(num_points);
    std::vector<std::complex<double>> func_values(num_points);
    _result.resize(num_points);
    double step_size = (end - start) / (num_points - 1);
    for (int i = 0; i < num_points; ++i) {
        x_points[i] = start + i * step_size;
        func_values[i] = std::complex<double>(func(x_points[i]), 0.0);
    }
    math::Transform T;
    T.FFT(func_values);
    std::vector<std::complex<double>> derivative_values(num_points);
    derivative_values = T.get_result();
    double L = (end - start);

    for (int k = 0; k < num_points; ++k) {
        double omega_k;
        if (k <= num_points / 2) {
            omega_k = 2.0 * math::PI * k / L;
        } else {
            omega_k = 2.0 * PI * (k - num_points) / L;
        }

        derivative_values[k] *= std::complex<double>(0.0, omega_k);
    }
    T.IFFT(derivative_values);
    derivative_values = T.get_result();

    for (int i = 0; i < num_points; ++i) {
        // std::cout << "derivative_values[" << i << "].real(): " << derivative_values[i].real() << std::endl;
        _result[i] = derivative_values[i].real() / static_cast<double>(num_points); 
    }
}

void math::CalcSolver::num_diff(std::function<double(double)> func, double start, double end, int num_points) {
    _result.resize(num_points);
    double step_size = (end - start) / (num_points - 1);

    _result[0] = (func(start + step_size) - func(start)) / step_size;

    for (int i = 1; i < num_points - 1; ++i) {
        double x_prev = start + (i - 1) * step_size;
        double x_next = start + (i + 1) * step_size;
        _result[i] = (func(x_next) - func(x_prev)) / (2 * step_size);
    }

    _result[num_points - 1] = (func(end) - func(end - step_size)) / step_size;
}

void math::CalcSolver::higher_order_diff(std::function<double(double)> func, double start, double end, int num_points, int order) {
    _result.resize(num_points);
    double step_size = (end - start) / (num_points - 1);

    // Get finite difference coefficients for the requested order
    std::vector<double> coefficients = this->get_finite_difference_coefficients(order);
    int stencil_half_width = coefficients.size() / 2;  // Half the stencil size

    // Central differences for interior points
    for (int i = stencil_half_width; i < num_points - stencil_half_width; ++i) {
        double sum = 0.0;
        for (int j = -stencil_half_width; j <= stencil_half_width; ++j) {
            double x_shifted = start + (i + j) * step_size;
            sum += coefficients[j + stencil_half_width] * func(x_shifted);
        }
        _result[i] = sum / math::pow(step_size, order);
    }

    // Forward difference for the first few points (lower-order stencil)
    for (int i = 0; i < stencil_half_width; ++i) {
        double sum = 0.0;
        for (int j = 0; j <= 2 * stencil_half_width; ++j) {
            double x_shifted = start + j * step_size;
            sum += coefficients[j] * func(x_shifted);
        }
        _result[i] = sum / math::pow(step_size, order);
    }

    // Backward difference for the last few points (lower-order stencil)
    for (int i = num_points - stencil_half_width; i < num_points; ++i) {
        double sum = 0.0;
        for (int j = 0; j <= 2 * stencil_half_width; ++j) {
            double x_shifted = start + (i - stencil_half_width + j) * step_size;
            sum += coefficients[j] * func(x_shifted);
        }
        _result[i] = sum / math::pow(step_size, order);
    }
}



