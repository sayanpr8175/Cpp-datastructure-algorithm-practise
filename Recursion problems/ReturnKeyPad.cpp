/*
	Given an integer n, using phone keypad find out all the possible strings,
	that can be made using digits of input n.
	Return empty string for numbers 0 and 1.
	
	Input Format : Integer n
	Output Format : All possible strings in different lines.
	
	Sample Input:	23
	Sample Output:	ad
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

int returnKeypad(int n, string output[]){
	
	string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	if(n==0){
		output[0] = "";
		return 1;}
	
	string smallOutputAr[1000];
	int smallOutputSize = returnKeypad(n/10, smallOutputAr);
	
	int val = n%10;
	int stringSize = map[val].size();
	string ch = map[val];
	
	int k = 0;
	
	for(int i=0; i<stringSize; i++){
		for(int j=0; j<smallOutputSize; j++){
			output[k++] = smallOutputAr[j]+ch[i];
		}
	}
	return stringSize*smallOutputSize;
}



int main(){
	int n;
	cin >> n;
	
	string * output = new string[1000];
	int num = returnKeypad(n, output);
	
	for(int i=0; i<num; i++){
		cout << output[i] << endl;
	}

}
