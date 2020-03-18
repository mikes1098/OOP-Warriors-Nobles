//Mike Singh (ms9744)
//hw06
//Warriors and Nobles (pointers to each other)

#ifndef Warriors_h
#define Warriors_h

#include <string>
#include <vector>
#include <iostream>


namespace WarriorCraft{
    // Creates Warrior Class
    class Noble;
    
    class Warrior{
    public:
        
        //Constructor
        Warrior(const std::string& name_, const int& warrior_strength) ;
        
        //Default Constructor
        Warrior();
        
        //Changes strength
        void changeStrength(int strength_decrease);
        
        // returns strength of warrior
        int returnStrength() const ;
        
        //return if already employed
        bool returnEmployed() const ;
        
        
        //changes if employed
        void changeEmployed(bool hire_or_fire);
        
        //adds new employer
        void newEmployer(Noble* employer_);
        
        //warrior runs away
        void runaway();
        
        //prints the warrior statistics
        void printWarrior() const ;
        
        // returns the name of warrior
        std::string returnName() const ;
        
    private:
        std::string warrior_name;
        int strength;
        bool employed;
        Noble* employer;
    };

}
#endif
