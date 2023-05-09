#include <iostream>

int main(){
    using namespace std;
    int n{0}, printed{0};
    cin >> n ;
    for (int i = 0; i <= n; i++)
    {
        for (int j = n-i; j >=0; j--)
        {
        cout << printed++;
        }
        printed =0;
        cout << endl;
    }
    
    return 0;
}