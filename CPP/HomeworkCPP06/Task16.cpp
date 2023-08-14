// Задача 16
// Напишете функция, която връща позициите на най-дясната и най-лявата единици в бинарната репрезентация на
// цяло положително число.
#include <iostream>
using ui = unsigned int;

void showFirstLastOnesPosition (ui num){
    int firstPos{0}, lastPos{0}; 
    bool isFirstInSearch = true;
    switch (num)
    {
    case 0:
        firstPos =-1;
        lastPos =-1;        
        break;
    case 1:
        firstPos = lastPos = 1;
        break;
    default:
        for (int i = num; i != 0; i /=2)
        {
            if (isFirstInSearch)
            {
                firstPos++;
                if(i & 1){
                    isFirstInSearch = false;
                }   
            }
            
            lastPos++;
        }

        break;
    }
    std::cout << lastPos <<" "<<firstPos;
}
int main(){
    showFirstLastOnesPosition(3);
    return 0;
}