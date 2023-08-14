#include <iostream>
#include <string>

int main (){
using namespace std;
   string str{""},longest{""},shortest{""};
   int longn{0}, shortn{0};
   bool isFirstString = true;

   while (cin)
   {
    getline(cin, str);
    if(isFirstString){
        isFirstString = false;
        longest = str;
        shortest = str;
        longn = str.size();
        shortn = str.size();
    } 

    if(str.size() > longn){
        longest = str;
        longn = str.size();
    }
    
    if(str.size() < shortn && str.size() != 0){
        shortest = str;
        shortn = str.size();
    }
   
   }
   
   cout <<"longes String: " << longest << endl
        << "shortest String: " << shortest << endl;

    return 0;
}