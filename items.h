#include <string>
#include <iostream>

class Item {
public:
    // Constructor clump
    Item(); // Default
    Item(const std::string& name, const std::string& description, const std::string& type, const std::string& rarity,
         int damage, int durability, double weight, int price); // Parameter one

    // Destructor
    ~Item();

    // Getter all on their own
    std::string getName() const;
    std::string getDescription() const;
    std::string getType() const;
    std::string getRarity() const;
    int getDamage() const;
    int getDurability() const;
    double getWeight() const;
    int getPrice() const;

    // Setter same thing
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setType(const std::string& type);
    void setRarity(const std::string& rarity);
    void setDamage(int damage);
    void setDurability(int durability);
    void setWeight(double weight);
    void setPrice(int price);

    // TODO: Display all details of item at once.
    void display() const;

private:
    std::string name_; // le item name
    std::string description_; // item description
    std::string type_; // item type
    std::string rarity_; // fortnight
    int damage_; // damage or power of the item
    int durability_; // durability or condition of the item
// TODO, some items don't take damage. We must account for it.
    double weight_; // item weight
    int price_; // item price
    //TODO, some items are priceless, allow a negative value to represent.
};
