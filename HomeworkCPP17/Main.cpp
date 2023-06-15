#include<iostream>
#include "PhoneBook.hpp"

int main(int argc, char const *argv[])
{
    PhoneBook b{};
    b.AddContact("Ani","89498654");
    b.AddContact("Alis","23498654");
    b.AddContact("Bobi","3843598654");
    b.AddContact("Nani","18946438654");
    b.AddContact("Robi","689455554");
    b.AddContact("Jan","18949877754");
    b.AddContact("Kon","1234911224");
    b.blockContact("Kon");
    b.blockContact("Bobi");
    b.blockContact("Alis");
    b.printContacts();
    std::cout<<"TEST 2 \n\n\n";
    b.unblockContact("Bobi");
    b.printContacts();
    std::cout<<"TEST 3 \n\n\n";
    b.blockContact("Nani");
    b.printContacts(true);
    return 0;
}

