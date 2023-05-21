// Задача 07
// Напишете функция, която записва vector с цели числа във текстов файл.

#include <iostream>
#include <fstream>
#include <vector>

int saveToFile (std::vector<int> & vec){
    std::fstream fileToSave;
    fileToSave.open("fileForVectors.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if (!fileToSave)
    {
        std::cerr << "file is not opened" << std::endl;
        return -1;
    }else{
        for (size_t i = 0; i < vec.size(); i++)
        {
            // fileToSave >> vec[i] >> std::ws;
            fileToSave << vec[i];
            fileToSave << " ";
            std::cout << vec[i] << " "<<std::endl;
        }
    }
    fileToSave.close();
    fileToSave.clear();
    return 0;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    vec = {1,2,3,4,5,6,7,8};
    saveToFile(vec);
    return 0;
}
