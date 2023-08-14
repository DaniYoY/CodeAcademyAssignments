#include <iostream>

int main(){
    using namespace std;
    int n {0};
    cin >> n;
    n % 10 == 0 ? cout << "The digit is 0" : cout << "The digit is not 0";
    cout << endl;
    return 0;
}