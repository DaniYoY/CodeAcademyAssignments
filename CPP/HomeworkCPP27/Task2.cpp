// Задача 02
// Напишете собствена версия на std::swap.

#include <iostream>
template<typename T>
void swaping(T* t1, T* t2)
{
    T temp= *t1;
    *t1 = *t2;
    *t2 = temp;
}

int main()
{
    int a{10}, b{20};
    char x{'x'}, y{'y'};
    std:: cout << a << ' ' << b << ' ' << x << ' ' << y << std::endl;

    swaping(&a,&b);
    swaping(&x,&y);
    std:: cout << a << ' ' << b << ' ' << x << ' ' << y;
    return 0;
}
