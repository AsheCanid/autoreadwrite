#include <iostream>
#include <fstream>

void writeFile(std::string fName);
std::string takeInput(std::string fName);
void readFile(std::string);

void fileCreate()
{
    std::ofstream thisFile;
    std::string fName;
    std::cout << "File name:" << std::endl;
    std::cin >> fName;
    thisFile.open(fName + (".txt"));
}

void writeFile(std::string fName)
{
    std::ofstream thisFile (fName);
    char[200] toWrite;
    try
    {
        toWrite = takeInput(fName);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Write to which file?" << std::endl;
        std::cin >> fName;
        writeFile(fName);
    }
    if(thisFile.is_open())
    {
        thisFile << toWrite;
        thisFile.close();
    }
    else
    {
        throw std::runtime_error("Unexpected ofstream error, check if file exists");
    }
}

char[] takeInput(std::string fName)
{
    char[200] input;
    char confirm = 'y';
    std::cout << "Writing to " << fName << ".txt, Correct? y/n" << std::endl;
    std::cin >> confirm;

    if (confirm = 'y')
    {
    std::cout << "What would you like to write to " << fName << " (limit 200 characters)" << std::endl;
    std::cin.getline(input, 200);
    return input;
    }
    else if (confirm = 'n')
    {
        std::cout << "What file would you like to write to? (no file extensions)" << std::endl;
        std::cin >> fName;
        writeFile(fName);
    }
    else{
        throw std::invalid_argument("Error: Invalid Input");
    }
    return input;
}

void readFile(std::string fName)
{
    std::string line;
    try
    {
            std::ifstream thisFile (fName + ".txt");
    }
    catch(...)
    {
        std::cout << "File cannot be accessed" << std::endl;
        exit;
    }
    std::ifstream thisFile (fName + ".txt");
    if(thisFile.is_open())
    {
        while (getline(thisFile, line))
        {
            std::cout << line << std::endl;
        }
        thisFile.close();
    }
    else{
       std::cout << "Unable to open file";
    }


}
