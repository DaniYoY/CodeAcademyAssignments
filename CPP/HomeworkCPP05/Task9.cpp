// Задача 09
// Напишете функция, която приема 2 стринга и 1 празен вектор от стрингове, който попълва с
// всички подстрингове от първия стринг параметър, които са разделени един от друг със
// някой от символите от втория стринг параметър.
// Например, при входни данни :
// "Hello;My name&is-Roger."
// и+
// "; -"
// за “списък с delimiter-и” , то резултатът би бил вектор с елементи:
// {"Hello", "My", "name&is", "Roger"}

#include <iostream>
#include <string>
#include <vector>

void divideInVectors(const std::string & source, std::string & delimeter, std::vector<std::string> result){
    std::string word{""};
    bool isDelimiter = false;
    for (int i = 0; i < source.size(); i++)
    {
        for (int j = 0; j < delimeter.size(); j++)
        {
            if (source[i] == delimeter[j])
            {
                isDelimiter = true;
                break;
            }else{
                isDelimiter = false;
            }
          
        }

        if(isDelimiter || (i == source.size()-1)){
                result.push_back(word);
                word ="";
        }else{
                word +=source[i];
        }
         
        
    }
    for (int i = 0; i < result.size(); i++)
    {
        std::cout<< result[i]<<std::endl;
    }
    
    return; 
}

int main(){
    std::vector<std::string> result;
    std::string deli {"; -"};
    divideInVectors("Hello;My name&is-Roger.",deli, result);
}