// Задача 18
// Добавете error-handling функционалност в програмата - конзолен калкулатор, така че да
// може да продължи да не крашва след въвеждане на данни, водещи до грешка.
// Хвърляйте и прихващайте изключение когато потребителя въведе невалидни данни и когато
// се стигне до делене на нула. Направете така, че програмата да може да продължи работа
// отначало при въвеждане на стойност, водеща до деление на 0

#include <string>
#include <iostream>

double verifyNumberInput(std::string & s);
bool isOperator(char ch);
bool isStingAcceptableLen(int size, const std::string &s);
double sum(double number,double inputNumber, char oprtr);
int calculate();

int main(){
    while (true)
    {
        try
        {
            calculate();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        
    }
    
};

int calculate(){
    double number {0}, tempNum {0};
    std::string tempString{""}, input{""};
    char oprtr{' '};
    bool isFirtsTime {true}, isEqualSign {false}, isOperatorStartRequired {false};
    std:: cout << "Hello, This is the calculator. You may calculate hexidecimal, octal, binady numbers and doubles. By pressing \'=\' you will exit the programm by getting the total."
           << "\n Rules:"
            <<" \n 1. If you enter decimal followed random chars, chars will be ingnored, otherwise invalid input stops the program" << std::endl
            <<" \n 2. Please bear in mind that any operator placed before the equals sign (e.g. +=) is ignored" << std::endl;
    while (!std::cin.fail())
    {
        std::getline(std::cin, input);
        
        if(input[0] == '='){
                break;
            }
        if(isOperatorStartRequired && !isOperator(input[0])){
            
            std::cout << "Interim total is " << number << " and to continue calculating start with a operator(+,-,.,/). Please try again!" << std::endl;
            continue;
        }
        if(!isOperatorStartRequired && isOperator(input[0])){
            std::cout << "Interim total is " << number << " and to continue calculating start with a number" << std::endl;
        }
        bool isSecondOperator {false};

        for (int i = 0; i < input.size(); i++)
        {
            if(std::iswspace(input[i])){
                continue;
            }
            if(input[i] == '='){
                isEqualSign = true;
                break;
            }
            if (isOperator(input[i])){
                oprtr = input[i];
                if(isFirtsTime){
                    isFirtsTime = false;
                    number = verifyNumberInput(tempString);
                }else{
                    tempNum = verifyNumberInput(tempString);
                }
               
                if (isSecondOperator){
                    number = sum(number,tempNum, oprtr);            
                }
                isSecondOperator = true;
                tempString ="";
                continue;
            }
            tempString += input[i]; 
        }

        
        if (tempString.empty() && (oprtr =='*'|| oprtr=='/'))
        {
            tempNum = 1;
        }else{
        tempNum = verifyNumberInput(tempString);
        }
        number = sum(number,tempNum, oprtr);   
        
        if(!isOperator(input[input.size() -1])){
                isOperatorStartRequired = true;
            }else{
                isOperatorStartRequired = false;
            }

        if(isEqualSign){
            break;
        }
    }
    std::cout << "Total is\t" << number;
    return 0;
};

bool isOperator(char ch){
    if (ch == '+'
     || ch == '-'
     || ch == '*'
     || ch == '/')
    {
        return true;
    }
    return false;
};

//  verifyNumberInput returns 0 if String is empty.
double verifyNumberInput(std::string & s){
    double result{1};
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
        result = std::stod(s);
    }
    return result;
};

double sum(double number, double inputNumber, char oprtr){
    switch (oprtr)
    {
    case '+':
        return number + inputNumber;
    case '-':
        return number - inputNumber;
    case '*':
        return number * inputNumber;
    case '/':
        if(inputNumber == 0){
            throw std::runtime_error("You cannot divide by 0");
        }
        return number / inputNumber;
    case '&':
        return static_cast<unsigned long long> (number) & static_cast<unsigned long long> (inputNumber);
    case '^':
        return static_cast<unsigned long long>(number) ^static_cast<unsigned long long>(inputNumber);
    case '|':
        return static_cast<unsigned long long>(number)| static_cast<unsigned long long>(inputNumber);
    default:
        return 0.0;
        break;
    }
};
bool isStingAcceptableLen(int size, const std::string &s){
    return size <= s.size();
};