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

    std::cout<<"TEST 4 \n\n\n";
    PhoneBook a{};
    a.AddContact("Kali","89498654");
    a.AddContact("Alis","0000000");
    a.AddContact("Bobi","38435900008654");
    a.AddContact("Bani","18946438654");
    a.AddContact("Tobi","689455554");
    a.AddContact("Wan","18949877754");
    a.AddContact("Kon","12349100000001224");
    b.merge(a);
    b.printContacts(true);
    
    return 0;
}

