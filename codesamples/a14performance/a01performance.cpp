
/*

 perf stat -e cache-references,cache-misses ./my_program
 g++ hello.cpp -o hello
 perf stat ./hello
time ./hello
https://web.cecs.pdx.edu/~karavan/perf/book_gprof.html

perf stat -B -e cache-misses,branches ./hello


sudo perf  report -f
perf record ./executable
g++ -g  -oexecutable source.cpp

g++ -fsanitize=thread -g -o binary source.cpp


g++ -pg -o binary binary.cpp

./binary  --run the program

gprof binary gmon.out > profile.txt

see the content of profile.txt















*/

#if 0
#include <iostream>

int main()
{

std::cout  << "\n hello \n ";
return 0;

}
#endif

#if 0

#include <iostream>
#include <cmath>

int main() {
    int x = 10;
    int y = 20;
    int result = 0;

    // Use likely branch outcome
    if (__builtin_expect(x > y, 0)) {
        result = x * x;
    } else {
        result = std::pow(y, 2);
    }

    std::cout << "Result: " << result << std::endl;
    
    return 0;
}




#endif



#if 0

#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> arr = {4, 1, 3, 2, 6};
    int searchValue = 3;

    // Insertion is already done during array initialization

    // Search for the value
    auto it = std::find(arr.begin(), arr.end(), searchValue);
    if (it != arr.end()) {
        // Value found, print its index
        std::size_t index = std::distance(arr.begin(), it);
        std::cout << "Value " << searchValue << " found at index " << index << std::endl;
    } else {
        // Value not found
        std::cout << "Value " << searchValue << " not found in the array." << std::endl;
    }

    return 0;
}


#endif


#if 0


#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Device {
    int deviceId;
    bool status;
    std::string location;
};

int main() {
    std::array<Device, 5> devices = {
        Device{1, true, "Living Room"},
        Device{2, false, "Kitchen"},
        Device{3, true, "Bedroom"},
        Device{4, false, "Office"},
        Device{5, true, "Garage"}
    };

    int searchDeviceId = 3;

    // Search for the device by deviceId
    auto it = std::find_if(devices.begin(), devices.end(),
        [searchDeviceId](const Device dev) {
            return dev.deviceId == searchDeviceId;
        });

    if (it != devices.end()) {
        std::size_t index = std::distance(devices.begin(), it);
        std::cout << "Device with ID " << searchDeviceId << " found at index " << index << std::endl;
        std::cout << "Status: " << (it->status ? "Active" : "Inactive") << std::endl;
        std::cout << "Location: " << it->location << std::endl;
    } else {
        std::cout << "Device with ID " << searchDeviceId << " not found." << std::endl;
    }

    return 0;
}

/*



 Performance counter stats for './scp1':

              1.45 msec task-clock                       #    0.767 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               125      page-faults                      #   86.323 K/sec                     
         4,747,078      cycles                           #    3.278 GHz                       
         3,764,583      instructions                     #    0.79  insn per cycle            
           722,620      branches                         #  499.032 M/sec                     
            18,815      branch-misses                    #    2.60% of all branches    


*/



#endif

#if 1


#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Device {
    int deviceId;
    bool status;
    std::string location;
};

// Function to initialize devices
std::array<Device, 5> initializeDevices() {
    std::array<Device,5> temp{
        Device{1, true, "Living Room"},
        Device{2, false, "Kitchen"},
        Device{3, true, "Bedroom"},
        Device{4, false, "Office"},
        Device{5, true, "Garage"}
    };
    return temp;
}

// Function to search for a device by deviceId
std::array<Device, 5>::iterator findDeviceById(std::array<Device, 5>& devices, int searchDeviceId) {
    return std::find_if(devices.begin(), devices.end(),
        [searchDeviceId](Device dev) {
            return dev.deviceId == searchDeviceId;
        });
}

// Function to display device information
void displayDeviceInfo(const Device& dev) {
    std::cout << "Device ID: " << dev.deviceId << std::endl;
    std::cout << "Status: " << (dev.status ? "Active" : "Inactive") << std::endl;
    std::cout << "Location: " << dev.location << std::endl;
}

int main() {
    std::array<Device, 5> devices = initializeDevices();
    int searchDeviceId = 3;
    auto it = findDeviceById(devices, searchDeviceId);
    if (it != devices.end()) {
        displayDeviceInfo(*it);
    } else {
        std::cout << "Device with ID " << searchDeviceId << " not found." << std::endl;
    }

    return 0;
}

/*

Performance counter stats for './scp1':

              1.69 msec task-clock                       #    0.750 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               124      page-faults                      #   73.205 K/sec                     
         4,542,228      cycles                           #    2.682 GHz                       
         3,731,023      instructions                     #    0.82  insn per cycle            
           715,562      branches                         #  422.441 M/sec                     
            19,514      branch-misses                    #    2.73% of all branches  



*/





/*

time ./hello

https://web.cecs.pdx.edu/~karavan/perf/book_gprof.html

real    0m0.007s
user    0m0.002s
sys     0m0.006s

*/














#endif

#if 0

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Device {
    int deviceId;
    bool status;
    std::string location;
};

class DeviceManager {
public:
    DeviceManager() {
        initializeDevices();
    }

