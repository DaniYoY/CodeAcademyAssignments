// #include "TeamMember.hpp"
// #include"Team.hpp"
#include "Organization.hpp"
void actAsMember(Organization &o);
int main()
{
    Organization org;
    std::string line{""};
    int option{0};
    std::cout << "Please choose an option or Press \"exit\" for closing the app:\n"
                 "1. Create new Member\n"
                 "2. Access as existing member\n";
    while (!std::getline(std::cin, line).eof())
    {

        if (line == "exit")
        {
            break;
        }

        try
        {
            option = std::stoi(line);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }

        switch (option)
        {
        case 1:
            std::cout << "Enter the new Name" << std::endl;
            std::cin >> line;
            std::cin.ignore();
            org.createTeamMember(line);
            break;
        case 2:
            actAsMember(org);
            break;
        default:
            std::cout << "this is not an option" << std::endl;
            break;
        }
        std::cout << "Please choose an option or Press \"exit\" for closing the app:\n"
                     "1. Create new Member\n"
                     "2. Access as existing member\n";
    }

    return 0;
}

void actAsMember(Organization &o)
{
    std::string line{""};
    int option{0};

    o.printAllTeamMembers();
    std::cout << "select a member number. Who are you?" << std::endl;
    std::getline(std::cin, line);
    try
    {
        option = std::stoi(line);
        if (option < 0 || option >= o.numOfMembers())
        {
            std::exception e;
            throw e;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "You are not you, select number next time!";
        return;
    }
    TeamMember &member = o.getMemberByIndex(option);
    std::cout << "select an action, " << member.getName()
              << "\n Your team is " << member.getTeamName()
              << "1. Leave team\n"
                 "2. Join team\n"
                 "3. Change team\n"
                 "4. Create team\n"
                 "5. Forget a message\n"
                 "6. Send a message"
              << std::endl;

    std::getline(std::cin, line);
    try
    {
        option = std::stoi(line);
        if (option < 1 || option > 6)
        {
            std::exception e;
            throw e;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "You are not you, select number next time!";
        return;
    }
    switch (option)
    {
    case 1:
        o.leaveTeam(member);
        break;
    case 2:
        o.printAllTeams();
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        o.joinTeam(o.getTeamByName(line), member);
        break;
    case 3:
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        o.changeTeam(o.getTeamByName(line), member);
        break;
    case 4:
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        o.createTeam(line, member);
        break;
    case 5:
        member.printMessages();
        std::cout << "enter message index" << std::endl;
        std::getline(std::cin, line);
        member.forget(member.getMessageByIndex(std::stoi(line)));
        break;
    case 6:
        member.printMessages();
        std::cout << "enter message index" << std::endl;
        std::getline(std::cin, line);
        member.send(line);
        break;
    }
}