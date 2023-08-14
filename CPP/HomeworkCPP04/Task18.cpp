// Задача 18
// Дефинирайте функция за пресмятане на факториел (factorial) на положително цяло число.

int factorial (int x){
    for (int i = x; i >= 1; --i)
    {
        x *=i;
    }
    return x;
}