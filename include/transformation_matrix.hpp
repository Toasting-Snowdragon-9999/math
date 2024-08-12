#ifndef TRANSFORMATION_MATRIX_HPP
#define TRANSFORMATION_MATRIX_HPP
#include <iostream>
#include "matrix.hpp"
#include "vector3d.hpp"
#include "math_exceptions.hpp"

namespace math{
    template <typename T>
    class TransformatioMatrix: public Matrix<T>{
        private:
            std::vector<std::vector<T>> _matrix;
            int _rows;
            int _cols;
            std::vector<int> _size;

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
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Transformation Matrix is not valid, one or more rows are not the same size!");
                }
            }

            TransformatioMatrix(std::vector<std::vector<T>> rotmat, math::Vec3d<T> translate): _rotmat(rotmat), _translate(translate){
                _matrix = rotmat;
                _matrix.push_back(translate.get_vector());
                if(verify_matrix(_matrix)){
                    _size = {_matrix.size(), _matrix[0].size()};
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Transformation Matrix is not valid, one or more rows are not the same size!");
                }
            }

            TransformatioMatrix(std::vector<std::vector<T>> rotmat, std::vector<T>translate, std::vector<T> ss): _rotmat(rotmat), _translate(translate){
                _matrix = rotmat;
                _matrix.push_back(translate.get_vector());
                for(int i = 0; i < ss.size(); i++){
                    _matrix[i].push_back(ss[i]);
                }
                if(verify_matrix(_matrix)){
                    _size = {_matrix.size(), _matrix[0].size()};
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Transformation Matrix is not valid, one or more rows are not the same size!");
                }
            }

            TransformatioMatrix(std::vector<std::vector<T>> rotmat, math::Vec3d<T> translate, std::vector<T> ss): _rotmat(rotmat), _translate(translate){
                _matrix = rotmat;
                _matrix.push_back(translate.get_vector());
                for(int i = 0; i < ss.size(); i++){
                    _matrix[i].push_back(ss[i]);
                }
                if(verify_matrix(_matrix)){
                    _size = {_matrix.size(), _matrix[0].size()};
                }
                else{
                    throw math::exceptions::MathException(math::exceptions::MATRIX_SIZE_ERROR, "Transformation Matrix is not valid, one or more rows are not the same size!");
                }
            }

            math::TransformatioMatrix<T> translation(std::vector<T> translate){
                _translate = translate;
                _matrix[3] = translate;
                return TransformatioMatrix(_matrix);
            }

            math::TransformatioMatrix<T> rotation(std::vector<std::vector<T>> rotmat){
                for(int i = 0; i < rotmat.size(); i++){
                    _matrix[i] = rotmat[i];

                }
                return TransformatioMatrix(_matrix);
            }
            
    };

}


#endif // TRANSFORMATION_MATRIX_HPP