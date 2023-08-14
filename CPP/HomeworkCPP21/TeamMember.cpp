#include "TeamMember.hpp"

std::vector<std::unique_ptr<TeamMember>> TeamMember::allMembers{};

TeamMember::TeamMember(const std::string &name) : m_name{name}, m_team{nullptr}
{
}
void TeamMember::join(const Team &t)
{
    if (!m_team)
    {
        this->m_team = Team::getTeamFromAll(t);
        Team::getTeams()[m_team].insert(this);
        std::cout << "Success"<<std::endl;
    }
    else
    {
        std::cout << m_name << " is already in team" << std::endl;
    }
}
void TeamMember::change(const Team &t)
{
    leave();
    join(t);
}
void TeamMember::leave()
{
    if (m_team)
    {
        Team::getTeams()[m_team].erase(this);
        this->m_team.reset();
        m_messages.clear();
        std::cout << "Success"<<std::endl;
        
    }
    else
    {
        std::cout << m_name << " is not in a team" << std::endl;
    }
}
void TeamMember::create(const Team::teamName &teamName)
{
    leave();
    if (!m_team)
    {
        this->m_team = std::make_shared<Team>(teamName);
        Team::getTeams()[m_team].insert(this);
        std::cout << "Success"<<std::endl;

    }
    else
    {
        std::cout << m_name << " is already in team" << std::endl;
    }
}
void TeamMember::send(const std::string& msg)
{
    auto message = std::make_shared<TeamMessage>(msg, m_name);
    for (auto &member : Team::getTeams()[m_team])
    {
        member->m_messages.push_back(message);
    }
}
void TeamMember::forget(const TeamMessage &msg)
{
    auto it = std::find_if(m_messages.begin(), m_messages.end(), [&](std::shared_ptr<TeamMessage>& iter){return (*iter) == msg;});
    m_messages.erase(it);
}
void TeamMember::printMessages()
{
    for (size_t i = 0; i < m_messages.size(); i++)
    {
        std::cout << i << ' ' << (*m_messages[i]).toString() << std::endl;
    }
}
void TeamMember::printAllTeamMembers()
{
    int i{0};
    for (auto &member : allMembers)
    {
        std::cout<< i << ' ' << (*member).m_name << std::endl;
    }
}

TeamMember & TeamMember::getMemberByIndex(int index)
{
    return *(allMembers[index]);
}
