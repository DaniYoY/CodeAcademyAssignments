#include "Team.hpp"

    std::map<Team::teamPtr, std::set<TeamMember *>, Team::TeamComarator> Team::allTeams {};
    // std::map<Team::teamPtr, std::set<TeamMember *>, std::owner_less<Team>> Team::allTeams = {};