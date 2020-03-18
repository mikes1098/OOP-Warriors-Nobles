//Mike Singh (ms9744)
//hw06
//Warriors and Nobles (pointers to each other)

#include "Noble.h"
#include "Warriors.h"
#include <iostream>
using namespace std;


namespace WarriorCraft{
    
    //Constructor
    Noble::Noble(const string& name) : noble_name(name){}

    // returns name of noble
    string Noble::returnNobleName() const {
        return noble_name;
    }

    // hires a warrior
    bool Noble::hire(Warrior& potential_employee){
        Warrior* new_employee = &potential_employee;
    
        // if already employed
        if (potential_employee.returnEmployed()){
            return false;
        }
        // else employ
        else{
            employees.push_back(new_employee);
            new_employee->changeEmployed(true);
            new_employee->newEmployer(this);
            nobleStrength();
            return true;
        }
    
    }

    // Displays noble warrior count and team statistics
    void Noble::display() const {
        size_t warrior_count = employees.size();
        
        //adds to count as long as warrior has not been removed
        cout << noble_name << " has an army of " << warrior_count << endl;
    
        // prints statistics as long as warrior has not been removed
        for (size_t index = 0; index < employees.size() ; ++index){
            if ( employees[index] != nullptr){
                employees[index]->printWarrior();
            }
        }
    }
    
    void Noble::removeWarrior(size_t index){
        //moves all warriors forward
        for (index +=1 ; index < employees.size(); ++index){
            Warrior* WarriorToMove;
            WarriorToMove = employees[index];
            employees[index-1] = WarriorToMove;
        }
        //deletes last warrior (or the warrior wanted to be removed)
        employees.pop_back();
    }

    size_t Noble::getIndexOfWarrior(Warrior* warrior_){
        for (size_t index = 0 ; index < employees.size() ; ++index){
            if (employees[index] == warrior_){
                return index;
            }
        }
        return 0;
    }

    // Fires a warrior
    bool Noble::fire(Warrior& fired){
        Warrior* fired_employee = &fired;
        
        // runs through the vector of employees to find the fired warrior
        for (size_t index = 0 ; index < employees.size() ; ++index){
            if (employees[index] == fired_employee){
                cout << fired_employee->returnName() << ", you're fired! -- " << noble_name << endl;
                removeWarrior(index);
                nobleStrength(); // needed in order to recalculate the new total_strength
                return true;
            }
        }
        return false;
    }

    // returns noble strength (main function used in order to recalculate the total strength due to changes of the vector) i.e adding a new warrior or firing one
    int Noble::nobleStrength(){
        total_strength = 0;
    
        // adds the strength of all the warriors in the nobles team
        for (size_t ind = 0; ind < employees.size(); ++ind){
            int StrengthToAdd = employees[ind]->returnStrength();
            total_strength += StrengthToAdd;
        }
        return total_strength;
    }

    // Changes strength of the noble
    void Noble::changeNobleStrength(const int& enemy_strength){
        if (enemy_strength >= total_strength){
            total_strength = 0;
            for (size_t index = 0 ; index < employees.size() ; ++index){
                int warrior_reduced_strength = employees[index]->returnStrength();
                employees[index] ->changeStrength(warrior_reduced_strength);
            }
        }
        else{
            double reduction_fraction = 0;
            reduction_fraction = double(enemy_strength) / double(total_strength);
            
            //Changes the strength of each warrior
            for (size_t index = 0 ; index < employees.size() ; ++index){
                int warrior_reduced_strength = employees[index]->returnStrength();
                warrior_reduced_strength = warrior_reduced_strength * reduction_fraction;
                employees[index] ->changeStrength(warrior_reduced_strength);
            }
            nobleStrength();
        }
    }

    //Returns true if the noble is dead
    bool Noble::checkIfDead() const {
        if (total_strength == 0){
            return true;
        }
        return false;
    }

    //Battle function
    void Noble::battle(Noble& Enemy){
        cout << noble_name << " battles " << Enemy.returnNobleName() << endl;
    
        // If both are dead
        if (Enemy.checkIfDead() && checkIfDead()) {
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
        else{
        
            //If enemy is dead
            if (Enemy.checkIfDead()) {
                cout << "He's dead " << noble_name << endl;
                
            }
            else{
            
                // If you are dead
                if (checkIfDead()) {
                    cout << "He's dead " << Enemy.returnNobleName() << endl;
                }
                else{
                
                    // If enemy is stronger
                    if (Enemy.nobleStrength() > nobleStrength()) {
                        int original_strength = nobleStrength();
                        total_strength = 0;
                        Enemy.changeNobleStrength(original_strength);
                        cout <<  Enemy.returnNobleName() << " defeats " << noble_name << endl;
                    }
                
                    // If enemy is weaker
                    if (Enemy.nobleStrength() < nobleStrength()) {
                        int original_strength = Enemy.nobleStrength();
                        changeNobleStrength(original_strength);
                        Enemy.changeNobleStrength(nobleStrength());
                        cout << returnNobleName() << " defeats " << Enemy.returnNobleName() << endl;
                    }
                
                    // If enemy and you have the same strength
                    if (Enemy.nobleStrength() == nobleStrength()){
                        int original_strength = total_strength;
                        changeNobleStrength(Enemy.nobleStrength());
                        Enemy.changeNobleStrength(original_strength);
                        cout << "Mutual Annihalation: " << Enemy.returnNobleName() << " and " << noble_name << " die at each other's hands." << endl;
                    }
                }
            }
        }
    }

    ostream& operator<<(ostream& os, const Noble& rhs) {
    
        size_t warrior_count = rhs.employees.size();
    
        //adds to count as long as warrior has not been removed
        
        os << rhs.noble_name << " has an army of " << warrior_count << endl;
    
        // prints statistics as long as warrior has not been removed
        for (size_t index = 0; index < rhs.employees.size() ; ++index){
            if (index == rhs.employees.size()-1){
                os << "     " << rhs.employees[index]->returnName() << ": " << rhs.employees[index]->returnStrength();
            }
            else{
                os << "     " << rhs.employees[index]->returnName() << ": " << rhs.employees[index]->returnStrength() << endl;
            }
        }
        return os;
    }
}
