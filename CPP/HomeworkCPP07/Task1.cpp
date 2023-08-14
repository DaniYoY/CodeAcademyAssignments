// Задача 01
// Напишете програма, която принтира n на брой "късметлийски" числа, където n е цяло, положително число, въведено
// от потребителя. Едно число е "късметлийско" ако сумата на цифрите му е равна на 7.

#include <iostream>
#include <vector>
int main (){
    unsigned long n{0ul};
    std::cin>> n;
    for (unsigned long i = 0; i <= n; i++)
    {
        
        unsigned long sum{0ul};
        for (unsigned long currNum = i; currNum !=0; currNum /=10)
        {
            sum +=(currNum%10);
        }

        if (sum == 7)
        {
            std::cout << i << std::endl;
        }  
    }
    return 0;
}