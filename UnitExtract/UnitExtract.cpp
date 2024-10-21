#include <fstream>
#include <iostream>
#include <vector>

#include "UnitResource.h"

int main(int argc, char* argv[])
{
    std::string inputFile = argv[1];
    std::ifstream infile{ inputFile, std::ios_base::binary };
    std::vector<char> buffer{ std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
    
    stingray::UnitResource::parse(buffer);
}
