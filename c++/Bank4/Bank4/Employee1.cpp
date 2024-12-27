#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)


class PermanentWorker
{
private:
    char name[100];
    int salary; 
public:
    PermanentWorker(const char* name, const int money) : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void SHowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};


class EmployeeHandler
{
private:
    
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    {
       
    }
    void AddEmployee(PermanentWorker* emp) 
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0;i < empNum;i++)
        {
            empList[i]->SHowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0;i < empNum;i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main()
{
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("CHOI", 1500));
    handler.AddEmployee(new PermanentWorker("JO", 2000));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}