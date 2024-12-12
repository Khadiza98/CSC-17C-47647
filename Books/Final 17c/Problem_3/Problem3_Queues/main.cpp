/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 10, 2024, 2:21 AM
 * Purpose: Let us say you are in a line at the grocery store or bank like I was
 *          last weekend. One line, yet there are 3 clerks/tellers which service
 *          the same line. Simulate the following,
            Clerk 1 - Services customers on the average 1/min
            Clerk 2 - Services customers on the average 0.5/min
            Clerk 3 - Services customers on the average 0.75/min
            Customers - Arrive at 4/minute intervals. When the line gets to 5 
 *          customers add one more Clerk with the same service rate as Clerk 1. 
 *          Add one more clerk similarly for each 5 customers. Take tellers away
 *          when they have serviced the line according to how they were added. 
 *          For instance, if a 4th clerk was added to the line because there 
 *          were 5 customers waiting then remove the clerk when the customer 
 *          count in line goes to zero. What is average customer wait time?
 *          What is the max number of customers in the line? If you randomize 
 *          servicing and arrival times by +-50% how does this change results?        
 */
//System Libraries
#include <iostream>   // For input/output
#include <queue>      // For the customer queue
#include <vector>     // For storing clerks
#include <random>     // For generating random numbers
using namespace std;  // STD Name-space where Library is compiled

// Structure representing a clerk
struct Clerk {
    float rate;        // Customers serviced per minute
    float nextFreeTime;  // Next time the clerk will be available
};

//Function Prototypes
float getRandTime(float, bool);
void runSimulation(float, vector<float>, int, bool);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    //Declare variables here
    float custArrRate = 4.0f;  // 4 customers per minute
    vector<float> clerkRates = { 1.0f, 0.5f, 0.75f };  // Service rates of clerks
    int simTime = 60;  // Simulate for 60 minutes

    // Run the simulation without randomization
    cout << "Simulation Without Randomized Times:\n";
    runSimulation(custArrRate, clerkRates, simTime, false);

    // Run the simulation with randomization
    cout << "Simulation With Randomized Times (±50%):\n";
    runSimulation(custArrRate, clerkRates, simTime, true);

    // Exit the program!
    return 0;
}

// Function to generate a randomized service time
float getRandTime(float baseRate, bool randomize) {
    if (!randomize) return baseRate;  // Return base rate if no randomization
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.5f, 1.5f);  // 50% ± variation
    return baseRate / dist(gen);  // Return adjusted rate
}

// Main simulation function
void runSimulation(float custArrRate, vector<float> clerkRates, int simTime, bool randomize) {
    queue<float> custQueue;         // Queue for customer arrival times
    vector<Clerk> clerks;           // List of clerks
    float currTime = 0.0f;          // Current time in the simulation
    float totalWait = 0.0f;         // Total wait time for customers
    int maxQueueLen = 0;            // Maximum queue length
    int servedCount = 0;            // Total customers served

    // Initialize the initial clerks
    for (float rate : clerkRates) {
        clerks.push_back({ rate, 0.0f });  // Initialize each clerk
    }

    // Simulation loop
    while (currTime < simTime) {
        // Generate the next customer's arrival time
        float nextArrival = getRandTime(1.0f / custArrRate, randomize);
        currTime += nextArrival;
        custQueue.push(currTime);  // Add customer to the queue

        // Add more clerks if needed
        while (custQueue.size() > clerks.size() * 5) {
            clerks.push_back({ 1.0f, currTime });  // Add a new clerk with 1 customer/min rate
        }

        // Service customers
        for (Clerk& clerk : clerks) {
            if (!custQueue.empty() && clerk.nextFreeTime <= currTime) {
                float arrivalTime = custQueue.front();  // Get next customer
                custQueue.pop();  // Remove customer from the queue

                totalWait += currTime - arrivalTime;  // Calculate waiting time
                clerk.nextFreeTime = currTime + getRandTime
                        (1.0f / clerk.rate, randomize);  // Update availability
                servedCount++;  // Increment served count
            }
        }

        // Remove extra clerks if queue is empty
        while (clerks.size() > 3 && custQueue.empty()) {
            clerks.pop_back();  // Remove dynamically added clerks
        }

        // Track the maximum queue length
        maxQueueLen = max(maxQueueLen, static_cast<int>(custQueue.size()));
    }

    // Calculate and print simulation results
    float avgWait = (servedCount > 0) ? (totalWait / servedCount) : 0.0f;
    cout << (randomize ? "Randomized Times:\n" : "Non-Randomized Times:\n");
    cout << "Average Customer Wait Time: " << avgWait << " minutes\n";
    cout << "Maximum number of customer in the line: " << maxQueueLen << "\n";
    cout << "Total Customers Served: " << servedCount << "\n\n";
}
