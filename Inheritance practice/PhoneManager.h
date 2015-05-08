//Luke Harris
//Nov 28th 2014
//Phone Manager class
#ifndef __PHONEMANAGER_H__
#define __PHONEMANAGER_H__

#include "PhoneItem.h"
#include <vector>
#include <memory>

using namespace std;
class PhoneManager
{
public:
	typedef std::shared_ptr<Item> spItem;
private:
	std::vector <spItem> v;
	double dSum;
public:
	PhoneManager(int);
	bool purchaseItem();
	//double getPrice(int);
	double getTotalValueSold() { return dSum; }
	void doInventory();
	void reStock(int i);
};

PhoneManager::PhoneManager(int iNum){
	for (unsigned i = 0; i < iNum; ++i)
	{
		v.push_back(shared_ptr<Item>(new IPhone("IPhone 6", 700.00, 12345+i)));
		v.push_back(shared_ptr<Item>(new Android("Galaxy 5", 599.00, 12345+i)));
		v.push_back(shared_ptr<Item>(new IPhoneCase("IPhone 6 Case", 100.00, 1111 + i)));
		v.push_back(shared_ptr<Item>(new AndroidCase("Galaxy 5 Case", 50.00, 2222 + i)));
	}
	dSum = 0.0;
}

bool PhoneManager::purchaseItem(){
	if (v.size() >0)
	{
		int iRemove = rand() % v.size();
		if (auto sp = dynamic_pointer_cast<Phone>(v[iRemove]))
		{
			sp->activate();
		}
		//get price of item sold
		dSum += v[iRemove]->getItemPrice();
		v.erase(v.begin() + iRemove);
		v[iRemove]->dispenseItem();
		return true;
	}
	else return false;

}


void PhoneManager::doInventory(){
	int numIPhone = 0;
	int numAndroid = 0;
	int numIPhoneCase = 0;
	int numAndroidCase = 0;
	for (auto x : v){
		if (dynamic_pointer_cast<IPhone>(x))
			numIPhone++;
		if (dynamic_pointer_cast<Android>(x))
			numAndroid++;
		if (dynamic_pointer_cast<IPhoneCase>(x))
			numIPhoneCase++;
		if (dynamic_pointer_cast<Android>(x))
			numAndroidCase++;
	}
	cout << "Inventory left: \n";
	cout << "IPhones: " << numIPhone << endl;
	cout << "Android: " << numAndroid << endl;
	cout << "IPhone Cases: " << numIPhoneCase << endl;
	cout << "Android Cases " << numAndroidCase << endl;
}

void PhoneManager::reStock(int num){
	int numIPhone = 0;
	int numAndroid = 0;
	int numIPhoneCase = 0;
	int numAndroidCase = 0;
	for (auto x : v){
		if (dynamic_pointer_cast<IPhone>(x))
			numIPhone++;
		if (dynamic_pointer_cast<Android>(x))
			numAndroid++;
		if (dynamic_pointer_cast<IPhoneCase>(x))
			numIPhoneCase++;
		if (dynamic_pointer_cast<Android>(x))
			numAndroidCase++;
	}
	for (int i = numIPhone; i < num; ++i){
		v.push_back(spItem(new IPhone("IPhone 6", 700.00, 12345 + i)));
	}
	for (int i = numIPhoneCase; i < num; ++i){
		v.push_back(shared_ptr<Item>(new IPhoneCase("IPhone 6 Case", 100.00, 1111 + i)));
	}
	for (int i = numAndroid; i < num; ++i){
		v.push_back(shared_ptr<Item>(new Android("Galaxy 5", 599.00, 12345 + i)));
	}
	for (int i = numAndroidCase; i < num; ++i){
		v.push_back(shared_ptr<Item>(new AndroidCase("Galaxy 5 Case", 50.00, 2222 + i)));
	}
	dSum = 0;
	cout << "RESTOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOCKED" << endl;
		

}

#endif