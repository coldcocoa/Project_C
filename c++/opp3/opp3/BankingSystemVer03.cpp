#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20; //�̸��Ǳ���

void ShowMenu(void); //�޴����
void MakeAccount(void); //���°���
void DepositMoney(void); //�Ա�
void WithdrawMoney(void); //���
void ShowAllAccInfo(void); //�ܾ���ȸ

//1. ���°���
//2. �Ա�
//3. ���
//4. ���¹�ȣ ��ü ���
//5. ���α׷� ����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
    int accID; //���� ID
    int balance; // �ܾ�
    char* cusName; //���̸� 
public:
    // ������, �Ҹ���
    Account(int _accID, int _balance, char* _name)  // ���°��� - ID, ���̸�, ��
        : accID(_accID), balance(_balance)
    {
        cusName = new char[strlen(_name) + 1]; //���̸� ��ü �����ͷ� �����Ҵ�
        strcpy(cusName, _name);
    }

    // ���� ȣ������� �ʴ� ���������
    // ���� ���縦 ��Ģ���� ����
    Account(const Account& ref)
        : accID(ref.accID), balance(ref.balance)
    {
        cusName = new char[strlen(ref.cusName) + 1]; //���̸� ��ü �����ͷ� �����Ҵ�
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

    // �Ա�
    void Deposit(int money)
    {
        balance += money;
    }

    // ���
    int WithDraw(int money) {
        if (balance < money) //�ܾ�<��ݾ� 
        {
            return 0;
        }
        balance -= money;
        return money;
    }

    // ���� ������ȸ
    void ShowAccInfo() {
        cout << "����ID: " << accID << endl;
        cout << "�̸�: " << cusName << endl;
        cout << "�ܾ�: " << balance << endl << endl;
    }
};

Account* accArr[100]; //Account ������ ���� �迭
int accNum = 0; //����� Account ��

int main()
{
    int choice;

    while (1)
    {
        ShowMenu();

        cout << "����(1~5������ ���ڸ� �Է�) : ";
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
            cout << "�߸��� ����" << endl;
        }
    }
    return 0;
}

//�޴����
void ShowMenu(void) {
    cout << "-----Menu-----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. ���¹�ȣ ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

//���°���
void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "����ID:(���ڷ� �Է�) "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

//�Ա�
void DepositMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;


    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

//���
void WithdrawMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;


    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if (accArr[i]->WithDraw(money) == 0) //�ܾ׺��� ��ݾ��� ũ��
            {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

// ��ü�� �ܾ���ȸ
void ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
    }
}
