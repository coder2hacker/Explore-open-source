// aaabb -> ababa

#include<iostream>
#include<queue>
using namespace std;
int main(){
	string s="aaabbb";
	priority_queue<pair<int,char>> maxHeap;
	int freq[26]={}; // empty array with 0 values
	for(int i=0; i<s.size(); i++){
		freq[s[i]-'a']++;
	}
 	for(int i=0 ;i<26 ;i++){
 		if(freq[i]>0){
 			maxHeap.push({freq[i],i+'a'}); //make pair of {freq, character} 
 		}
 	}
 	

 	string out="";
 	while(!maxHeap.empty()){
 		if(maxHeap.size()==1){
			pair<int,char>p_max=maxHeap.top(); maxHeap.pop();
			if(p_max.first>1){
				cout<< "";
				break;
			}else{
				out+=p_max.second;
				cout<<out;
				break;
			}
 		}else{
 			pair<int,char>p_max1;
 			p_max1=maxHeap.top();
 			maxHeap.pop();
 			out+=p_max1.second;
 			p_max1.first--;
 			// i cant chooose the same element so ill pop another element 
 			// and add it to output string
 			pair<int,char>p_max2;
 			p_max2=maxHeap.top();
 			maxHeap.pop();
 			out+=p_max2.second;
 			p_max2.first--;
 			// now if the frequecy left the we push
 			if(p_max1.first > 0)maxHeap.push(p_max1);
 			if(p_max2.first > 0)maxHeap.push(p_max2);
  		}	
 	}
	return 0;
}