// Задача 07
// Дефинирайте собствена версия на библиотечната функция ceil от <cmath>, която приема double и връща най-близкото до него
// цяло число, не по-малко от числото (в частност, закръгля нагоре за положителни числа)

int ceiling (double x){
    int x1 = x;
    x1 != x ?  x1++ : x1;
    return x1; 
}