    void searchDeviceById(int searchDeviceId) {
        auto it = std::find_if(devices_.begin(), devices_.end(),
            [searchDeviceId](const Device dev) {
                return dev.deviceId == searchDeviceId;
            });

        if (it != devices_.end()) {
            displayDeviceInfo(*it);
        } else {
            std::cout << "Device with ID " << searchDeviceId << " not found." << std::endl;
        }
    }

private:
    std::array<Device, 5> devices_;

    void initializeDevices() {
        devices_ = {
            Device{1, true, "Living Room"},
            Device{2, false, "Kitchen"},
            Device{3, true, "Bedroom"},
            Device{4, false, "Office"},
            Device{5, true, "Garage"}
        };
    }

    void displayDeviceInfo(const Device& dev) {
        std::cout << "Device ID: " << dev.deviceId << std::endl;
        std::cout << "Status: " << (dev.status ? "Active" : "Inactive") << std::endl;
        std::cout << "Location: " << dev.location << std::endl;
    }
};

int main() {
    DeviceManager manager;
    int searchDeviceId = 3;
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    int randNum = 0;
        

    for(int i=0; i <3; i++)
    {

    searchDeviceId = (rand() % 3) + 1; // Generates a random number between 1 and 3
    manager.searchDeviceById(searchDeviceId);

    /*
    
    real    0m0.003s
    user    0m0.001s
    sys     0m0.002s
    
    */

    }
    return 0;
}



/*

Performance counter stats for './scp1':

              1.91 msec task-clock                       #    0.755 CPUs utilized             
                 1      context-switches                 #  522.635 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               125      page-faults                      #   65.329 K/sec                     
         6,248,545      cycles                           #    3.266 GHz                       
         3,814,045      instructions                     #    0.61  insn per cycle            
           733,070      branches                         #  383.128 M/sec                     
            21,346      branch-misses                    #    2.91% of all branches     


*/

#endif

#if 0
#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Device {
    int deviceId;
    bool status;
    std::string location;
};

class DeviceManager {
public:
    DeviceManager() {
        initializeDevices();
    }

    void searchDeviceById(int searchDeviceId) {
        auto it = std::find(deviceIds_.begin(), deviceIds_.end(), searchDeviceId);

        if (it != deviceIds_.end()) {
            int index = std::distance(deviceIds_.begin(), it);
            displayDeviceInfo(index);
        } else {
            std::cout << "Device with ID " << searchDeviceId << " not found." << std::endl;
        }
    }

private:
    std::array<int, 5> deviceIds_;
    std::array<bool, 5> deviceStatuses_;
    std::array<std::string, 5> deviceLocations_;

    void initializeDevices() {
        deviceIds_ = {1, 2, 3, 4, 5};
        deviceStatuses_ = {false, false, false, false, false};
        deviceLocations_ = {"xyz", "pqr", "xyz", "pqr", "pqr"};
    }

    void displayDeviceInfo(int index) {
        std::cout << "Device ID: " << deviceIds_[index] << std::endl;
        std::cout << "Status: " << (deviceStatuses_[index] ? "Active" : "Inactive") << std::endl;
        std::cout << "Location: " << deviceLocations_[index] << std::endl;
    }
};

int main() {

    /*
    DeviceManager manager;
    int searchDeviceId = 3;
    manager.searchDeviceById(searchDeviceId);
    */


    DeviceManager manager;
    int searchDeviceId = 3;
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    int randNum = 0;
        

    for(int i=0; i <3; i++)
    {

    searchDeviceId = (rand() % 3) + 1; // Generates a random number between 1 and 3
    manager.searchDeviceById(searchDeviceId);
    
    }
    return 0;
    return 0;
}


/*


Performance counter stats for './scp1':

              1.23 msec task-clock                       #    0.762 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               125      page-faults                      #  101.712 K/sec                     
         4,271,327      cycles                           #    3.476 GHz                       
         3,774,159      instructions                     #    0.88  insn per cycle            
           725,325      branches                         #  590.193 M/sec                     
            19,759      branch-misses                    #    2.72% of all branches 


*/



/*

real    0m0.008s
user    0m0.004s
sys     0m0.004s


*/


#endif

#if 0

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

    int randNum = (rand() % 3) + 1; // Generates a random number between 1 and 3
    std::cout << "Random number: " << randNum << std::endl;

    return 0;
}
/*

Performance counter stats for './scp1':

              1.18 msec task-clock                       #    0.752 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               125      page-faults                      #  105.598 K/sec                     
         4,114,376      cycles                           #    3.476 GHz                       
         3,698,830      instructions                     #    0.90  insn per cycle            
           709,905      branches                         #  599.718 M/sec                     
            19,997      branch-misses                    #    2.82% of all branches      



*/


#endif


#if 0

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    int randNum = (rand() % 3) + 1; // Generates a random number between 1 and 3
    std::cout << "Random number: " << randNum << std::endl;
    return 0;
}

/*

g++ scp1.cpp -o scp1
perf stat ./scp1


*/

/*
performance counter stats for './scp1':

              1.19 msec task-clock                       #    0.751 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               126      page-faults                      #  106.070 K/sec                     
         4,130,175      cycles                           #    3.477 GHz                       
         3,689,808      instructions                     #    0.89  insn per cycle            
           708,558      branches                         #  596.480 M/sec                     
            19,754      branch-misses                    #    2.79% of all branches   


*/

/*

real    0m0.008s
user    0m0.003s
sys     0m0.004s

*/

#endif

#if 0

#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<int> dist(1, 3); // Range [1, 3]

    int randNum = dist(gen);
    std::cout << "Random number: " << randNum << std::endl;

    return 0;
}

