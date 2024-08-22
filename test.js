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

function main() {
    let s=readline();
    let p=readline();
    let vis1 = new Map();
    let vis2 = new Map();
    let f = false;

    for (let it of s) {
        vis1.set(it, (vis1.get(it) || 0) + 1);
    }
    
    for (let it of p) {
        vis2.set(it, (vis2.get(it) || 0) + 1);
    }

    for (let [key, value] of vis1) {
        if (value !== vis2.get(key)) {
            f = true;
            break;
        }
    }
    if (!f) {
        for (let [key, value] of vis2) {
            if (value !== vis1.get(key)) {
                f = true;
                break;
            }
        }
    }
    if (f) {
        print("NO\n");
    } else {
        print("YES\n");
    }
}