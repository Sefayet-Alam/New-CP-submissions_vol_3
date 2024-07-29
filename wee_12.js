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

function gcd(a, b) {
    while (b !== 0) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

function main() {
    var ar = readline().split(' ').map(x => parseInt(x));
    var x=ar[0];
    var y=ar[1];
    var mult=1;
    for(var i=1;i<=y;i++){
        mult*=x;
    }
    
    print(mult,"\n")
}