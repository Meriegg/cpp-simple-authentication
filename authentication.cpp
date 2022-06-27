#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string runLogin()
{
    std::string username;
    std::string* pUsername = &username;
    std::string password;
    std::string fileContent;
    std::vector<std::string> splitWord;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::string fileName = *pUsername;
    std::ifstream ExistingFile;
    ExistingFile.open(fileName.insert(size(username), ".txt"));
    if (!ExistingFile) {
        std::cerr << "Could not find User!";
        ExistingFile.close();
        exit(1);
    }

    if (ExistingFile.is_open()) {
        ExistingFile >> fileContent;
    }

    for (int i = 0; i < size(fileContent); i++) {
        if (fileContent[i] == ':') {
            splitWord.push_back(fileContent.substr(0, i));
            splitWord .push_back(fileContent.substr(i + 1, size(fileContent)));
        }
    }

    if (username != splitWord[0] || password != splitWord[1]) {
        std::cerr << "Unauthorized!";
        exit(1);
    }

    std::cout << "Logged in successfully!";

    return "hello";
}

std::string runRegister()
{    
    std::string username;
    std::string* pUsername = &username;
    std::string password;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::ifstream ExistingFile;
    ExistingFile.open(username);
    if (ExistingFile) {
        std::cerr << "Username is already in use!\n";
        ExistingFile.close();
        exit(1);
    }

    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::string fileName = *pUsername;
    std::ofstream UserFile(fileName.insert(size(username), ".txt"));
    UserFile << username << ":" << password;

    std::cout << "Registered successfully!";

    return username;
}

void chooseAuthMethod(int choice)
{
    switch (choice) {
    case 1:
        runLogin();
        break;
    case 2:
        runRegister();
        break;
    default:
        std::cout << "No such action!";
        break;
    }
}

int main()
{
    int choice;

    std::cout << "What do you want to do? 1. Login 2. Register: ";
    std::cin >> choice;
    std::cin.ignore();

    chooseAuthMethod(choice);
}
