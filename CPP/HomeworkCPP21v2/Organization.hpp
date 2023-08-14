#ifndef ORGANIZATION_HPP
#define ORGANIZATION_HPP

#include"Team.hpp"
#include"TeamMember.hpp"

#include<string>
#include<vector>
#include<map>
#include<memory>
#include<iostream>
#include<algorithm>

class Organization
{
private:
    std::map<Team::teamPtr, std::set<TeamMember *>, Team::TeamComarator> allTeams;
    std::vector<std::unique_ptr<TeamMember>> allMembers;
public:
    Organization();
    ~Organization();

    std::map<Team::teamPtr, std::set<TeamMember *>,Team::TeamComarator> getTeams()
    {
        return allTeams;
    }
    void printAllTeams();
    std::shared_ptr<Team> getTeamByName(const Team::teamName &name);
    void createTeamMember(const std::string & name)
    {
        allMembers.push_back(std::unique_ptr<TeamMember>(new TeamMember(name)));
    }
    void printAllTeamMembers();
    TeamMember& getMemberByIndex(int index);
    int numOfMembers()
    {
        return  allMembers.size();
    }

    void joinTeam(std::shared_ptr<Team> t, TeamMember& member);
    void changeTeam(std::shared_ptr<Team> t,TeamMember& member );
    void leaveTeam(TeamMember& member);
    void createTeam(const std::string & teamName, TeamMember& member);

    void sendTeamMessage(const std::string& msg, TeamMember& member);
};


#endif