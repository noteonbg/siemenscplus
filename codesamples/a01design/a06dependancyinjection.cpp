#if 1

// Interface for transient simulation
class ITransientSimulator {
public:
    virtual void simulateTransient() = 0;
};

// Interface for DC simulation
class IDCSimulator {
public:
    virtual void simulateDC() = 0;
};

// Interface for AC simulation
class IACSimulator {
public:
    virtual void simulateAC() = 0;
};

// Circuit simulator implementing the specific interfaces
class CircuitSimulator : public ITransientSimulator, public IDCSimulator, public IACSimulator {
public:
    void simulateTransient() override {
        // Implement transient simulation logic
        std::cout << "Performing transient simulation..." << std::endl;
    }

    void simulateDC() override {
        // Implement DC simulation logic
        std::cout << "Performing DC simulation..." << std::endl;
    }

    void simulateAC() override {
        // Implement AC simulation logic
        std::cout << "Performing AC simulation..." << std::endl;
    }
};

// Client examples
class CircuitDesigner {
public:
//dependancy injection
    void analyzeCircuit(IACSimulator& simulator) {
        // Use AC simulation
        simulator.simulateAC();
    }
};

class PowerEngineer {
public:
    void analyzePower(IACSimulator& simulator) {
        // Use AC simulation
        simulator.simulateAC();
    }
};

int main() {
    CircuitSimulator mySimulator;

    CircuitDesigner designer;
    designer.analyzeCircuit(mySimulator);

    PowerEngineer engineer;
    engineer.analyzePower(mySimulator);

    return 0;
}


#endif