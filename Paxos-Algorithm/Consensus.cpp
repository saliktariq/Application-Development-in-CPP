#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>

// Paxos is a consensus algorithm that is used to achieve distributed consensus
// among a group of nodes in a network. The basic idea is to have a group of nodes
// agree on a value, even if some of them fail or experience delays.

// In this simple implementation, I assume that there are no failures, and
// the communication is synchronous (messages are sent and received instantly).

// Define constants for the number of nodes and the majority
const int NUM_NODES = 5;
const int MAJORITY = (NUM_NODES / 2) + 1;

class Node {
public:
    // Each node has an ID and keeps track of its state
    int id;
    int highestPrepareSeen;
    int highestAcceptSeen;
    int highestAcceptValue;

    // Constructor
    Node(int id) : id(id), highestPrepareSeen(-1), highestAcceptSeen(-1), highestAcceptValue(-1) {}

    // Prepare phase
    std::pair<int, int> prepare(int proposalNumber) {
        // If the proposal number is higher than any seen so far, update the state
        if (proposalNumber > highestPrepareSeen) {
            highestPrepareSeen = proposalNumber;
            return std::make_pair(highestAcceptSeen, highestAcceptValue);
        }
        return std::make_pair(-1, -1);
    }

    // Accept phase
    bool accept(int proposalNumber, int value) {
        // If the proposal number is higher than or equal to the highest seen in the prepare phase,
        // update the state and accept the proposal
        if (proposalNumber >= highestPrepareSeen) {
            highestAcceptSeen = proposalNumber;
            highestAcceptValue = value;
            return true;
        }
        return false;
    }
};

int main() {
    // Initialize the nodes
    std::vector<Node> nodes;
    for (int i = 0; i < NUM_NODES; ++i) {
        nodes.push_back(Node(i));
    }

    // Generate a random proposal number and value
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> proposalDist(1, 100);
    std::uniform_int_distribution<> valueDist(1, 100);
    int proposalNumber = proposalDist(gen);
    int proposedValue = valueDist(gen);

    // Prepare phase: Send prepare messages to all nodes and collect their responses on separate threads
    std::vector<std::pair<int, int>> prepareResponses;
    std::vector<std::thread> prepareThreads;
    for (auto& node : nodes) {
        prepareThreads.emplace_back([&prepareResponses, &node, proposalNumber]() {
            prepareResponses.push_back(node.prepare(proposalNumber));
            });
    }
    for (auto& thread : prepareThreads) {
        thread.join();
    }

    // Find the highest accepted value among the responses
    auto maxResponse = std::max_element(prepareResponses.begin(), prepareResponses.end());
    if (maxResponse->second != -1) {
        proposedValue = maxResponse->second;
    }

    // Accept phase: Send accept messages with the proposed value to all nodes and collect their responses on separate threads
    std::vector<bool> acceptResponses;
    std::vector<std::thread> acceptThreads;
    for (auto& node : nodes) {
        acceptThreads.emplace_back([&acceptResponses, &node, proposalNumber, proposedValue]() {
            acceptResponses.push_back(node.accept(proposalNumber, proposedValue));
            });
    }
    for (auto& thread : acceptThreads) {
        thread.join();
    }

    // Count the number of accept responses
    int numAccepts = std::count(acceptResponses.begin(), acceptResponses.end(), true);

    // If a majority of nodes accept the proposal, the consensus is reached
    if (numAccepts >= MAJORITY) {
        std::cout << "Consensus reached with value: " << proposedValue << std::endl;
    }
    else {
        std::cout << "Consensus not reached" << std::endl;
    }

    return 0;
}
