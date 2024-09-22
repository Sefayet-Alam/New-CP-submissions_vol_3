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
    var s=readline();
    let z=0;
    for(let i=0;s[i]==0;i++){
        if(s[i]=='0') z++;
    }
    let a=parseFloat(s);
    var pref="";
    for(let i=0;i<z;i++) pref+='0'; 
    print(pref+a+'\n');
}