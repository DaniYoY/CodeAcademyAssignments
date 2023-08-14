#include "TeamMember.hpp"
#include"Team.hpp"

void actAsMember();
int main()
{
    std::string line{""};
    int option{0};
    while (!std::getline(std::cin, line).eof())
    {

        if (line == "exit")
        {
            break;
        }
        std::cout << "Please choose an option or Press \"exit\" for closing the app:\n"
                     "1. Create new Member\n"
                     "2. Access as existing member\n";

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
            TeamMember::createTeamMember(line);
            continue;
        case 2:
            actAsMember();
            continue;
        default:
            std::cout << "this is not an option" << std::endl;
            continue;
            ;
        }
    }

    return 0;
}

void actAsMember()
{
    std::string line{""};
    int option{0};

    TeamMember::printAllTeamMembers();
    std::cout << "select a member number. Who are you?" << std::endl;
    std::getline(std::cin, line);
    try
    {
        option = std::stoi(line);
        if (option < 0 || option >= TeamMember::numOfMembers())
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
    TeamMember &member = TeamMember::getMemberByIndex(option);
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
        member.leave();
        break;
    case 2:
        Team::printAllTeams();
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        member.join(*Team::getTeamByName(line));
        break;
    case 3:
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        member.change(*Team::getTeamByName(line));
        break;
    case 4:
        std::cout << "enter team name" << std::endl;
        std::getline(std::cin, line);
        member.create(line);
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