#include<iostream>
using namespace std;
#include "Student.cpp"

int main(){
	
	// Create object statically
	
	Student s1;
	Student s2, s3, s4;
	
	s1.age = 17;
	s1.rollNumber = 70;
	
	
	cout << s1.age << endl;
	cout << s1.rollNumber << endl;
	
	// Create object dynamically
	
	Student * s6 = new Student;
	
	(*s6).rollNumber = 104;
	(*s6).age = 15;
	
	cout << (*s6).rollNumber << endl;
	cout << (*s6).age << endl;
	
	
	s6->rollNumber = 204;
	s6->age = 14;
	
	
	
	
	
	
}
