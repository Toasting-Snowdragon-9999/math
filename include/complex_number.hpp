#ifndef COMPLEX_NUMBERS_HPP
#define COMPLEX_NUMBERS_HPP
#include <vector>
#include <string>

namespace math{

    template<typename T>
    class Complex{
        private: 
            T _re;
            T _im;
            
        public: 
        Complex(){}
        Complex(T re, T im): _re(re), _im(im){}
        Complex(std::vector<T> com): _re(com[0]), _im(com[0]){}

        void set_re(T val){
            _re = val;
        }

        void set_im(T val){
            _im = val;
        }

        T get_re(){
            return _re;
        }

        T get_im(){
            return _im;
        }
        
        std::vector<T> get_val(){
            std::vector<T> val = {_re, _im};
            return val;
        }

        std::string get_type() const {
            return typeid(T).name();
        }

        Complex operator+(Complex i){

        }

        Complex operator-(Complex i){

        }

        Complex operator*(Complex i){

        }

        Complex operator/(Complex i){

        }

        Complex operator%(Complex i){

        }

        Complex& operator=(Complex i){

        }

        Complex operator^(Complex i){
            
        }

        bool operator==(Complex i){

        }

        bool operator<(Complex i){

        }

        bool operator>(Complex i){

        }

        bool operator<=(Complex i){

        }

        bool operator>=(Complex i){

        }

        bool operator!=(Complex i){

        }

        Complex& operator+=(Complex i){

        }

        Complex& operator-=(Complex i){

        }

        Complex& operator*=(Complex i){

        }

        Complex& operator/=(Complex i){

        }

        Complex& operator%=(Complex i){

        }

        Complex& operator++(){

        }

        Complex& operator--(){

        }
    
        Complex& operator~(){

        }
        
        friend std::ostream& operator<<(std::ostream& os, const Vec3d& obj){

        }
    };
}
#endif