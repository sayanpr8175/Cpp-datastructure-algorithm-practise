/*
	Staircase
	A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time.
	Implement a method to count how many possible ways the child can run up to the stairs.
	You need to return number of possible ways W.
	
	Sample Input 1 :  4
	Sample Output 1 : 7
	
	Sample Input 2 : 5
	Sample Output 1 : 13
*/


#include<iostream>
using namespace std;


int staircaseCalculate(int n){
	
	// Base cases
	
	if(n==1){return 1;}
	else if(n==2){return 2;}
	else if(n==0){return 1;}
	
	// induction 
	int x = staircaseCalculate(n-1);
	int y = staircaseCalculate(n-2);
	int z = staircaseCalculate(n-3);
	
	int xyz = (x+y+z);
	return xyz;
}


int main(){
	
	int n;
	cin >> n;
	cout << staircaseCalculate(n) << endl;
}
