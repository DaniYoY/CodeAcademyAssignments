// Задача 10
// Напишете програма, в която потребителя въвежда два дена от седмицата (цели числа от 1 до 7), след което
// програмата принтира броя дни между тях, използвайки имената на дните (Monday, Tuesday, ..).
// Използвайте enum за дните от седмицата и дефинирайте помощни функции за въвеждане на ден и за
// преобразуване от enum константа за ден към std::string - името на деня.

#include <iostream>
#include <string>
#include <cmath>

enum Days{
 Monday,
 Tuesday,
 Wednesday,
 Thursday,
 Friday,
 Saturday,
 Sunday, 
 NoSuchDay = -100
};
Days strToDays(std::string & str);

void calculateDifferenceBetweenDays(std::string d1, std::string d2){
    Days day1 = strToDays(d1);
    Days day2 = strToDays(d2);
    std::cout<< std::abs(day1 - day2);
}

Days StrToDays(std::string & str){
    if (str == "Monday"){
        return Days::Monday;
    }else if (str == "Tuesday")
    {
        return Days::Tuesday;
    }else if (str == "wednesday")
    {
        return Days::Wednesday;
    }else if (str == "Thursday")
    {
        return Days::Thursday;
    }else if (str == "Friday")
    {
        return Days::Friday;
    }else if (str == "Saturday")
    {
        return Days::Saturday;
    }else if (str == "Sunday")
    {
        return Days::Sunday;
    }else{
        return Days::NoSuchDay;
    }    
}
