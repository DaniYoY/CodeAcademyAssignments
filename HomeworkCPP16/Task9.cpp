// Задача 09
// Напишете функция, в която използвате std::unique за да премахнете всички
// повтарящи се съседни символи в c-style стринг

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    char s[] = "aaaaaassrerttttt";
    size_t sizeArr = sizeof (s)/sizeof (*s);
    std::unique(s, (s + sizeArr));
    std::cout << s;

    return 0;
}
