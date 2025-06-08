// let number  = [4, 5, 6, 7, 8, 9, 10];

// // let items = number.map(function(item){
// //     return item +" is a number";
// // });

// // console.log(items); 

// let filteredItems = number.filter(function(item){
//     return item >= 8;
// })

// console.log(filteredItems);

let number  = [4, 5, 6, 7, 8, 9, 10];

// let filteredItems = number.filter(function(item){
//     return item >= 8;
// })
// console.log(filteredItems);


// let totalSum = number.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
// console.log(totalSum);


let a = "helloWorld";
let b = a.split("").reverse().join("");
console.log(b)



//reduce function

let numbers = [1, 2, 3, 4, 5];
let sum = numbers.reduce(function(accumulator, currentValue) {
    return accumulator + currentValue;
}, 0);
console.log(sum); // Output: 15


