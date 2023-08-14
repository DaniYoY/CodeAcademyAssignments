// Задача 05
// Запазете думите от текст, състоящ се само от букви и space, въведен от потребителя, във вектор от стрингове.
// Използвайте std::for_each за да принтирате текста, но с обърнати наобратно думи.
// hi
// asl pls
// ->
// ih
// lsa slp

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

void print_list(std::vector<std::string> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << '\n';
    }
}
void reverseWordsInString(std::string &str, char delim)
{
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::string word{""};

    while (std::getline(iss, word, delim))
    {
        words.push_back(word);
    }

    str.clear();
    std::for_each(words.begin(), words.end(),
                  [&str](std::string s)
                  {
                      std::reverse(s.begin(), s.end());
                      str += s + ' ';
                  });
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> lines{"hi", "abc def", "no! yes!"};
    std::for_each(lines.begin(), lines.end(), [](std::string & s)
                  { reverseWordsInString(s, ' '); });
    print_list(lines);
    return 0;
}
