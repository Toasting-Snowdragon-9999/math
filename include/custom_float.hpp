#ifndef CUSTOM_FLOAT_HPP
#define CUSTOM_FLOAT_HPP
#include <vector>
#include <iostream>
#include <cmath>

namespace math{
class c_float{
    
    private: 
        float _float;
    
    public: 
        c_float();

        c_float(float i);
        
        void set_val(float i);

        float get_val() const;

        c_float operator+(c_float i);

        c_float operator-(c_float i);

        c_float operator*(c_float i);

        c_float operator/(c_float i);

        c_float operator%(c_float i);

        c_float& operator=(float i);

        double operator^(c_float i);

        bool operator==(c_float i);

        bool operator<(c_float i);

        bool operator>(c_float i);

        bool operator<=(c_float i);

        bool operator>=(c_float i);

        bool operator!=(c_float i);

        c_float& operator+=(c_float i);

        c_float& operator-=(c_float i);

        c_float& operator*=(c_float i);

        c_float& operator/=(c_float i);

        c_float& operator%=(c_float i);

        c_float& operator++();

        c_float& operator--();

        operator float() const;
        operator double() const;
        operator int() const;

        c_float& operator~();

        friend std::ostream& operator<<(std::ostream& os, const c_float& obj);
};
}
#endif  // CUSTOM_FLOAT_HPP