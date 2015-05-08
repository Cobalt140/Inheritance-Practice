//Luke Harris
//Nov 28th 2014
//Phone Kiosk: Application that simulates a phone kiosk that
//dispenses phone and accessories
#include <iostream>
#include <string>
#include "PhoneItem.h"
#include "PhoneManager.h"
#include <ctime>
#include <vector>
using namespace std;
static const int NUMITEM = 50;

int main()
{
	srand(unsigned(time(NULL)));
	PhoneManager pm(NUMITEM);
	double moneyMade = 0;
	// sell 40 items 
	for (int i = 0; i < 40; ++i)
	{
		//moneyMade += pm.getPrice(i);
		pm.purchaseItem();
	}
	moneyMade += pm.getTotalValueSold();
	cout << "Total money= " << moneyMade << endl;
	//check inventory left
	pm.doInventory();
	pm.reStock(NUMITEM);
	pm.doInventory();

	
}