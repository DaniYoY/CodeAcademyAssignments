#ifndef TEAM_MESSAGE_HPP
#define TEAM_MESSAGE_HPP

#include <string>

class TeamMessage
{
private:
    std::string msg;
public:
    TeamMessage(const std::string & note ="", const std::string & autorName = ""): msg {note + " by " + autorName} 
    {
    }
    ~TeamMessage()
    {
    }
    std::string toString()
    {
        return msg;
    }
      friend bool operator< (TeamMessage l, TeamMessage r){
        return l.msg < r.msg;
    }
      friend bool operator== (TeamMessage l, TeamMessage r){
        return l.msg == r.msg;
    }

};

#endif