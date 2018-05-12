/*author: Kevin
  create date: 2018-05-12 17:43:21
  propose: 
********************/

public class Puppy{
	String _name;
	int _age;

	public Puppy(String name){
		_name=name;
		//System.out.println("Passed Name is : " + name);
	}

	void set_age(int age){
		_age=age;
	}

	int get_age(){
		return _age;
	}

	String get_name(){
		return _name;
	}

	public static void main(String[] args) {
		//create object 
		Puppy mPuppy = new Puppy("Tommy");
		System.out.println("Name: " + mPuppy.get_name() + " Age: " + mPuppy.get_age());
	}
}
