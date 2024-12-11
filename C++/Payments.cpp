#include <iostream>

using namespace std;

class Employee {
protected:
    string id;
    string name;
    double basicSalary;
public:
    Employee(){}
    Employee(const string id, const string name, double basicSalary) {
        this->id = id;
        this->name = name;
        this->basicSalary = basicSalary;
    }

    virtual double calculateSalary() const = 0;

    string getId() const {
        return id;
    }
    string getName() const { return name; }
    double getBasicSalary() const { return basicSalary; }

};

class PermanentEmployee : public Employee {
public:
    PermanentEmployee(const string& id, const string& name, double basicSalary)
        : Employee(id, name, basicSalary) {}

    double calculateSalary() const override {
        return basicSalary;
    }
};

class ContractualEmployee : public Employee {
private:
    int hoursWorked;
public:
    ContractualEmployee(const string& id, const string& name, double basicSalary, int hoursWorked)
        : Employee(id, name, basicSalary), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return basicSalary * hoursWorked;
    }


};

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    while (true) {
        cout << "1. Add permanent employee\n"
             << "2. Add contractual employee\n"
             << "3. Display employee payroll\n"
             << "4. Quit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                if (numEmployees >= MAX_EMPLOYEES) {
                    cout << "Employee limit reached.\n";
                    break;
                }

                string id, name;
                double basicSalary;

                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter basic salary: ";
                cin >> basicSalary;

                employees[numEmployees] = new PermanentEmployee(id, name, basicSalary);
                numEmployees++;
                break;
            }
            case 2: {
                if (numEmployees >= MAX_EMPLOYEES) {
                    cout << "Employee limit reached.\n";
                    break;
                }

                string id, name;
                double basicSalary;
                int hoursWorked;

                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter basic salary: ";
                cin >> basicSalary;
                cout << "Enter hours worked: ";
                cin >> hoursWorked;

                employees[numEmployees] = new ContractualEmployee(id, name, basicSalary, hoursWorked);
                numEmployees++;
                break;
            }
            case 3: {
                cout << "Employee Payroll:\n";
                cout << "ID: \t" << "Name: \t" << "Total Salary: " << endl;
                for (int i = 0; i < numEmployees; i++) {
                    cout << employees[i]->getId() << "\t"
                        << employees[i]->getName() << "\t"
                        << employees[i]->calculateSalary() << "\t\n";
                }
                break;
            }
            case 4:
                for(int i=0; i < numEmployees; i++){
                    delete employees[i];
                }

                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
