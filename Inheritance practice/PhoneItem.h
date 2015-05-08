//Luke Harris
//Nov 28th 2014
//Phone and accessories classes
#ifndef __PHONEITEM_H__
#define __PHONEITEM_H__

#include<string>
#include<iostream>

class Item{
protected:
	std::string sName_;
	int id_;
	double dPrice_;
public:
	Item(std::string s, double dp, int id) : sName_(s), dPrice_(dp), id_(id){}
	virtual void toString(){ std::cout << sName_ << "," << dPrice_ << ":" << id_ << std::endl; }
	virtual void dispenseItem() = 0;
	virtual ~Item(){}
	double getItemPrice(){return dPrice_; }

};

class Phone : public Item{
public:
	Phone(std::string sn, double dp, int id) : Item(sn, dp, id){}
	virtual void activate() = 0;
	virtual ~Phone(){}

};

class IPhone : public Phone {
public:
	IPhone(std::string sn, double dp, int id) : Phone(sn, dp, id){}
	void activate() { std::cout << "Setting carrier to Bell for IPhone\n" << std::endl; }
	void dispenseItem(){ std::cout << "Selling " << sName_ << " for $" << dPrice_ << std::endl; }

};

class Android : public Phone {
public:
	Android(std::string sn, double dp, int id) : Phone(sn, dp, id){}
	void activate() { std::cout << "Setting carrier to Rogers for Android\n" << std::endl; }
	void dispenseItem(){ std::cout << "Selling " << sName_ << " for $" << dPrice_ << std::endl; }

};

class Accessory : public Item{
public:
	Accessory(std::string s, double dp, int i) : Item(s, dp, i){}
};

class IPhoneCase : public Accessory{
public:
	IPhoneCase(std::string sn, double dp, int i) : Accessory (sn, dp, i){}
	void dispenseItem(){ std::cout << "Selling " << sName_ << " for $" << dPrice_ << std::endl; }
};

class AndroidCase : public Accessory{
public:
	AndroidCase(std::string sn, double dp, int i) : Accessory(sn, dp, i){}
	void dispenseItem(){ std::cout << "Selling " << sName_ << " for $" << dPrice_ << std::endl; }
};

#endif