#include <iostream>

int main(){
    using namespace std;
    char a{' '};
    int width{0}, height{0};
    cin >> a >> width >> height;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        cout << a;
        }
        cout << endl;
    }
    
    return 0;
}