/*
real    0m0.008s
user    0m0.003s
sys     0m0.005s



Performance counter stats for './scp1':

              5.35 msec task-clock                       #    0.773 CPUs utilized             
                 2      context-switches                 #  373.857 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               126      page-faults                      #   23.553 K/sec                     
         5,427,862      cycles                           #    1.015 GHz                       
         3,844,074      instructions                     #    0.71  insn per cycle            
           732,589      branches                         #  136.942 M/sec                     
            21,489      branch-misses                    #    2.93% of all branches           

       0.006924230 seconds time elapsed

       0.002653000 seconds user
       0.004422000 seconds sys


*/

#endif

#if 0

#include <iostream>
using namespace std;

class Shape {
public:
    Shape(int l, int w) {
        length = l;
        width = w;
    }

    // Virtual function for calculating area
    virtual int get_Area() {
        cout << "This is a call to the parent class area" << endl;
        return 1;
    }

protected:
    int length, width;
};

class Square : public Shape {
public:
    Square(int l = 0, int w = 0) : Shape(l, w) {}

    // Override the base class function
    int get_Area() override {
        cout << "Square area: " << length * width << endl;
        return length * width;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int l = 0, int w = 0) : Shape(l, w) {}

    // Override the base class function
    int get_Area() override {
        cout << "Rectangle area: " << length * width << endl;
        return length * width;
    }
};

int main() {
    Shape* s;
    Square sq(5, 5);
    Rectangle rec(4, 5);

    // Using base class pointer to demonstrate runtime polymorphism
    s = &sq;
    s->get_Area(); // Calls Square's get_Area()

    s = &rec;
    s->get_Area(); // Calls Rectangle's get_Area()

    return 0;
}


/*
real    0m0.008s
user    0m0.000s
sys     0m0.008s

Performance counter stats for './scp1':

              2.17 msec task-clock                       #    0.738 CPUs utilized             
                 2      context-switches                 #  923.773 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               125      page-faults                      #   57.736 K/sec                     
         4,258,865      cycles                           #    1.967 GHz                       
         3,748,072      instructions                     #    0.88  insn per cycle            
           719,875      branches                         #  332.500 M/sec                     
            19,050      branch-misses                    #    2.65% of all branches


*/

#endif



#if 0

#include <vector>

// Array of Structs (AoS)
struct Particle {
    float x, y, z;
    float vx, vy, vz;
};

void updateParticlesAoS(std::vector<Particle>& particles, float dt);

// Struct of Arrays (SoA)
struct Particles {
    std::vector<float> x, y, z;
    std::vector<float> vx, vy, vz;
};

void updateParticlesSoA(Particles& particles, float dt);

void processSimd(std::vector<float>& data);





#include <immintrin.h>
#include <algorithm>

// Update particle positions (AoS)
void updateParticlesAoS(std::vector<Particle>& particles, float dt) {
    for (auto& p : particles) {
        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.z += p.vz * dt;
    }
}

// Update particle positions (SoA)
void updateParticlesSoA(Particles& particles, float dt) {
    size_t N = particles.x.size();
    for (size_t i = 0; i < N; ++i) {
        particles.x[i] += particles.vx[i] * dt;
        particles.y[i] += particles.vy[i] * dt;
        particles.z[i] += particles.vz[i] * dt;
    }
}

// SIMD optimized processing
void processSimd(std::vector<float>& data) {
    size_t i = 0;
    for (; i + 4 <= data.size(); i += 4) {
        __m128 vec = _mm_loadu_ps(&data[i]);
        vec = _mm_mul_ps(vec, _mm_set1_ps(2.0f)); // Multiply by 2
        _mm_storeu_ps(&data[i], vec);
    }
    // Handle remaining elements
    for (; i < data.size(); ++i) {
        data[i] *= 2.0f;
    }
}



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Initialize particles with random values (AoS)
void initParticlesAoS(std::vector<Particle>& particles, size_t N) {
    for (size_t i = 0; i < N; ++i) {
        particles.push_back({rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
                             rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX});
    }
}

// Initialize particles with random values (SoA)
void initParticlesSoA(Particles& particles, size_t N) {
    particles.x.resize(N);
    particles.y.resize(N);
    particles.z.resize(N);
    particles.vx.resize(N);
    particles.vy.resize(N);
    particles.vz.resize(N);
    for (size_t i = 0; i < N; ++i) {
        particles.x[i] = rand() / (float)RAND_MAX;
        particles.y[i] = rand() / (float)RAND_MAX;
        particles.z[i] = rand() / (float)RAND_MAX;
        particles.vx[i] = rand() / (float)RAND_MAX;
        particles.vy[i] = rand() / (float)RAND_MAX;
        particles.vz[i] = rand() / (float)RAND_MAX;
    }
}

