/*
	print subsequences of a string
	
	input : "abc"
	output : "a"
			 "b"
			 "c"
			 "ab"
			 "ac"
			 "abc"
*/

#include<iostream>
#include<string>
using namespace std;

int subs(string input, string output[]){
		if(input.empty()){
			output[0] = "";
			return 1;
		}
	
	
	int smallOutputSize = subs(input.substr(1), output);
	for(int i=0; i<smallOutputSize; i++){
		output[i+smallOutputSize] = input[0]+output[i];
	}
	return 2*smallOutputSize;
	
}
int main(){
	
	string input;
	cin >> input;
	string * output = new string[1000];
	
	int count = subs(input, output);
	for(int i=0; i<count; i++){
		cout << output[i] << endl;
	}
		
}


