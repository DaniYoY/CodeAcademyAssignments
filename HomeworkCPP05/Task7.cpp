// Задача 07
// Напишете функция, която приема вектор от стрингове и принтира най-често срещания във вектора
// стринг. Ако има повече от един такъв (с еднакъв брой срещания), то функцията трябва да принтира
// всичките.


#include <iostream>
#include <string>
#include <vector>
#include <map>

void printDupes(const std::vector<std::string> & stringsVector){
  int mostFrequesnt{0};
  std::map<std::string, int> result;
  for (int i = 0; i < stringsVector.size(); i++)
  {
    ++result[stringsVector[i]];
    if(result[stringsVector[i]]> mostFrequesnt){
      mostFrequesnt = result[stringsVector[i]];
    }
  }
  
  for (int i = 0; i < stringsVector.size(); i++)
  {
    if (result[stringsVector[i]] == mostFrequesnt)
    {
      std::cout << stringsVector[i]<<std::endl;
    }
  }
    return;
}






