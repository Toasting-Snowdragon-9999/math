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

        T get_re() const{
            return _re;
        }

        T get_im() const{
            return _im;
        }

        T modulo() const{
            return sqrt((_re * _re) + (_im * _im));
        }
        
        std::vector<T> get_val() const{
            std::vector<T> val = {_re, _im};
            return val;
        }

        std::string get_type() const {
            return typeid(T).name();
        }

        Complex operator+(Complex i) const {
            T new_re = _re + i.get_re();
            T new_im = _im + i.get_im();
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator+(T i) const {
            T new_re = _re + i;
            T new_im = _im + 0;
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator-(Complex i) const{
            T new_re = _re - i.get_re();
            T new_im = _im - i.get_im();
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator-(T i) const{
            T new_re = _re - i.get_re();
            T new_im = _im - 0;
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator*(Complex i) const{
            T new_re = (_re * i.get_re()) - (_im * i.get_im());
            T new_im = (_re * i.get_im()) + (_im * i.get_re());
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator*(T i) const{
            T new_re = _re * i;
            T new_im = _im * i;
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator/(Complex i) const{
            T new_re = ((_re * i.get_re()) + (_im * i.get_im())) / ((i.get_re() * i.get_re()) + (i.get_im() * i.get_im()));
            T new_im = ((_im * i.get_re()) - (_re * i.get_im())) / ((i.get_re() * i.get_re()) + (i.get_im() * i.get_im()));
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator/(T i) const{
            T new_re = _re / i;
            T new_im = _im / i;
            Complex ret(new_re, new_im);
            return ret;
        }

        Complex operator%(Complex i) const{
            T new_re = _re % i.get_re();
            T new_im = _im % i.get_im();
            Complex ret(new_re, new_im);
            return ret;
        }   

        Complex operator%(T i) const{
            T new_re = _re % i;
            T new_im = _im % i;
            Complex ret(new_re, new_im);
            return ret;
        }       

        Complex& operator=(Complex i) const{
            _re = i.get_re();
            _im = i.get_im();
            return *this;
        }

        Complex operator^(Complex i) const{
            /*Yet to be implementer, a method of doing the real logirithm of a complex number
            is needed, because the operation is defines: z^w=e^w*log(z) therfore som 
            eksta methods is needed to do this*/
        }

        bool operator==(Complex i){
            return (_re == i.get_re() && _im == i.get_im());
        }

        bool operator<(Complex i){
            return (modulo() < i.modulo());
        }

        bool operator>(Complex i){
            return (modulo() > i.modulo());
        }

        bool operator<=(Complex i){
            return (modulo() <= i.modulo());
        }

        bool operator>=(Complex i){
            return (modulo() >= i.modulo());
        }

        bool operator!=(Complex i){
            return (_re != i.get_re() && _im != i.get_im());
        }

        Complex& operator+=(Complex i){
            _re += i.get_re();
            _im += i.get_im();
            return *this;
        }

        Complex& operator+=(T i){
            _re += i;
            return *this;
        }

        Complex& operator-=(Complex i){
            _re -= i.get_re();
            _im -= i.get_im();
            return *this;
        }

        Complex& operator-=(T i){
            _re -= i.get_re();
            return *this;
        }

        Complex& operator*=(Complex i){
            _re = (_re * i.get_re()) - (_im * i.get_im());
            _im = (_re * i.get_im()) + (_im * i.get_re());
            return *this;
        }

        Complex& operator*=(T i){
            _re = (_re * i);
            _im = (_re * i)
            ;
            return *this;
        }

        Complex& operator/=(Complex i){
            _re = ((_re * i.get_re()) + (_im * i.get_im())) / ((i.get_re() * i.get_re()) + (i.get_im() * i.get_im()));
            _im = ((_im * i.get_re()) - (_re * i.get_im())) / ((i.get_re() * i.get_re()) + (i.get_im() * i.get_im()));
            return *this;
        }

        Complex& operator/=(T i){
            _re = _re / i;
            _im = _im / i;
            return *this;
        }

        Complex& operator%=(Complex i){
            _re = _re % i.get_re();
            _im = _im % i.get_im();
            return *this;
        }

        Complex& operator%=(T i){
            _re = _re % i;
            _im = _im % i;
            return *this;
        }

        Complex& operator++(){
            _re+=1;
            return *this;
        }

        Complex& operator--(){
            _re-=1;
            return *this;
        }
    
        T& operator~() const{
            return modulo();    
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Complex& obj){
            os << obj.get_re() << " + " << obj.get_im() << "i";
            return os;
        }
};
}   
#endif