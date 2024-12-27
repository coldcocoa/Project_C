#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class Employee
{
private:
    char name[100];
public:
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }

    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
};


class PermanentWorker : public Employee
{
private:
    
    int salary; 
public:
    PermanentWorker(const char* name, const int money) : Employee(name), salary(money)
    {

    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char* name, const int pay) : Employee(name), payPerHour(pay)
    {

    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }

};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {

    }
    void AddSalesResult(const int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        cout << "salary: " << GetPay() << endl;
    }
};


class EmployeeHandler
{
private:
    
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    {
        //empty
    }
    void AddEmployee(Employee* emp) 
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
                for(int i=0;i<empNum;i++)
                {
                    empList[i]->ShowSalaryInfo();
                }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
                for(int i = 0;i<empNum;i++)
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
    handler.AddEmployee(new PermanentWorker("CHOI", 2000));

    TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("PARK", 1500, 0.1);
    seller->AddSalesResult(7000);

    handler.AddEmployee(seller);
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}