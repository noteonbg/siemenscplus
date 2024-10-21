#if 0

#include <iostream>
#include <array>
#include <cstddef>
#include <immintrin.h> // For SIMD intrinsics
#include <vector>

// Constants
constexpr size_t NUM_CHANNELS = 4; // Number of audio channels
constexpr size_t SAMPLES_PER_CHANNEL = 16; // Samples per channel

// Define an aligned struct for audio samples
struct alignas(64) AlignedAudioBuffer {
    std::array<float, SAMPLES_PER_CHANNEL> samples; // Aligned buffer for audio samples
};

// Function to mix audio channels
void mixAudio(const std::array<AlignedAudioBuffer, NUM_CHANNELS>& buffers, AlignedAudioBuffer& output) {
    // Initialize output samples to zero
    for (auto& sample : output.samples) {
        sample = 0.0f;
    }

    // Mix channels using SIMD
    for (size_t i = 0; i < SAMPLES_PER_CHANNEL; i += 8) { // Process 8 samples at a time
        __m256 mixed = _mm256_setzero_ps(); // Initialize mixed value to zero
        for (size_t channel = 0; channel < NUM_CHANNELS; ++channel) {
            __m256 channelSamples = _mm256_load_ps(&buffers[channel].samples[i]);
            mixed = _mm256_add_ps(mixed, channelSamples); // Add channel samples
        }
        _mm256_store_ps(&output.samples[i], mixed); // Store mixed result back
    }
}

// Function to apply a gain to the audio samples
void applyGain(AlignedAudioBuffer& buffer, float gain) {
    __m256 gainVector = _mm256_set1_ps(gain); // Create a SIMD vector for gain
    for (size_t i = 0; i < SAMPLES_PER_CHANNEL; i += 8) {
        __m256 samples = _mm256_load_ps(&buffer.samples[i]);
        __m256 processed = _mm256_mul_ps(samples, gainVector); // Apply gain
        _mm256_store_ps(&buffer.samples[i], processed); // Store back to buffer
    }
}

int main() {
    // Create buffers for audio channels
    std::array<AlignedAudioBuffer, NUM_CHANNELS> audioBuffers;

    // Initialize the audio buffers with sample values
    for (size_t channel = 0; channel < NUM_CHANNELS; ++channel) {
        for (size_t i = 0; i < SAMPLES_PER_CHANNEL; ++i) {
            audioBuffers[channel].samples[i] = static_cast<float>(channel + 1) * (i + 1); // Channel 1: 1, 2, 3..., Channel 2: 2, 4, 6...
        }
    }

    // Display original samples
    std::cout << "Original audio samples:" << std::endl;
    for (size_t channel = 0; channel < NUM_CHANNELS; ++channel) {
        std::cout << "Channel " << channel + 1 << ": ";
        for (const auto& sample : audioBuffers[channel].samples) {
            std::cout << sample << " ";
        }
        std::cout << std::endl;
    }

    // Mix audio channels
    AlignedAudioBuffer mixedBuffer;
    mixAudio(audioBuffers, mixedBuffer);

    // Apply gain to the mixed output
    applyGain(mixedBuffer, 0.5f); // Reduce volume by half

    // Display processed (mixed and gain applied) samples
    std::cout << "\nProcessed (Mixed and Gain Applied) samples:" << std::endl;
    for (const auto& sample : mixedBuffer.samples) {
        std::cout << sample << " ";
    }
    std::cout << std::endl;

    return 0;
}


#endif

/*

The alignas specifier in C++ is used to control the alignment of variables or user-defined types. 
typical uses are

1. Memory Alignment Control
Performance Optimization:
 Certain architectures perform better with data that is aligned
  to specific byte boundaries (e.g., 4, 8, or 16 bytes).
   Using alignas, you can ensure that your data structures are aligned to
    these boundaries, which can lead to improved access speed.


2. Preventing Unintended Padding
Custom Data Structures: When defining complex data structures 
(like structs or classes), you may want to avoid the default 
padding that compilers might introduce. Using alignas allows you
 to specify a particular alignment, ensuring the layout of your structure is as expected.


3. Compatibility with SIMD Instructions
Vectorization: Some SIMD (Single Instruction, Multiple Data) operations require data
 to be aligned to specific boundaries. By using alignas, you can ensure that
  your data meets these requirements, enabling effective use of vectorized instructions.

4. Interfacing with Hardware or APIs
Hardware Requirements: When working with certain hardware interfaces, APIs,
 or low-level code (e.g., graphics programming), you may need to ensure that
  data  structures have specific alignments to comply with those requirements.

5. Improving Cache Efficiency
Cache Line Alignment: Aligning data structures to cache line boundaries can reduce cache
 misses and improve performance. By ensuring that data structures are aligned,
  you can optimize how the CPU accesses memory.


*/

#if 0

#include <iostream>

struct MyStruct {
    int a;
    double b;
};

int main() {
    std::cout << "Alignment of int: " << alignof(int) << " bytes" << std::endl;
    std::cout << "Alignment of double: " << alignof(double) << " bytes" << std::endl;
    std::cout << "Alignment of MyStruct: " << alignof(MyStruct) << " bytes" << std::endl;

    return 0;
}



#endif