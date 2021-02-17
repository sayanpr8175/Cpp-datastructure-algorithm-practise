
/*
	** Remove Duplicates Recursively ** 
	Given a string S, remove consecutive duplicates from it recursively.
	
	Sample Input 1 : 	aabccba
	Sample Output 1 :   abcba
	    
	Sample Input 2 :    xxxyyyzwwzzz
	Sample Output 2 :   xyzwz
		
*/

#include<iostream>
using namespace std;


// returns length of a string
int length(char str[]){
	int count = 0;
	for(int i=0; str[i]!='\0'; i++){
		count++;
	}
	return count;
}

// removes consecutive duplicates element
void removeConsDup(char strng[]){
	
	// Base case
	if(strng[0]=='\0'){
		return;
	}
	
	// Induction / assume recursion has done the work
	removeConsDup(strng+1);
	
	// small calculation
	if(strng[0]==strng[1]){
		for(int i=1; i<=length(strng); i++){
			strng[i] = strng[i+1];
		}
	}
}

int main(){
	
	cout << "Enter the string (max limit - 100)" << endl;	
	char str[100];
	cin >> str;
	
	removeConsDup(str);
	
	cout << str << endl;
	
}


