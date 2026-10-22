#include <iomanip>
#include <iostream>
#include <string>

class Items {
protected:
     std::string name;
     double price;
     int quantity;
     std::string description;

public:
     //Constructor
     Items(std ::string itemName = "", double itemPrice = 0, int itemQuantity = 0, std::string itemDescription = "Item" )
          : name(itemName), price(itemPrice), quantity(itemQuantity), description(itemDescription) {
          std :: cout << "[Constructor was called] Created " << description << ": " << (name.empty() ? "Empty" : name) << std :: endl;
     }
     //Destructor
     virtual ~Items() {
          std::cout << "[Destructor was called] Destroyed " << description << ": "  << (name.empty() ? "Empty Item" : name) << std :: endl;
     }
     //Copy Constructor
     Items(const Items& other) {
          name = other.name;
          price = other.price;
          quantity = other.quantity;
          description = other.description;
          std::cout << "[Copy Constructor was called] Copied " << name << std :: endl;
     }
     //Copy Assignment Operator
     Items& operator=(const Items& other) {
          if (this != &other) {
               name = other.name;
               price = other.price;
               quantity = other.quantity;
               description = other.description;
               std::cout << "[Copy Assignment Operator was called] Assigned " << name << std :: endl;
          }
          return *this;
     }
     //calculaterPrice Function
     double calculatePrice() const {
          return price * quantity;
     }

     //printDetails function
     virtual void printDetails() const {
          std::cout << std :: left << std::setw(12) << description
                    << std :: setw(12) << name
                    << "PHP " << std::setw(8) << price
                    << "x" << std::setw(5) << quantity
                    << "Total: PHP " << calculatePrice() << std :: endl;
     }

     //getName function
     std :: string getName() const { return name;}
};

//Problem 1

class Fruit : public Items {
public:
     Fruit(std::string name = "", double price = 0.0, int quantity = 0)
     : Items(name, price, quantity, "Fruit"){}
};

class Vegetable : public Items {
public:
     Vegetable(std::string name = "", double price = 0.0, int quantity = 0)
     : Items(name, price, quantity, "Vegetable"){}
};

//Problem 3

double TotalPrice(Items** list, size_t size) {
     double grandTotal = 0.0;
     for (size_t i =0; i < size; i++) {
          if (list[i] != nullptr) {
               grandTotal += list[i]->calculatePrice();
          }
     }
     return grandTotal;
}

//Driver Code

int main() {
     std :: cout << "--- CREATING GROCERY ITEMS ---\n";

     //Problem 2
     
     size_t listSize = 4;
     Items** groceryList = new Items* [listSize];

     groceryList[0] = new Fruit("APPLE", 10.0, 7);
     groceryList[1] = new Fruit("BANANA", 10.0,8);
     groceryList[2] = new Vegetable("BROCCOLI", 60.0,12);
     groceryList[3] = new Vegetable("LETTUCE", 50.0, 10);

     std :: cout << "\n--- JENNA'S GROCERY LIST DETAILS ---\n";
     for (size_t i = 0; i < listSize; i++) {
          if (groceryList[i] != nullptr) {
               groceryList[i]->printDetails();
          }
     }
     //Problem 3

     std :: cout << "GRAND TOTAL SUM: PHP " << TotalPrice(groceryList, listSize) << "\n";

     //Problem 4

     std :: cout << "\n--- REMOVING LETTUCE AND DEALLOCATE MEMORY ---\n";
     for (size_t i = 0; i < listSize; i++) {
          if (groceryList[i] != nullptr && groceryList[i]->getName() == "LETTUCE") {
               delete groceryList[i];
               groceryList[i] = nullptr;
               std :: cout << "SUCCESSFULLY REMOVE LETTUCE FROM THE LIST.\n";
          }
     }
     std :: cout << "\n--- RE-CALCULATING THE GRAND TOTAL AFTER REMOVING LETTUCE ---\n";
     std :: cout << "NEW TOTAL SUM: PHP " << TotalPrice(groceryList, listSize) << "\n";

     std :: cout << "---CLEAN THE PROGRAM ---\n";
     for (size_t i = 0; i < listSize; i++) {
          if (groceryList[i] != nullptr) {
               delete groceryList[i];
               groceryList[i] = nullptr;
          }
     }
     delete[] groceryList;

     return 0;
}