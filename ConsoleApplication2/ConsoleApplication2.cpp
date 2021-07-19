#include <iostream>
#include <string>
using namespace std;
#include <chrono>
#include <thread>


struct Employee
{
	int nEmpId;
	string sName;
	int nManagerId;
};

int main()
{
	int nNoOfRec = 0;
	bool bInit = true;
	std::cout << "Enter number of Records\n";
	std::cin >> nNoOfRec;
	while (nNoOfRec <= 0 || nNoOfRec > 100)
	{
		std::cout << "NA\n";
		cin.clear();
		cin.ignore(10000, '\n');
		std::cin >> nNoOfRec;
	}

	Employee* EmpArr = new Employee[nNoOfRec];

	int nFunction = 0;
	int nStartIndex = 0;
	int nInLoop = 1;
	int i = 0;

	for (i; i < nNoOfRec; i++)
	{
		std::cout << "Emp Id     : ";
		std::cin >> EmpArr[i].nEmpId;
		while (EmpArr[i].nEmpId <= 0)
		{
			std::cout << "NA\n";
			cin.clear();
			cin.ignore(10000, '\n');
			std::cin >> EmpArr[i].nEmpId;
		}
		if (i >= 1)
		{
			nStartIndex = 0;
			for (; nStartIndex < i; )
			{
				if (EmpArr[i].nEmpId == EmpArr[nStartIndex].nEmpId)
				{
					std::cout << "Duplicate Entry not allowed\n";
					std::cin >> EmpArr[i].nEmpId;
				}
				else
					nStartIndex++;
				std::chrono::milliseconds timespan(100);
				std::this_thread::sleep_for(timespan);
			}
		}
		std::cout << "Emp Name   : ";
		std::cin >> EmpArr[i].sName;
		std::cout << "Manager Id : ";
		std::cin >> EmpArr[i].nManagerId;
		while (EmpArr[i].nManagerId <= 0)
		{
			std::cout << "NA\n";
			cin.clear();
			cin.ignore(10000, '\n');
			std::cin >> EmpArr[i].nManagerId;
		}
	}

	while (nFunction < 3)
	{
		std::cout << "Enter 1 for List or 2 for Search by Manger ID or 3 to Quit \n\n";
		cin >> nFunction;

		if (nFunction == 1)
		{
			std::cout << "\nEmployee List\n";

			for (int i = 0; i < nNoOfRec; i++)
			{
				std::cout << EmpArr[i].nEmpId << "\t" << EmpArr[i].sName << "\t" << EmpArr[i].nManagerId << "\n";
			}
		}
		else if (nFunction == 2)
		{
			std::cout << "\nEnter Manager Id\n";
			bool bFlag = false;
			int nFindManagerId = 0;
			cin >> nFindManagerId;
			for (int i = 0; i < nNoOfRec; i++)
			{
				if (nFindManagerId == EmpArr[i].nManagerId)
				{
					std::cout << EmpArr[i].nEmpId << "\t" << EmpArr[i].sName << "\t" << EmpArr[i].nManagerId << "\n";
					bFlag = true;
				}

			}
			if (bFlag == false)
				std::cout << "\nManager Id not found\n";
		}
		else if (nFunction == 3)
		{

		}
		else
		{
			std::cout << "\nWrong Input. Please Re enter\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	delete[] EmpArr;
	return 0;
}
