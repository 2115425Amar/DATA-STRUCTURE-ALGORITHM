function sortObjectByKey(obj) {
    if (typeof obj !== 'object' || obj === null) {
        return obj;
    }

    if (Array.isArray(obj)) {
        return obj.map(sortObjectByKey);
    }

    const sortedKeys = Object.keys(obj).sort();
    // console.log(sortedKeys);
    const result = {};

    sortedKeys.forEach(key => {
        result[key] = sortObjectByKey(obj[key]);   //recursion
    });

    return result;
}

const o1 = {
    o2: {
        name: "Sourav",
        contacts: {
            emails: ["sourav@example.com", "sourav.work@example.com"],
            phone: "123-456-7890"
        }
    }
};

const sortedO1 = sortObjectByKey(o1);
console.log(sortedO1);