// Задача 05.
// Дефинирайте функция, която връща стойността на бит от число num на дадена позиция pos на val:
// u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val);

#include <iostream>
#include <string>

typedef unsigned char u8;
typedef unsigned int   u8bitpos;
typedef bool u8bit;

u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val){
    u8 mask = 1 << pos; 
    return (num & ~mask) | (val<< pos); 
}