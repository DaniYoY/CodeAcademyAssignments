#include <iostream>
#include <iomanip>

int main(){
    using namespace std;
    int n {0}, counter {0};
    float sum{0.0f};
    cin >> n;
    if (n < 0)
    {
        n *= -1; 
    }
    
    while (n !=0)
    {
        sum += n%10 ;
        n /= 10;
        counter++;
    }
    
    cout << setprecision(2) << sum/counter << endl;
    return 0;
}