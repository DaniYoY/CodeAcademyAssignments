#include<iostream>

int main(int argc, char const *argv[])
{
    int x{3}, y{7};
    unsigned long res{0};
    res |= x; 
    res <<= 8;
    res |=  y;
    // return std::to_string(res);
    std::cout<< res <<std::endl;
    return 0;
}
