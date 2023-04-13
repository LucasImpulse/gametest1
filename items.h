#include <string>
#include <iostream>

class Item {
public:
    // Constructor clump
    Item(); // Default
    Item(const std::string& name, const std::string& description, const std::string& type, const std::string& rarity,
        int damage, int durability, double weight, int price)
        : name_(name), description_(description), type_(type), rarity_(rarity),
        damage_(damage), durability_(durability), weight_(weight), price_(price),
        maxDurability_(durability_) {
    // Parameter ones
    // what a bloody eyesore of a constructor. Messes with my head the longer I look at it...

    // Destructor really is for debugs later on maybe?
    ~Item() {
        std::cout << name_ << ", item destroyed!" << std::endl;
    }

    // Getter all on their own
    std::string getName() const {
        return name_;
    }
    std::string getDescription() const {
        return description_;
    }
    std::string getType() const {
        return type_;
    }
    std::string getRarity() const {
        return rarity_;
    }
    int getDamage() const {
        return damage_;
    }
    int getDurability() const {
        if (maxDurability_ == -1) {
            return -1;  // idk wtf is the point but consistency i guess
        }  
        return durability_;
    }
    double getWeight() const {
        return weight_;
    }
    int getPrice() const {
        return price_;
    }

    // Setter same thing
    void setName(const std::string& name) {
        name_ = name;
    }
    void setDescription(const std::string& description) {
        description_ = description;
    }
    void setType(const std::string& type) {
        type_ = type;
    }
    void setRarity(const std::string& rarity) {
        rarity_ = rarity;
    }
    void setDamage(int damage) {
        damage_ = damage;
    }
    void setDurability(int durability) {
        if (maxDurability_ == -1) {
            return;  // -1 means item won't break.
        }
        durability_ = durability;
    }
    void setWeight(double weight) {
        weight_ = weight;
    }
    void setPrice(int price) {
        price_ = price;
    }

    // Durability incrementer and decrementer.
    void healDamage(int amount) {
        if (maxDurability_ == -1) {
            return;  // What cannot break doesn't need a fix.
        }

        durability_ += amount;
        if (durability_ > maxDurability_) {
            durability_ = maxDurability_;
        }
    }
    void takeDamage(int amount) {
        if (maxDurability_ == -1) {
            return;  // Item's not going to break, -1 means durability is off.
        }
        
        durability_ -= amount;
        if (durability_ < 0) {
            durability_ = 0;
        }
    }
    // I think it's important for example if we had anvils to fix and some anvils do it better, I don't want to super maths it with the setter and I just made these.
    // And also if you hit some rock-skinned prick your item's going to get more damage, or you use it wrong for example.

    void display() const {
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Description: " << description_ << std::endl;
        std::cout << "Type: " << type_ << std::endl;
        std::cout << "Rarity: " << rarity_ << std::endl;
        std::cout << "Damage: " << damage_ << std::endl;
        std::cout << "Durability: " << durability_ << std::endl;
        std::cout << "Weight: " << weight_ << std::endl;
        std::cout << "Price: " << price_ << std::endl;
    }

private:
    std::string name_; // le item name
    std::string description_; // item description
    std::string type_; // item type
    std::string rarity_; // fortnight
    int damage_; // damage or power of the item
    int durability_; // durability or condition of the item at the time
    int maxDurability_; // good we set this so item doesn't overheal, if we want overheal we can add it later as a buffer int var and change our methods to account for this << variable, and that overheal variable.
    double weight_; // item weight
    int price_; // item price

    // apparently so far this is the biggest single class i have written to represent an entity. so you know i am a noob.
};
