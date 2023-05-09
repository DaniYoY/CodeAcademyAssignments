// Задача 11
// Дефинирайте функция за проверка на това дали едно цяло положително число е просто число

bool isPrime (int x){
    if (x == 1 || x == 2 || x ==3){
        return true;
    }
    for (int i = 2; i <= x/2; i++)
    {
        if (x % i ==0){
            return false;
        }
    }
    return true;
}