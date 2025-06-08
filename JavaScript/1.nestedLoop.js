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
