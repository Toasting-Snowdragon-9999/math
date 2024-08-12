#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include "math_exceptions.hpp"

namespace math{
    template <typename T>
    class Matrix {
        private:
            std::vector<std::vector<T>> _matrix;
            int _rows;
            int _cols;

        public: 
            Matrix(): _rows(0), _cols(0){};
            Matrix(std::vector<std::vector<T>> matrix): _matrix(matrix), _rows(matrix.size()), _cols(matrix[0].size()){}
            Matrix(int rows, int cols): _rows(rows), _cols(cols){
                _matrix.resize(rows, std::vector<T>(cols));
            }

            void set_val(std::vector<int> position, T value){
                if (position.size()==2){
                    _matrix[position[0]][position[1]] = value;
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::RANGE_ERROR, "Position out of bounds");
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

            Matrix<T>& transpose() {
                if (!verify_matrix(_matrix)) {
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
                std::vector<std::vector<T>> temp(_cols, std::vector<T>(_rows));  // Correctly initialize the size of temp
                for (int i = 0; i < _rows; i++) {
                    for (int j = 0; j < _cols; j++) {
                        temp[j][i] = _matrix[i][j];
                    }
                }
                _matrix = temp;
                std::swap(_rows, _cols);  // Update the rows and columns
                return *this;
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

            bool is_square(){
                if (verify_matrix(_matrix)){
                    if(_matrix.size() == _matrix[0].size()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            double norm(){
                /*
                This method calculates the frobenius norm of a matrix
                */
                if (verify_matrix(_matrix)){
                    double sum = 0.0;
                    for(int i = 0; i < _matrix.size(); i++){
                        for(int j = 0; j < _matrix[i].size(); j++){
                            sum += _matrix[i][j] * _matrix[i][j];
                        }
                    }
                    return sqrt(sum);
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            double det(){
                if (verify_matrix(_matrix)){
                    if(_matrix.size() == 2 && _matrix[0].size() == 2){
                        return _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
                    }
                    else{
                        if (!is_square()){
                            throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not square!");
                        }
                        double sum = 0;
                        for(int i = 0; i < _matrix.size(); i++){
                            std::vector<std::vector<T>> temp;
                            for(int j = 1; j < _matrix.size(); j++){
                                std::vector<T> row;
                                for(int k = 0; k < _matrix.size(); k++){
                                    if(k != i){
                                        row.push_back(_matrix[j][k]);
                                    }
                                }
                                temp.push_back(row);
                            }
                            math::Matrix<T> temp_matrix = temp;
                            sum += pow(-1, i) * _matrix[0][i] * temp_matrix.det();
                        }
                        return sum;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> adj(){
                if (verify_matrix(_matrix)){
                    if(is_square()){
                        std::vector<std::vector<T>> cofactor_matrix;
                        for(int i = 0; i < _matrix.size(); i++){
                            std::vector<T> row;
                            for(int j = 0; j < _matrix.size(); j++){
                                std::vector<std::vector<T>> minor_matrix;
                                for(int k = 0; k < _matrix.size(); k++){
                                    std::vector<T> minor_row;
                                    for(int l = 0; l < _matrix.size(); l++){
                                        if(k != i && l != j){
                                            minor_row.push_back(_matrix[k][l]);
                                        }
                                    }  
                                        if (minor_row.size() > 0){
                                            minor_matrix.push_back(minor_row);
                                        }
                                }
                                try{
                                    Matrix<T> minor_matrix_object(minor_matrix);
                                    if (minor_matrix_object.verify_matrix(minor_matrix)){
                                        // std::cout << "Minor Matrix is valid" << std::endl;
                                    }
                                    if (minor_matrix_object.is_square()){
                                        // std::cout << "Minor Matrix is square" << std::endl;
                                    }
                                    row.push_back(pow(-1, i+j) * minor_matrix_object.det());
                                }catch(math::exceptions::MathException e){
                                    std::cout << e.GetInfo() << std::endl;
                                }
                            }
                            cofactor_matrix.push_back(row);
                        }
                        Matrix<T> adj_matrix(cofactor_matrix);
                        Matrix<T> return_matrix = adj_matrix.transpose();
                        return return_matrix;
                    }
                    else{throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not square!");}
                }
                else{throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");}
                
            }

            
            math::Matrix<T> inverse(){
                /*
                Adjugate method (also called the classical adjoint method or cofactor method).
                This uses the method above to compute the inverse of a matrix
                */

                if(det() != 0){
                    math::Matrix<T> temp_matrix = adj();
                    return temp_matrix * (1/det());
                }
                
                else{throw math::exceptions::MathException(math::exceptions::DET_ERROR, "Determinant is 0, matrix is not invertible!");}
            }

            std::vector<int> get_size(){
                if (verify_matrix(_matrix)){
                    std::vector<int> length;
                    length[0] = _matrix.size();
                    length[1] = _matrix[0].size();
                    return length;
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> operator+(Matrix<T> m){
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
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> operator+(T m){
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
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> operator-(Matrix<T> m){
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
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> operator*(T scalar){
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
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T> operator*(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    if(get_rows(0).size() == m.get_cols(0).size()    || get_cols(0).size() == m.get_rows(0).size()){
                        std::vector<std::vector<T>> temp;
                        for(int i = 0; i < _matrix.size(); i++){
                            std::vector<T> row;
                            for(int j = 0; j < m.get_cols(0).size(); j++){
                                T sum = 0;
                                for(int k = 0; k < get_cols(0).size(); k++){
                                    sum += _matrix[i][k] * m.get_rows(k)[j];
                                }
                                row.push_back(sum);
                            }
                            temp.push_back(row);
                        }
                        return Matrix<T>(temp);

                    }
                    else{
                        throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                    }
                }  
            }

            math::Matrix<T>& operator=(std::vector<std::vector<T>> m){
                _matrix = m;
                return *this;
            }

            math::Matrix<T>& operator=(Matrix m){
                _matrix = m.get_matrix();
                return *this;
            }

            bool operator==(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    for(int i = 0; i < _matrix.size(); i++){
                        for(int j = 0; j < _matrix[i].size(); j++){
                            if(_matrix[i][j] != m._matrix[i][j]){
                                return false;
                            }
                        }
                    }
                    return true;
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            bool operator!=(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    for(int i = 0; i < _matrix.size(); i++){
                        for(int j = 0; j < _matrix[i].size(); j++){
                            if(_matrix[i][j] != m._matrix[i][j]){
                                return true;
                            }
                        }
                    }
                    return false;
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::Matrix<T>& operator~(){
                transpose();
                return *this;
            }

            math::Matrix<T> operator^(int8_t power){
                if (power == -1){
                    return inverse();
                }
                if (power > 0){
                    if(is_square()){
                        Matrix<T> temp = *this;
                        for(int i = 0; i < power; i++){
                            temp = temp * *this;
                        }
                        return temp;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::RANGE_ERROR, "Power must be greater than 0");
                }
            }

            bool operator>(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    if(_matrix.size() > m.get_matrix().size()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            bool operator<(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    if(_matrix.size() < m.get_matrix().size()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            bool operator>=(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    if(_matrix.size() >= m.get_matrix().size()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            bool operator<=(Matrix<T> m){
                if (verify_matrix(_matrix) && m.verify_matrix(m.get_matrix())){
                    if(_matrix.size() <= m.get_matrix().size()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Matrix is not valid, one or more rows are not the same size!");
                }
            }

            std::vector<T> operator[](int row){
                return _matrix[row];
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

};

#endif // MATRIX_HPP