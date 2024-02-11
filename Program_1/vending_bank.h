#ifndef VENDING_BANK_H
#define VENDING_BACK_H
#include <string>

class VendingBank {

    public:
        // Default Constructor
        VendingBank();
        // Constructor with id
        VendingBank(int id);
        // Constructor with id and value
        VendingBank(int id, int value);
        // Get id of vending bank
        int id() const;
        // Set id for vending bank
        void setId(int id);
        // Insert a coin into bank
        void insertCoin(int value);
        // Withdraw Coin from bank
        int withdrawCoin();
        // Return the amount of money in the bank
        int totalValue() const;
         // Overload + operator for combining banks
        VendingBank operator+(const VendingBank& other) const;
        // Overload += operator for in-place addition
        VendingBank& operator+=(const VendingBank& other);
        // Overload == operator for equality comparison
        bool operator==(const VendingBank& other) const;
        // Overload != operator for inequality comparison
        bool operator!=(const VendingBank& other) const;
        // Overload << operator for stream output
        friend std::ostream& operator<<(std::ostream& os, const VendingBank& bank);

    private:
        // id Data Member
        int id_;
        // Value Data Member
        int total_value_;

};

#endif
