#include <iostream>
#include <fstream>
#include <string>

// Abstract base class for characters
class Character {
public:
    virtual void Attack() = 0;
    virtual void Defend() = 0;
};

// Player class inheriting from Character
class Player : public Character {
public:
    void Attack() override {
        std::cout << "Player attacks!" << std::endl;
    }

    void Defend() override {
        std::cout << "Player defends!" << std::endl;
    }
};

// Enemy class inheriting from Character
class Enemy : public Character {
public:
    void Attack() override {
        std::cout << "Enemy attacks!" << std::endl;
    }

    void Defend() override {
        std::cout << "Enemy defends!" << std::endl;
    }
};

// Command parser function
void ParseCommand(const std::string& command, Character* character) {
    if (command == "Swing Sword") {
        character->Attack();
    } else if (command == "Defend") {
        character->Defend();
    } else {
        std::cout << "Invalid command!" << std::endl;
    }
}

// Main function
int main() {
   
    Player player;
    Enemy enemy;

    std::string userInput;
    std::cout << "Enter a command (e.g., 'Swing Sword', 'Defend'): ";
    std::getline(std::cin, userInput);

    ParseCommand(userInput, &player); 
    ParseCommand(userInput, &enemy); 

    
    std::ofstream playerFile("player.bin", std::ios::binary);
    if (playerFile.is_open()) {
        playerFile.write(reinterpret_cast<const char*>(&player), sizeof(player));
        playerFile.close();
    } else {
        std::cerr << "Unable to open player file!" << std::endl;
    }

    std::ofstream enemyFile("enemy.bin", std::ios::binary);
    if (enemyFile.is_open()) {
        enemyFile.write(reinterpret_cast<const char*>(&enemy), sizeof(enemy));
        enemyFile.close();
    } else {
        std::cerr << "Unable to open enemy file!" << std::endl;
    }

    std::ofstream dialogFile("dialog.txt");
    if (dialogFile.is_open()) {
        dialogFile << "This is a sample dialog." << std::endl;
        dialogFile.close();
    } else {
        std::cerr << "Unable to open dialog file!" << std::endl;
    }

    return 0;
}
