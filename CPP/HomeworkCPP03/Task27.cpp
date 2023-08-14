#include <iostream>

int main (){
using namespace std;
    int age{0};
    char gender{' '};
    cout << " Enter gender (m/f) and age separated by space: ";
    while (cin >> gender >> age)
    { 
        if ((gender == 'm' && age >= 30 && age <=40) 
        || (gender == 'f' && age >= 25 && age <=35))
        {
            cout << "Acceptable to be added to the test subjects" << endl;
        }else{
            cout << "Unacceptable to be added to the test subjects" << endl;
        }
    }
    
    return 0;
}