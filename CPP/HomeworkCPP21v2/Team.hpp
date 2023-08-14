#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <set>
#include <iostream>
#include "TeamMember.hpp"


class Team
{

public:
    using teamName = std::string;
    using teamPtr = std::weak_ptr<Team>;

    class TeamComarator
    {
    public:
        bool operator()(const teamPtr &l, const teamPtr &r) const
        {
            return (*l.lock()).getName() < (*r.lock()).getName();
        }
    };

private:
    teamName m_name;


public:
// Team related
    Team(teamName name = "") : m_name{name}
    {
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