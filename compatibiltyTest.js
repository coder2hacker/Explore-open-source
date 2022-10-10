//author'name  : Priyanshi Rai
//Modification date : 5-10-2022


/* LOGIC BEHIND THE PROGRAM:-
This is a simple program of generating a random number using javascript.
I have modified it in such a way that the number is generated between 1-100 and moulding it into a compatitbilty test program.
1.) Firstly it will ask for 1st name and then the 2nd name .
2.) It will generate a random number and display it as a percentage of comaptibility in the output.
For the simplicity purpose , you don't need to have a editor to run this code . Just copy it -> paste it in the console window -> ctrl + enter -> you will get the output.
*/


prompt("Enter 1st name :- ");
prompt("Enter 2nd name :- ");
function compatabilityTest(){
    var num=Math.random();
    num=Math.floor(num*100);
    return alert("Compatibility between you guys is :- " +num + '%');
}
compatabilityTest();
