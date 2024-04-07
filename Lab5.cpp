#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib> 


class OutOfPancakeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Out of pancakes!";
    }
};


class PancakeShop {
private:
    std::queue<int> customers;
    std::stack<int> pancakes; 
    int servedCustomers; 
    int pancakesRemaining; 

public:
    PancakeShop() : servedCustomers(0), pancakesRemaining(0) {}

    
    void addCustomer(int numPancakes) {
        customers.push(numPancakes);
    }

    
    void serveCustomer() {
        if (pancakes.empty()) {
            makePancakes();
        }

        int numPancakesRequested = customers.front();
        customers.pop();

        std::cout << "Serving customer " << servedCustomers + 1 << " with " << numPancakesRequested << " pancakes." << std::endl;

        if (numPancakesRequested <= pancakes.size()) {
           
            for (int i = 0; i < numPancakesRequested; ++i) {
                pancakes.pop();
            }
            pancakesRemaining = pancakes.size();
        } else {
            throw OutOfPancakeException(); 
        }

        servedCustomers++;
    }

    
    void makePancakes() {
        std::cout << "Making 5 more pancakes." << std::endl;
        for (int i = 0; i < 5; ++i) {
            pancakes.push(rand() % 10 + 1); 
        }
        pancakesRemaining = pancakes.size();
    }

    
    int getCustomersServed() const {
        return servedCustomers;
    }

    
    int getPancakesRemaining() const {
        return pancakesRemaining;
    }
};

int main() {
    PancakeShop shop;

    
    for (int i = 0; i < 30; ++i) {
        shop.addCustomer(rand() % 3 + 1);
    }

    try {
        while (shop.getCustomersServed() < 30) {
            shop.serveCustomer();
            std::cout << "Pancakes remaining: " << shop.getPancakesRemaining() << std::endl;
        }
    } catch (const OutOfPancakeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
