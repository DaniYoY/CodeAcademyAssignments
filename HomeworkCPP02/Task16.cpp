#include <iostream>

int main(){
    using namespace std;

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
        cout << i << " x " << j << " = " << j*i << endl;
        }
    }
    
    return 0;
}