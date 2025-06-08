const person = {
    firstName: "John",
    lastName: "Doe",
    age: 50,
    eyeColor: "blue"
  };
  
  // Get the Keys
  const keys = Object.keys(person).sort();    //[ 'firstName', 'lastName', 'age', 'eyeColor' ]

  console.log(keys);

  console.log(person);