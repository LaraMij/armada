#include "spaceship.h"

string to_string(Type t) {
	switch (t) {
	case Type::Squadron: return "Squadron";
	case Type::Small: return "Small";
	case Type::Medium: return "Medium";
	case Type::Big: return "Big";
	default: throw runtime_error("Illegal Type");
	}
}

Spaceship::Spaceship(const string& name, const Faction& faction, const Type& type): name{name}, faction{faction}, type{type}
{
    if(name.empty()) throw runtime_error("Error!");
}

Faction Spaceship::get_faction()const
{
    return this->faction;
}

Type Spaceship::get_type()const
{
    return this->type;
}

int Spaceship::get_value() const
{
    if(get_faction()==Faction::Rebels) return (int)get_type()*2;

    return (int)get_type()*3;
}

bool operator<(const Spaceship& links, const Spaceship& rechts)
{
    return(links.get_type()<rechts.get_type());
}

bool Spaceship::same_faction(const vector<Spaceship>& ships, Faction f)
{
    for(const auto& i : ships)
    {
        if(i.get_faction()!=f)
            return false;
    }
    return true;
}

ostream& operator<<(ostream& o, const Spaceship& space)
{
    return o << "[" << space.name << ", " << faction_names.at(static_cast<int>(space.faction)) << ", " << to_string(space.type) << ", " << space.get_value() << "]";
}
