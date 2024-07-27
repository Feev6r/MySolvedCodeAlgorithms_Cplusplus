#include <iostream>
#include <vector>

enum props {
	NAME,
	EXPERIENCE,
	ROLE,
	AGE,
	SALARY
};

class Employee {
//private:


public:
	std::string Name;
	int Experience;
	std::string Role;
	int Age;
	double Salary;
	static int id;


	Employee(std::string name, int experience, std::string role, int age, double salary) {
		Name = name;
		Experience = experience;
		Role = role;
		Age = age;
		Salary = salary;

	}

};



class DataBase {
private:

	std::vector<Employee> Employees;

public:

	void Add(Employee& employee) {

		Employees.push_back(employee);
	}

	void Show(int ID = -1) {

		if (ID != -1) {

			std::cout << "-----------------" << std::endl;
			std::cout << "    Employe " << ID << "    " << std::endl;
			std::cout << "-----------------" << std::endl;


			std::cout << "Name: " << Employees[ID].Name << std::endl;
			std::cout << "Experience: " << Employees[ID].Experience << std::endl;
			std::cout << "Age: " << Employees[ID].Age << std::endl;
			std::cout << "Role: " << Employees[ID].Role << std::endl;
			std::cout << "Salary: " << Employees[ID].Salary << std::endl << std::endl;
		}
		else {

			int index = 0;
			for (auto it = Employees.begin(); it != Employees.end(); it++)
			{
				std::cout << "-----------------" << std::endl;
				std::cout << "    Employe " << index << "    " << std::endl;
				std::cout << "-----------------" << std::endl;


				std::cout << "Name: " << it->Name << std::endl;
				std::cout << "Experience: " << it->Experience << std::endl;
				std::cout << "Age: " << it->Age << std::endl;
				std::cout << "Role: " << it->Role << std::endl;
				std::cout << "Salary: " << it->Salary << std::endl << std::endl;

				index++;
			}
		}

	}

	void Edit(int ID, props p) {

	}

	DataBase() {

	}

};


int re(int n) {

	if (n == 0) {
		n = 1;
	}
	else {
		return n * re(n - 1);
	}

	return n;
}

int main()
{	
	//Employee e1("Fernando", 10, "Director", 18, 200.000);
	//Employee e2("e2", 1, "employee", 30, 100.000);

	//DataBase db;
	//db.Add(e1);
	//db.Add(e2);

	//db.Show(1);
	int a = re(5);
	std::cout << a;

	//std::cout << e1.GetId();

	//std::cout << e2.GetId();
	//std::cout << e1.Age;
}


