#include "transform.hpp"

math::Transform::Transform(){
}

math::Transform::~Transform(){
}

void math::Transform::FFT(std::vector<std::complex<double>>& data) {
    int size = data.size();
    _result.resize(size);  

    if (size == 1) {
        _result[0] = data[0];
        return;
    }

    std::vector<std::complex<double>> even(size / 2), odd(size / 2);
    for (int i = 0; i < size / 2; i++) {
        even[i] = data[i * 2];        
        odd[i] = data[i * 2 + 1];      
    }

    std::vector<std::complex<double>> evenResult(size / 2), oddResult(size / 2);
    math::Transform evenTransform, oddTransform;

    evenTransform.FFT(even);  
    oddTransform.FFT(odd);   

    evenResult = evenTransform.get_result();  
    oddResult = oddTransform.get_result();   

    for (int i = 0; i < size / 2; i++) {
        std::complex<double> t = std::polar(1.0, -2 * math::PI * i / size) * oddResult[i];
        _result[i] = evenResult[i] + t;
        _result[i + size / 2] = evenResult[i] - t;
    }

}


void math::Transform::FFT(double* data, int size) {
    std::vector<std::complex<double>> complexData(size);
    for (int i = 0; i < size; i++) {
        complexData[i] = std::complex<double>(data[i], 0);
    }
    FFT(complexData);
}

void math::Transform::DFT(std::vector<std::complex<double>>& data) {
    int size = data.size();
    _result.resize(size); 

    for (int k = 0; k < size; k++) {
        std::complex<double> sum(0.0, 0.0); 
        
        for (int n = 0; n < size; n++) {
            double angle = -2 * math::PI * k * n / size;
            std::complex<double> twiddle(std::cos(angle), std::sin(angle));
            sum += data[n] * twiddle;
        }
        
        _result[k] = sum;
    }
}

void math::Transform::IDFT(std::vector<std::complex<double>>& data) {
    int size = data.size();
    _result.resize(size);  

    for (int n = 0; n < size; n++) {
        std::complex<double> sum(0.0, 0.0);  

        for (int k = 0; k < size; k++) {
            double angle = 2 * math::PI * k * n / size;
            std::complex<double> twiddle(std::cos(angle), std::sin(angle));

            sum += data[k] * twiddle;
        }

        _result[n] = sum / static_cast<double>(size);
    }

}

void math::Transform::perform_IFFT(std::vector<std::complex<double>>& data) {
    int size = data.size();
    _result.resize(size);

    if (size == 1) {
        _result[0] = data[0];
        return;
    }

    std::vector<std::complex<double>> even(size / 2), odd(size / 2);
    for (int i = 0; i < size / 2; i++) {
        even[i] = data[i * 2]; 
        odd[i] = data[i * 2 + 1];  
    }

    std::vector<std::complex<double>> evenResult(size / 2), oddResult(size / 2);
    math::Transform evenTransform, oddTransform;

    evenTransform.perform_IFFT(even);  
    oddTransform.perform_IFFT(odd);    

    evenResult = evenTransform.get_result();  
    oddResult = oddTransform.get_result();    

    for (int i = 0; i < size / 2; i++) {
        std::complex<double> t = std::polar(1.0, 2 * math::PI * i / size) * oddResult[i];
        _result[i] = evenResult[i] + t;
        _result[i + size / 2] = evenResult[i] - t;
    }
}

void math::Transform::IFFT(std::vector<std::complex<double>>& data) {
    perform_IFFT(data);  // Perform the IFFT as usual.
    int size = data.size();

    // Now normalize the result once after the recursion.
    for (int i = 0; i < size; i++) {
        _result[i] /= static_cast<double>(size);  // Normalize at the end
    }
}


void math::Transform::DCT(){
}   

void math::Transform::IDCT(){
}

void math::Transform::DST(){
}

void math::Transform::IDST(){
}