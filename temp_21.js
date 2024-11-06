"use strict";
process.stdin.resume();
process.stdin.setEncoding("utf-8");

function print(x) {
    console.log(x);
}
let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});
process.stdin.on("end", () => {
    inputString = inputString.split("\n");
    main();
});
function readline() {
    return inputString[currentLine++].trim();
}

// ************************ Code Start ***************************

function swapValues(num1, num2) {
    [num1, num2] = [num2, num1];
    return [num1, num2];
}

function main() {

    let input = readline().split(" ").map(Number);
    let num1 = input[0];
    let num2 = input[1];

    print(`Before swapping: num1 = ${num1}, num2 = ${num2}`);
    let [newNum1, newNum2] = swapValues(num1, num2);

    print(`After swapping: num1 = ${newNum1}, num2 = ${newNum2}`);
}
