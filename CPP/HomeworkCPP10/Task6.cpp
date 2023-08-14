// Задача 06
// Дефинирайте функция, която претърсва за последователност от цели числа в друга последователност,
// използвайки initializer_list параметри. Напишете функцията с trailing return type.

#include <initializer_list>
#include <iostream>
using ls = std::initializer_list<int>;
auto getLostNumbers(const ls& group, const ls& lostParty) -> ls
{
    for (ls::const_iterator iter = group.begin(); iter != group.end(); iter++)
    {
        bool isNotFound{true};
        if (*iter == *lostParty.begin())
        {
            ls::const_iterator it = lostParty.begin();
            for (int i = 0; i < lostParty.size(); i++)
            {
                if (*(iter + i) != *(it + i))
                {
                    isNotFound = false;
                }
            }
            if (!isNotFound)
            {
                return group;
            }
        }
    }
    return lostParty;
}

int main(int argc, char const *argv[])
{

    for (int i : getLostNumbers({1,2,3,4,5,},{7,4}))
    {
        std::cout<< i << ' ';
    }
    
    return 0;
}

