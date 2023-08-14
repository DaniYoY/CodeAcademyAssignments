// Задача 32
// Напишете програма, която принтира следната информация за въведено от потребителя цяло
// положително число под формата на десетична, двоична, осмична или шестнадесетична литерала:
// ● Числото в десетичен вид
// ● Числото в бинарен вид
// ● Числото в шестнадесетичен вид
// ● Числото в осмичен вид
// ● Четно или нечетно е числото
// ● Просто ли е числото
// ● Броя на цифрите на числото (в десетичен вид)
// ● Сумата на цифрите на числото (в десетичен вид)
// ● Числото с обърнат наобратно ред на цифрите (ако сме въвели 506, то тук принтираме 605)
// ● Дали числото е палиндром

#include <iostream>
#include <string>
int verifyNumberInput(std::string & s);
bool isStingAcceptableLen(int size, const std::string &s);
std::string printBinaryValue(int number);
std::string printHexValue(int number);
std::string printOctValue(int number);
std::string isOddNumber(int number);
std::string isPrimeNumber(int number);
std::string numberOfDigits(int number);
std::string sumOfDigits(int number);
std::string reverseNumber(std::string & numberStr);
std::string isPalindrome(int number);
std::string convertDecToBinString(int number);

int showNumInfo(){
    int number{0};
    std::string inputNumber;
    std::cout << "Endter an integer: ";
    std::cin >> inputNumber;
    std::cout << std::endl;
    number = verifyNumberInput(inputNumber);
    std::cout << number << std::endl;
    std::cout <<"binary " << printBinaryValue(number) << std::endl;
    std::cout << "hex " << printHexValue(number) << std::endl;
    std::cout << "oct " << printOctValue(number) << std::endl;
    std::cout << isOddNumber(number) << std::endl;
    std::cout << isPrimeNumber(number) << std::endl;
    std::cout << "Num of digits is " << numberOfDigits(number) << std::endl;
    std::cout << "Sum of digits is" <<sumOfDigits(number) << std::endl;
    std::cout << "Reversed the number is "<<reverseNumber(inputNumber) << std::endl;
    std::cout << isPalindrome(number) << std::endl;
    return 0;
}


int verifyNumberInput(std::string & s){
    int result{1};
    if (s.empty())
    {
        return result;
    }
    
    if(isStingAcceptableLen(3,s) && ((s[0] == '0' && s[1] == 'x') || (s[0] == '0' && s[1] == 'X'))){
            result = (double) std::stoi(s.substr(2),0,16);
    }else if (isStingAcceptableLen(3,s) && ((s[0] == '0' && s[1] == 'b') || (s[0] == '0' && s[1] == 'B')))
    {
        result = (double) std::stoi(s.substr(2),0,2);
    }else if (isStingAcceptableLen(2,s) && (s[0] == '0'))
    {
        result = (double) std::stoi(s.substr(1),0,8);
    }else{
        result = std::stoi(s);
    }
    return result;
};
bool isStingAcceptableLen(int size, const std::string &s){
    return size <= s.size();
};

std::string printBinaryValue(int number){
    return convertDecToBinString(number);
    
};
std::string printHexValue(int number){
    std::string result{""};
    std::string hex {"0123456789abcdef"};
    for (int i = number; i > 0 ; i/=16)
    {
        result += hex[i%16]; 
    }
     result = reverseNumber(result);
     return result;
};
std::string printOctValue(int number){
      std::string result{""};
    std::string oct {"01234567"};
    for (int i = number; i > 0 ; i/=8)
    {
        result += oct[i%8]; 
    }
     result = reverseNumber(result);
     return result;
};
std::string isOddNumber(int number){
    if(number %2==0){
        return "The number is Even";
    }
    return "The number is Odd";
};
std::string isPrimeNumber(int number){
    for (int i = 2; i < number/2; i++)
    {
        if(number % i == 0){
            return "The number is not Prime";
        }
    }
    return "The number is Prime";
};
std::string numberOfDigits(int number){
    int counter {0};
    for (int i = number; i > 0; i/=10)
    {
        ++counter;
    }
    return std::to_string(counter);
};
std::string sumOfDigits(int number){
    int sum {0};
    for (int i = number; i > 0; i /=10)
    {
        sum += i %10;
    }
    return std::to_string(sum);
};
std::string reverseNumber(std::string & number){
    std::string result{""};
    for (int i = 0; i < number.size(); i++)
    {
        result += number[number.size() -1 -i];
    }
    return result;
};
std::string isPalindrome(int number){
    std::string s{""};
    s= std::to_string(number);
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] != s[s.size()-1-i]){
            return "The number is not a palindrome";
        }
    }
    return "The number is a palindrome";
};

std::string convertDecToBinString(int number){
    std::string binary {""};
    for (int i = number; i > 0; i/=2)
    {
        if(i % 2 ==0){
            binary += '0';
        }else{
            binary += '1';
        }
    }
    binary = reverseNumber(binary);
    return binary;
    };

    int main(){
        showNumInfo();
        return 0;
    }