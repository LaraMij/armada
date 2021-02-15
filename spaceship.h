#ifndef SPACESHIP_H
#define SPACESHIP_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Faction{Empire, Rebels};
const std::vector<std::string> faction_names{"Empire", "Rebels"};

enum class Type{Squadron=10,Small=50,Medium=100,Big=200};
string to_string(Type);

class Spaceship
{
    private:
        string name;
        Faction faction;
        Type type;

    public:
        Spaceship(const string& name, const Faction& faction, const Type& type = Type::Squadron);
        int get_value() const;
        Faction get_faction()const;
        Type get_type()const;
        friend bool operator<(const Spaceship&, const Spaceship&);
        static bool same_faction(const vector<Spaceship>& ships, Faction f);
        friend ostream& operator<<(ostream&, const Spaceship&);
};

#endif // SPACESHIP_H
