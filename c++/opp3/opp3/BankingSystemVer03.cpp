#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20; //이름의길이

void ShowMenu(void); //메뉴출력
void MakeAccount(void); //계좌개설
void DepositMoney(void); //입금
void WithdrawMoney(void); //출금
void ShowAllAccInfo(void); //잔액조회

//1. 계좌개설
//2. 입금
//3. 출금
//4. 계좌번호 전체 출력
//5. 프로그램 종료
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
    int accID; //계좌 ID
    int balance; // 잔액
    char* cusName; //고객이름 
public:
    // 생성자, 소멸자
    Account(int _accID, int _balance, char* _name)  // 계좌개설 - ID, 고객이름, 돈
        : accID(_accID), balance(_balance)
    {
        cusName = new char[strlen(_name) + 1]; //고객이름 객체 포인터로 동적할당
        strcpy(cusName, _name);
    }

    // 실제 호출되지는 않는 복사생성자
    // 깊은 복사를 원칙으로 정의
    Account(const Account& ref)
        : accID(ref.accID), balance(ref.balance)
    {
        cusName = new char[strlen(ref.cusName) + 1]; //고객이름 객체 포인터로 동적할당
        strcpy(cusName, ref.cusName);
    }

    ~Account()
    {
        delete[]cusName;
    }

    // ID
    int GetAccID()
    {
        return accID;
    }

    // 입금
    void Deposit(int money)
    {
        balance += money;
    }

    // 출금
    int WithDraw(int money) {
        if (balance < money) //잔액<출금액 
        {
            return 0;
        }
        balance -= money;
        return money;
    }

    // 개인 계좌조회
    void ShowAccInfo() {
        cout << "계좌ID: " << accID << endl;
        cout << "이름: " << cusName << endl;
        cout << "잔액: " << balance << endl << endl;
    }
};

Account* accArr[100]; //Account 저장을 위한 배열
int accNum = 0; //저장된 Account 수

int main()
{
    int choice;

    while (1)
    {
        ShowMenu();

        cout << "선택(1~5까지의 숫자만 입력) : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "잘못된 선택" << endl;
        }
    }
    return 0;
}

//메뉴출력
void ShowMenu(void) {
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌번호 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

//계좌개설
void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID:(숫자로 입력) "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

//입금
void DepositMoney(void) {
    int money;
    int id;
    cout << "[입  금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;


    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

//출금
void WithdrawMoney(void) {
    int money;
    int id;
    cout << "[출  금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;


    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if (accArr[i]->WithDraw(money) == 0) //잔액보다 출금액이 크면
            {
                cout << "잔액부족" << endl << endl;
                return;
            }
            cout << "출금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다" << endl << endl;
}

// 전체고객 잔액조회
void ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
    }
}
