#include "studyInPink.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
const std::string ntb1= "ntb1.txt";
const std::string ntb2= "ntb2.txt";
const std::string ntb3= "ntb3.txt";
const std::string tag= "tag.txt";
const std::string message= "Rachel";

    std::string pwd1= notebook1(ntb1);
    std::string pwd2= notebook2(ntb2);
    std::string pwd3= notebook3(ntb3);
    std::string listpass= generateListPasswords(pwd1, pwd2, pwd3);

    std::cout<< "Notebook1 result:  " << pwd1 << "\n";
    std::cout<< "Notebook2 result:  " << pwd2 << "\n";
    std::cout<< "Notebook3 result:  " << pwd3 << "\n";
    std::cout<< "List pass result:  " << listpass << "\n";
    std::cout<< "Laptop result: " << enterLaptop(tag, message) << "\n";
    return 0;
}