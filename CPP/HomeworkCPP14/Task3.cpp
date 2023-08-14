// Задача 03
// Напишете програма, която симулира опашка пред магазин : програмата трябва да има опции за:
// ● нареждане на човек на опашката (най-отзад)
// ● минаване на човек през касата
// ● принтиране на опашката от клиенти

#include <iostream>
#include <deque>
#include <string>

void addToQueue ( const std::string & clientName, std::deque<std::string> & queue){
    queue.push_back(clientName);
} 
void goToCashier( const std::string & clientName, std::deque<std::string> & queue){
    if (clientName == queue.front())
    {
        queue.pop_front();
    }else{
        std::cout << "It is not "<< clientName << "\'s turn"<<std::endl;
    }
}
void printQueue (std::deque<std::string> & queue){
    std::cout << "Next in queue: \n";
    for (auto it = queue.cbegin(); it != queue.cend(); it++)
    {
        std::cout << *it;
    }
}

void selectQueueAction(int choice,std::deque<std::string> & queue){
    std::string clientName{""};
    switch (choice)
    {
    case 1:
        std::cout<< "Please add client name"<< std::endl;
        std::getline(std::cin, clientName);
        addToQueue(clientName, queue);
        clientName.clear();
        break;
    case 2:
        std::cout<< "Please add client name for verification"<< std::endl;
        std::getline(std::cin, clientName);
        goToCashier(clientName, queue);
        clientName.clear();
        break;
    case 3:
        printQueue(queue);
        break;
    default:
        std::cout<< "This is not an option" << std::endl;
        break;
    }
}

int main(int argc, char const *argv[])
{
    int n{0};
    std::deque<std::string> queue;
    while(n != -1){
        std::cout << "Please select an action number \n"
        "1 for Adding someone to the queue \n"
        "2 for Removing someone to the queue, because it is his/her/their turn \n"
        "3 for Printing the queue \n"
        "-1 for Ending the program \n";
        std::cin>>n;
        selectQueueAction(n,queue);
    }
    return 0;
}
