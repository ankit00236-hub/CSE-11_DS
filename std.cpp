#include <iostream>
#include <string>
#include <vector>

// Structure to store store information
struct Store {
    std::string name;
    std::string location;
    int items;
    double revenue;
};

int main() {
    // Creating a vector to store multiple stores
    std::vector<Store> stores;

    // Adding store data
    stores.push_back({"Store A", "New York", 100, 5000.00});
    stores.push_back({"Store B", "delhi", 150, 7500.00});
    stores.push_back({"Store C", "China", 75, 3000.00});

    // Displaying store data
    for (const auto& store : stores) {
        std::cout << "Store Name: " << store.name << std::endl;
        std::cout << "Location: " << store.location << std::endl;
        std::cout << "Items: " << store.items << std::endl;
        std::cout << "Revenue: " << store.revenue << std::endl;
        std::cout << std::endl;
    
    
    
    
    
    
    
    
    
    }
    return 0;
}