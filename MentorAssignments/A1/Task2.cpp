// Hanoi towers

// Задача 2:
// Ханойските кули: имате 3 кули със като една от тях има обръчи нанизани на нея, обръчите са с различен размер, като по-малък обръч може да бъде поставен върху по-голям: но не и на обратно:
// 1
// 2
// 3
// 4
// 5
// може да бъде разделено на:
// 1
// 3      2
// 4      5З
// адачата ви е, при подадено от клиента число, и 3 кули, да преместите всички обръчи от началната кула до мишената:
// примерен инпут:
// обръчи: 4
// кула 1: 1
// мишена: 2
// кула 2: 3На всеки ход можете да местите само по един обръч, започвайки с примерния инпут:
// 1
// 2
// 3
// 4
// 1    2    3
// трябва да преместите обръчите да са на другата кула:
//       1
//       2
//       3
//       4
// 1    2    3 
// Може на която и да е свободна кула да преместите обръч, но не трябва да има по-малък обръч на тази кула
// и за да вадите обръч той трябва да е на върха.

#include <iostream>
#include <string>
#include <stack>
void moveRing(std::stack<int>& tower1, std::stack<int>& tower2);
int main(int argc, char const *argv[])
{
    // generating the towers

    int n{0};
    std::cout<< "Please enter a number of levels for the tower ";
    std::stack<int> towerSource, towerToGrow, towerHelper;
    std::cin >> n;
    for (size_t i = n; i >0; i--)
    {
        towerSource.push(i);
    }
    
    // choosing scenario depending on n (odd or even).This way we ensure the tower where rings will be transferred.  
   
   while (!towerSource.empty() || !towerHelper.empty())
   {
    if (n%2 == 0)
    {
        moveRing(towerSource, towerHelper);
        moveRing(towerSource, towerToGrow);
        moveRing(towerHelper, towerToGrow);
    }else{
        moveRing(towerSource, towerToGrow);
        moveRing(towerSource, towerHelper);
        moveRing(towerHelper, towerToGrow);
    }
   }
      
    std::cout << "Process complete";
    return 0;
}


void moveRing(std::stack<int>& tower1, std::stack<int>& tower2){
    if (tower1.empty() && !tower2.empty())
    {
        tower1.push(tower2.top());
        tower2.pop();   
    }else if(!tower1.empty() && tower2.empty())
    {
        tower2.push(tower1.top());
        tower1.pop();
    }else{
        if (tower1.top() > tower2.top()){
            tower1.push(tower2.top());
            tower2.pop();  
        }else{
            tower2.push(tower1.top());
            tower1.pop();
        }
    }
}
