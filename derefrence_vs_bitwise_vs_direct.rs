use std::time::Instant;
use std::process::exit;

const N: usize = 1_000_000; // Number of characters in the large string

// Function to perform dereferencing for 2 bytes (with proper alignment handling)
fn dereference_comparison_2bytes(str: &[u8]) -> usize {
    let mut count = 0;
    let str_len = str.len();

    for i in 1..str_len {
        // SAFETY: We need to ensure the pointer is aligned for u16 dereferencing
        let ptr = unsafe { str.as_ptr().add(i - 1) }; // Unsafe: Pointer arithmetic requires unsafe block
        if (ptr as usize) % 2 == 0 {
            // Pointer is aligned correctly (multiple of 2 for u16)
            let der = unsafe { *(ptr as *const u16) }; // Unsafe: Dereferencing the pointer
            if der == 0x6867 { // 0x6867 = 'gh' in little-endian
                count += 1;
            }
        }
    }
    count
}

// Function to perform uint16_t construction using bitwise shifting for 2 bytes
fn uint16_t_construction_2bytes(str: &[u8]) -> usize {
    let mut count = 0;
    for i in 0..str.len() - 1 {
        // Construct uint16_t from two consecutive characters using bit shifting
        let con = (str[i] as u16) << 8 | (str[i + 1] as u16);

        if con == 0x6768 { // Compare to 'gh'
            count += 1;
        }
    }
    count
}

// Function to perform direct 2-byte comparison (character-by-character)
fn direct_2byte_comparison(str: &[u8]) -> usize {
    let mut count = 0;
    for i in 0..str.len() - 1 {
        if str[i] == b'g' && str[i + 1] == b'h' {
            count += 1;
        }
    }
    count
}

fn main() {
    // Create a large string of 'a' to 'z' repeating
    let mut str = Vec::with_capacity(N);
    for i in 0..N - 1 {
        str.push(b'a' + (i % 26) as u8); // Fill with repeating alphabet characters
    }
    str.push(b'\0'); // Null-terminate the string (though not necessary in Rust)

    // Perform comparisons and measure execution time
    let start = Instant::now();
    let count = dereference_comparison_2bytes(&str);
    println!("Dereference Comparison: Found {} occurrences of 'gh'.", count);
    println!("Dereference Comparison took: {:?}", start.elapsed());

    let start = Instant::now();
    let count = uint16_t_construction_2bytes(&str);
    println!("Bitwise Comparison: Found {} occurrences of 'gh'.", count);
    println!("Bitwise Comparison took: {:?}", start.elapsed());

    let start = Instant::now();
    let count = direct_2byte_comparison(&str);
    println!("Direct Comparison: Found {} occurrences of 'gh'.", count);
    println!("Direct Comparison took: {:?}", start.elapsed());
}
