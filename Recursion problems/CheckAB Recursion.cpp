/*
	Check AB 
	
	Suppose you have a string, S, made up of only 'a's and 'b's.
	Write a recursive function that checks if the string was generated using the following rules:
	
	a. The string begins with an 'a'
	b. Each 'a' is followed by nothing or an 'a' or "bb"
	c. Each "bb" is followed by nothing or an 'a'
	
	Test case: 1
	input: abb
	output: true
	
	input: abababa
	output: false
	
*/

#include<iostream>
using namespace std;

/* Find the length of an character array */

int lenf(char input[]){
	int count = 0;
	for(int i=0; input[i]!='\0'; i++){
		count++;
	}
	return count;
}

/* checkAB */

bool checkAB(char input[]){
	
	// Base case 
	
	if(lenf(input)<1){
		return true;
	}
	
	if(input[0]=='b'){
		return false;
	}
	
	bool k;
	if(input[0]=='a' && input[1]=='\0'){
		return true;
	}
	
	else if(input[0]=='a' && input[1]=='a'){
		k = checkAB(input+2);
		if(k==false){
			k = checkAB(input+1);
		}
	}
	
	else if(input[1]=='b' && input[2]=='b'){
		k = checkAB(input+3);
	}
	else{
		k = false;}
	
	return k;
}


int main(){
	char input[100];
	cin >> input ;
	
	bool output = checkAB(input);
	if(output){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
}



