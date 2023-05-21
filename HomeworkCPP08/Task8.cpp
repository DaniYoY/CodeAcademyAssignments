// Задача 08
// Напишете функция, която прочита от файл (същия формат от предходната задача) цели числа във vector.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int readfromFile (const std::string & file, std::vector<int>& result){
    int a{0};
    std::fstream fileToRead;
    std::string line{""};
    fileToRead.open(file, std::fstream::in | std::fstream::out);
    if (!fileToRead)
    {
        std::cerr << "file is not opened" << std::endl;
        return -1;
    }else{
      while (!(fileToRead >> a).eof())
      {
        result.push_back(a);
      }
    }
    fileToRead.close();
    fileToRead.clear();
    return 0;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    readfromFile("fileForVectors.txt", vec);
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
    }
    
    return 0;
}