int main() {
    srand(time(0));
    const size_t N = 10000;
    const float dt = 0.01f;

    // Array of Structs (AoS)

    #if 0
    std::vector<Particle> particlesAoS;
    initParticlesAoS(particlesAoS, N);
    updateParticlesAoS(particlesAoS, dt);
    #endif

    
    #if 0
    
    // Struct of Arrays (SoA)
    Particles particlesSoA;
    initParticlesSoA(particlesSoA, N);
    updateParticlesSoA(particlesSoA, dt);

    #endif

    #if 0

    // SIMD processing example
    std::vector<float> data(N);
    std::generate(data.begin(), data.end(), []() { return rand() / (float)RAND_MAX; });
    processSimd(data);

    #endif

    std::cout << "Processing complete." << std::endl;
    return 0;
}
/*
real    0m0.017s
user    0m0.010s
sys     0m0.007s

Performance counter stats for './scp1':

              6.54 msec task-clock                       #    0.888 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               281      page-faults                      #   42.940 K/sec                     
        10,427,474      cycles                           #    1.593 GHz                       
        11,346,176      instructions                     #    1.09  insn per cycle            
         2,319,621      branches                         #  354.464 M/sec                     
            27,262      branch-misses                    #    1.18% of all branches 

*/



/*

Performance counter stats for './scp1':

              6.86 msec task-clock                       #    0.899 CPUs utilized             
                 1      context-switches                 #  145.720 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               185      page-faults                      #   26.958 K/sec                     
        11,309,998      cycles                           #    1.648 GHz                       
        10,480,360      instructions                     #    0.93  insn per cycle            
         2,069,531      branches                         #  301.572 M/sec                     
            79,565      branch-misses                    #    3.84% of all branches 

real    0m0.015s
user    0m0.012s
sys     0m0.004s


*/


#endif

#if 0

//code sample dont try to run this part

const size_t N = 10000;

//traditional oop

struct Particle {
    float x, y, z;
    float vx, vy, vz;
};

std::vector<Particle> particles(N);
//Array of structures.


//data oriented  --In DOP, you would often use a struct of arrays (SoA) to improve cache efficiency:

struct Particles {
    std::vector<float> x, y, z;
    std::vector<float> vx, vy, vz;
};


Particles particles;
particles.x.resize(N);
particles.y.resize(N);
particles.z.resize(N);
particles.vx.resize(N);
particles.vy.resize(N);
particles.vz.resize(N);



//et's say you want to update the positions of the particles based on their velocities. With AoS:
for (auto& p : particles) {
    p.x += p.vx * dt;
    p.y += p.vy * dt;
    p.z += p.vz * dt;
}

//update with positions of particles
for (size_t i = 0; i < N; ++i) {
    particles.x[i] += particles.vx[i] * dt;
    particles.y[i] += particles.vy[i] * dt;
    particles.z[i] += particles.vz[i] * dt;
}

return 0;
}

//cache friendly data layout


struct Position {
    float x, y, z;
};

struct Velocity {
    float vx, vy, vz;
};

struct Health {
    int hp;
};

std::vector<Position> positions;
std::vector<Velocity> velocities;
std::vector<Health> healths;

// Process positions and velocities separately
void updatePositions(float dt) {
    for (size_t i = 0; i < positions.size(); ++i) {
        positions[i].x += velocities[i].vx * dt;
        positions[i].y += velocities[i].vy * dt;
        positions[i].z += velocities[i].vz * dt;
    }
}


/*

Data-oriented design often leads to more straightforward opportunities for SIMD (Single Instruction, Multiple Data) optimizations. 
Consider an array of floats that you want to process in parallel:

*/

std::vector<float> data(N);

// Initialize data
std::generate(data.begin(), data.end(), std::rand);

// Process data with SIMD
void process(std::vector<float>& data) {
    size_t i = 0;
    for (; i + 4 <= data.size(); i += 4) {
        __m128 vec = _mm_loadu_ps(&data[i]);
        vec = _mm_mul_ps(vec, _mm_set1_ps(2.0f)); // Multiply by 2
        _mm_storeu_ps(&data[i], vec);
    }

    // Handle remaining elements
    for (; i < data.size(); ++i) {
        data[i] *= 2.0f;
    }
}



void process(std::vector<float>& data) {
    const size_t cache_line_size = 64; // Typical cache line size
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % (cache_line_size / sizeof(float)) == 0) {
            _mm_prefetch(reinterpret_cast<const char*>(&data[i]), _MM_HINT_T0);
        }
        data[i] *= 2.0f;
    }
}



#endif

