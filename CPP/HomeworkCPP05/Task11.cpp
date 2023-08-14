// Задача 11
// Напишете програма, в която потребителя въвежда месец от годината (стринг - име на месеца във определен
// формат) и принтира броя дни в месеца при високосна или невисокосна година.
// Дефинирайте enum за високосна и невисокосна година и го ползвайте като параметър на функцията.
// Използвайте enum за месеците и инициализиран контейнер с обекти, съдържащи информация за всеки месец -
// имената на месеца (начините, по които може да бъде написан в различни формати) и броя дни при високосна и
// невисокосна година.
// Програмата трябва да поддържа поне два формата - “Jan” и “January”, като не трябва да прави разлика между
// главни и малки букви (ако потребителя въведе “jAN”, това е валиден инпут)

#include <iostream>
#include <string>
#include <vector>
#include <map>


enum Month{
 January =1,
 February,
 March,
 April,
 May,
 June,
 July, 
 August, 
 September, 
 October, 
 November,
 December,
 NoSuchMonth = -100
};
enum yearType{
    leapYear,
    regYear,
};

Month strToMon(std::string & month){
    month = month.substr(0,3);
    for (char c :month)
    {
        std::tolower(c);
    }
    if (month == "jan")
    {
        return Month::January;
    }else if (month == "feb")
    {
        return Month::February;
    }else if (month ==  "mar")
    {
        return Month::March;
    }else if (month == "apr")
    {
        return Month::April;
    }else if (month == "may")
    {
        return Month::May;
    }else if (month == "jun")
    {
        return Month::June;
    }else if (month == "jul")
    {
        return Month::July;
    }else if (month == "aug")
    {
        return Month::August;
    }else if (month == "sep")
    {
        return Month::September;
    }else if (month == "oct")
    {
        return Month::October;
    }else if (month == "nov")
    {
        return Month::November;
    }else if (month == "dec")
    {
        return Month::December;
    }else{
        return Month::NoSuchMonth;
    }
};

void returnDays(std::string & month, yearType t){
        Month m = strToMon(month);
        switch (m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                std::cout<< 31;
                break;
            case 2:
                switch (t)
                {
                case yearType::leapYear :
                    std::cout<<  29;
                    break;
                default:
                    std::cout<< 28;
                    break;
                }
                break;
            case 4:
            case 6:   
            case 9:
            case 11:
                std::cout<<30;
                break;
        }
        return;
    };



  

    
    
    
    
    
    
    
    
    
    


