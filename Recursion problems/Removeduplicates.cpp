
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


// Alternate solution to avoid loops while shifting 
void removeDuplicate(char *input, int newIndex, int index){
	if(input[index]=='\0'){
		input[newIndex] = input[index-1];
		input[newIndex+1] = '\0';
		return;
	}
	if(input[index] == input[index-1]){
		removeDuplicate(input, newIndex, index+1);
		return;
	}
	else{
		input[newIndex] = input[index - 1];
	}
	removeDuplicate(input, newIndex+1, index+1);
}

void removeConsDup2(char input[]){
	removeDuplicate(input, 0, 1);
}
/// alternate solution above

int main(){
	
	cout << "Enter the string (max limit - 100)" << endl;	
	char str[100];
	cin >> str;
	
	//uncomment line 77  and comment line 79 to use alternate function without loop
	// removeConsDup2(str);
	
	removeConsDup(str);
	
	cout << str << endl;	
}


