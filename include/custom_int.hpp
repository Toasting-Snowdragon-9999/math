#ifndef CUSTOM_INT_HPP
#define CUSTOM_INT_HPP
#include <vector>
#include <iostream>
#include <cmath>

namespace math{

class c_int{
    private: 
        int16_t _int;
    
    public: 
        c_int();

        c_int(int16_t i);

        void set_val(int16_t i);

        int16_t get_val() const;

        c_int operator+(c_int i);

        c_int operator-(c_int i);

        c_int operator*(c_int i);

        c_int operator/(c_int i);

        c_int operator%(c_int i);

        c_int& operator=(int16_t i);

        bool operator==(c_int i);

        bool operator<(c_int i);

        bool operator>(c_int i);

        bool operator<=(c_int i);

        bool operator>=(c_int i);

        bool operator!=(c_int i);

        c_int& operator+=(c_int i);

        c_int& operator-=(c_int i);

        c_int& operator*=(c_int i);

        c_int& operator/=(c_int i);

        c_int& operator%=(c_int i);

        c_int& operator++();

        c_int& operator--();

        operator float() const;
        operator double() const;
        operator int() const;

        c_int& operator~();

        double operator^(c_int i);

        friend std::ostream& operator<<(std::ostream& os, const c_int& obj);
    };
    
    std::ostream& operator<<(std::ostream& os, const c_int& obj);

}
#endif