/**
 * @class Character
 * @brief Базовий абстрактний клас, що представляє істоту з іменем та здоров'ям.
 *
 * @details
 * Клас є батьківським для Player та Enemy.
 * Містить базові властивості та методи: ім'я, здоров'я, отримання шкоди.
 *
 * @example
 * // Character є абстрактним класом, тому його не можна створювати напряму.
 * // Але можна використовувати його як тип:
 * Character* c = new Enemy("Orc", 80);
 * c->takeDamage(10);
 */
class Character {
protected:
    string name;   ///< Ім'я персонажа
    int health;    ///< Поточний рівень здоров'я

public:
    /**
     * @brief Конструктор базового персонажа.
     *
     * @param n Ім'я персонажа.
     * @param h Початковий рівень здоров'я.
     */
    Character(string n, int h) : name(n), health(h) {}

    /**
     * @brief Абстрактний метод атаки.
     *
     * @details Реалізується у похідних класах Player та Enemy.
     */
    virtual void attack() = 0;

    /**
     * @brief Зменшує здоров'я персонажа.
     *
     * @param amount Кількість завданої шкоди.
     * @return Нічого не повертає.
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
     * @brief Повертає поточне здоров’я персонажа.
     *
     * @return Значення здоров’я.
     */
    int getHealth() const { return health; }
};


/**
 * @class Player
 * @brief Клас гравця, що має досвід та додаткові здібності.
 *
 * @details
 * Похідний клас від Character.
 * Містить атаку, кастування заклять та відображення статусу.
 */
class Player : public Character {
private:
    int experience; ///< Досвід гравця

public:
    /**
     * @brief Конструктор класу Player.
     *
     * @param n Ім'я гравця.
     * @param h Початкове здоров'я.
     * @param xp Початковий досвід.
     */
    Player(string n, int h, int xp) : Character(n, h), experience(xp) {}

    /**
     * @brief Виконує атаку гравця.
     *
     * @details Збільшує досвід на 10.
     */
    void attack() override {
        cout << name << " attacks with a sword!" << endl;
        experience += 10;
    }

    /**
     * @brief Гравець кастує магічне закляття.
     */
    void castSpell() {
        cout << name << " casts a protective spell!" << endl;
    }

    /**
     * @brief Виводить інформацію про стан гравця.
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
 * @brief Ворог, який може атакувати гравця.
 *
 * @details
 * Простий клас, що успадковує Character і реалізує метод attack().
 */
class Enemy : public Character {
public:
    /**
     * @brief Конструктор класу Enemy.
     *
     * @param n Ім'я ворога.
     * @param h Початковий рівень здоров'я.
     */
    Enemy(string n, int h) : Character(n, h) {}

    /**
     * @brief Виконує атаку ворога.
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
