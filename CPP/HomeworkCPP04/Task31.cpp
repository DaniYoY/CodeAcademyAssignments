// Задача 31
// Напишете програма, която принтира следната информация за въведен от потребителя текст на няколко реда:
// ● Общ брой символи
// ● Общ брой букви
// ● Общ брой главни букви
// ● Общ брой малки букви
// ● Общ брой гласни букви
// ● Общ брой съгласни букви
// ● Общ брой думи (последователност от символи, отделени с whitespace)
// ● Общ брой цифри
// ● Първия уникален символ от текста ако има такъв
// ● Най-дългата дума
// ● Най-дългата дума, съставена от уникални символи (без повтарящи се символи)

#include <iostream>
#include <string>
#include <array>

void analyzeText(std::string & text);
std::string multilineInput ();
bool isVowel(char c);
bool isWithUniqueChars(std::string & longestWord);

int main(){
    std::string text{""};
    text = multilineInput();
    analyzeText(text);
}

std::string multilineInput ()
{
    std::string line{""};
    std::string result{""};
    std::cout<< "Please enter text. Stop by placing eof on a single line " << std::endl;
    while (std::getline(std::cin, line))
    {
        if(line == "eof"){
            break;
        }
        result += line + "\n"; 
    }
    return result;
};

void analyzeText(std::string & text){
    long numberOfSymbols {0};
    long numberOfDigits {0};
    long numberOfAlphas {0};
    long numberOfUpperAlphas {0};
    long numberOfLowerAlphas {0};
    long numberOfVowels {0};
    long numberOfConsonants {0}; 
    long numberOfWords {0};
    bool isWord {false};
    char firstUnique{' '};
    bool repeatedCharMap[text.size()];
    std::string longestWord{""}; 
    std::string temp{""}; 
    std::string longestWordWithUniqueChars{""};
    for (auto i = 0; i < text.size(); i++)
    {
        repeatedCharMap[i] = false;
    }
    
    for (int i = 0; i < text.size(); i++)
    {
        // checking the unique char
        if(!std::iswspace(text[i])){
            ++numberOfSymbols;
            if (std::iswdigit(text[i]))
            {
                ++numberOfDigits;
            }
            if (std::iswalpha(text[i]))
            {
                ++numberOfAlphas;
                
                if (std::isupper(text[i]))
                {
                    ++numberOfUpperAlphas;
                }else{
                    ++numberOfLowerAlphas;
                }

                if (isVowel(text[i]))
                {
                    ++numberOfVowels;
                }else{
                    ++numberOfConsonants;
                }
            }

            // Gathering info on chars uniqueness
            for (auto j = i; j < text.size(); j++)
            {   
                if(repeatedCharMap[i]){
                    break;
                }
                if(repeatedCharMap[j]){
                    continue;
                }
                if(text[i] == text[j]){
                    repeatedCharMap[i] = true;
                    repeatedCharMap[j] = true;
                }
            }   
        }

        // Start counting words
        
        if(isWord){
            temp += text[i];
            
            if(i != text.size()-1){
                if(!std::isalpha(text[i+1])){
                    isWord = false;
                }
            }
        }else{
            if(temp.size() > longestWord.size()){
                longestWord = temp;
                if(isWithUniqueChars(longestWord)){
                    longestWordWithUniqueChars = longestWord;
                }   
            }

            if(i != text.size()-1){
                if ((std::iswspace(text[i]) && std::isalpha(text[i+1]) )|| (std::ispunct(text[i]) && std::isalpha(text[i+1]))
                    || std::isalpha(text[0]))
                {
                    isWord = true;
                    numberOfWords++;
                    if(i !=0){
                        temp ="";
                    }else{
                        temp += text[0];
                    }
                }
            }
        }
        
    }

    for (auto i = 0; i < text.size(); i++)
    {
        if(!repeatedCharMap[i]){
            firstUnique = text[i];
            break;
        }
    }
    if(longestWordWithUniqueChars.empty()){
        longestWordWithUniqueChars = "not in this text";
    }
    std:: cout << "Text has "<< numberOfSymbols<<" symbols, "
    << numberOfDigits <<" digits, "<< numberOfAlphas <<" letters ("<< numberOfUpperAlphas<<" upper case and \n"
    <<numberOfLowerAlphas <<" lower case, "<< numberOfVowels<<" vowels and "<<numberOfConsonants <<" consonants)"
    <<".\n It contains "<< numberOfWords<<" words. The longest is "<<longestWord<<" and the longest with unique chars is "
    << longestWordWithUniqueChars << "The first Unique char is " << firstUnique << std::endl;
    
}

bool isVowel(char c){
    // according to Wikipadeia Y is vowel in 97.5% of the cases
    if (c == 'A' || c== 'a'
    || c == 'E' || c == 'e'
    || c == 'O' || c == 'o'
    || c == 'U' || c == 'u'
    || c == 'I' || c == 'i'
    || c== 'Y' || c == 'y'
    )
    {
        return true;
    }
    return false;
};

bool isWithUniqueChars(std::string & longestWord){
    for (int i = 0; i < longestWord.size()-1; i++)
    {
        for (int j = i; j < longestWord.size(); j++)
        {
            if(longestWord[i]== longestWord[j]){
                return false;
            }
        }
    }
    return true;
};