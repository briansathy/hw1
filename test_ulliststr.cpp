using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr dat;
// Checks to see if popping empty list works
dat.pop_back();
dat.pop_front();
dat.push_back("asd");
dat.push_front("bips");
dat.push_back("book");
// Checks the legitamacy of 
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
dat.pop_back();
dat.pop_back();
cout << dat.back() << endl;
cout << dat.back() << "and is of the size: " << dat.size() << endl;
cout << dat.size() << endl;  

dat.push_front("the_front");
cout << dat.front();

dat.push_back("the_back");
cout << dat.back();

dat.pop_back();

cout << dat.front() << endl;

std::string test = dat.front();
cout << test << endl;

dat.push_back(test);
dat.push_front(test);

cout << dat.front() << dat.back() << endl;
}