/*
SIMD (Single Instruction, Multiple Data) is a class of parallel computing where a single instruction operates on multiple data points simultaneously. SIMD is particularly useful for tasks that involve processing large arrays or matrices, such as multimedia applications, scientific computing, and other data-intensive operations.


SIMD optimization leverages special CPU instructions that operate on multiple data points in parallel. 
These instructions are available in modern processors through SIMD instruction sets like 
SSE (Streaming SIMD Extensions),
 AVX (Advanced Vector Extensions), 
 and NEON (for ARM processors).

Key Concepts
Vectorization: The process of converting scalar operations (which process one data element at a time) into vector operations
 (which process multiple data elements at once).

Registers: SIMD operations use wide registers to hold multiple data points.
 For example, an SSE register is 128 bits wide and can hold 
 four 32-bit floating-point numbers.

Alignment: Data alignment in memory can affect the performance of SIMD operations.
 Properly aligned data can be processed more efficiently.

Example of SIMD Optimization

void multiplyByScalar(float* data, size_t size, float scalar) {
    for (size_t i = 0; i < size; ++i) {
        data[i] *= scalar;
    }
}

With SIMD (Using SSE)
#include <xmmintrin.h> // Header file for SSE intrinsics

void multiplyByScalarSIMD(float* data, size_t size, float scalar) {
    __m128 scalar_vec = _mm_set1_ps(scalar); // Load the scalar into a SIMD register
    size_t i = 0;
    for (; i + 4 <= size; i += 4) {
        __m128 vec = _mm_loadu_ps(&data[i]); // Load 4 floats from memory into a SIMD register
        vec = _mm_mul_ps(vec, scalar_vec);   // Multiply the SIMD register by the scalar
        _mm_storeu_ps(&data[i], vec);        // Store the result back to memory
    }
    // Handle remaining elements
    for (; i < size; ++i) {
        data[i] *= scalar;
    }
}



Load Scalar into SIMD Register: _mm_set1_ps(scalar) creates a SIMD register where all four lanes contain the scalar value.
Loop Unrolling: The loop processes four elements at a time by incrementing i by 4 in each iteration.
Load Data: _mm_loadu_ps(&data[i]) loads four consecutive float values from the array into a SIMD register.
Perform SIMD Operation: _mm_mul_ps(vec, scalar_vec) multiplies the four packed float values by the scalar in parallel.
Store Result: _mm_storeu_ps(&data[i], vec) writes the results back to the array.
Handle Remaining Elements: After the SIMD loop, any remaining elements (less than 4) are processed by a scalar loop.

Advantages of SIMD Optimization
Performance: SIMD can significantly improve performance for data-parallel tasks by processing multiple data points in a single instruction.
Efficiency: Better use of CPU resources and memory bandwidth.

When to Use SIMD Optimization
Large Data Sets: SIMD is particularly effective for large arrays or matrices where the same operation needs to be applied to many elements.
Repetitive Calculations: Ideal for operations like vector addition, matrix multiplication, image processing, and signal processing.
Bottlenecks: Use SIMD optimization to address performance bottlenecks in your code.


Considerations
Alignment: Ensure that data is properly aligned in memory to avoid performance penalties.
Portability: SIMD code can be less portable because it relies on specific CPU instruction sets. Use libraries or compiler intrinsics that abstract some of these details.
Complexity: Writing and maintaining SIMD code can be more complex compared to scalar code.


*/

#if 0


#include <vector>
void multiplyByScalarSIMD(std::vector<float>& data, float scalar);


void multiplyByScalar(float* data, std::size_t size, float scalar) {
    for (std::size_t i = 0; i < size; ++i) {
        data[i] *= scalar;
    }
}


#include <xmmintrin.h> // Header file for SSE intrinsics

/*
void multiplyByScalarSIMD(std::vector<float>& data, float scalar) {
    __m128 scalar_vec = _mm_set1_ps(scalar); // Load the scalar into a SIMD register
    size_t size = data.size();
    size_t i = 0;
    for (; i + 4 <= size; i += 4) {
        __m128 vec = _mm_loadu_ps(&data[i]); // Load 4 floats from memory into a SIMD register
        vec = _mm_mul_ps(vec, scalar_vec);   // Multiply the SIMD register by the scalar
        _mm_storeu_ps(&data[i], vec);        // Store the result back to memory
    }
    // Handle remaining elements
    for (; i < size; ++i) {
        data[i] *= scalar;
    }
}
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstddef>

int main() {
    srand(static_cast<unsigned>(time(0)));
    const size_t N = 10000;
    std::vector<float> data(N);

    // Initialize data with random values
    for (size_t i = 0; i < N; ++i) {
        data[i] = rand() / (float)RAND_MAX;
    }

    float scalar = 2.0f;
   // multiplyByScalarSIMD(data, scalar);
        multiplyByScalar(data, scalar);
    std::cout << "SIMD processing complete." << std::endl;
    return 0;
}

/*
real    0m0.003s
user    0m0.001s
sys     0m0.003s

*/


/*

real    0m0.003s
user    0m0.002s
sys     0m0.001s

*/



#endif

/*

To instruct the GNU g++ compiler to generate SIMD (Single Instruction, Multiple Data) instructions,
 you can use specific compiler flags that enable the use of various SIMD instruction sets such as
  SSE, AVX, or NEON.
  
   here are the options

SSE (Streaming SIMD Extensions): Available on most x86 CPUs. Use -msse, -msse2, -msse3, etc.
AVX (Advanced Vector Extensions): Available on newer x86 CPUs. Use -mavx, -mavx2, etc.
NEON: Available on ARM CPUs. Use -mfpu=neon.

//To enable SSE and AVX instructions, you can compile your code as follows:
g++ -O3 -msse4.2 -mavx -o myprogram myprogram.cpp

-O3: Enables high-level optimizations.
-msse4.2: Enables SSE4.2 instructions.
-mavx: Enables AVX instructions.

g++ -O3 -mfpu=neon -o myprogram myprogram.cpp


-ftree-vectorize: Enables the GCC auto-vectorizer.
-fopt-info-vec: Provides information about vectorized loops and functions.

g++ -O3 -ftree-vectorize -fopt-info-vec -msse4.2 -mavx -o myprogram myprogram.cpp


For finer control over SIMD operations, you can use SIMD intrinsics directly in your code. 
Intrinsics provide a way to use SIMD instructions without writing assembly code.


*/

#if 0

#include <iostream>
#include <vector>
#include <functional>

// Function pointer type for area calculation
using AreaFunction = double (*)(void*);

// Shape struct holding the function pointer and data
struct Shape {
    void* data;
    AreaFunction areaFunc;
};

struct Circle {
    double radius;
};

struct Square {
    double side;
};

// Area calculation functions
double calculateCircleArea(void* data) {
    Circle* circle = static_cast<Circle*>(data);
    return 3.14159 * circle->radius * circle->radius;
}

