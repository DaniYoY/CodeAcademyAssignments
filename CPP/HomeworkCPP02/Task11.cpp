#include <iostream>

int main(){
    using namespace std;
    int n {0};
    cin >> n;
    if (n < 0)
    {
        n *= -1;

    }
    
    while (n !=0)
    {
        cout << n%10 << endl;
        n /= 10;
    }
    
    return 0;
}