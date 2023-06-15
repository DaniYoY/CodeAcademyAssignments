#include "PhoneContact.hpp"

static const std::string LINE_SEPARATOR_SIGN = "\n";
static const std::string BLOCKED_SIGN = "! BLOCKED CONTACT !";

PhoneContact::PhoneContact(const std::string & name="", const std::string & number=""):m_isBlackListed{false}, m_name{name}, m_number{number}  {};

const std::string PhoneContact::getPhoneNumber() const{
    return this->m_number;
}

const std::string PhoneContact::getContactName() const{
    return this->m_name;
}

const bool PhoneContact::isBlocked() const{
    return this->m_isBlackListed;
}

void PhoneContact::changeBlock(){
    m_isBlackListed = m_isBlackListed == false ? true : false;
}

void PhoneContact::setPhoneContact(const std::string & name, const std::string & number){
    this->m_isBlackListed = false;
    this->m_name = name;
    this->m_number = number;
}

std::string PhoneContact::toString(){
    std::string result{""};
    if (m_isBlackListed)
    {
        result.append(BLOCKED_SIGN).append(LINE_SEPARATOR_SIGN); 
    }
    result.append(m_name).append(LINE_SEPARATOR_SIGN).append(m_number).append(LINE_SEPARATOR_SIGN);
    return result;
}