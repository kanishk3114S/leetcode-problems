/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    let dynamicArray = [];

    for (let i=1; i<=n; i++) {

        dynamicArray.push(i);

    }

    dynamicArray.sort();

    return dynamicArray;

};