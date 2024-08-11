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
            Matrix(): _rows(0), _cols(0){};
            Matrix(std::vector<std::vector<T>> matrix): _matrix(matrix), _rows(matrix.size()), _cols(matrix[0].size()){};
            Matrix(int rows, int cols): _rows(rows), _cols(cols){
                _matrix.resize(rows, std::vector<T>(cols));
            };

            void set_val(std::vector<int> position, T value){
                if (position.size()==2){
                    _matrix[position[0]][position[1]] = value;
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            std::vector<T> get_rows(int idx) const { 
                return _matrix[idx]; 
            }
            
            std::vector<T> get_cols(int idx) const {
                std::vector<T> temp;
                for(int i = 0; i < _matrix.size(); i++){
                    temp.push_back(_matrix[i][idx]);
                }
                return temp; 
            }

            void transpose (){
                if (!verify_matrix()){
                    throw std::invalid_argument("Matrix is not valid");
                }
                std::vector<std::vector<T>> temp;
                for(int i = 0; i < _matrix.size(); i++){
                    for(int j = 0; j < _matrix[i].size(); i++){
                        temp[j][i] = _matrix[i][j];
                    }
                }
                _matrix = temp;
            }

            bool verify_matrix(std::vector<std::vector<T>> m){
                /*This Method varifies that all rows are the same size*/
                for(int i = 0; i < m.size()-1; i++){
                    if (m[i].size() != m[i+1].size()){
                        return false;
                    }
                }
                return true;
            }

            std::vector<int> get_size(){
                if (verify_matrix(_matrix)){
                    std::vector<int> length;
                    length[0] = _matrix.size();
                    length[1] = _matrix[0].size();
                    return length;
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            Matrix<T> operator+(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
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
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            Matrix<T> operator+(T m){
                if (verify_matrix(_matrix)){
                    std::vector<std::vector<T>> temp;
                    for(int i = 0; i < _matrix.size(); i++){
                        std::vector<T> row;
                        for(int j = 0; j < _matrix[i].size(); j++){
                            row.push_back(_matrix[i][j] + m);
                        }
                        temp.push_back(row);
                    }
                    return Matrix(temp);
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            Matrix<T> operator-(T m){
                if (verify_matrix(_matrix)){
                    std::vector<std::vector<T>> temp;
                    for(int i = 0; i < _matrix.size(); i++){
                        std::vector<T> row;
                        for(int j = 0; j < _matrix[i].size(); j++){
                            row.push_back(_matrix[i][j] - m);
                        }
                        temp.push_back(row);
                    }
                    return Matrix<T>(temp);
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            Matrix<T> operator-(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    std::vector<std::vector<T>> temp;
                    for(int i = 0; i < _matrix.size(); i++){
                        std::vector<T> row;
                        for(int j = 0; j < _matrix[i].size(); j++){
                            row.push_back(_matrix[i][j] - m._matrix[i][j]);
                        }
                        temp.push_back(row);
                    }
                    return Matrix<T>(temp);
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            Matrix<T> operator*(T scalar){
                if (verify_matrix(_matrix)){
                    std::vector<std::vector<T>> temp;
                    for(int i = 0; i < _matrix.size(); i++){
                        std::vector<T> row;
                        for(int j = 0; j < _matrix[i].size(); j++){
                            row.push_back(_matrix[i][j] * scalar);
                        }
                        temp.push_back(row);
                    }
                    return Matrix<T>(temp);
                }
                else{
                    throw std::invalid_argument("Matrix is not valid");
                }
            }

            void print(){
                for(int i = 0; i < _matrix.size(); i++){
                    std::cout << "[";
                    for(int j = 0; j < _matrix[i].size(); j++){
                        std::cout << _matrix[i][j] << " ";
                    }
                    std::cout << "]" << std::endl;
                }
            }

            std::vector<std::vector<T>> get_matrix(){
                return _matrix;
            }

            friend std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
                os << "[";
                for (int i = 0; i < obj.get_cols(0).size(); ++i) {
                    os << "";
                    for (int j = 0; j < obj.get_rows(0).size(); ++j) {
                        os << obj.get_rows(i)[j];
                        if (j < obj.get_rows(i).size() - 1) {
                            os << ", ";
                        }
                    }
                    if( i < obj.get_cols(0).size()-1){
                        os << "" << std::endl;
                    }
                    else{
                        os << "";
                    }
                }
                os << "]" << std::endl;
                return os;
            }
    };

    template <typename T>
    class TransformatioMatrix: public Matrix<T>{
        private:
            std::vector<std::vector<T>> _matrix;
            int _rows;
            int _cols;
            std::vector<int> _size;
            std::vector<std::vector<T>> _rotmat;
            std::vector<T> _translate;

        public: 
            TransformatioMatrix(){
                _matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
                _size = {4, 4};
            }
            TransformatioMatrix(std::vector<std::vector<T>> matrix): _matrix(matrix){};
            TransformatioMatrix(math::Matrix<T> matrix){
                _matrix = matrix.get_matrix();
            }
            TransformatioMatrix(std::vector<std::vector<T>> rotmat, std::vector<T> translate): _rotmat(rotmat), _translate(translate){
                _matrix = rotmat;
                _matrix.push_back(translate);
                if(verify_matrix(_matrix)){
                    _size = {rotmat.size(), rotmat[0].size()};
                }
                else{
                    throw std::invalid_argument("Position out of bounds");
                }
            }
    };
};

#endif // MATRIX_HPP