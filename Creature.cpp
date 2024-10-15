// Brij Malhotra
// Creature.cpp (hw2)
// Purpose: Function declaration for the pet farm

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include "Creature.h"
#include "Species.h"

using namespace std;

struct Species;

string Creature::generateName(){
    
    unsigned seed = time(0);
    srand(seed);

    string name;
    int randomName = rand() % 12 + 1;

    switch(randomName) {
        case 1:
            name = "Alex";
            break;
        case 2:
            name = "Gloria";
            break;
        case 3:
            name = "Melman";
            break;
        case 4:
            name = "Marty";
            break;
        case 5:
            name = "Skipper";
            break;
        case 6:
            name = "Julien";
            break;
        case 7:
            name = "Mort";
            break;
        case 8: 
            name = "Zuba";
            break;
        case 9:
            name = "Anakin";
            break;
        case 10:
            name = "Obi";
            break;
        case 11:
            name = "Yoda";
            break;
        case 12:
            name = "Jabba";
            break;
    }
    
    return name;
}

Creature::Creature(const Species &species, const std::string &name)
:species(species)
, name(name)
, age(0)
, happiness(500)
, fullness(500)
, cleanliness(500)
, ageGroup(0)
{
}

string Creature::getDetails() const {
    
    string emoticon;
    if (happiness >= 800){
        emoticon = ":D";
    } else if (happiness >= 550){
        emoticon = ":)";
    } else if (happiness >= 450){
        emoticon = ":|";
    } else if (happiness > 200){
        emoticon = "):";
    } else {
        emoticon = "D:";
    }

    stringstream sentenceStream;
    sentenceStream << name << "(" << species.name << ", " << AGE_GROUPS[ageGroup] << "): " << emoticon << ", fullness=" << fullness << ", cleanliness=" << cleanliness;
    string details = sentenceStream.str();

    return details;
}

string Creature::getName() const {
    return name;
}

bool Creature::canCreateEgg() const {
    if (ageGroup == 3 && happiness >= 700){
        return true;
    }
   
    return false;
}

bool Creature::isAlive() const {
    if (age >=  species.ageThresholds[4]){
        return false;
    }

    return true;
}

bool Creature::wantsToRunAway() const {
    if (fullness <= 50 || happiness <= 100){
        return true;
    }

    return false;
}

void Creature::clean(){
    cleanliness = MAX_ATTRIBUTE_VALUE;
    if (species.likesBaths == true){
        happiness += 50;
        if (happiness >= MAX_ATTRIBUTE_VALUE){
            happiness = MAX_ATTRIBUTE_VALUE;
        }
    } else {
        happiness -= 50;
    }
}

void Creature::feed(){
    fullness += 75;
    if (fullness > MAX_ATTRIBUTE_VALUE){
        fullness = MAX_ATTRIBUTE_VALUE;
        happiness -= 25;
    }
}

void Creature::rename(const std::string &newName){
    name = newName;
}

void Creature::advance(){
    age++;
    
    if (age >= species.ageThresholds[ageGroup]){
        ageGroup++;
    }

    fullness -= species.foodConsumption;
    cleanliness -= 75;
    if(fullness > 900 || fullness < 250){
        happiness -= 75;
    } else if (fullness >= 600){
        happiness += 75;
    }
    if (cleanliness < 300){
        happiness -= 50;
    }
}