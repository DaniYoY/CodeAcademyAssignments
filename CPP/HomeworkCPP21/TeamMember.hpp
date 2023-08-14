#ifndef TEAM_MEMBER_HPP
#define TEAM_MEMBER_HPP

#include<string>
#include<vector>
#include<map>
#include<memory>
#include<iostream>
#include<algorithm>
#include "Team.hpp"
#include"TeamMessage.hpp"

class TeamMember
{
private:
    std::string m_name;
    Team::teamPtr m_team;
    std::vector< std::shared_ptr<TeamMessage>> m_messages;

public:
    static std::vector<std::unique_ptr<TeamMember>> allMembers;
    static void createTeamMember(const std::string & name)
    {
        TeamMember:: allMembers.push_back(std::unique_ptr<TeamMember>(new TeamMember(name)));
    }
    static void printAllTeamMembers();
    static TeamMember& getMemberByIndex(int index);
    static int numOfMembers()
    {
        return TeamMember:: allMembers.size();
    }
    // non static
public:
    TeamMember(const std::string& name = "");
    std::string getName()const
    {
        return this->m_name;
    }
    std::string getTeamName()
    {
        return m_team ? (*this->m_team).getName() : "no team";
    }
    void join(const Team& t);
    void change(const Team& t);
    void leave();
    void create(const Team::teamName& teamName = "");
    void send(const std::string& msg);
    void forget (const TeamMessage& msg);
    TeamMessage& getMessageByIndex(size_t ind) const
    {
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