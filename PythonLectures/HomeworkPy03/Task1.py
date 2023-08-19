# 1.Employee Management System Using OOP
#
# Task: Define classes for managing employees,
# including classes for Employee, Manager, Engineer, etc.
# Implement methods for promotions, demotions, and salary adjustments.
# Example Input: employee.promote()
# Example Output: Promotion successful. New title: Manager

class EmployeeRole:
    _name = str()

    def __str__(self):
        return str(self._name)


class Manager(EmployeeRole):
    def __init__(self):
        self._name = "Manager"


class Engineer(EmployeeRole):
    def __init__(self):
        super()
        self._name = "Engineer"


class Intern(EmployeeRole):
    def __init__(self):
        self._name = "Intern"


class Employee:
    __salary_adjuster = 0.2

    def __init__(self, name, role, salary):
        self.__name = str(name)
        self.__role = self.__set_role(role)
        self.__salary = float(salary)

    def promote(self):
        if type(self.__role) == Intern:
            self.__role = Engineer()
        elif type(self.__role) == Engineer:
            self.__role = Manager()
        else:
            print("{0} cannot be promoted, because the role is highest".format(self.__name))
            return
        self.adjust_salary(is_promoted=True)
        print("Promotion successful. New title: {0}".format(self.__role))

    def demote(self):
        if type(self.__role) == Manager:
            self.__role = Engineer()
        elif type(self.__role) == Engineer:
            self.__role = Intern()
        else:
            print("{0} can now be only fired, because the role is lowest".format(self.__name))
            return
        self.adjust_salary(is_promoted=False)
        print("Demotion successful. New title: {0}".format(self.__role))

    def adjust_salary(self, *, is_promoted):
        if is_promoted:
            self.__salary += self.__salary * self.__salary_adjuster
        else:
            self.__salary -= self.__salary * self.__salary_adjuster

    def __set_role(self, role):
        if type(role) == str:
            role = str(role).lower()
            dic = {
                "intern": Intern,
                "manager": Manager,
                "engineer": Engineer
            }
            return dic[role]()
        else:
            print("No such role {0}".format(role))

    def __str__(self):
        return str("Name: {0}; Role: {1}; Salary: {2:.2f}").format(self.__name, self.__role, self.__salary)


# Test
emp1 = Employee("John Doe", "intern", 1500.50)
print(emp1)
emp1.promote()
emp1.promote()
emp1.promote()

emp1.demote()
emp1.demote()
emp1.demote()

emp1.promote()
print(emp1)
emp1.promote()
print(emp1)
emp1.demote()
print(emp1)
