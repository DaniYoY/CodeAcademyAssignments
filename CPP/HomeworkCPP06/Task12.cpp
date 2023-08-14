// Задача 12
// Напишете функция, която приема vector от цели положителни числа и намира двойката числа в конейнера с най-
// голяма XOR стойност
#include <vector>

using ui = unsigned int;
using vec = std::vector<ui>;
vec findBiggestXORPair(vec numbers){
    vec xorNums(numbers.size()), result;
    ui biggestXor{0},interim{0}, bigNum{0},secBigNum{0};

    for (int i = 0; i < numbers.size()-1; i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            interim = numbers[i]^numbers[j];
            if (interim>biggestXor)
            {
                biggestXor = interim;
                bigNum = numbers[i];
                secBigNum =numbers[j];
            }
        }
    }
    result.push_back(secBigNum);
    result.push_back(bigNum);
    return result;
}