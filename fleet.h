#ifndef FLEET_H
#define FLEET_H

#include "spaceship.h"

class Fleet
{
    private:
        string name;
        Faction factionFleet;
        vector<Spaceship>liste;

    public:
        Fleet(const string& name, const Faction& factionFleet, const vector<Spaceship>& liste);
        Faction get_factionFleet()const;
        bool add(const vector<Spaceship>& ships);
        friend ostream& operator<<(ostream&, const Fleet&);

        vector<int> extremes() const;
        vector<Spaceship> elite(Fleet& f);
};

#endif // FLEET_H
