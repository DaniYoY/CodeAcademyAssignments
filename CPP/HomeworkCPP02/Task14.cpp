#include <iostream>
#include <string>


int main(){
    using namespace std;
    int age {0}, counter {0};
    string name = "";
    cout << "Please enter name: " << endl;
    cin >> name;
    cout << "Please neter age: " << endl;
    cin >> age;
    
    while(true){
        if(age % 10 == 5 || age % 10 == 0){
            break;
        }
        counter++;
        age++;
    }

    if(counter != 0){
       cout << name << " is " << age- counter <<" years old and next jubelee is in " << counter << "years";
    }else{
       cout << name << " is " << age- counter <<" years old and next jubelee is in 5 years";
    }
    cout << endl;
    return 0;
}