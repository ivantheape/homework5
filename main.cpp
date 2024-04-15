#include <iostream>
#include <string>

class Weapon;

class Character {
private:
    Weapon* weapon;

public:
    // Creating of weapon
    Character() : weapon(nullptr) {}

    // Destruction of ewapon
    ~Character() {
        delete weapon;
    }

    void SetWeapon(Weapon* weapon) {
        this->weapon = weapon;
    }

    Weapon* GetWeapon() const {
        return weapon;
    }
};

class Weapon {
public:

    virtual float GetDamage() const = 0;

    virtual std::string GetName() const = 0;
};

class Sword : public Weapon {
public:
   
    float GetDamage() const override {
        return 20.0f; 
    }

    std::string GetName() const override {
        return "Sword";
    }
};


class Bow : public Weapon {
public:
    
    float GetDamage() const override {
        return 30.0f; 
    }

    std::string GetName() const override {
        return "Bow";
    }
};

int main() {
   
    Character character;

    Weapon* sword = new Sword();
    character.SetWeapon(sword);

    Weapon* equippedWeapon = character.GetWeapon();
    if (equippedWeapon) {
        std::cout << "Equipped weapon: " << equippedWeapon->GetName() << std::endl;
        std::cout << "Damage: " << equippedWeapon->GetDamage() << std::endl;
    }
    else {
        std::cout << "Character does not have a weapon." << std::endl;
    }

    return 0;
}
