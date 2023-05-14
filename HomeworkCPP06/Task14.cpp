// Задача 14
// Напишете функция, която приема две цели положителни числа и връща броя различаващи се битове в побитовите
// им репрезентации (Hamming distance).

int hammingDistance( unsigned int a, unsigned int b){
    unsigned int check{0}, counter{0}; 
    check = a ^ b;

     for (int i = check; i != 0; i/=2)
    {
        if(1 & i){
            counter++;
        }
    }
    return counter;
}