#ifndef GENERAL_MATH_HPP
#define GENERAL_MATH_HPP
#include <vector>
#include <iostream>


namespace math{
class c_int{
    
    private: 
        int16_t _int;
    
    public: 
        c_int(){
            _int = 0;
        }
        c_int(int16_t i){
            _int = i;
        }
        void set_val(int16_t i){
            _int = i;
        }
        int16_t get_val(){
            return _int;
        }
        c_int operator+(c_int i){
            return c_int(_int + i.get_val());
        }
        c_int operator-(c_int i){
            return c_int(_int - i.get_val());
        }
        c_int operator*(c_int i){
            return c_int(_int * i.get_val());
        }
        c_int operator/(c_int i){
            return c_int(_int / i.get_val());
        }
        c_int operator%(c_int i){
            return c_int(_int % i.get_val());
        }
        double operator^(c_int i){
            double temp; 
            for (int j = 0; j < i.get_val(); j++){
                temp *= _int;
            }
            return temp;
        }
        void print(){
            std::cout << _int << std::endl;
        }
        

};










};
#endif