// Input:
// A = "babad"
// Expected Output: "bab" or "aba"

// Input:
// A = "racecar"
// Expected Output: "racecar"


// Input:
// A = "forgeeksskeegfor"
// Expected Output: "geeksskeeg"

function longPal(A) {
    let ans = "";
    // Iterate over all substrings
    for (let i = 0; i < A.length; i++) {
        for (let j = i; j < A.length; j++) {
            let substr = A.substring(i, j + 1);
            // Check if substring is palindrome and longer than current answer
            if (substr === substr.split('').reverse().join('') && substr.length > ans.length) {
                ans = substr;
            }
        }
    }
    return ans;
}

// Example usage:
console.log(longPal("babad")); // "bab" or "aba"
console.log(longPal("racecar")); // "racecar"
console.log(longPal("forgeeksskeegfor")); // "geeksskeeg"