double calculateSquareArea(void* data) {
    Square* square = static_cast<Square*>(data);
    return square->side * square->side;
}

int main() {
    // Create shapes
    Circle circle{5.0};
    Square square{4.0};

    // Create Shape instances with appropriate function pointers
    Shape shapes[2];
    shapes[0] = {&circle, calculateCircleArea};
    shapes[1] = {&square, calculateSquareArea};

    // Calculate and print areas
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape.areaFunc(shape.data) << std::endl;
    }

    return 0;
}

/*

real    0m0.004s
user    0m0.001s
sys     0m0.003s


Performance counter stats for './scp1':

              1.34 msec task-clock                       #    0.752 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               127      page-faults                      #   94.715 K/sec                     
         3,860,458      cycles                           #    2.879 GHz                       
         3,746,505      instructions                     #    0.97  insn per cycle            
           719,690      branches                         #  536.737 M/sec                     
            18,087      branch-misses                    #    2.51% of all branches           


*/

#endif


#if 0

#include <iostream>

// Function pointer type for area calculation
using AreaFunction = double (*)(void*);

// Shape struct holding the function pointer and data
struct Shape {
    void* data;
    AreaFunction areaFunc;
};

struct Circle {
    double radius;
};

struct Square {
    double side;
};

// Area calculation functions
double calculateCircleArea(void* data) {
    Circle* circle = static_cast<Circle*>(data);
    return 3.14159 * circle->radius * circle->radius;
}

double calculateSquareArea(void* data) {
    Square* square = static_cast<Square*>(data);
    return square->side * square->side;
}

int main() {
    // Create shapes
    Circle circle{5.0};
    Square square{4.0};

    // Create Shape instances with appropriate function pointers
    Shape shapes[2];
    shapes[0] = {&circle, calculateCircleArea};
    shapes[1] = {&square, calculateSquareArea};

    // Calculate and print areas
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape.areaFunc(shape.data) << std::endl;
    }

    return 0;
}

/*

real    0m0.003s
user    0m0.003s
sys     0m0.001s

/*


 Performance counter stats for './scp1':

              1.36 msec task-clock                       #    0.731 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               128      page-faults                      #   94.288 K/sec                     
         4,044,583      cycles                           #    2.979 GHz                       
         3,770,785      instructions                     #    0.93  insn per cycle            
           723,228      branches                         #  532.749 M/sec                     
            18,778      branch-misses                    #    2.60% of all branches

*/



*/


#endif

#if 0


#include <iostream>
#include <vector>

// Shape data structures
struct Circle {
    double radius;
};

struct Square {
    double side;
};

// Template function for calculating area
template <typename Shape>
double calculateArea(const Shape& shape);

template <>
double calculateArea<Circle>(const Circle& circle) {
    return 3.14159 * circle.radius * circle.radius;
}

template <>
double calculateArea<Square>(const Square& square) {
    return square.side * square.side;
}

// Wrapper structure for shapes
template <typename Shape>
struct ShapeWrapper {
    Shape shape;
    double (*areaFunc)(const Shape&);

    ShapeWrapper(const Shape& s, double (*func)(const Shape&))
        : shape(s), areaFunc(func) {}
};

int main() {
    // Create shapes
    Circle circle{5.0};
    Square square{4.0};

    // Create ShapeWrapper instances with appropriate function pointers
    std::vector<ShapeWrapper<Circle>> circles = { ShapeWrapper<Circle>(circle, calculateArea<Circle>) };
    std::vector<ShapeWrapper<Square>> squares = { ShapeWrapper<Square>(square, calculateArea<Square>) };

    // Calculate and print areas
    for (const auto& wrapper : circles) {
        std::cout << "Circle Area: " << wrapper.areaFunc(wrapper.shape) << std::endl;
    }
    for (const auto& wrapper : squares) {
        std::cout << "Square Area: " << wrapper.areaFunc(wrapper.shape) << std::endl;
    }

    return 0;
}

/*

real    0m0.003s
user    0m0.002s
sys     0m0.002s

*/

/*
Performance counter stats for './scp1':

              1.17 msec task-clock                       #    0.747 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               127      page-faults                      #  108.806 K/sec                     
         3,941,077      cycles                           #    3.376 GHz                       
         3,743,697      instructions                     #    0.95  insn per cycle            
           719,067      branches                         #  616.053 M/sec                     
            18,423      branch-misses                    #    2.56% of all branches           





*/


#endif

#if 0

#include <iostream>
#include <vector>
#include <variant>

// Shape data structures
struct Circle {
    double radius;
};

struct Square {
    double side;
};

// Area calculation functions
double calculateArea(const Circle& circle) {
    return 3.14159 * circle.radius * circle.radius;
}

double calculateArea(const Square& square) {
    return square.side * square.side;
}

// Variant type to hold shapes
using Shape = std::variant<Circle, Square>;

int main() {
    // Create shapes
    Circle circle{5.0};
    Square square{4.0};

    // Create a vector of shapes
    std::vector<Shape> shapes = {circle, square};

    // Calculate and print areas
    for (const auto& shape : shapes) {
        std::visit([](const auto& s) {
            std::cout << "Area: " << calculateArea(s) << std::endl;
        }, shape);
    }

    return 0;
}


