
#ifndef PHONE_CONTACT_H
#define PHONE_CONTACT_H

#include <string>

class PhoneContact
{

public:
    static const std::string LINE_SEPARATOR_SIGN;
    static const std::string BLOCKED_SIGN;
private:
    bool m_isBlackListed;
    std::string m_name;
    std::string m_number;
public:
    PhoneContact();
    PhoneContact(const std::string & name, const std::string & number);
    const std::string getPhoneNumber() const;
    const std::string getContactName() const;
    const bool isBlocked() const;
    void changeBlock();
    void setPhoneContact(const std::string & name, const std::string & number);
    std::string toString();
    
};

#endif
