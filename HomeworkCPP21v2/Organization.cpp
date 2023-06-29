#include "Organization.hpp"

Organization::Organization()
{
}

Organization::~Organization()
{
}
void Organization::printAllTeams()
    {
        int i{1};
        for (auto &team : allTeams)
        {
            auto interim = (team.first).lock();
            if(interim)
            {
                std::cout << i++ << ' ' << (*interim).getName() << std::endl;
            }
        }
    }
 std::shared_ptr<Team> Organization:: getTeamByName(const Team::teamName &name)
    {
        for (auto &team : allTeams)
        {
            auto teamWeakPtr= team.first.lock();
            if (teamWeakPtr && (*teamWeakPtr).getName() == name)
            {
                return team.first.lock();
            }
        }
        throw std::invalid_argument("There is no team! First create it!");
    }


void Organization::printAllTeamMembers()
{
    int i{0};
    for (auto &member : allMembers)
    {
        std::cout<< i++ << ' ' << (*member).getName() << std::endl;
    }
}

TeamMember & Organization::getMemberByIndex(int index)
{
    return *(allMembers[index]);
}

void Organization::joinTeam(std::shared_ptr<Team> t,  TeamMember& member)
{
    member.join(t);
    allTeams[member.getTeamWeakPtr()].insert(&member);
}
void Organization::changeTeam(std::shared_ptr<Team> t, TeamMember& member )
{
    allTeams[member.getTeamWeakPtr()].erase(&member);
    member.change(t);
    allTeams[member.getTeamWeakPtr()].insert(&member);
}
void Organization::leaveTeam( TeamMember& member)
{
    allTeams[member.getTeamWeakPtr()].erase(&member);
    member.leave();
}
void Organization::createTeam(const std::string & teamName,  TeamMember& member)
{
    member.create(teamName);
    allTeams[member.getTeamWeakPtr()].insert(&member);
}

   void Organization::sendTeamMessage(const std::string& msg, TeamMember& member)
   {
        auto message = std::make_shared<TeamMessage>(msg, member.getName());
        for (TeamMember* mem : allTeams[member.getTeamWeakPtr()])
        {
            (*mem).receive(message);
        }        
   }