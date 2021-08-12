// Build using:
// clang++ -o sse -arch x86_64 -msse4.2 --std=c++17 sse.cpp

#include <iostream>
#include <iomanip>

// SSE 4.2
#include <nmmintrin.h>

alignas(128) const float data[16] =
{
    -0.1892006f,
    -0.0921285f,
    0.0704854f,
    0.281443f,
    0.5124368f,
    0.7289534f,
    0.8966951f,
    0.9881902f,
    0.9881902f,
    0.8966951f,
    0.7289534f,
    0.5124368f,
    0.281443f,
    0.0704854f,
    -0.0921285f,
    -0.1892006f
};

int main(const int argc, const char** argv)
{
    std::cout << "Hello!" << std::endl;

    // Immediates
    const __m128 A = {0.1f, 0.2f, 0.3f, 0.4f};
    const __m128 B = {0.4f, 0.4f, 0.4f, 0.5f};

    __m128 X = _mm_setzero_ps();

    for(auto i=0; i<100; i++)
    {
        // Load aligned data
        const __m128 C = _mm_load_ps(&data[0]);

        // Load unaligned data
        const __m128 D = _mm_loadu_ps(&data[1]);

        X = _mm_add_ps(X, _mm_mul_ps(A, C));
        X = _mm_sub_ps(X, D);
    }

    alignas(128) float out[4];
    alignas(128) float sum[4];

    // Store
    _mm_store_ps(&out[0], X);

    // Horizontal sum
    __m128 X2 = _mm_hadd_ps(X,X);
    __m128 X4 = _mm_hadd_ps(X2,X2);

    // Store
    _mm_store_ps(&sum[0], X4);

    std::cout << "{" << out[0]<< ", " << out[1] << ", " << out[2] << ", " << out[3] << "}" << std::endl;
    std::cout << "Sum: " << sum[0] << std::endl;

    return 0;
}