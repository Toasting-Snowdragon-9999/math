#ifndef QUATERNIONS_HPP
#define QUATERNIONS_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include "general_vector.hpp"

namespace math{
    template <typename T>
    class Quat: public Vec<T>{

        public: 
            void conjugate(){
                this->_vec[1] = -this->_vec[1];
                this->_vec[2] = -this->_vec[2];
                this->_vec[3] = -this->_vec[3];
            }

            Quat<T> inverse(){
                T norm = this->norm();
                Quat<T> temp = Quat<T>(this->_vec);
                temp.conjugate();
                for(int i = 0; i < 4; i++){
                    temp.set_val(i, temp.get_val(i) / (norm * norm));
                }
                return temp;
            }


    }; // class Quaternions
} //namespace math

#endif // QUATERNIONS_HPP