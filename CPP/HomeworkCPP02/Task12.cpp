#include <iostream>

int main(){
    using namespace std;
    int n {0}, sum {0};
    cin >> n;
    if (n < 0)
    {
        n *= -1; 
    }
    
    while (n !=0)
    {
        sum += n%10; 
        n /= 10;
    }
    
    cout << sum << endl;
    return 0;
}