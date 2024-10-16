#ifndef GENERAL_VECTOR_HPP
#define GENERAL_VECTOR_HPP

/*
Make the vec3d and vec4d to inherit from arbitrary_vector
this vector should give all the basic function to a vector of and arbitrary size
Make the vector classes define how to multiply and divide by a matrix

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "matrix.hpp"

namespace math{
template <typename T>
/*
This is the base class for all the vectors, this class will define the basic operations
that a vector should have
*/
class Vec{
    protected: 
            std::vector<T> _vec;
            uint8_t _size;

    public: 
        Vec(){}

        Vec(uint8_t size): _size(size){
            _vec.resize(size);
        }

        Vec(std::vector<T> vec){
            _vec = vec;
            _size = vec.size();
        }

        Vec(T* vec, uint8_t size): _size(size){
            _vec.resize(size);
            for(int i = 0; i < size; i++){
                _vec[i] = vec[i];
            }
        }
        /**
         * @brief This will set the value of the vector at a given position
         * 
         * @param position The position in the vector to set the value. 
         * @param value The value to set at the position.
         */
        void set_val(uint8_t position, T value){
            if (position < _size){
                _vec[position] = value;
            }
            else{
                throw std::invalid_argument("Position out of bounds");
            }
        }
        
        /**
         * @brief This will return the value of the vector at a given position
         * @param idx The position in the vector to get the value.
         */
        T get_val(uint8_t idx) const{
            return _vec[idx];
        }

        std::vector <T> get_vector() const{
            return _vec;
        }

        uint8_t get_size() const{
            return _size;
        }

        /**
         * @brief This method will return the norm of the vector, by this formular sqrt(x1^2 + x2^2 + ... + xn^2)
         * @return This will return the value of the norm of the vector in type: double
         */
        double norm(){
            T sum = 0;
            for(int i = 0; i < _vec.size(); i++){
                sum += _vec[i] * _vec[i];
            }
            return math::sqrt(sum);
        }

        /**
        @brief This method returns the sum of the abosulte value of the vector
        also called the manhatten norm.
        */
        double manhatten_norm(){
            T sum = 0;
            for(int i = 0; i < _vec.size(); i++){
                sum += math::sqrt(_vec[i]*_vec[i]);
            }
            return sum;
        }

