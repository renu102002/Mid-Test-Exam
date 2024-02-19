#include <iostream>
#include <string>
#include <vector>

class TrainStation {
private:
    std::string name;
    std::vector<TrainStation*> connections;

public:
    TrainStation(const std::string& n) : name(n) {}

    void addConnection(TrainStation* station) {
        connections.push_back(station);
    }

    std::string getName() const {
        return name;
    }

    void print(int depth = 0) const {
        for (int i = 0; i < depth; ++i)
            std::cout << "   |";

        std::cout << "---" << name << "\n";

        for (const auto& connection : connections)
            connection->print(depth + 1);
    }

    ~TrainStation() {
        for (auto connection : connections)
            delete connection;
    }
};

// Function to recursively build the train network
void buildTrainNetwork(TrainStation* currentStation) {
    int numConnections;
    std::cout << "Enter the number of connections for station " << currentStation->getName() << ": ";
    std::cin >> numConnections;

    for (int i = 0; i < numConnections; ++i) {
        std::string connectionName;

        std::cout << "Enter the name of connected station " << i + 1 << ": ";
        std::cin >> connectionName;

        TrainStation* connectedStation = new TrainStation(connectionName);
        currentStation->addConnection(connectedStation);

        // Recursively build the train network for the connected station
        buildTrainNetwork(connectedStation);
    }
}

int main() {
    std::string centralStationName;

    // Getting information for the central station
    std::cout << "Enter the name for the central station: ";
    std::cin >> centralStationName;

    // Creating the central station
    TrainStation* centralStation = new TrainStation(centralStationName);

    // Building the train network
    buildTrainNetwork(centralStation);

    // Printing the train network
    std::cout << "\nTrain Network:\n";
    centralStation->print();

    // Clean up allocated memory
    //binary tree
    delete centralStation;

    return 0;
}