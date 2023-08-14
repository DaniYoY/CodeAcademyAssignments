#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    int a{0}, sInt;
    float sFlt(0.0f);
    cin >> a;
    
    sFlt = sqrtf(a);
    sInt = sqrt(a);

    if (sInt == sFlt){
        cout << "The number is exact sqare of " << sInt << endl;
    } else{
        cout << "The number is not exact sqare"  << endl;
    }
    return 0;
}