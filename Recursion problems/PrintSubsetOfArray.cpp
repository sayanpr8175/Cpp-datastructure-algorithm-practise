/*
	 Print Subsets of Array 
	 Given an integer array (of length n), find and print all the subsets of input array.
	 
	 Subsets are of length varying from 0 to n, that contain elements of the array.
	 But the order of elements should remain same as in the input array.
	 Note : The order of subsets are not important. Just print the subsets in different lines.
	
	Sample Input:
				3
				15 20 12
	
	Sample Output:
				12 
				20 
				20 12 
				15 
				15 12 
				15 20 
				15 20 12 
	
*/

#include<iostream>
using namespace std;
void PrintHelper(int input[], int length, int output[], int outsize){
	if(length==0){
		for(int i=0; i<outsize; i++){
			cout << output[i] << " ";
		}cout << endl;
		return;
	}
	
	int newOutput[1000];
	for(int i=0; i<outsize; i++){
		newOutput[i] = output[i];
	}
	newOutput[outsize] = input[0];
	
	PrintHelper(input+1, length-1, newOutput, outsize+1);
	
	PrintHelper(input+1, length-1, newOutput, outsize);

}

void PrintSubsetOfArray(int input[], int length){
	int output[3000], start = 0;
	PrintHelper(input, length, output, start);
}


int main(){
	int input[1000], length;
	cin >> length;
	for(int i=0; i<length; i++){
		cin >> input[i];
	}
	
	PrintSubsetOfArray(input, length);
	
}
