#include <iostream>
#include <string>
using namespace std;
void cc(string s,char a,char b){
    if(s.length()==0){
        return;
    }
    if (s[0]==a) {
        s[0]=b;
        cc(s.substr(1),a,b);
    }
    cc(s.substr(1),a,b);;
}
int main(){
    string s="asdfgh";
    char a='a',b='z';
 /*   cin >> s;
    cin >> a >> b;
*/
    cc(s,a,b); 
    cout<<s;

}