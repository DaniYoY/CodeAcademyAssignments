#include <iostream>

int main(){
    using namespace std;
    int n {0}, counter {1};
    cin >> n;
    if (n < 0)
    {
        n *= -1; 
    }
    
    
     while (n/10 != 0)
     {
        counter++;
        n /=10;
    }

    cout << counter << endl;
    return 0;
}