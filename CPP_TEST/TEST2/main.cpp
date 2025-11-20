#include <iostream>
#include <vector>
#include <algorithm>

// Abstract Base Class 
class ProblemSolver {

protected: 
    std::string problemName;

public:
    ProblemSolver(const std::string& name) : problemName(name) {}

    virtual void solve() = 0; // Pure virtual function

    void PrintProblemName() {
        std::cout << "Problem: " << problemName << std::endl;
    } 

    virtual ~ProblemSolver() {}
};



class CoinChangeSolver : public ProblemSolver {

private: 
    std::vector<int> denominations; // Vector for coin denominations
    std::vector<int> coinsCount; // Vector to store the number of coins used
    int remainingAmount; // Remaining amount to be changed
    int amount; // Target amount

public:
    // Constructor
    CoinChangeSolver(const std::vector<int>& coins, int targetAmount )
        : ProblemSolver("Coin Change Problem"), denominations(coins), amount(targetAmount), remainingAmount(0) {}

    // Solve method: Use Greedy Algorithm or other algorithms to solve the problem
    void solve() override {
        
        remainingAmount = amount;
        for(int i = denominations.size()-1; i >= 0; i--) {
            coinsCount.push_back(remainingAmount/denominations[i]);
            remainingAmount = remainingAmount % denominations[i];
        }
                    
 
    }

    void PrintProblemSolution() {

        PrintProblemName();
        
        if (remainingAmount == 0) {
            std::cout << "Coins used to make " << amount << ": "<<std::endl;
            for (int i=0; i<denominations.size(); i++) {
                std::cout <<"Coin: "<< denominations[i] << ", Count: " << coinsCount[i] << " "<<std::endl;
            }
            std::cout << std::endl;
        } else {
            std::cout << "It's not possible to make the amount " << amount << " with the given denominations." << std::endl;
        }
    }
};

// Main Function
int main() {

    std::vector<int> coins = {1, 2, 5, 10}; 
    int targetAmount;

    std::cout << "Enter the amount you want to change: ";
    std::cin >> targetAmount;


    CoinChangeSolver solver(coins, targetAmount);
    solver.solve();
    solver.PrintProblemSolution();

    return 0;
}
