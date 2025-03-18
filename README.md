# find_chrs_C_vs_Rust

## Results
### C (-O0):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 0.001861 seconds
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 0.002066 seconds
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 0.001782 seconds

### C (-O3):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 0.000519 seconds
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 0.000153 seconds
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 0.000363 seconds

### Rust (-O0):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 15.570645ms
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 16.004473ms
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 14.369994ms

### Rust (-O3):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 15.370962ms
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 15.837152ms
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 14.465161ms

### Summary with Percentage Difference:
| Comparison Type         | C Time (Seconds) | Rust Time (Seconds) | Percentage Difference (C vs Rust) |
|-------------------------|------------------|---------------------|----------------------------------|
| Dereference Comparison  | 0.000519         | 0.015370962         | 2905.57%                         |
| Bitwise Comparison      | 0.000153         | 0.015837152         | 10362.12%                        |
| Direct Comparison       | 0.000363         | 0.014465161         | 3885.71%                         |


