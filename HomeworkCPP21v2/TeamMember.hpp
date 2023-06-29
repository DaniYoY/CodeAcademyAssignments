#ifndef TEAM_MEMBER_HPP
#define TEAM_MEMBER_HPP

#include<string>
#include<vector>
#include<map>
#include<memory>
#include<iostream>
#include<algorithm>

#include"TeamMessage.hpp"

class Team;

class TeamMember
{
private:
    std::string m_name;
    std::shared_ptr<Team> m_team;
    std::vector< std::shared_ptr<TeamMessage>> m_messages;

public:
    TeamMember(const std::string& name = "");
    std::string getName()const
    {
        return this->m_name;
    }
    std::string getTeamName();
    std::weak_ptr<Team> getTeamWeakPtr()
    {
        return std::weak_ptr<Team>(m_team);
    }
    void join(std::shared_ptr<Team> t);
    void change(std::shared_ptr<Team> t );
    void leave();
    void create(const std::string & teamName = "");
    void send(const std::string& msg);
    void forget (const TeamMessage& msg);
    void receive(std::shared_ptr<TeamMessage> message);
    TeamMessage& getMessageByIndex(size_t ind) const
    {
        if (ind < 0 || ind >= m_messages.size())
        {
            throw std::invalid_argument("there is no such index");
        }
        
        return *(m_messages[ind]);
    }
    void printMessages();
   
    ~TeamMember(){};
   
    friend bool operator< (TeamMember l, TeamMember r){
        return l.m_name < r.m_name;
    }
      friend bool operator== (TeamMember l, TeamMember r){
        return l.m_name == r.m_name;
    }
};

#endif