/*
real    0m0.010s
user    0m0.003s
sys     0m0.007s

Performance counter stats for './scp1':

              1.55 msec task-clock                       #    0.743 CPUs utilized             
                 1      context-switches                 #  644.592 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               127      page-faults                      #   81.863 K/sec                     
         4,293,783      cycles                           #    2.768 GHz                       
         3,753,544      instructions                     #    0.87  insn per cycle            
           721,580      branches                         #  465.124 M/sec                     
            20,880      branch-misses                    #    2.89% of all branches  


*/

#endif

#if 0

#include <iostream>
#include <vector>

// Function to calculate portfolio value using matrix operations
void calculatePortfolioValue(const std::vector<std::vector<float>>& assetPrices, const std::vector<float>& assetQuantities, std::vector<float>& portfolioValue) {
    const size_t numAssets = assetPrices.size();
    const size_t numDays = assetPrices[0].size();
    
    float sum = 0.0f;
    for (size_t day = 0; day < numDays; ++day) {
        
        for (size_t asset = 0; asset < numAssets; ++asset) {
            sum += assetPrices[asset][day] * assetQuantities[asset];
        }
        portfolioValue[day] = sum;
    }
}

int main() {
    // Example data: Asset prices and quantities
    std::vector<std::vector<float>> assetPrices = {
        {100.0f, 101.0f, 102.0f, 103.0f}, // Asset 1 prices over 4 days
        {50.0f, 49.0f, 48.0f, 47.0f},     // Asset 2 prices over 4 days
        {75.0f, 76.0f, 77.0f, 78.0f}      // Asset 3 prices over 4 days
    };
    std::vector<float> assetQuantities = {10.0f, 20.0f, 30.0f}; // Asset quantities
    std::vector<float> portfolioValue(assetPrices[0].size());  // Portfolio value over time

    // Calculate portfolio value
    calculatePortfolioValue(assetPrices, assetQuantities, portfolioValue);

    // Print portfolio value for each day
    std::cout << "Portfolio Value over Time:" << std::endl;
    for (size_t day = 0; day < portfolioValue.size(); ++day) {
        std::cout << "Day " << day + 1 << ": " << portfolioValue[day] << std::endl;
    }

    return 0;
}


/*
Data

perf stat ./scp1

performance counter stats for './scp1':

              1.53 msec task-clock                       #    0.764 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               127      page-faults                      #   83.007 K/sec                     
         4,865,519      cycles                           #    3.180 GHz                       
         3,793,760      instructions                     #    0.78  insn per cycle            
           728,531      branches                         #  476.167 M/sec                     
            21,433      branch-misses                    #    2.94% of all branches  


*/

#endif

#if 0

#include <iostream>
#include <climits>

// Function to calculate absolute difference using conditional branches
inline int absoluteDifference(int a, int b) {
    if (a >= b) {
        return a - b;
    } else {
        return b - a;
    }
}

inline int aabsoluteDifference(int a, int b) {
    int diff = a - b;
    int mask = diff >> (sizeof(int) * CHAR_BIT - 1);
    return (diff ^ mask) - mask;
}

int main() {
    int x = 10;
    int y = 20;

    // Calculate and print absolute difference
    
    //std::cout << "Absolute Difference: " << absoluteDifference(x, y) << std::endl;
     std::cout << "Absolute Difference: " << aabsoluteDifference(x, y) << std::endl;

    return 0;
}


/*
low branches

real    0m0.009s
user    0m0.004s
sys     0m0.005s

Performance counter stats for './scp1':

              1.29 msec task-clock                       #    0.746 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               126      page-faults                      #   97.617 K/sec                     
         3,844,205      cycles                           #    2.978 GHz                       
         3,677,461      instructions                     #    0.96  insn per cycle            
           705,969      branches                         #  546.940 M/sec                     
            17,567      branch-misses                    #    2.49% of all branches  




    High branches

    bsolute Difference: 10

real    0m0.008s
user    0m0.002s
sys     0m0.006s

Performance counter stats for './scp1':

              1.94 msec task-clock                       #    0.755 CPUs utilized             
                 0      context-switches                 #    0.000 /sec                      
                 0      cpu-migrations                   #    0.000 /sec                      
               124      page-faults                      #   63.908 K/sec                     
         3,854,562      cycles                           #    1.987 GHz                       
         3,669,700      instructions                     #    0.95  insn per cycle            
           703,679      branches                         #  362.665 M/sec                     
            19,899      branch-misses                    #    2.83% of all branches           



*/

#endif

#if 0

#include <iostream>
#include <vector>

// Forward declarations
struct Component;
struct PositionComponent;
struct VelocityComponent;

// Entity class
struct Entity {
    std::vector<Component*> components;

    // Template function to check if entity has a specific component
    template<typename T>
    bool hasComponent() const {
        for (const auto& component : components) {
            if (dynamic_cast<T*>(component)) {
                return true;
            }
        }
        return false;
    }

    // Template function to get a specific component
    template<typename T>
    T& getComponent() const {
        for (auto* component : components) {
            if (auto* specificComponent = dynamic_cast<T*>(component)) {
                return *specificComponent;
            }
        }
        throw std::runtime_error("Component not found");
    }
};

// Component base class
struct Component {
    virtual void update() = 0;
    virtual ~Component() {} // Ensure destructor is virtual for proper cleanup
};

// PositionComponent class
struct PositionComponent : Component {
    float x, y;

    void update() override {
        // Update position logic
    }
};

// VelocityComponent class
struct VelocityComponent : Component {
    float vx, vy;

