// Задача 1
// Дефинирайте макро константи DEG_TO_RAD и RAD_TO_DEG за преобразуване на ъгъл от градуси в
// радиани и обратно (чрез умножаване по константата), съответно

#define PI 3.14
#define DEG_TO_RAD(x) (x)*PI/180
#define RAD_TO_DEG(x) (x)*180/PI

#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << RAD_TO_DEG(1.57) << std::endl; //90
    std::cout << DEG_TO_RAD(57.3) << std::endl; // 1

    return 0;
}
