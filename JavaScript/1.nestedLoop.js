const o1 = {
    o2: {
        name: "Sourav",
        contacts: {
            emails: ["sourav@example.com", "sourav.work@example.com"],
            phone: "123-456-7890"
        }
    }
};

Explanation:
//  Code is a recursive function that prints all the nested values inside a deeply nested object (o1).
//  It iterates over each key in the object and prints every non-object value (like strings or arrays).

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