#include "TeamMember.hpp"
#include "Team.hpp"
TeamMember::TeamMember(const std::string &name) : m_name{name}, m_team{nullptr}
{
}

std::string TeamMember::getTeamName()
    {
        return m_team ? (*m_team).getName() : "no team";
    }
void TeamMember::join(std::shared_ptr<Team>t)
{
    if (!m_team)
    {
        m_team.reset();
        m_team = t;
        std::cout << "Success"<<std::endl;
    }
    else
    {
        std::cout << m_name << " is already in team" << std::endl;
    }
}
void TeamMember::change(std::shared_ptr<Team> t)
{
    leave();
    join(t);
}
void TeamMember::leave()
{
    if (m_team)
    {
        this->m_team.reset();
        m_messages.clear();
        std::cout << "Success"<<std::endl;
        
    }
    else
    {
        std::cout << m_name << " is not in a team" << std::endl;
    }
}
void TeamMember::create(const std::string &teamName)
{
    leave();
    if (!m_team)
    {
        this->m_team = std::make_shared<Team>(teamName);
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
    m_messages.push_back(message);
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

