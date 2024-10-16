#include "custom_float.hpp"

math::c_float::c_float(){
    _float = 0;
}

math::c_float::c_float(float i){
    _float = i;
}

void math::c_float::set_val(float i){
    _float = i;
}

float math::c_float::get_val() const{
    return _float;
}

math::c_float math::c_float::operator+(c_float i){
    return c_float(_float + i.get_val());
}

math::c_float math::c_float::operator-(c_float i){
    return c_float(_float - i.get_val());
}

math::c_float math::c_float::operator*(c_float i){
    return c_float(_float * i.get_val());
}

math::c_float math::c_float::operator/(c_float i){
    return c_float(_float / i.get_val());
}


math::c_float& math::c_float::operator=(float i){
    _float = i;
    return *this;
}

math::c_float math::c_float::operator%(c_float i){
    float temp = _float;
    temp -= static_cast<int32_t>(_float);
    math::c_float ret_float(temp);
    return ret_float;   
}

bool math::c_float::operator==(c_float i){
    return _float == i.get_val();
}

bool math::c_float::operator<(c_float i){
    return _float < i.get_val();
}

bool math::c_float::operator>(c_float i){
    return _float > i.get_val();
}

bool math::c_float::operator<=(c_float i){
    return _float <= i.get_val();
}

bool math::c_float::operator>=(c_float i){
    return _float >= i.get_val();
}

bool math::c_float::operator!=(c_float i){
    return _float != i.get_val();
}

math::c_float& math::c_float::operator++(){ 
    _float += 1;
    return *this;
}

math::c_float& math::c_float::operator+=(c_float i){
    _float += i.get_val();
    return *this;
}

math::c_float& math::c_float::operator-=(c_float i){
    _float -= i.get_val();
    return *this;
}

math::c_float& math::c_float::operator*=(c_float i){
    _float *= i.get_val();
    return *this;
}

math::c_float& math::c_float::operator/=(c_float i){
    _float /= i.get_val();
    return *this;
}

math::c_float& math::c_float::operator%=(c_float i){
    _float -= static_cast<int>(_float);
    return *this;
}

double math::c_float::operator^(c_float i){
    double temp = 1;
    for(int16_t j = 0; j < i.get_val(); j++){
        temp *= static_cast<double>(_float);
    }
    return temp;
}

math::c_float::operator float() const {
    return _float;
}

math::c_float::operator double() const {
    return static_cast<double>(_float);
}

math::c_float::operator int() const {
    return static_cast<int>(_float);
}

math::c_float& math::c_float::operator~(){
    _float = std::abs(_float);
    return *this;
}

std::ostream &math::operator<<(std::ostream& os, const math::c_float& obj) {
    os << obj.get_val();
    return os;
}