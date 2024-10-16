#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <iostream>
#include <vector>
#include <complex>
#include "math_exceptions.hpp"
#include "general_math.hpp" 


namespace math{
    class Transform {
        private:
            std::vector<std::complex<double>> _result;
            void perform_IFFT(std::vector<std::complex<double>>& data);

        public: 
            /**
             * @brief Default constructor for the Transform class
             * 
             */
            Transform();
            /**
             * @brief Default destructor for the Transform class
             * 
             */
            ~Transform();
            /**
             * @brief Fast fourier transform
             * 
             * @param data std::vector<std::complex<double>> data
             * 
             */
            void FFT(std::vector<std::complex<double>>& data);
            /**
             * @brief Fast fourier transform
             * 
             * @param data double pointer to the data
             */
            void FFT(double* data, int size);
            /**
             * @brief Discrete fourier transform
             * 
             */
            void DFT(std::vector<std::complex<double>>& data);
            /**
             * @brief inverse discrete fourier transform
             * 
             */
            void IDFT(std::vector<std::complex<double>>& data);
            /**
             * @brief inverse fast fourier transform
             * 
             */
            void IFFT(std::vector<std::complex<double>>& data);
            /**
             * @brief Discrete cosine transform
             * 
             */
            void DCT();
            /**
             * @brief inverse discrete cosine transform
             * 
             */
            void IDCT();
            /**
             * @brief Discrete sine transform
             * 
             */
            void DST();
            /**
             * @brief inverse discrete sine transform
             * 
             */
            void IDST();
            /**
             * @brief Get the Result object
             * 
             * @return std::vector<std::complex<double>> 
             */
            std::vector<std::complex<double>> get_result(){return _result;}

    };

};

#endif