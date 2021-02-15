#include "fleet.h"
#include "spaceship.h"


Fleet::Fleet(const string& name, const Faction& factionFleet, const vector<Spaceship>& liste): name{name}, factionFleet{factionFleet}, liste{liste}
{
    if(name.empty()) throw runtime_error("Error!");

    for(const auto& i : liste)
    {
        if(i.get_faction()!=factionFleet)
        {
            throw runtime_error("Error!");
        }
    }
}

Faction Fleet::get_factionFleet()const
{
    return this->factionFleet;
}

bool Fleet::add(const vector<Spaceship>& ships)
{
    if(ships.empty()) throw runtime_error("Error!");

    for(const auto& i : ships)
    {
        if(i.get_faction()!=get_factionFleet())
            return false;
    }

    vector<Spaceship>neu;
    for(const auto& i : liste)
    {
        neu.push_back(i);
    }

    liste.clear();
    for(const auto& i : ships) liste.push_back(i);

    for(const auto& i : neu) liste.push_back(i);
    return true;
}

vector<int> Fleet::extremes() const
{
    if(liste.empty()) throw runtime_error("Error!");
    vector<int>ergebnis;
    int maximum = liste.at(0).get_value();
    int minimum = liste.at(0).get_value();
    for(const auto& i : liste)
    {
        if(i.get_value()<minimum)
        {
            minimum = i.get_value();
        }

        if(i.get_value()>maximum)
        {
            maximum = i.get_value();
        }
    }
    ergebnis.push_back(minimum);
    ergebnis.push_back(maximum);
    return ergebnis;
}

vector<Spaceship> Fleet::elite(Fleet& f)
{
    if(f.liste.size()!=liste.size() || get_factionFleet()!=f.get_factionFleet()) throw runtime_error("Error!");

    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i).get_value()<f.liste.at(i).get_value())
        {
            Spaceship temp = f.liste.at(i);
            f.liste.at(i)=liste.at(i);
            liste.at(i)=temp;
        }
    }

    vector<Spaceship>ergebnis;
    for(size_t i = liste.size(); i>0; i--)
    {
        ergebnis.push_back(liste.at(i-1));
    }
    return ergebnis;
}

ostream& operator<<(ostream& os, const Fleet& fleet)
{
    os << "[" << fleet.name << ", " << faction_names.at(static_cast<int>(fleet.factionFleet)) << ", {";
    for(size_t i = 0; i<fleet.liste.size(); i++)
    {
        os << fleet.liste.at(i);
        if(i!=fleet.liste.size()-1)
        {
            os << ", ";
        }
    }
    return os << "}]";
}
