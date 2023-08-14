#include <iostream>

int main(){
    int a{0}, b{0};
    float interim {1.0f};

    std::cout << "Please enter num A: " << std::endl;
    std::cin >> a;
    std::cout << "Please enter num of the power " << std::endl;
    std::cin >> b;
   
    if (b < 0)
    {
        for (int i = 0; i < -b; i++)
        {
            interim /= a;
        }
    }else if(b == 0){
            interim =1;
    }else{
        for (int i = 0; i < b; i++)
        {
            interim *= a;
        }
    }
        
    std::cout <<"result is" << interim << std::endl;
    
    return 0;
}