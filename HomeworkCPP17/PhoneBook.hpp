#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include "PhoneContact.hpp"

class PhoneBook
{     
private:
    static const std::string MISSING_CONTACT;
private:
    std::map<const std::string, PhoneContact> m_contacts;
    std::set<std::string> m_blocked;

public:
    PhoneBook();
    void AddContact(const std::string& contactName, const std::string& contactNumber);
    const std::string GetNumber(const std::string& name) const;
    std::map<const std::string, PhoneContact> getContacts() const;
    void blockContact(const std::string& name);
    void unblockContact(const std::string& name);
    void printContacts (bool includeBlackListed = false);
public:    
    void merge(PhoneBook pb);
};
#endif