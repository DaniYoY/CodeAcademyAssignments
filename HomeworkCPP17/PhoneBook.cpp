#include "PhoneBook.hpp"
#include<map>

    PhoneBook::PhoneBook()
    {
    }

    void PhoneBook::AddContact(const std::string& contactName, const std::string& contactNumber){
        m_contacts[contactName] = PhoneContact(contactName, contactNumber);
    }


    const std::string PhoneBook::GetNumber(const std::string& name) const{
        return getContacts()[name].getPhoneNumber();
    }

    std::map<const std::string, PhoneContact> PhoneBook::getContacts() const{
        return m_contacts;
    }

    void PhoneBook::blockContact(const std::string& name){
        m_contacts[name].changeBlock();
        m_blocked.insert(name);
    }

    void PhoneBook::unblockContact(const std::string& name){
        if(m_blocked.find(name) != m_blocked.end()){
            m_contacts[name].changeBlock();
            m_blocked.erase(name);
        }
    }

    void PhoneBook::printContacts (bool includeBlackListed){
            std::for_each(m_contacts.begin(),m_contacts.end(),
                [includeBlackListed](std::pair<const std::string, PhoneContact>& contactPair){
                    if((!contactPair.second.isBlocked()) || (contactPair.second.isBlocked() && includeBlackListed)){
                        std::cout<< contactPair.second.toString() << std::endl;
                    } } );
    }

    void PhoneBook::merge(PhoneBook pb){
        std::for_each(pb.m_contacts.begin(), pb.m_contacts.end(),
                    [this](std::pair<const std::string, PhoneContact>& pair){
                    if (!this->getContacts().count(pair.first))
                    {
                        this->AddContact(pair.second.getContactName(),pair.second.getPhoneNumber());
                    } } );
    }