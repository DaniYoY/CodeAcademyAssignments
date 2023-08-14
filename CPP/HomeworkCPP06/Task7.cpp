// Задача 07.
// Дефинирайте функция, която променя (обръща) стойностите на всички битове от число num:
// u8 u8_toggle_bits(u8 num);

using u8 = unsigned char;

u8 u8_toggle_bits(u8 num){
     num ^=num;
     return num;
}

