#ifndef VECTOR4D_HPP
#define VECTOR4D_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include "arbitrary_vector.hpp"

namespace math{
    template <typename T>
    class Vec4d: public Vec<T>{

        public: 
            Vec4d(): Vec<T>({0, 0, 0, 0}){};

            Vec4d(std::vector<T> vec): Vec<T>(vec){
                if (vec.size() != 4){
                    throw std::invalid_argument("Vector 4D size must be 4");
                }

            };

            Vec<T> wedge(const Vec4d<T>& vec) const {
                std::vector<T> temp(6);
                temp[0] = this->_vec[0] * vec.get_val(1) - this->_vec[1] * vec.get_val(0); // e1 ^ e2
                temp[1] = this->_vec[0] * vec.get_val(2) - this->_vec[2] * vec.get_val(0); // e1 ^ e3
                temp[2] = this->_vec[0] * vec.get_val(3) - this->_vec[3] * vec.get_val(0); // e1 ^ e4
                temp[3] = this->_vec[1] * vec.get_val(2) - this->_vec[2] * vec.get_val(1); // e2 ^ e3
                temp[4] = this->_vec[1] * vec.get_val(3) - this->_vec[3] * vec.get_val(1); // e2 ^ e4
                temp[5] = this->_vec[2] * vec.get_val(3) - this->_vec[3] * vec.get_val(2); // e3 ^ e4

                return Vec<T>(temp);
            }

    }; // class Vec3d
} //namespace math

#endif // VECTOR3D_HPP