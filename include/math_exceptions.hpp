#ifndef MATH_EXCEPTIONS_HPP
#define MATH_EXCEPTIONS_HPP

#include<iostream>
#include<exception>
namespace math{
namespace exceptions {

    enum ExceptionType{
        RANGE_ERROR = 1,
        MATRIX_SIZE_ERROR = 2,
        DET_ERROR = 3
        
    }; 

    class MathException : public std::exception {
        public:
            MathException(ExceptionType excption_type, std::string info) : _type(excption_type), _info(info){}
            
            std::string GetTypeString(){
                switch (_type){
                    case RANGE_ERROR:
                        return "Range Error";
                        break;
                    case MATRIX_SIZE_ERROR:
                        return "Invalid matrix size, one or more rows are not the same size!";
                        break;
                    case DET_ERROR:
                        return "Determinant is zero!";
                        break;
                }
            }

            ExceptionType GetType() { return _type; }
            std::string GetInfo() { return _info; }

        private: 
            ExceptionType _type; 
            std::string _info; 
        
    }; 
} // namespace exceptions
} // namespace math 
#endif