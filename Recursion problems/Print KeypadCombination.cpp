/*
	Given an integer n,
	using phone keypad find out and print all the possible strings that can be made using digits of input n.
	
	Input Format :  Integer n
	
	Output Format :  All possible strings in different lines
	
	Sample Input: 23
	Sample Output:
				ad
				ae
				af
				bd
				be
				bf
				cd
				ce
				cf

	
*/


#include<iostream>
using namespace std;

void printKey(int num, string output){
	
	// keys corresponding keypad
	
	string keys[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	
	// Base case : when num gets to 0 then print the number
	
	if(num==0){
		cout << output << endl;
		return;
	}	
	string temp = keys[num%10];
	
	for(int i=0; i<temp.size(); i++){
		printKey(num/10, temp[i]+output);
	}
	
}

/*A middle function that initiated with empty string*/

void printKeypadCombination(int n){
	string st = "";
	printKey(n, st);
}


int main(){
	int n;
	cin >> n;
	printKeypadCombination(n);
	
	return 0;
}
