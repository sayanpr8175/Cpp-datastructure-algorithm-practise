/* 
	Print Subsequences of a string:
	Input:	"abc"
	
	Output: "a"
			"b"
			"c"    [order does not matter]
			"ab"
			"bc"
			"ac"
			"abc"
*/
#include<iostream>
#include<cstring>
using namespace std;

int subsequence(string input, string output[]){
	// base case
	if(input.size()==0){
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);   
	int smallen = subsequence(smallString, output); /* giving arg as 2nd place of input string. Smallen = output size */
	for(int i=0; i<smallen; i++){
		output[i+smallen] = input[0]+output[i];    // attaching 1st char of input string with output
	}
	
	return 2*smallen;
	
}

int main(){
	string input;
	cin >> input;
	string * output = new string[1000];
	int count = subsequence(input, output);
	for(int i=0; i<count; i++){
		cout << output[i] << endl;
	}	
}
