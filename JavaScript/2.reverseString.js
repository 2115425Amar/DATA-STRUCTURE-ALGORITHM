const s = "Hello world";

// -------------------------------------------------------
// Method 1: Using nested loops
const w = s.split(" "); // array bana diya
console.log(w);         // [ 'Hello', 'world' ]
// ---------------------------------------------------------

const wordss = s.split(" ");
let reverse = [];
for (let i = 0; i < wordss.length; i++) {
    let temp = "";
    for (let j = wordss[i].length - 1; j >= 0; j--) {
        temp += wordss[i][j];
    }
    reverse.push(temp);
}
console.log(reverse);                  // [ 'olleH', 'dlrow' ]
console.log(reverse.join(' '));        // olleH dlrow


// -----------------------------------------------------------------
// Method 2: Using map() and split().reverse().join()
const rev = s.split(" ").map(word => word.split("").reverse().join(""));
console.log(rev.join(' '));              // olleH dlrow


// ----------------------------------------------------------------------
// Method 3: Using for...of loop
const words = s.split(" ");
let rev2 = [];
for (const word of words) {
    rev2.push(word.split("").reverse().join(""));
}
console.log(rev2.join(" "));
