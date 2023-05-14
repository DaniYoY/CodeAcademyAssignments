// Задача 15
// Напишете функция, която приема цяло положително число и връща следващото по големина число със същия брой
// битове, равни на 1.

#include <iostream>

using ui = unsigned char;

ui nextBinNum(ui a){
    ui flag{1};
    for (ui i = flag; i < a; i*=2)
    {
        flag <<= 1u;
        flag |=1;
    }
    
    return flag;
}

int main(){
    ui a{0};
    a = nextBinNum(8);
    std::cout<< a;
    return 0;
}