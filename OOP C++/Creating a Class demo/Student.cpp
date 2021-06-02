class Student{
	
	public:
		int rollNumber;
		int age;
		
	private:
		int value;
		
		
	public:
	
	void display(){
		cout << age << " " << rollNumber <<endl;
	}
	
	void setValue(int value){
		this->value = value;
	}
	
	int getValue(){
		return value;
	}
	
};




