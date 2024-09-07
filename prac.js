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
    return inputString[currentLine++];
}
// ************************ Code Start ***************************

function generatePermutations(str) {
    if (str.length === 0) return [''];
    
    let result = [];
    
    for (let i = 0; i < str.length; i++) {
        let char = str[i];
        let remainingChars = str.slice(0, i) + str.slice(i + 1);
        let remainingPerms = generatePermutations(remainingChars);
        
        for (let perm of remainingPerms) {
            result.push(char + perm);
        }
    }
    
    return result.sort();
}

function main() {
    var s = readline();
    var ans = generatePermutations(s);
    ans.sort();
    console.log(ans.join(' '));
}