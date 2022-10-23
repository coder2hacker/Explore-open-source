class Solution {
public:
    int maxVowels(string s, int k) {
       int c=0;
        int mxvowel=0;
        for(int i=0;i<k;++i){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
                c++;
            }
        }
        mxvowel=c;
        for(int j=k;j<s.size();++j){
            if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u' ){
                c++;
            }
            if(s[j-k]=='a' ||s[j-k]=='e' ||s[j-k]=='i' ||s[j-k]=='o' ||s[j-k]=='u' ){
                c--;
            }
            if(c>mxvowel){
                mxvowel=c;
            }
        }
        return mxvowel;
    }      
};