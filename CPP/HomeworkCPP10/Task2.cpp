// Задача 02
// Изберете поне десет функции от всички задачи за самоподготовка, давани до момента, които биха били добри
// кандидати за inline и ги дефинирайте като такива.
#include <exception>
#include<string>
#include<map>
#include<vector>
inline unsigned int generateRandomNumber( unsigned int lower, unsigned int upper, unsigned int& state){
    unsigned int num = state;
    num ^= num << 13;
    num ^= num >> 17;
    num ^= num << 5;
    state = num;
    return (num % (upper - lower)) + lower;
}

inline float divide(float num, float divisor){
    
    if(divisor == 0){
        throw std::exception();
    }
    return num/divisor;
}
inline bool isStingAcceptableLen(int size, const std::string &s){
    return size <= s.size();
}
inline bool isOperator(char ch){
    if (ch == '+'
     || ch == '-'
     || ch == '*'
     || ch == '/')
    {
        return true;
    }
    return false;
}
// inline Player & determineNextPlayer(TicTakToe & game){
//     if (game.players[0].moves == game.players[1].moves)
//     {
//         return  game.players[0];
//     }
//     return game.players[1];
//  }
inline int calculateDiversChars(const std::string & s){
    std::map<char,int> charecters;
    for (int i = 0; i < s.size()-1; i++)
    {
        charecters[s[i]]++;
    }
    return charecters.size();    
}
inline bool isOrderedLexicographically(std::vector<std::string> v1){
    for (int i = 0; i < v1.size() -1; i++)
    {
        if (v1[i] > v1[i+1])
        {
            return false;
        }
    }
    return true;
}
inline std::vector<int> join(std::vector<int> & v1, std::vector<int> & v2){
    for (int i = 0; i < v2.size(); i++)
    {
        v1.push_back(v2[i]);
    }
    return v1;
}
inline bool equalsSequenceZero(const std::vector<int> & numbers){
    int sum{0};
    for (int i = 0; i < numbers.size(); i++)
    {
        sum +=numbers[i];
    }
    return sum == 0;
}
inline void swapValues(int numA, int numB)
{
    int temp{numA};
    numA = numB;
    numB = temp;
    return;
}