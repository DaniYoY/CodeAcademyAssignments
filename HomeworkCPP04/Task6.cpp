// Задача 06
// Дефинирайте собствена версия на библиотечната функция abs от <cmath>, която приема double и връща double, който е
// абсолютната стойност на аргумента (математически модул - |x| )

double absolute (double x){
    if(x < 0){
        return -1*x;
    }
    return x;
}