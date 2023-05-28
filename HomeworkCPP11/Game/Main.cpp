#include "Menu.h"
// known bugs:: going back from access games menu "press any other key to return to main menu"
// known bugs:: invalid input in Hangman
// known bugs:: getting lives when attemp exists in Hangman
// known bugs:: invalid input in TTT
// known bugs:: table creation in TTT
// planned improvements:: serialization
int main(int argc, char const *argv[])
{
    Menu menu;
    menu.run();
    return 0;
}
