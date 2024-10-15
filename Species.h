#ifndef SPECIES_H
#define SPECIES_H
#include <string>

struct Species {
    std::string name;
    int ageThresholds[5];
    int foodConsumption;
    bool likesBaths;
};

static const int NUM_SPECIES = 6;
static const Species SPECIES[NUM_SPECIES] = {
        { "Mayfly", {1, 2, 5, 16, 20}, 5, false },
        { "Elephant", {20, 100, 250, 600, 800}, 40, true },
        { "Giraffe", {20, 75, 150, 250, 350}, 20, true },
        { "Zebra", {20, 50, 75, 150, 200}, 15, true },
        { "Lion", {10, 30, 45, 90, 120}, 30, false },
        { "Hippopotamus", {20, 100, 250, 400, 600}, 35, true}
};

// ages: egg, baby, adolescent, adult, elder
// age thresholds are when they transition _out_ of that age
static const int NUM_AGE_GROUPS = 5;
static const std::string AGE_GROUPS[NUM_AGE_GROUPS] = {
        "egg",
        "baby",
        "adolescent",
        "adult",
        "elder"
};

#endif //SPECIES_H