    void update() override {
        // Update velocity logic
    }
};

// MovementSystem class
class MovementSystem {
public:
    void update(Entity& entity) {
        if (entity.hasComponent<PositionComponent>() && entity.hasComponent<VelocityComponent>()) {
            auto& position = entity.getComponent<PositionComponent>();
            auto& velocity = entity.getComponent<VelocityComponent>();
            position.x += velocity.vx;
            position.y += velocity.vy;
        }
    }
};

int main() {
    // Create an entity with position and velocity components
    Entity entity;
    entity.components.push_back(new PositionComponent());
    entity.components.push_back(new VelocityComponent());

    // Create a movement system
    MovementSystem movementSystem;

    // Update the entity's position using the movement system
    movementSystem.update(entity);

    // Print the updated position
    std::cout << "Updated Position: (" << entity.getComponent<PositionComponent>().x << ", "
              << entity.getComponent<PositionComponent>().y << ")" << std::endl;

    // Clean up allocated components
    for (auto* component : entity.components) {
        delete component;
    }

    return 0;
}


#endif
/*
perf list | grep cache-misses



valgrind --tool=cachegrind <your_program>

cg_annotate cachegrind.out.<pid>


valgrind --tool=callgrind <your_program>
kcachegrind callgrind.out.<pid>


*/


#if 0


//normal matrix multiplication.

#include <iostream>
#include <vector>

using namespace std;

const int N = 512; // Example matrix size

void naiveMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Initialize matrices A, B, and C
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 2));
    vector<vector<int>> C(N, vector<int>(N, 0));

    // Perform naive matrix multiplication
    naiveMatrixMultiplication(A, B, C);

    // Output the result
    cout << "Result of naive matrix multiplication:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



#endif

#if 0

//cache friendly multiplication.

#include <iostream>
#include <vector>

using namespace std;

const int N = 512; // Example matrix size
const int BLOCK_SIZE = 32; // Example block size for tiling

void cacheFriendlyMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int ii = 0; ii < N; ii += BLOCK_SIZE) {
        for (int jj = 0; jj < N; jj += BLOCK_SIZE) {
            for (int kk = 0; kk < N; kk += BLOCK_SIZE) {
                for (int i = ii; i < min(ii + BLOCK_SIZE, N); ++i) {
                    for (int j = jj; j < min(jj + BLOCK_SIZE, N); ++j) {
                        for (int k = kk; k < min(kk + BLOCK_SIZE, N); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Initialize matrices A, B, and C
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 2));
    vector<vector<int>> C(N, vector<int>(N, 0));

    // Perform cache-friendly matrix multiplication
    cacheFriendlyMatrixMultiplication(A, B, C);

    // Output the result
    cout << "Result of cache-friendly matrix multiplication:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


#endif

#if 0

/*
Spatial locality refers to accessing data locations that are close to each other in memory.
 Arrays are a common data structure that benefits from spatial locality
  because their elements are stored contiguously in memory.

*/

//example of spatial locality
#include <iostream>
#include <vector>

void exampleSpatialLocality() {
    const int N = 1024;
    std::vector<int> array(N);

    // Initialize the array
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    int sum = 0;

    // Accessing elements sequentially (good spatial locality)
    for (int i = 0; i < N; ++i) {
        sum += array[i];
    }

    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    exampleSpatialLocality();
    return 0;
}


#endif

#if 0

/* 
Temporal locality refers to accessing the same memory locations repeatedly within a short period of time.
 This can keep frequently accessed data in the cache, reducing access times.

 */


#include <iostream>
#include <vector>

void exampleTemporalLocality() {
    const int N = 1024;
    std::vector<int> array(N);

    // Initialize the array
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    int sum = 0;

    // Accessing the same element multiple times (good temporal locality)
    for (int i = 0; i < N; ++i) {
        sum += array[0]; // Accessing array[0] repeatedly
    }

    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    exampleTemporalLocality();
    return 0;
}











#endif

#if 0

#include <iostream>
#include <vector>

class Resistor {
public:
    Resistor(double resistance) : resistance(resistance) {}

    double getResistance() const {
        return resistance;
    }

private:
    double resistance;
};

class Circuit {
public:
    Circuit(int numResistors) : resistors(numResistors) {
        // Initialize resistors with random resistances
        for (int i = 0; i < numResistors; ++i) {
            resistors[i] = Resistor(static_cast<double>(i + 1) * 10);
        }
    }

    void calculateTotalResistanceSpatial() {
        double totalResistance = 0;

        // Good spatial locality: iterating through the array sequentially
        for (int i = 0; i < resistors.size(); ++i) {
            totalResistance += resistors[i].getResistance();
        }

        std::cout << "Total Resistance (Spatial): " << totalResistance << " ohms" << std::endl;
    }

    void calculateSpecificResistanceTemporal() {
        double specificResistance = 0;
        const int index = 0; // Let's say we are interested in the first resistor

        // Good temporal locality: accessing the same resistor multiple times
        for (int i = 0; i < 1000; ++i) {
            specificResistance += resistors[index].getResistance();
        }

        std::cout << "Specific Resistance (Temporal): " << specificResistance << " ohms" << std::endl;
    }

private:
    std::vector<Resistor> resistors;
};

int main() {
    const int numResistors = 1024;

    Circuit circuit(numResistors);

    circuit.calculateTotalResistanceSpatial();
    circuit.calculateSpecificResistanceTemporal();

    return 0;
}


#endif