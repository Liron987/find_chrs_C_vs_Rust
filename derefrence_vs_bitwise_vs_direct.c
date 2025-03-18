#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define N 1000000  // Number of characters in the large string (for benchmarking)


// Function to perform dereferencing for 2 bytes (using pointer dereference)
void dereference_comparison_2bytes(char *str, size_t len) {
    int count = 0;
    for (size_t i = 1; i < len; i++) {
        // Cast the pointer to uint16_t* to interpret 2 consecutive bytes as 16-bit value
        uint16_t der = *(uint16_t*)&str[i - 1];  // Points to a pair of consecutive chars

        if (der == 0x6867) {  // Compare to 'gh' (0x67 = 'g', 0x68 = 'h')
            count++;
        }
    }
    printf("Dereference Comparison: Found %d occurrences of 'gh'.\n", count);
}

// Function to perform uint16_t construction using bitwise shifting for 2 bytes
void uint16_t_construction_2bytes(char *str, size_t len) {
    int count = 0;
    for (size_t i = 0; i < len - 1; i++) {
        // Construct uint16_t from two consecutive characters using bit shifting
        uint16_t con = (uint16_t)str[i] << 8 | (uint16_t)str[i + 1];
        if (con == 0x6768) {  // Compare to 'gh'
            count++;
        }
    }
    printf("Bitwise Comparison: Found %d occurrences of 'gh'.\n", count);
}

// Function to perform direct 2-byte comparison (character-by-character)
void direct_2byte_comparison(char *str, size_t len) {
    int count = 0;
    for (size_t i = 0; i < len - 1; i++) {
        if (str[i] == 'g' && str[i + 1] == 'h') {
            count++;
        }
    }
    printf("Direct Comparison: Found %d occurrences of 'gh'.\n", count);
}

// Helper function to benchmark the three methods
void perform_comparisons(char *str, size_t len) {
    clock_t start, end;

    // Dereference Comparison
    start = clock();
    dereference_comparison_2bytes(str, len);
    end = clock();
    printf("Dereference Comparison took: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Bitwise Comparison
    start = clock();
    uint16_t_construction_2bytes(str, len);
    end = clock();
    printf("Bitwise Comparison took: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Direct Comparison
    start = clock();
    direct_2byte_comparison(str, len);
    end = clock();
    printf("Direct Comparison took: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    // Create a large string of 'a' to 'z' repeating
    char str[N];
    for (int i = 0; i < N - 1; i++) {
        str[i] = 'a' + (i % 26);  // Fill with repeating alphabet characters
    }
    str[N - 1] = '\0';  // Null-terminate the string

    // Perform comparisons and measure execution time
    perform_comparisons(str, N);

    return 0;
}
