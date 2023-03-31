#include"fmexp.hpp"

template<typename T>
T fmexp::pow(T b, unsigned int exp, int m) {
    if ((b % m) == 0) return 0;
    T prod =  1;
    T acc = b;
    while (exp > 0) {
        if (exp & 1) {
            prod = (acc * prod) % m;
        }
        acc = (acc * acc) % m;
        exp = exp >> 1;
    }
    return prod;
}

// I am lazy OKAY
// #include<iostream>
// #include<chrono>

// int main() {
//     std::cout << fmexp::pow(2047, 5, 1024) << '\n';
//     int s = 0;
//     for (int i; i < 99999; i++) {
//         s += fmexp::pow(i, 5, 16000);
//     }
//     std::cout << s << '\n';
// }