#include <iostream>
#include <vector>

class PurchaseRequest
{
private:
    int amount;
    bool approval_status{ false };
    std::string approved_by;
public:
    PurchaseRequest(const int n) :amount(n){ }
    int GetAmount() const { 
        return amount; 
    }

    void ProcessPR(const std::string& approver)
    {
        approved_by = approver;
        approval_status = true;
    }

    void GetStatus()
    {
        std::cout << " Purchase Order Summary --- " << std::endl;
        std::cout << " Amount: " << amount << std::endl;
        std::cout << " Approval Status: " << approval_status << std::endl;
        std::cout << " Approver Name: " << approved_by << std::endl;
    }
};

class Employee
{
public:
    Employee() = default;
    Employee(const std::string& name, const int& limit) :
        name(name), approval_limit(limit) {}
    int GetLimit() {
        return approval_limit;
    }

    void Approve(PurchaseRequest& request)
    {
        std::cout << " Order is approved by " << name << std::endl;
        request.ProcessPR(name);
    }
private:
    std::string name;
    int approval_limit;
};

class JuniorAssociate :public Employee
{
public:
    JuniorAssociate() : Employee("Junior", 500){}
};

class SeniorAssociate : public Employee {
public:
    SeniorAssociate() : Employee("Senior", 1500) {}
};

class Manager : public Employee {
public:
    Manager() : Employee("Manager", 3000) {}
};

class ApprovalSystem
{
public:
    void ProcessRequest(PurchaseRequest& request)
    {
        const int request_amount = request.GetAmount();
        if (request_amount <= junior.GetLimit())
        {
            junior.Approve(request);
        }
        else if (request_amount <= senior.GetLimit())
        {
            senior.Approve(request);
        }
        else if (request_amount <= manager.GetLimit())
        {
            manager.Approve(request);
        }
        else
        {
            std::cout << "order cannot be approved by anyone" << std::endl;
        }
    }
private:
    JuniorAssociate junior;
    SeniorAssociate senior;
    Manager manager; 
};

int main() 
{
    PurchaseRequest pr_200(200);
    ApprovalSystem sys;
    sys.ProcessRequest(pr_200);

    PurchaseRequest PR_600(600);
    sys.ProcessRequest(PR_600);

    PurchaseRequest PR_1600(1600);
    sys.ProcessRequest(PR_1600);

    PurchaseRequest PR_5000(5000);
    sys.ProcessRequest(PR_5000);
}
