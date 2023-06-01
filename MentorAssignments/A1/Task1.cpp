#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    // generating the field
    vector<string> holder; 
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        holder.push_back(line);
    }

    string missingNeibour ="-1 -1 ";
    for (size_t vertical = 0; vertical < height; vertical++)
    {
        for (size_t horizontal = 0; horizontal < width; )
        {   const int xForYcheck = horizontal;
            //  check if 0 or go to next on same line;
            if (holder[vertical][horizontal]== '0')
            {
                cout << horizontal << ' '<< vertical << ' ';
            }else{
                horizontal++;
                continue;
            }

            // check for right neibour (if found for next iteration start from it)
            for (size_t i = horizontal+1; i <= width; i++)
            {
                if ((i != width) && holder[vertical][i] == '0')
                {
                    cout << i << ' '<< vertical << ' ';
                    horizontal = i;
                    break;
                }else if(i==width){
                    cout << missingNeibour;
                    horizontal = width;
                }   
            }

            // check for below neibour 
            for (size_t y = vertical+1; y <= height; y++)
            {
                if ((y != height) && holder[y][xForYcheck]== '0')
                {
                     cout << xForYcheck << ' '<< y << ' ';
                     break;
                }else if(y==height){
                     cout << missingNeibour;
                }
            }
            cout<<endl;
        }
    }
}
