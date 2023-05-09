#include <iostream>

int main(){
    using namespace std;
    char a{' '}, b {' '};
    int n{0};
    int counter = 0;
    cin >> a >> b >> n ;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-i; j >0; j--)
        {
        cout << a;
        }
        for (int j = 0; j < counter; j++)
        {
            cout << b;
        }
        counter++;
        cout << endl;
    }
    
    return 0;
}