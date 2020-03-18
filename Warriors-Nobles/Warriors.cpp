//Mike Singh (ms9744)
//hw06
//Warriors and Nobles (pointers to each other)

#include "Warriors.h"
#include "Noble.h"
#include <iostream>
using namespace std;

namespace WarriorCraft{
    //Constructor
    Warrior::Warrior(const string& name_, const int& warrior_strength) : warrior_name(name_), strength(warrior_strength){}

    //Default Constructor
    Warrior::Warrior() : warrior_name("dead_or_removed"), strength(0) {}


    void Warrior::changeStrength(int strength_decrease){
        strength -= strength_decrease;
        //if dead, cant have a negative strength
        if (strength < 0){
            strength = 0;
        }
    }
    int Warrior::returnStrength() const {
        int return_str = strength;
        return return_str;
    }

    bool Warrior::returnEmployed() const {
        if (employed){
            return true;
        }
        else{
            return false;
        }
    }

    void Warrior::changeEmployed(bool hire_or_fire){
        if (hire_or_fire){
            employed = true;
        }
        else{
            employed = false;
            employer = nullptr;
        }
    }

    void Warrior::runaway() {
        cout << warrior_name << " flees in terror, abandoning his lord, " << employer->returnNobleName() << endl;
        size_t index_of_warrior = employer->getIndexOfWarrior(this);
        employer->removeWarrior(index_of_warrior);
        employer = nullptr;
    }

    void Warrior::newEmployer(Noble* employer_){
        employer = employer_;
        employed = true;
    }

    //prints the warrior statistics
    void Warrior::printWarrior() const {
        cout << "       " << warrior_name << ": " << strength << endl;
    }
    // returns the name of warrior
    string Warrior::returnName() const {
        return warrior_name;
    }
}
