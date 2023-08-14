#include <iostream>

int main(){
    using namespace std;
    char a{' '}, b {' '};
    int width{0}, height{0};
    cin >> a >> b >> width >> height;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j % 2 == 0){
                cout << a;
            }else{
                cout << b;
            }
        }
        cout << endl;
    }
    
    return 0;
}