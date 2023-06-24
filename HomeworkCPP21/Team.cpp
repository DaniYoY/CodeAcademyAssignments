#include "Team.hpp"

    std::map<Team::teamPtr, std::set<TeamMember *>, Team::TeamComarator> Team::allTeams{{{},{}},Team::TeamComarator{}};