// Задача 02
// Създайте списък от int стойности. Създайте 2 копия на списъка:
// ● Едното започва със сортирани във възходящ ред четни, следвани от сортирани
// в низходящ ред нечетни стойности.
// ● Едното започва със сортирани във низходящ ред положителни, следвани от
// сортирани във възходящ ред отрицателни стойности.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> ogList{-2, -10, -5, -6, 9,8,3,7,-20,50,0};

    std::vector<int> asc(ogList.size()), desc(ogList.size());
    std::sort(ogList.begin(), ogList.end(),
              [](int a,int b)  -> bool
              {
                  if(a%2==0){
                    if (b%2==0)
                    {
                        return a<b;
                    }else{
                        return false;
                    }
                  }else{
                    if (b%2==0)
                    {
                        return true;
                    }else{
                        return a>b;
                    }
                  }
              });
    std::copy(ogList.begin(), ogList.end(), asc.begin());
    std::sort(ogList.begin(), ogList.end(),
              [](int a, int b)
              {
                     if(a>0){
                    if (b>0)
                    {
                        return a>b;
                    }else{
                        return false;
                    }
                  }else{
                    if (b>0)
                    {
                        return true;
                    }else{
                        return a<b;
                    }
                  }
              });
    std::copy(ogList.begin(), ogList.end(), desc.begin());
    for (size_t i = 0; i < asc.size(); i++)
    {
        std::cout << asc[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < desc.size(); i++)
    {
        std::cout << desc[i] << ' ';
    }
    return 0;
}