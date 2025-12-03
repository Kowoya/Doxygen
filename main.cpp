/**
 * @class Character
 * @brief Base abstract class representing a creature with name and health.
 *
 * @details
 * This class is parent for Player and Enemy.
 * Contains basic properties and methods: name, health, taking damage.
 *
 * @example
 * // Character is an abstract class, so it cannot be instantiated directly.
 * // But it can be used as a type:
 * Character* c = new Enemy("Orc", 80);
 * c->takeDamage(10);
 */
class Character {
protected:
    string name;   ///< Character's name
    int health;    ///< Current health level

public:
    /**
     * @brief Base character constructor.
     *
     * @param n Character's name.
     * @param h Initial health level.
     */
    Character(string n, int h) : name(n), health(h) {}

    /**
     * @brief Abstract attack method.
     *
     * @details Implemented in derived classes Player and Enemy.
     */
    virtual void attack() = 0;

    /**
     * @brief Reduces character's health.
     *
     * @param amount Amount of damage inflicted.
     * @return Returns nothing.
     *
     * @example
     * character->takeDamage(15);
     */
    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
        cout << name << " takes " << amount << " damage. Health = " << health << endl;
    }

    /**
     * @brief Returns current character's health.
     *
     * @return Health value.
     */
    int getHealth() const { return health; }
};


/**
 * @class Player
 * @brief Player class with experience and additional abilities.
 *
 * @details
 * Derived class from Character.
 * Contains attack, spell casting, and status display.
 */
class Player : public Character {
private:
    int experience; ///< Player's experience

public:
    /**
     * @brief Player class constructor.
     *
     * @param n Player's name.
     * @param h Initial health.
     * @param xp Initial experience.
     */
    Player(string n, int h, int xp) : Character(n, h), experience(xp) {}

    /**
     * @brief Executes player's attack.
     *
     * @details Increases experience by 10.
     */
    void attack() override {
        cout << name << " attacks with a sword!" << endl;
        experience += 10;
    }

    /**
     * @brief Player casts a magic spell.
     */
    void castSpell() {
        cout << name << " casts a protective spell!" << endl;
    }

    /**
     * @brief Displays information about player's status.
     *
     * @example
     * Player p("Hero", 100, 0);
     * p.showStatus();
     */
    void showStatus() const {
        cout << "Player: " << name << ", Health: " << health << ", XP: " << experience << endl;
    }
};


/**
 * @class Enemy
 * @brief Enemy that can attack the player.
 *
 * @details
 * Simple class that inherits from Character and implements attack() method.
 */
class Enemy : public Character {
public:
    /**
     * @brief Enemy class constructor.
     *
     * @param n Enemy's name.
     * @param h Initial health level.
     */
    Enemy(string n, int h) : Character(n, h) {}

    /**
     * @brief Executes enemy's attack.
     */
    void attack() override {
        cout << name << " strikes viciously!" << endl;
    }
};


int main() {
    Player p("Alex", 100, 5);  
    p.showStatus();            
    p.attack();                
    p.takeDamage(20);          
    p.castSpell();             
}