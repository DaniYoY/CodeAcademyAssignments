#include <iostream>

int main(){
    using namespace std;

    for (int i = 9; i > 0; i--)
    {
        for (int j = 9; j > 0; j--)
        {
        cout << i << " x " << j << " = " << j*i << endl;
        }
    }
    
    return 0;
}