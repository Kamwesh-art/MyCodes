class Employee:
    def __init__(self, name, hours_worked, hourly_rate):
        self.name = name
        self.hours_worked = hours_worked
        self.hourly_rate = hourly_rate

    def calculate_gross_pay(self):
        return self.hours_worked * self.hourly_rate

class Payroll:
    def __init__(self):
        self.employees = []

    def add_employee(self, employee):
        self.employees.append(employee)

    def calculate_payroll(self):
        for employee in self.employees:
            gross_pay = employee.calculate_gross_pay()
            tax_deduction = gross_pay * 0.2  # Assuming 20% tax
            other_deductions = gross_pay * 0.05  # Assuming 5% other deductions
            net_pay = gross_pay - (tax_deduction + other_deductions)

            print(f"Employee: {employee.name}")
            print(f"Gross Pay: ${gross_pay:.2f}")
            print(f"Tax Deduction: ${tax_deduction:.2f}")
            print(f"Other Deductions: ${other_deductions:.2f}")
            print(f"Net Pay: ${net_pay:.2f}\n")

# Example usage
if __name__ == "__main__":
    payroll = Payroll()

    emp1 = Employee("John Doe", 40, 25)  # 40 hours at $25/hour
    emp2 = Employee("Jane Smith", 35, 30)  # 35 hours at $30/hour

    payroll.add_employee(emp1)
    payroll.add_employee(emp2)

    payroll.calculate_payroll()
