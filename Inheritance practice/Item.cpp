//Luke Harris
//Inheritance practice

#include<string>
using namespace std;

class Item{
protected:
	int id;
	double price;
	string color;
	void dispense();
public:
	
};

class Phone : Item{

};

class Accessory : Item{

};

class Android : Phone{

};

class AndroidAccessory : Accessory{

};

class Iphone : Phone {

};

class IphoneAccessory : Accessory{

};