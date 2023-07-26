
#include<string>
class AuthenticationDetail
{
private:
    std::string m_username;
    std::string m_password;

public:
    AuthenticationDetail(const std::string & name, const std::string & password) : m_username{name}, m_password{password} {};
    AuthenticationDetail(std::istream & stream){ stream >> *this;}
    ~AuthenticationDetail(){};
    friend std::ostream& operator<<(std::ostream& stream, const AuthenticationDetail& detail){ 
            stream << detail.m_username << ' ' << detail.m_password << ' ';
            return stream;
    }
    friend std::istream& operator>>(std::istream& stream, AuthenticationDetail& detail){ 
            stream >> detail.m_username >> detail.m_password;
            return stream;
    }
    friend bool operator==(const AuthenticationDetail& d1, const AuthenticationDetail& d2){
        return d1.m_username == d2.m_username && d1.m_password == d2.m_password;
    }
    friend bool operator!=(const AuthenticationDetail& d1, const AuthenticationDetail& d2){
        return d1==d2;
    }
    friend bool operator<(const AuthenticationDetail& d1, const AuthenticationDetail& d2){
        return d1.m_username == d2.m_username ? d1.m_password < d2.m_password : d1.m_username < d2.m_username;
    }
    friend bool operator>(const AuthenticationDetail& d1, const AuthenticationDetail& d2){
        return d1.m_username == d2.m_username ? d1.m_password > d2.m_password : d1.m_username > d2.m_username;
    }
};
