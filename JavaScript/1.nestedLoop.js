// 3. Using for…in and for…of Loops for Iteration
const o = {
    a: [
        { name: "Sourav", age: 22 },
        { name: "Rohit", age: 30 }
    ]
};

for (let a of o.a) {
    console.log(a.name, a.age);
}
// Sourav 22
// Rohit 30




const o1 = {
    o2: {
        name: "Sourav",
        contacts: {
            emails: ["sourav@example.com", "sourav.work@example.com"],
            phone: "123-456-7890"
        }
    }
};


// 1 method.
console.log(o1.o2.contacts.emails);  // [ 'sourav@example.com', 'sourav.work@example.com' ]


function printNested(obj) {
    if (typeof obj === 'object') {
        for (let key in obj) {
            printNested(obj[key]);    //recursion
        }
    } else {
        console.log(obj);
    }
}
printNested(o1);

// Explanation:
//  Code is a recursive function that prints all the nested values inside a deeply nested object (o1).
//  It iterates over each key in the object and prints every non-object value (like strings or arrays).



// Dry Run Step-by-Step

// printNested(o1);
// typeof o1 === 'object' → true
// for (let key in o1) → key = "o2"

// Step into printNested(o1.o2)
// typeof o1.o2 === 'object' → true
// key = "name" → printNested("Sourav") → prints "Sourav"

// Next key: "contacts"

// Step into printNested(o1.o2.contacts)
// typeof === 'object' → true
// key = "emails" → printNested(["sourav@example.com", "sourav.work@example.com"])

// Now inside the emails array
// It's an array, but in JS, typeof array === "object" → still true
// Loop over 0 and 1 indices


// printNested("sourav@example.com") → prints
// printNested("sourav.work@example.com") → prints
// Next key in contacts: "phone" → printNested("123-456-7890") → prints

// ✅ Final Console Output

// Sourav
// sourav@example.com
// sourav.work@example.com
// 123-456-7890
// 🧠 What's Happening?
// Your function:

// Recursively drills down every key in the object

// If it encounters a primitive (string/number) → prints it

// If it's an object/array, it goes deeper

// 📌 Want to Improve?
// If you want to track keys or nesting, you can modify the function like:


function printNested(obj, prefix = '') {
    if (typeof obj === 'object' && obj !== null) {
        for (let key in obj) {
            printNested(obj[key], `${prefix}${key}.`);
        }
    } else {
        console.log(prefix.slice(0, -1), ":", obj);
    }
}
// This will print key paths like:

// o2.name : Sourav
// o2.contacts.emails.0 : sourav@example.com
// o2.contacts.emails.1 : sourav.work@example.com
// o2.contacts.phone : 123-456-7890


// --------------------------------------------------------------


// Sort Object by Keys (Recursively)

// Object.keys(obj).sort() ensures keys are visited in alphabetical order.
function printNestedSorted(obj, prefix = '') {
    if (typeof obj === 'object' && obj !== null) {
        const sortedKeys = Object.keys(obj).sort();  // Sort keys alphabetically
        for (let key of sortedKeys) {
            printNestedSorted(obj[key], `${prefix}${key}.`);
        }
    } else {
        console.log(prefix.slice(0, -1), ":", obj);  // Remove trailing "."
    }
}

// o2.contacts.emails.0 : sourav@example.com
// o2.contacts.emails.1 : sourav.work@example.com
// o2.contacts.phone : 123-456-7890
// o2.name : Sourav



// -------------------------------------------------------


// Sort Object by Key Length (Recursively)

function printNestedSortedByKeyLength(obj, prefix = '') {
    if (typeof obj === 'object' && obj !== null) {
        const sortedKeys = Object.keys(obj).sort((a, b) => a.length - b.length);
        for (let key of sortedKeys) {
            printNestedSortedByKeyLength(obj[key], `${prefix}${key}.`);
        }
    } else {
        console.log(prefix.slice(0, -1), ":", obj);
    }
}

// o2.name : Sourav
// o2.contacts.phone : 123-456-7890
// o2.contacts.emails.0 : sourav@example.com
// o2.contacts.emails.1 : sourav.work@example.com