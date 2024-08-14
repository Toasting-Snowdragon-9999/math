#ifndef CUSTOM_FLOAT_HPP
#define CUSTOM_FLOAT_HPP
#include <vector>
#include <iostream>
#include <cmath>

namespace math{
class c_float{
    
    private: 
        float _float;
    
    public: 
        c_float();

        c_float(float i);
        /**
         * @brief Sends a message over the socket connection to the endpoint. 
         * 
         * @param buffer The pointer to the char buffer containing the data to send. 
         * @param length The number of bytes to send. 
         * @return true The send was succesfull. 
         * @return false The send was NOT succesfull. 
         */
        void set_val(float i);

        float get_val() const;

        c_float operator+(c_float i);

        c_float operator-(c_float i);

        c_float operator*(c_float i);

        c_float operator/(c_float i);

        c_float operator%(c_float i);

        c_float& operator=(float i);

        double operator^(c_float i);

        bool operator==(c_float i);

        bool operator<(c_float i);

        bool operator>(c_float i);

        bool operator<=(c_float i);

        bool operator>=(c_float i);

        bool operator!=(c_float i);

        c_float& operator+=(c_float i);

        c_float& operator-=(c_float i);

        c_float& operator*=(c_float i);

        c_float& operator/=(c_float i);

        c_float& operator%=(c_float i);

        c_float& operator++();

        c_float& operator--();
    
        c_float& operator~();

        friend std::ostream& operator<<(std::ostream& os, const c_float& obj);
};
}
#endif  // CUSTOM_FLOAT_HPP