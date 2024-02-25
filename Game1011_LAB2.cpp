#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
private:
    string epicName;
    int damage;
    vector<string> specialAbilities;
public:
    Weapon(string name, int dmg, vector<string> abilities) : epicName(name), damage(dmg), specialAbilities(abilities) {}

    friend ostream& operator<<(ostream& os, const Weapon& weapon) {
        os << "Epic Weapon Name: " << weapon.epicName << endl;
        os << "Damage Value: " << weapon.damage << endl;
        os << "Special Abilities:" << endl;
        for(const string& ability : weapon.specialAbilities) {
            os << "- " << ability << endl;
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return epicName == other.epicName && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armour {
private:
    string epicName;
    string description;
    int armourValue;
public:
    Armour(string name, string desc, int value) : epicName(name), description(desc), armourValue(value) {}

    friend ostream& operator<<(ostream& os, const Armour& armour) {
        os << "Epic Armour Name: " << armour.epicName << endl;#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
private:
    string epicName;
    int damage;
    vector<string> specialAbilities;
public:
    Weapon(string name, int dmg, vector<string> abilities) : epicName(name), damage(dmg), specialAbilities(abilities) {}

    friend ostream& operator<<(ostream& os, const Weapon& weapon) {
        os << "Epic Weapon Name: " << weapon.epicName << endl;
        os << "Damage Value: " << weapon.damage << endl;
        os << "Special Abilities:" << endl;
        for(const string& ability : weapon.specialAbilities) {
            os << "- " << ability << endl;
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return epicName == other.epicName && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armour {
private:
    string epicName;
    string description;
    int armourValue;
public:
    Armour(string name, string desc, int value) : epicName(name), description(desc), armourValue(value) {}

    friend ostream& operator<<(ostream& os, const Armour& armour) {
        os << "Epic Armour Name: " << armour.epicName << endl;
        os << "Description: " << armour.description << endl;
        os << "Armour Value: " << armour.armourValue << endl;
        return os;
    }

    bool operator==(const Armour& other) const {
        return epicName == other.epicName && description == other.description && armourValue == other.armourValue;
    }
};

class Character {
private:
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armour armour;
public:
    Character(string n, string sp, string bs, int hp, Weapon w, Armour a) : name(n), species(sp), backstory(bs), startingHealth(hp), weapon(w), armour(a) {}

    void displayInfo() {
        cout << "Character Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Backstory: " << backstory << endl;
        cout << "Starting Health: " << startingHealth << endl;
        cout << "Weapon Info:" << endl;
        cout << weapon << endl;
        cout << "Armour Info:" << endl;
        cout << armour << endl;
    }

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && backstory == other.backstory && startingHealth == other.startingHealth && weapon == other.weapon && armour == other.armour;
    }
};

int main() {
    cout << "Welcome to Character Customizer!" << endl;

    vector<Character> characters;

    for(int i = 0; i < 3; ++i) {
        cout << "Creating Character " << i+1 << endl;

        string name, species, backstory;
        int startingHealth;
        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter character species: ";
        cin >> species;
        cout << "Enter character backstory: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, backstory);
        cout << "Enter starting health value: ";
        cin >> startingHealth;

        // Creating default weapon and armour (you can customize this)
        Weapon defaultWeapon("Default Sword", 10, {"Slash", "Thrust"});
        Armour defaultArmour("Basic Armor", "Sturdy armor for basic protection", 5);

        Character newCharacter(name, species, backstory, startingHealth, defaultWeapon, defaultArmour);
        characters.push_back(newCharacter);

        cout << "Character " << name << " created!" << endl << endl;
    }

    cout << "Character Information:" << endl;
    for(int i = 0; i < characters.size(); ++i) {
        cout << "Character " << i+1 << " Information:" << endl;
        characters[i].displayInfo();
        cout << endl;
    }

    // Comparing two characters
    int char1, char2;
    cout << "Enter the indices of two characters to compare: ";
    cin >> char1 >> char2;
    if(char1 >= 1 && char1 <= characters.size() && char2 >= 1 && char2 <= characters.size()) {
        if(characters[char1-1] == characters[char2-1]) {
            cout << "Characters " << char1 << " and " << char2 << " are identical." << endl;
        } else {
            cout << "Characters " << char1 << " and " << char2 << " are not identical." << endl;
        }
    } else {
        cout << "Invalid character indices." << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
private:
    string epicName;
    int damage;
    vector<string> specialAbilities;
public:
    Weapon(string name, int dmg, vector<string> abilities) : epicName(name), damage(dmg), specialAbilities(abilities) {}

    friend ostream& operator<<(ostream& os, const Weapon& weapon) {
        os << "Epic Weapon Name: " << weapon.epicName << endl;
        os << "Damage Value: " << weapon.damage << endl;
        os << "Special Abilities:" << endl;
        for(const string& ability : weapon.specialAbilities) {
            os << "- " << ability << endl;
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return epicName == other.epicName && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armour {
private:
    string epicName;
    string description;
    int armourValue;
public:
    Armour(string name, string desc, int value) : epicName(name), description(desc), armourValue(value) {}

    friend ostream& operator<<(ostream& os, const Armour& armour) {
        os << "Epic Armour Name: " << armour.epicName << endl;
        os << "Description: " << armour.description << endl;
        os << "Armour Value: " << armour.armourValue << endl;
        return os;
    }

    bool operator==(const Armour& other) const {
        return epicName == other.epicName && description == other.description && armourValue == other.armourValue;
    }
};

class Character {
private:
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armour armour;
public:
    Character(string n, string sp, string bs, int hp, Weapon w, Armour a) : name(n), species(sp), backstory(bs), startingHealth(hp), weapon(w), armour(a) {}

    void displayInfo() {
        cout << "Character Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Backstory: " << backstory << endl;
        cout << "Starting Health: " << startingHealth << endl;
        cout << "Weapon Info:" << endl;
        cout << weapon << endl;
        cout << "Armour Info:" << endl;
        cout << armour << endl;
    }

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && backstory == other.backstory && startingHealth == other.startingHealth && weapon == other.weapon && armour == other.armour;
    }
};

int main() {
    cout << "Welcome to Character Customizer!" << endl;

    vector<Character> characters;

    for(int i = 0; i < 3; ++i) {
        cout << "Creating Character " << i+1 << endl;

        string name, species, backstory;
        int startingHealth;
        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter character species: ";
        cin >> species;
        cout << "Enter character backstory: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, backstory);
        cout << "Enter starting health value: ";
        cin >> startingHealth;

        // Creating default weapon and armour (you can customize this)
        Weapon defaultWeapon("Default Sword", 10, {"Slash", "Thrust"});
        Armour defaultArmour("Basic Armor", "Sturdy armor for basic protection", 5);

        Character newCharacter(name, species, backstory, startingHealth, defaultWeapon, defaultArmour);
        characters.push_back(newCharacter);

        cout << "Character " << name << " created!" << endl << endl;
    }

    cout << "Character Information:" << endl;
    for(int i = 0; i < characters.size(); ++i) {
        cout << "Character " << i+1 << " Information:" << endl;
        characters[i].displayInfo();
        cout << endl;
    }

    // Comparing two characters
    int char1, char2;
    cout << "Enter the indices of two characters to compare: ";
    cin >> char1 >> char2;
    if(char1 >= 1 && char1 <= characters.size() && char2 >= 1 && char2 <= characters.size()) {
        if(characters[char1-1] == characters[char2-1]) {
            cout << "Characters " << char1 << " and " << char2 << " are identical." << endl;
        } else {
            cout << "Characters " << char1 << " and " << char2 << " are not identical." << endl;
        }
    } else {
        cout << "Invalid character indices." << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
private:
    string epicName;
    int damage;
    vector<string> specialAbilities;
public:
    Weapon(string name, int dmg, vector<string> abilities) : epicName(name), damage(dmg), specialAbilities(abilities) {}

    friend ostream& operator<<(ostream& os, const Weapon& weapon) {
        os << "Epic Weapon Name: " << weapon.epicName << endl;
        os << "Damage Value: " << weapon.damage << endl;
        os << "Special Abilities:" << endl;
        for(const string& ability : weapon.specialAbilities) {
            os << "- " << ability << endl;
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return epicName == other.epicName && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armour {
private:
    string epicName;
    string description;
    int armourValue;
public:
    Armour(string name, string desc, int value) : epicName(name), description(desc), armourValue(value) {}

    friend ostream& operator<<(ostream& os, const Armour& armour) {
        os << "Epic Armour Name: " << armour.epicName << endl;
        os << "Description: " << armour.description << endl;
        os << "Armour Value: " << armour.armourValue << endl;
        return os;
    }

    bool operator==(const Armour& other) const {
        return epicName == other.epicName && description == other.description && armourValue == other.armourValue;
    }
};

class Character {
private:
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armour armour;
public:
    Character(string n, string sp, string bs, int hp, Weapon w, Armour a) : name(n), species(sp), backstory(bs), startingHealth(hp), weapon(w), armour(a) {}

    void displayInfo() {
        cout << "Character Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Backstory: " << backstory << endl;
        cout << "Starting Health: " << startingHealth << endl;
        cout << "Weapon Info:" << endl;
        cout << weapon << endl;
        cout << "Armour Info:" << endl;
        cout << armour << endl;
    }

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && backstory == other.backstory && startingHealth == other.startingHealth && weapon == other.weapon && armour == other.armour;
    }
};

int main() {
    cout << "Welcome to Character Customizer!" << endl;

    vector<Character> characters;

    for(int i = 0; i < 3; ++i) {
        cout << "Creating Character " << i+1 << endl;

        string name, species, backstory;
        int startingHealth;
        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter character species: ";
        cin >> species;
        cout << "Enter character backstory: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, backstory);
        cout << "Enter starting health value: ";
        cin >> startingHealth;

        // Creating default weapon and armour (you can customize this)
        Weapon defaultWeapon("Default Sword", 10, {"Slash", "Thrust"});
        Armour defaultArmour("Basic Armor", "Sturdy armor for basic protection", 5);

        Character newCharacter(name, species, backstory, startingHealth, defaultWeapon, defaultArmour);
        characters.push_back(newCharacter);

        cout << "Character " << name << " created!" << endl << endl;
    }

    cout << "Character Information:" << endl;
    for(int i = 0; i < characters.size(); ++i) {
        cout << "Character " << i+1 << " Information:" << endl;
        characters[i].displayInfo();
        cout << endl;
    }

    // Comparing two characters
    int char1, char2;
    cout << "Enter the indices of two characters to compare: ";
    cin >> char1 >> char2;
    if(char1 >= 1 && char1 <= characters.size() && char2 >= 1 && char2 <= characters.size()) {
        if(characters[char1-1] == characters[char2-1]) {
            cout << "Characters " << char1 << " and " << char2 << " are identical." << endl;
        } else {
            cout << "Characters " << char1 << " and " << char2 << " are not identical." << endl;
        }
    } else {
        cout << "Invalid character indices." << endl;
    }

    return 0;
}

        os << "Description: " << armour.description << endl;
        os << "Armour Value: " << armour.armourValue << endl;
        return os;
    }

    bool operator==(const Armour& other) const {
        return epicName == other.epicName && description == other.description && armourValue == other.armourValue;
    }
};

class Character {
private:
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armour armour;
public:
    Character(string n, string sp, string bs, int hp, Weapon w, Armour a) : name(n), species(sp), backstory(bs), startingHealth(hp), weapon(w), armour(a) {}

    void displayInfo() {
        cout << "Character Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Backstory: " << backstory << endl;
        cout << "Starting Health: " << startingHealth << endl;
        cout << "Weapon Info:" << endl;
        cout << weapon << endl;
        cout << "Armour Info:" << endl;
        cout << armour << endl;
    }

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && backstory == other.backstory && startingHealth == other.startingHealth && weapon == other.weapon && armour == other.armour;
    }
};

int main() {
    cout << "Welcome to Character Customizer!" << endl;

    vector<Character> characters;

    for(int i = 0; i < 3; ++i) {
        cout << "Creating Character " << i+1 << endl;

        string name, species, backstory;
        int startingHealth;
        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter character species: ";
        cin >> species;
        cout << "Enter character backstory: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, backstory);
        cout << "Enter starting health value: ";
        cin >> startingHealth;

        // Creating default weapon and armour (you can customize this)
        Weapon defaultWeapon("Default Sword", 10, {"Slash", "Thrust"});
        Armour defaultArmour("Basic Armor", "Sturdy armor for basic protection", 5);

        Character newCharacter(name, species, backstory, startingHealth, defaultWeapon, defaultArmour);
        characters.push_back(newCharacter);

        cout << "Character " << name << " created!" << endl << endl;
    }

    cout << "Character Information:" << endl;
    for(int i = 0; i < characters.size(); ++i) {
        cout << "Character " << i+1 << " Information:" << endl;
        characters[i].displayInfo();
        cout << endl;
    }

    // Comparing two characters
    int char1, char2;
    cout << "Enter the indices of two characters to compare: ";
    cin >> char1 >> char2;
    if(char1 >= 1 && char1 <= characters.size() && char2 >= 1 && char2 <= characters.size()) {
        if(characters[char1-1] == characters[char2-1]) {
            cout << "Characters " << char1 << " and " << char2 << " are identical." << endl;
        } else {
            cout << "Characters " << char1 << " and " << char2 << " are not identical." << endl;
        }
    } else {
        cout << "Invalid character indices." << endl;
    }

    return 0;
}
