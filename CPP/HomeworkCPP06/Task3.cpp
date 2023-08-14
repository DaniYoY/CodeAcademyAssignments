// Задача 03.
// Дефинирайте функция, която променя стойността на бит от число num на дадена позиция pos на 1:
// u8 u8_set_bit_on(u8 num, u8bitpos pos);

#include <iostream>
#include <string>

typedef unsigned char u8;
typedef unsigned int   u8bitpos;
typedef bool u8bit;

u8 u8_set_bit_on(u8 num, u8bitpos pos){
    u8 mask = 1 << pos;
    return (num | mask); 
}