// Задача 08.
// Дефинирайте функция, която обръща стойностите на битовете на число num в обратен ред:
// u8 u8_reverse_bits(u8 num)

#include <iostream>
#include <string>

typedef unsigned char u8;
typedef unsigned int   u8bitpos;
typedef bool u8bit;

u8 u8_reverse_bits(u8 num){
    u8 result{0};
    u8bit bit = 1;
    int pos{0};
    for (int i = num; i !=0; i/=2)
    {
        if (i&bit)
        {
            result |= (1<<pos);
        }else{
            result<<1;
        }
        pos++;
    }
    return result;
}

