#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <vector>
#include <iostream>
#include "math_exceptions.hpp"
#include "arbitrary_vector.hpp"


namespace math{
    template <typename T>
    class Vec3d: public Vec<T>{

        public: 
            Vec3d(): Vec<T>({0, 0, 0}){};

            Vec3d(std::vector<T> vec): Vec<T>(vec){
                if (vec.size() != 3){
                    throw math::exceptions::MathException(math::exceptions::RANGE_ERROR, "Vector size must be 3");
                }

            };

            Vec3d<T> cross(Vec3d<T> vec){
                std::vector<T> temp;
                temp.push_back(this->_vec[1] * vec.get_val(2) - this->_vec[2] * vec.get_val(1));
                temp.push_back(this->_vec[2] * vec.get_val(0) - this->_vec[0] * vec.get_val(2));
                temp.push_back(this->_vec[0] * vec.get_val(1) - this->_vec[1] * vec.get_val(0));
                return Vec3d<T>(temp);
            }

    }; // class Vec3d
} //namespace math

#endif // VECTOR3D_HPP