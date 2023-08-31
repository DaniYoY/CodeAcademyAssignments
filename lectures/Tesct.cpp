#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <memory>
#include <array>
#include <map>
#include <cstring>
#include<set>

int main()
{
 std::stringstream str("12 3 6 489 dgdfd 4 6 4");
 int num{0};
 while ((str>>num).failbit && !str.eof())
 {
  std::cout << num << ' ';
  str.exceptions(str.failbit);
 }
  return 0;
}
