#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <set>
#include <iostream>

class TeamMember;

class Team
{
    
public:
    using teamName = std::string;
    using teamPtr = std::shared_ptr<Team>;

class TeamComarator
{
public:
    bool operator()(const teamPtr & l,const teamPtr & r) const
    {
        return (*l).getName() < (*r).getName();
    }
};

private:
    teamName m_name;
    static std::map<teamPtr, std::set<TeamMember *>, TeamComarator> allTeams;

public:
        static std::map<teamPtr, std::set<TeamMember *>,TeamComarator> getTeams()
        {
            return allTeams;
        }
    Team(teamName name = "") : m_name{name}{};

    static teamPtr getTeamByName(const teamName& name)
    {
        for (auto &team : allTeams)
        {
            if ((*team.first).getName() == name)
            {
                return team.first;
            }
        }
        return nullptr;
    }
 

    static teamPtr getTeamFromAll(const Team &t)
    {
        for (auto &team : allTeams)
        {
            if ((*team.first) == t)
            {
                return team.first;
            }
        }
        return nullptr;
    }

    static void printAllTeams()
    {
        int i{1};
        for (auto &team : allTeams)
        {
            std::cout << i++ << ' '<< (*team.first).m_name << std::endl;
        }
    }

    teamName getName() const
    {
        return m_name;
    }
    friend bool operator==(Team l, Team r)
    {
        return l.m_name == r.m_name;
    }
    friend bool operator<(Team l, Team r)
    {
        return l.m_name < r.m_name;
    }
    ~Team(){};
};

#endif