        /**
        @brief This method will normalize the vector, this will not change the original vector.
        This will divide each element of the vector by the norm of the vector
        @return This will return the normalized vector, as an object of this class.
        */
        Vec<T> normalize(){
                double n = norm();
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] / n);
                }
                return Vec(temp);
            }

        Vec<T> operator+(Vec<T> vec){
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            std::vector<T> temp;
            for(int i = 0; i < _vec.size(); i++){
                temp.push_back(_vec[i] + vec.get_val(i));
            }
            return Vec<T>(temp);
        }

        Vec<T> operator-(Vec<T> vec){
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            std::vector<T> temp;
            for(int i = 0; i < _vec.size(); i++){
                temp.push_back(_vec[i] - vec.get_val(i));
            }
            return Vec<T>(temp);
        }

        T operator*(Vec<T> vec){
            /*
            This method will compute the dot product of two vectors
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            T temp = 0;
            for(int i = 0; i < _vec.size(); i++){
                temp += _vec[i] * vec.get_val(i);
            }
            return temp;
        }
        
        Vec<T> operator*(T scalar){
            /*
            This method will multiply the vector by a scalar
            */
            std::vector<T> temp;
            for(int i = 0; i < _vec.size(); i++){
                temp.push_back(_vec[i] * scalar);
            }
            return Vec<T>(temp);
        }

        virtual Vec<T> operator*(math::Matrix<T> matrix){
            /*
            This method will multiply the vector by a matrix
            */
            if (matrix.verify_matrix(matrix.get_matrix())){
                std::vector<T> temp(matrix.get_cols(0).size(), 0);
                for(int i = 0; i < matrix.get_rows(0).size(); i++){
                    for(int j = 0; j < temp.size(); j++){
                        temp[i] += matrix.get_matrix()[i][j] * _vec[j];
                    }
                }
                return Vec<T>(temp);
            }
            else{
                throw std::invalid_argument("Matrix is not valid");
            }
        }

        Vec<T> operator/(T scalar){
            /*
            This method will divide the vector by a scalar
            */
            std::vector<T> temp;
            for(int i = 0; i < _vec.size(); i++){
                temp.push_back(_vec[i] / scalar);
            }
            return Vec<T>(temp);
        }

        Vec<T> operator/(Vec<T> vec){
            /*
            This method will do elemtwise division of the vector by another vector
            */
            std::vector<T> temp;
            for(int i = 0; i < _vec.size(); i++){
                temp.push_back(_vec[i] / vec.get_val(i));
            }
            return Vec<T>(temp);
        }

        Vec<T> operator+=(Vec<T> vec){
            /*
            This method will add a vector to the current vector and assign it to the original vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            for(int i = 0; i < _vec.size(); i++){
                _vec[i] += vec.get_val(i);
            }
            return *this;
        }

        Vec<T> operator-=(Vec<T> vec){
            /*
            This method will subtract a vector from the current vector and assign it to the original vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            for(int i = 0; i < _vec.size(); i++){
                _vec[i] -= vec.get_val(i);
            }
            return *this;
        }

        Vec<T> operator*=(T scalar){
            /*
            This method will multiply the vector by a scalar and assign it to the original vector
            */
            for(int i = 0; i < _vec.size(); i++){
                _vec[i] *= scalar;
            }
            return *this;
        }

        Vec<T> operator/=(T scalar){
            /*
            This method will divide the vector by a scalar and assign it to the original vector
            */
            for(int i = 0; i < _vec.size(); i++){
                _vec[i] /= scalar;
            }
            return *this;
        }

        Vec<T> operator=(Vec<T> vec){
            /*
            This method will assign the values of a vector to the current vector
            */
            if(this != &vec){
                for(int i = 0; i < _vec.size(); i++){
                    _vec[i] = vec.get_val(i);
                }
            }
            _size = vec.get_size();
            return *this;
        }

        Vec<T> operator=(std::vector<T> vec){
            /*
            This method will assign the values of a vector to the current vector
            */
            _vec = vec; 
            _size = vec.size();
            return *this;
        }

        bool operator==(Vec<T> vec){
            /*
            This method will compare two vectors and return true if they are equal
            */
            if(_size != vec.get_size()){
                return false;
            }
            for(int i = 0; i < _vec.size(); i++){
                if (_vec[i] != vec.get_val(i)){
                    return false;
                }
            }
            return true;
        }

        bool operator!=(Vec<T> vec){
            /*
            This method will compare two vectors and return true if they are not equal
            */
            if(_size != vec.get_size()){
                return true;
            }
            for(int i = 0; i < _vec.size(); i++){
                if (_vec[i] != vec.get_val(i)){
                    return true;
                }
            }
            return false;
        }

        virtual bool operator<(Vec<T> vec){
            /*
            This method will compare two vectors and return true if the current vector is less than the other vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            
            return norm() < vec.norm();
        }

        virtual bool operator<=(Vec<T> vec){
            /*
            This method will compare two vectors and return true if the current vector is less than the other vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            
            return norm() <= vec.norm();
        }

        virtual bool operator>(Vec<T> vec){
            /*
            This method will compare two vectors and return true if the current vector is less than the other vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            
            return norm() > vec.norm();
        }

        virtual bool operator>=(Vec<T> vec){
            /*
            This method will compare two vectors and return true if the current vector is less than the other vector
            */
            if(_size != vec.get_size()){
                throw std::invalid_argument("Vector sizes do not match");
            }
            
            return norm() >= vec.norm();
        }

        bool operator==(T scalar){
            /*
            This method will compare the vector to a scalar and return true if they are equal
            */
            for(int i = 0; i < _vec.size(); i++){
                if (_vec[i] != scalar){
                    return false;
                }
            }
            return true;
        }

        T operator[](int idx){
                return _vec[idx];
        }

        virtual Vec<T> project(Vec<T> vec){
            T dot_product = (*this) * vec;
            T scalar = (dot_product / (vec*vec)); 
            return vec*scalar;
        }

        virtual Matrix<T> operator|(Matrix<T> m){
            if (m.verify_matrix(m.get_matrix())){
                std::vector<std::vector<T>> temp_matrix = m.get_matrix();
                for(int i = 0; i < _vec.size(); i++){
                    temp_matrix[i].push_back(_vec[i]);
                }
                
                return Matrix<T>(temp_matrix);
            }
            else{
                throw std::invalid_argument("Matrix is not valid");
            }
        }

        virtual T operator~(){
            /*
            This method will return length of the vector
            */
            return norm();
            
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec& obj){
            os << "[";
            for (int i = 0; i < obj._vec.size(); i++){
                os << obj._vec[i];
                if(i < obj._vec.size()-1){
                    os<<", ";
                }
            }
            os << "]";
            return os;
        }
    virtual ~Vec() = default;
};
}

#endif