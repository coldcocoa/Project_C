#include <iostream>
using namespace std;

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numofApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) 
		: APPLE_PRICE(price), numofApples(num), myMoney(money)
	{
		
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numofApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult()
	{
		cout << "남은 사과 : " << numofApples << endl;
		cout << "판매 수익 : " << myMoney << endl << endl;
	}

};

class FruitBuyer
{
private:
	int myMoney;
	int numofApples;
public:
	FruitBuyer(int money):myMoney(money),numofApples(0)
	
	{
		
	}
	void BuyApples(FruitSeller& seller, int money)
	{
		numofApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numofApples << endl << endl;
	}
};




//int main()
//{
//	FruitSeller seller(1000, 20, 0);	
//	FruitBuyer buyer(5000);
//	buyer.BuyApples(seller, 2000);
//
//	cout << "과일 판매자 현황" << endl;
//	seller.ShowSalesResult();
//	cout << "과일 구매자 현황" << endl;
//	buyer.ShowBuyResult();
//	return 0;
//}