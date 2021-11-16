#include "ATApp.hpp"

void ATApp::runApp(void)
{
	while (true)
	{
		displayMenu();
		int i = selectMenuOption();
		cout << "--------------------------------------------------------------" << endl;

		switch (i)
		{
		case 1:
		{
			fstream file;
			file.open("classList.csv", std::ios::in);

			if (!master.isEmpty())
			{
				master.destroyList();
			}
			fileToMaster(file);

			break;
		}
		case 2:
		{
			fstream file;
			file.open("master.txt", std::ios::in);

			fileToMaster(file);

			break;
		}
		case 3:
		{
			if (!master.isEmpty())
			{
				fstream file;
				file.open("master.txt", std::ios::out);

				if (file.is_open())
				{
					file << ",ID,Name,Email,Units,Program,Level" << endl;
					file << master;
				}

				file.close();

				cout << "Store Successful!" << endl;
			}

			break;
		}
		case 4:
		{
			markAbsences();

			break;
		}
		case 5:
		{
			cout << "1. Generate report for all students; showing only the most recent absence for each student" << endl;
			cout << "2. Generate report for students with absences that match or exceed (the number entered by the user)" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;

			int n = selectMenuOption();

			switch (n)
			{
			case 1:
			{
				fstream file;
				file.open("abs.txt", std::ios::out);

				cout << "--------------------------------------------------------------" << endl;

				Node<Data>* node = master.getPHead();

				while (node != nullptr)
				{
					cout << node->getPData()->getName() << ": " << node->getPData()->getAbsNum();
					file << node->getPData()->getName() << ": " << node->getPData()->getAbsNum();
					if (!node->getPData()->getPAbsStore()->isEmpty())
					{
						cout << ", " << node->getPData()->getPAbsStore()->peek() << endl;
						file << ", " << node->getPData()->getPAbsStore()->peek() << endl;
					}
					else
					{
						cout << endl;
						file << endl;
					}
					node = node->getPNext();
				}

				file.close();

				break;
			}
			case 2:
			{
				fstream file;
				file.open("thres.txt", std::ios::out);

				cout << "--------------------------------------------------------------" << endl;

				int limit = 0;
				cout << "Input the threshold for the number of absences: ";
				cin >> limit;
				cout << endl;

				Node<Data>* node = master.getPHead();

				while (node != nullptr)
				{
					if (node->getPData()->getAbsNum() >= limit)
					{
						cout << node->getPData()->getName() << ": " << node->getPData()->getAbsNum() << endl;
						file << node->getPData()->getName() << ": " << node->getPData()->getAbsNum() << endl;
					}
					node = node->getPNext();
				}

				file.close();

				break;
			}
			}
			break;
		}
		case 6:
		{
			cout << "Thank you for using Attendance Tracker Application!" << endl;
			cout << "--------------------------------------------------------------" << endl;
			return;

			break;
		}
		default:
			cout << "Invalid Input, Try Again!" << endl;

			break;
		}
		cout << "--------------------------------------------------------------" << endl << endl;
	}
}

void ATApp::displayMenu()
{
	cout << "Attendance Tracker Application" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Generate report" << endl;
	cout << "6. Exit" << endl << endl;
}

int ATApp::selectMenuOption() const
{
	int n = 0;
	cout << "Select an option: ";
	cin >> n;

	system("cls");
	return n;
}

void ATApp::fileToMaster(fstream& file)
{
	Data access;
	char rLine[100] = "";
	file.getline(rLine, 100);

	while (file.is_open() && !file.eof())
	{
		file.getline(rLine, 100, ',');
		access.setRecNum(atoi(rLine));
		if (access.getRecNum() == 0)
		{
			break;
		}
		file.getline(rLine, 100, ',');
		access.setIDNum(atoi(rLine));
		file.getline(rLine, 100, '\"');
		file.getline(rLine, 100, '\"');
		access.setName(rLine);
		file.getline(rLine, 100, ',');
		file.getline(rLine, 100, ',');
		access.setEmail(rLine);
		file.getline(rLine, 100, ',');
		access.setUnits(rLine);
		file.getline(rLine, 100, ',');
		access.setProgram(rLine);
		file.getline(rLine, 100);
		access.setLevel(rLine);

		master.insertAtFront(access);
	}

	file.close();
	master.printList();
}

void ATApp::markAbsences()
{
	master.printList();
	// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	string date = std::to_string(now->tm_year + 1900) 
		+ "-" + std::to_string(now->tm_mon + 1)
		+ "-" + std::to_string(now->tm_mday);
	cout << endl << "Today's Date: " << date << endl << endl;

	string answer;
	Node<Data>* node = master.getPHead();

	while (node != nullptr)
	{
		cout << "Was " << node->getPData()->getName() << " absent today? (Y/N): ";
		cin >> answer;
	
		if (answer == "Y")
		{
			node->getPData()->getPAbsStore()->push(date);
			node->getPData()->incrementAbsNum();
		}
		node = node->getPNext();
	}
}