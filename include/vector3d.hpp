#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <vector>
#include <iostream>

namespace math{
    template <typename T>
    class Vec3d {
        private: 
            std::vector<T> _vec;
            int _size;

        public: 
            Vec3d(){
                _vec = {0, 0, 0};
            };
            Vec3d(std::vector<T> vec){
                if (vec.size() == 3){
                    _vec = vec;
                    _size = vec.size();
                }
                else{
                    throw std::invalid_argument("Vector size must be 3");
                }
            };

            void set_val(int position, T value){
                if (position < _size){
                    _vec[position] = value;
                }
                else{
                    throw std::invalid_argument("Position out of bounds");
                }
            };

            T get_val(int idx){
                return _vec[idx];
            }

            void print(){
                std::cout << "["; 
                for(int i = 0; i < _vec.size(); i++){
                    std::cout << _vec[i] << " ";
                }
                std::cout << "]" << std::endl;
            }

            Vec3d operator+(Vec3d vec){
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] + vec.get_val(i));
                }
                return Vec3d(temp);
            }

            Vec3d operator-(Vec3d vec){
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] - vec.get_val(i));
                }
                return Vec3d(temp);
            }

            Vec3d operator*(Vec3d vec){
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] * vec.get_val(i));
                }
                return Vec3d(temp);
            }

            Vec3d operator/(Vec3d vec){
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] / vec.get_val(i));
                }
                return Vec3d(temp);
            }

            Vec3d operator*(T scalar){
                std::vector<T> temp;
                for(int i = 0; i < _vec.size(); i++){
                    temp.push_back(_vec[i] * scalar);
                }
                return Vec3d(temp);
            }

    };
};

#endif // VECTOR3D_HPP