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
    var n = parseInt(readline());
    let dp = new Array(n + 1).fill(0);
    for (let i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        
        if (i % 2 === 0) {
            dp[i] = Math.min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 === 0) {
            dp[i] = Math.min(dp[i], dp[i / 3] + 1);
        }
    }
    print(dp[n],"\n")
}