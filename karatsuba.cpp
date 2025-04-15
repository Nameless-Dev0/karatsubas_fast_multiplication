/*
This is a recursive implementation of karatsuba's fast 
multiplication algorithm for large integers.
*/

#include <iostream>
#include <math.h>
#include <cstdint>
#include <stdexcept> 

uint64_t karatsuba(int x, int y){
    if(x < 0 || y < 0){
        std::cout<<"Negative numbers are not supported. ";
        abort();
    }

    else if(x < 10 || y < 10)
        return x * y;
    else{
        int n = std::max(std::to_string(x).length(), std::to_string(x).length()); 
        int shift_by_half = pow(10, (n / 2));
        int revert_shift = pow(10, n);
        
        uint64_t a = x / shift_by_half;
        uint64_t b = x % shift_by_half;
        uint64_t c = y / shift_by_half;
        uint64_t d = y % shift_by_half;

        uint64_t ac = karatsuba(a,c);
        uint64_t bd = karatsuba(b, d);
        uint64_t ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

        return ac * revert_shift + ad_plus_bc * shift_by_half + bd;
    }
    
}

int main(){
    std:: cout<< karatsuba(942,10) << '\n';

}
