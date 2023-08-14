// Задача 06
// Използвайте "smart shuffle" логика за media player програма, която да позволява произволно пускане на следваща
// песен, но която гарантира, че всичките песни от плейлистата ще бъдат пуснати точно веднъж (в произволен ред),
// преди да започнат да се пускат по втори път.
// Използвайте std::random_shuffle.

#include<random>
#include <algorithm>
#include <vector>
#include <iostream>
void print_vec(std::vector<int> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}
int main(int argc, char const *argv[])
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9,10,11};
    for (size_t i = 0; i < v.size(); i++)
    {
        std::random_shuffle(v.begin(),v.end());
        print_vec(v);
        std::cout << std::endl;   
    }
    
    return 0;
}
