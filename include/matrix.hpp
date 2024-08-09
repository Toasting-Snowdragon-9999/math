#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
namespace math{
    template <typename T>
    class Matrix {
        private:
            std::vector<std::vector<T>> _matrix;
            int _rows;
            int _cols;

        public: 
            Matrix(){};
            Matrix(std::vector<std::vector<T>> matrix): _matrix(matrix){};
            // Matrix(std::vector<T> rows, std::vector<T> cols){}
            void set_val(std::vector<int> position, T value){
                if (position.size()==2){
                    _matrix[position[0]][position[1]] = value;
                }
                else{
                    throw std::invalid_argument("Position out of bounds");
                }
                
            };

            void transpose (){
                if (!verify_matrix()){
                    throw std::invalid_argument("Position out of bounds");
                }
                std::vector<std::vector<T>> temp;
                for(int i = 0; i < _matrix.size(); i++){
                    for(int j = 0; j < _matrix[i].size(); i++){
                        temp[j][i] = _matrix[i][j];
                    }
                }
                _matrix = temp;
            }

            bool verify_matrix(){
                /*This Method varifies that all rows are the same size*/
                for(int i = 0; i < _matrix.size()-1; i++){
                    if (_matrix[i].size() != _matrix[i+1].size()){
                        return false;
                    }
                }
            }

            std::vector<int> get_size(){
                if (verify_matrix()){
                    std::vector<int> length;
                    length[0] = _matrix.size();
                    length[1] = _matrix[0].size();
                    return length;
                }
                else{
                    throw std::invalid_argument("Position out of bounds");
                }
            }

            Matrix operator+(Matrix m){
                if (verify_matrix() && m.verify_matrix()){
                    std::vector<std::vector<T>> temp;
                    for(int i = 0; i < _matrix.size(); i++){
                        std::vector<T> row;
                        for(int j = 0; j < _matrix[i].size(); j++){
                            row.push_back(_matrix[i][j] + m._matrix[i][j]);
                        }
                        temp.push_back(row);
                    }
                    return Matrix(temp);
                }
                else{
                    throw std::invalid_argument("Position out of bounds");
                }
            }
    };
};

#endif // MATRIX_HPP