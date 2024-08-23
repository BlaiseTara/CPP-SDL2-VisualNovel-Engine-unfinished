#include "compiler.h"

int main(){
    // Open Code File
    std::ifstream file("syntax.txt");
    if (!file.is_open()) {
        return -1; // or better, throw exception.
    }

    // Get Lines
    std::string line; 
    while (std::getline(file, line))
    {
        LexLine(line);
    }
    
    return 0;
}