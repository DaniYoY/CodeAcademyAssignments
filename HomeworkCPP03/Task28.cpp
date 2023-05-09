#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

int main (){
using namespace std;
    string str{""};
    double total {0.0};
    cout << " Enter product and quality separated by space. Once finished enter \"q\" " << endl;
    while (getline(cin,str))
    { 
        if (str == "q")
        {
            break;
        }
        
        string product{""};
        double quality {0.0}, price{0.0};
        int pieces{0};
        product = str.substr(0, str.find(' '));
        quality = stod(str.substr(str.find(' ')+1));
        pieces = quality;

        if (product == "avocado")
        {
            price = 1.23;
            if(pieces != quality){
                cout << "Quality of avocados must be a whole number" << endl;
                continue;
            }
        }else if (product == "oil")
        {
            price = 2.53;
            if(pieces != quality){
                cout << "Quality of bottles of oil must be a whole number" << endl;
                continue;
            }
        }else if (product == "tomatoes")
        {
            price = 0.27;
        }else if (product == "onion")
        {
            price = 0.15;
        }else if (product == "lemons")
        {
            price = 8.99;
        }
        total += price*quality; 
    }
    cout << setprecision(2) << "Total price is " << total << endl;
    return 0;
}