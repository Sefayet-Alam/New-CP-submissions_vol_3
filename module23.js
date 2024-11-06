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
    var ar = readline().split(' ').map(x => parseFloat(x));
    var f=ar[0];
    var n=ar[1];
    var m=ar[2];
    var sum=f*n>m;
    print(sum,"\n");
}