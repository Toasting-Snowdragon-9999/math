#ifndef GENERAL_MATH_HPP
#define GENERAL_MATH_HPP

#include <iostream>
#include "math_exceptions.hpp"
/*
ALL THESE CONSTANT HAVE A 31 DECIMAL PLACES OF PRECISION

*/
namespace math{
    /*
    PI constant
    */
    const double PI = 3.1415926535897932384626433832795;

    /*
    PI squared
    */
    const double PI2 = 9.8696044010893586188344909998762;

    /* 
    PI divided by two
    */ 
    const double PI_2 = 1.5707963267948966192313216916397;

    /*
    
    */
    const double PI_4 = 0.7853981633974483096156608458198;

    /*
    Constant used for converting degrees to radians
    */
    const double DEG2RAD = PI/180.;

    /*
    Constant used for converting radians to degrees
    */
    const double RAD2DEG = 180./PI;

    /*
    E constant
    */
    const double E = 2.7182818284590452353602874713526;

    /*
    Value of root 2
    */
    const double ROOT_TWO = 1.4142135623730950488016887242096; 
    
    /*
    Value of root 3
    */
    const double ROOT_THREE = 1.7320508075688772935274463415058;

    /*
    Gamma, the euler-mascheroni constant
    */
    const double GAMMA = 0.5772156649015328606065120900824;


    template<typename T>
    T abs(T x){
        return x < 0 ? -x : x;
    }

    template<typename T>
    T max(T a, T b){
        return a > b ? a : b;
    }

    template<typename T>
    T min(T a, T b){
        return a < b ? a : b;
    }

    
}
#endif