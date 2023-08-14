// Задача 02
// Дефинирайте вектор и напишете цикъл, в който добавяте елементи и принтирате размера и капацитета на всяка итерация. Направете
// същото, но преди цикъла използвайте reserve.

#include <iostream>
#include <vector>
#include <string>

void observeVectorGrowth()
{
    std::vector<std::string> vec;
    std::string line;
    while(!std::getline(std::cin, line).eof()){
        vec.push_back(line);
        std::cout << "Size is " << vec.size()
                << " and capacity is " << vec.capacity() 
                << std:: endl;
    }
    return;
}

void observeVectorGrowthWithReserve(size_t n)
{
    std::vector<std::string> vec;
    std::string line;
    vec.reserve(n);
    while(!std::getline(std::cin, line).eof()){
        vec.push_back(line);
        std::cout << "Size is " << vec.size()
                << " and capacity is " << vec.capacity() 
                << std:: endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    observeVectorGrowth();
    observeVectorGrowthWithReserve(100);
    return 0;
}
