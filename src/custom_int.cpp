#include "custom_int.hpp"

math::c_int::c_int(){
    _int = 0;
}

math::c_int::c_int(int16_t i){
    _int = i;
}

void math::c_int::set_val(int16_t i){
    _int = i;
}

int16_t math::c_int::get_val() const{
    return _int;
}

math::c_int math::c_int::operator+(c_int i){
    return c_int(_int + i.get_val());
}

math::c_int math::c_int::operator-(c_int i){
    return c_int(_int - i.get_val());
}

math::c_int math::c_int::operator*(c_int i){
    return c_int(_int * i.get_val());
}

math::c_int math::c_int::operator/(c_int i){
    return c_int(_int / i.get_val());
}

math::c_int math::c_int::operator%(c_int i){
    return c_int(_int % i.get_val());
}

math::c_int& math::c_int::operator=(int16_t i){
    _int = i;
    return *this;
}

bool math::c_int::operator==(c_int i){
    return _int == i.get_val();
}

bool math::c_int::operator<(c_int i){
    return _int < i.get_val();
}

bool math::c_int::operator>(c_int i){
    return _int > i.get_val();
}

bool math::c_int::operator<=(c_int i){
    return _int <= i.get_val();
}

bool math::c_int::operator>=(c_int i){
    return _int >= i.get_val();
}

bool math::c_int::operator!=(c_int i){
    return _int != i.get_val();
}


math::c_int& math::c_int::operator++(){
    _int+=1;
    return *this;
}

math::c_int& math::c_int::operator*=(math::c_int i){
    _int*=1;
    return *this;
}

math::c_int& math::c_int::operator/=(math::c_int i){
    _int/=1;
    return *this;
}

math::c_int& math::c_int::operator--(){
    _int-=1;
    return *this;
}

math::c_int& math::c_int::operator~(){
    _int = std::abs(_int);
    return *this;
}

double math::c_int::operator^(c_int i){
    double temp = 1;
    for(int16_t j = 0; j < i.get_val(); j++){
        temp *= static_cast<double>(_int);
    }
    return temp;
}

std::ostream &math::operator<<(std::ostream& os, const math::c_int& obj) {
    os << obj.get_val();
    return os;
}

