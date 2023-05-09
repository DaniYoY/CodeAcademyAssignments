#include <iostream>

int main(){
    using namespace std;
    char a{' '};
    int n{0};
    cin >> a >> n ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
        cout << a;
        }
        cout << endl;
    }
    
    return 0;
}