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
- Dereference Comparison took: 357.317µs
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 1.531081ms
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 378.094µs

### Summary with Percentage Difference (-O3):
| Comparison Type         | C Time (Seconds) | Rust Time (Seconds) | Percentage Difference (C vs Rust) |
|-------------------------|------------------|---------------------|----------------------------------|
| Dereference Comparison  | 0.000519         | 0.000357317         | -31.2%                           |
| Bitwise Comparison      | 0.000153         | 0.001531081         | 899.2%                           |
| Direct Comparison       | 0.000363         | 0.000378094         | 4.2%                             |


