//Mike Singh (ms9744)
//hw06
//Warriors and Nobles (pointers to each other)

#ifndef Noble_h
#define Noble_h

#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft{
    
    class Warrior;
    
    //Noble class
    class Noble{
        
    public:
        //Constructor
        Noble(const std::string& name);
        
        //Output operator overload
        friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
        
        //Returns name of noble
        std::string returnNobleName() const ;
        
        //Hires a warrior
        bool hire(Warrior& potential_employee);
        
        // Displays noble warrior count and team statistics
        void display() const ;
        
        //Remove warrior from employees
        void removeWarrior(size_t index);
        
        //Returns index of warrior in vector
        size_t getIndexOfWarrior(Warrior* warrior_);
        
        // Fires a warrior
        bool fire(Warrior& fired);
        
        // returns noble strength (main function used in order to recalculate the total strength due to changes of the vector) i.e adding a new warrior or firing one
        int nobleStrength();
        
        // Changes strength of the noble
        void changeNobleStrength(const int& enemy_strength);
        
        //Returns true if the noble is dead
        bool checkIfDead() const ;
        
        //Battle function
        void battle(Noble& Enemy);
        
    private:
        std::string noble_name;
        int total_strength;
        std::vector<Warrior*> employees;
        
    };
}

#endif
