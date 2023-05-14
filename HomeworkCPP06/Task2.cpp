// Задача 02.
// Дефинирайте функция, която връща стойността на бит от число num на дадена позиция pos:
// u8bit u8_get_bit(u8 num, u8bitpos pos);

#include <iostream>
#include <string>

typedef unsigned char u8;
typedef unsigned int   u8bitpos;
typedef bool u8bit;

u8bit u8_get_bit(u8 num, u8bitpos pos){
    u8bit isOne{true};

    return (num & (1 << pos))>>pos;
};