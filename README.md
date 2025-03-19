# find_chrs_C_vs_Rust

## Results
### C (-O0):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 0.001861 seconds
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 0.002066 seconds
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 0.001782 seconds

### C (-O3, GCC):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 0.000519 seconds
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 0.000153 seconds
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 0.000363 seconds

### C (-O3, LLVM):
- Dereference Comparison: Found 38462 occurrences of 'gh'.
- Dereference Comparison took: 0.000252 seconds
- Bitwise Comparison: Found 38462 occurrences of 'gh'.
- Bitwise Comparison took: 0.000388 seconds
- Direct Comparison: Found 38462 occurrences of 'gh'.
- Direct Comparison took: 0.000223 seconds


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
| Dereference Comparison  | 0.000252         | 0.000357317         | 41.8%                            |
| Bitwise Comparison      | 0.000388         | 0.001531081         | 294.3%                           |
| Direct Comparison       | 0.000223         | 0.000378094         | 69.5%                            |



