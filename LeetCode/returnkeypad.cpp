#include <iostream>
using namespace std;
#include <string>

string phone[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

int keypad(string p,string output[]){
    if(p.empty()){
        output[0]=""; 
        return 1;
    } 
    int n=p[0]-'0'; 
    string rof=phone[n];  
    int sizerof=rof.length();

    int z=keypad(p.substr(1),output); 

    string temp[z*sizerof]; 
     int k=0; 

     for(int i=0; i<sizerof; i++){
         for(int j=0; j<z; j++){
             temp[k]=rof[i]+output[j]; 
             k++;
         } 
     }

    for(int i=0; i<z*sizerof; i++){
        output[i]=temp[i];
    }
    return sizerof*z;
}
int main(){
    string  p="23";
   // cin >> p;
    string* output=new string[100];
    int z=keypad(p,output); 
    for(int i=0; i<z; i++) {
        cout << output[i] << endl;
    }
    return 0; 
}