//	         Abdulrehman Siddiqi
//             3190/BSCS/F15/A
//       Microsoft Visual Studio 2013           
/*     Display menu in which ask user to
create, append, delete or search data
then create program using object oriented approach
write each member function to do those work */


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define MAX 70
#define TM 500
#define SMAX 6
#define TRUE true

//int searchReg(student ss, int sinfo, int nn);

using namespace std;

class student
{
	// Default they are private
	int reg;
	string name;
	float per;
	char grade;
	int mks[SMAX];

	// Member Function
public:
	void input();
	void getResult();
	void display();
	bool search(int sinfo);
	void append();
	void update(int op);
	int regCh();
	bool check(int min, int max, int& nn);
};

// Input function
void student::input()
{
	int temp;
	bool pos;

	cout << endl;

	do{
		cout << " Enter Reg No : ";
		cin >> temp;
		if (cin)
		{
			if (check(1000, 9999, temp) == false)
			{
				pos = search(temp);
				if (pos == false)
				{
					reg = temp;
					break;
				}
				else
					cout << "\nThis Reg No. already exists ... " << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "\n Enter correct Number.. \n" << endl;
		}
		cin.clear();
		cin.ignore();
	} while (TRUE);

	cout << " Enter Student Name : ";
	cin >> name;

	for (int j = 0; j < SMAX - 1; j++)
	{
		do{
			cout << " Enter Marks of Subject No : " << j + 1 << " : ";
			cin >> mks[j];
		} while (check(0, 100, mks[j]));
	}
	getResult();
}

// GetResult Function
void student::getResult()
{
	mks[5] = 0;

	for (int j = 0; j < SMAX - 1; j++)
		mks[5] += mks[j];   // Total Marks   [1][2][3][4][5][total marks]

	per = static_cast<float>((mks[5] / float(TM)) * 100.00);

	if (per >= 80) grade = 'A';
	else if ((per < 80) && (per >= 70)) grade = 'B';
	else if ((per < 70) && (per >= 60)) grade = 'C';
	else grade = 'F';

	cout << endl;
}

// Display Function
void student::display()
{
	cout << setw(5) << reg << setw(8) << name
		<< setw(7) << mks[0]
		<< setw(7) << mks[1]
		<< setw(7) << mks[2]
		<< setw(7) << mks[3]
		<< setw(7) << mks[4]
		<< setw(8) << mks[5]
		<< setw(8) << TM
		<< setw(7) << per << "%"
		<< setw(7) << grade << endl;
}

// Append Function
void student::append()
{
		int temp;

		do{
			cout << " Enter Reg No : ";
			cin >> temp;
			if (cin)
			{
				if (check(1000, 9999, temp) == false)
				{
					reg = temp;
					break;
				}



			}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "\n Enter correct Number.. \n" << endl;
		}

	} while (TRUE);

	cout << " Enter Name : ";
	cin >> name;

	int temp1;
	for (int j = 0; j < SMAX - 1; j++)
	{
		do{
			cout << " Enter Marks of Subject : " << j + 1 << " : ";
			cin >> temp1;
			if (cin)
			{
				mks[j] = temp1;
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "\n Enter correct Number.. \n" << endl;
			}
		} while (check(0, 100, mks[j]));
	}

	getResult();
}

// Update Student Information
void student::update(int op)
{
	int newInt, temp;
	string newString;

	switch (op)
	{
	case 1:
		do{
			cout << " Enter new Reg No : ";
			cin >> temp;
			if (cin)
			{
				if (check(1000, 9999, temp) == true)
				{
					reg = temp;
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "\n Enter correct Number.. \n" << endl;
			}
		} while (TRUE);
		break;

	case 2:
		cout << "Enter Corrected Name : ";
		cin.ignore();
		getline(cin, newString);
		name = newString;
		break;

	case 3:
		do{
			cout << "Enter new Marks is Sub-1 : ";
			cin >> newInt;
		} while (check(0, 100, newInt));
		mks[0] = newInt;
		break;

	case 4:
		do{
			cout << "Enter new Marks is Sub-2 : ";
			cin >> newInt;
		} while (check(0, 100, newInt));
		mks[1] = newInt;
		break;

	case 5:
		do{
			cout << "Enter new Marks is Sub-3 : ";
			cin >> newInt;
		} while (check(0, 100, newInt));
		mks[2] = newInt;
		break;

	case 6:
		do{
			cout << "Enter new Marks is Sub-4 : ";
			cin >> newInt;
		} while (check(0, 100, newInt));
		mks[3] = newInt;
		break;

	case 7:
		do{
			cout << "Enter new Marks is Sub-5 : ";
			cin >> newInt;
		} while (check(0, 100, newInt));
		mks[4] = newInt;
		break;
	}

	getResult();
}


// Sorting function returning registration no. 
int student::regCh()
{
	return reg;
}

// Check function
bool student::check(int min, int max, int& nn)
{
	if ((nn >= min) && (nn <= max))
		return false;
	else
		return true;
}

// search function
bool student::search(int sinfo)
{
	bool pos;

	if (reg == sinfo)
		pos = true;
	else
		pos = false;

	return pos;
}

// +++++++++++++++++++++++++++++++++++++++++++++++  Main Function +++++++++++++++++++++
int main()
{
	student s[MAX];
	bool p;
	int n, count = 0, sinfo, pos, op, cnt = 0;
	char cls, ch;

	do
	{
		cout << "\t\t\t******************************" << endl;

		do{
			cout << endl;

			do{
				cout << "\t\t\t\t MAIN MENU" << endl
					<< "\t\t\t    1. Create DataBase  " << endl
					<< "\t\t\t    2. Display Database " << endl
					<< "\t\t\t    3. Append a Record  " << endl
					<< "\t\t\t    4. Search a record  " << endl
					<< "\t\t\t    5. Delete a Record  " << endl
					<< "\t\t\t    6. Update a Record  " << endl
					<< "\t\t\t    7. Save on File     " << endl
					<< "\t\t\t    8. Read from File   " << endl
					<< "\t\t\t    X. Exit             " << endl
					<< "\t\t\t******************************" << endl
					<< "\n\n\t\t  Enter your choice : ";

				cin >> ch;
				ch = toupper(ch);
				if (((ch > '0') && (ch <= '8')) || (ch == 'X'))
					break;
			} while (TRUE);

			if (!(ch == '8'))
			{
				if (count == 0)  // First time program runs
				{
					if ((ch == '2') || (ch == '3') || (ch == '4') || (ch == '5') || (ch == '6') || (ch == '7'))
					{
						cout << "\n************# First Create Database #**************\n" << endl;
					}
					else
					{
						count = 1;
						break;
					}
				}
				else if (count == 1) // Second time program runs
				{
					if ((ch == '3') || (ch == '4') || (ch == '5') || (ch == '6') || (ch == '7'))
						cout << "\n************# First generate DATA #**************\n" << endl;
					else
					{
						count = 2;
						break;
					}
				}
				else // Third time program runs
					break;
			}
			else
			{
				count = 2;
				break;
			}
		} while (TRUE);

		//  Controlling the flow of program
		switch (ch)
		{
		case '1':  // Input Case
		{
					   do{
						   cout << "\n Enter the Number of Students [MAX 70] : ";
						   cin >> n;
					   } while (s[1].check(0, MAX, n));

					   for (int i = 0; i < n; i++)
					   {
						   s[i].input();
					   }

					   cout << "\n************# DataBase Created #**************\n";
					   cout << "\nPress 'c' to clear screen : ";
					   cin >> cls;
					   cls = toupper(cls);
					   if (cls == 'C')
						   system("cls");
					   else
						   break;
		}
			break;

		case '2':  // Display Case
		{
					   int pass = n - 1;

					   for (int i = 0; i < pass; i++)
					   for (int j = i + 1; j < n; j++)
					   if (s[i].regCh() > s[j].regCh())
						   swap(s[i], s[j]);

					   cout << "\n\t\t\t\tRESULT CARD";
					   cout << "\n\n******************************************************************************\n";

					   cout << setw(5) << "Reg#" << setw(8) << "Name"
						   << setw(7) << " Sub-1"
						   << setw(7) << " Sub-2"
						   << setw(7) << " Sub-3"
						   << setw(7) << " Sub-4"
						   << setw(7) << " Sub-5"
						   << setw(8) << " Obtain"
						   << setw(8) << " Total"
						   << setw(7) << " %age"
						   << setw(7) << "Grade" << endl;

					   for (int i = 0; i < n; i++)
					   {
						   s[i].display();
					   }
					   cout << "\n\n******************************************************************************\n";

					   cout << "\nPress 'c' to clear screen : ";
					   cin >> cls;
					   cls = toupper(cls);
					   if (cls == 'C')
						   system("cls");
					   else
						   break;
		}
			break;

		case '3':  // Append Case
		{
					   if (n >= MAX)
						   cout << "\n************# There is no Space in DataBase #**************\n";
					   else
					   {
						   cout << "\n\t ENTER DATA FOR STUDENT : " << n + 1 << endl << endl;
						   s[n].append();
						   n++;
						   cout << "\n************# Data Appended #**************\n";

					   }

					   cout << "\nPress 'c' to clear screen : ";
					   cin >> cls;
					   cls = toupper(cls);
					   if (cls == 'C')
						   system("cls");
					   else
						   break;
		}
			break;

		case '4':  // Search Case
		{
					   do{
						   cout << "\n Enter Reg no. of the student to Search : ";
						   cin >> sinfo;
					   } while (s[1].check(1000, 9999, sinfo));

					   for (int i = 0; i < n; i++)
					   {
						   p = s[i].search(sinfo);
						   if (p == true)
						   {
							   pos = i;
							   break;
						   }
						   else pos = -1;
					   }

					   if (pos == -1)
						   cout << "\n************# Not Found #**************\n" << endl;
					   else
					   {
						   cout << endl << " Record found at positon = " << pos + 1 << endl;
						   cout << "\n\n******************************************************************************\n";
						   cout << setw(5) << "Reg#" << setw(8) << "Name"
							   << setw(7) << " Sub-1"
							   << setw(7) << " Sub-2"
							   << setw(7) << " Sub-3"
							   << setw(7) << " Sub-4"
							   << setw(7) << " Sub-5"
							   << setw(8) << " Obtain"
							   << setw(8) << " Total"
							   << setw(7) << " %age"
							   << setw(7) << "Grade" << endl;

						   s[pos].display();
						   cout << "\n\n******************************************************************************\n";
					   }
					   cout << "\nPress 'c' to clear screen : ";
					   cin >> cls;
					   cls = toupper(cls);
					   if (cls == 'C')
						   system("cls");
					   else
						   break;
		}
			break;

		case '5': // Delete Case
		{
					  cout << "\n\nEnter Reg# of the student to delete: ";
					  cin >> sinfo;
					  for (int i = 0; i < n; i++)
					  {
						  p = s[i].search(sinfo);
						  if (p == true)
						  {
							  pos = i;
							  break;
						  }
						  else
							  pos = -1;
					  }

					  if (pos == -1)
						  cout << "Not Found \n" << endl;
					  else
					  for (int i = pos; i < n - 1; i++)
						  s[i] = s[i + 1];

					  n = n - 1;

					  cout << endl << "\t\tStudent record Deleted..." << endl << endl;

					  cout << "\nPress 'c' to clear screen : ";
					  cin >> cls;
					  cls = toupper(cls);
					  if (cls == 'C')
						  system("cls");
					  else
						  break;
		}
			break;

		case '6': // Update Case
		{
					  do{
						  cout << "\nEnter the reg no. of Student you want to update : ";
						  cin >> sinfo;
					  } while (s[1].check(1000, 9999, sinfo));

					  for (int i = 0; i < n; i++)
					  {
						  p = s[i].search(sinfo);
						  if (p == true)
						  {
							  pos = i;
							  break;
						  }
						  else
							  pos = -1;
					  }

					  if (pos != -1)
					  {
						  cout << "\n\n******************************************************************************\n";
						  cout << setw(5) << "Reg#" << setw(8) << "Name"
							  << setw(7) << " Sub-1"
							  << setw(7) << " Sub-2"
							  << setw(7) << " Sub-3"
							  << setw(7) << " Sub-4"
							  << setw(7) << " Sub-5"
							  << setw(8) << " Obtain"
							  << setw(8) << " Total"
							  << setw(7) << " %age"
							  << setw(7) << "Grade" << endl;

						  s[pos].display();
						  cout << "\n\n******************************************************************************\n";

						  do{
							  cout << "\t\t\t" << "+: What do you want to Update :+" << endl;
							  cout << "\t\t\t" << "1 : Update Reg# " << endl;
							  cout << "\t\t\t" << "2 : Update Name " << endl;
							  cout << "\t\t\t" << "3 : Update marks in Sub-1 " << endl;
							  cout << "\t\t\t" << "4 : Update marks in Sub-2 " << endl;
							  cout << "\t\t\t" << "5 : Update marks in Sub-3 " << endl;
							  cout << "\t\t\t" << "6 : Update marks in Sub-4 " << endl;
							  cout << "\t\t\t" << "7 : Update marks in Sub-5 " << endl << endl;
							  cout << " Enter your Choice from above menu : ";
							  cin >> op;
						  } while (s[1].check(1, 7, op));
						  s[pos].update(op);
						  cout << "\n************# Data Updated #**************\n";
					  }
					  else
						  cout << "\n************* This Reg No. Does't exist ***************\n";

					  cout << "\nPress 'c' to clear screen : ";
					  cin >> cls;
					  cls = toupper(cls);
					  if (cls == 'C')
						  system("cls");
					  else
						  break;
		}
			break;

		case '7': // Output file Case
		{
					  ofstream stu_o;

					  stu_o.open("Result Card.dat", ios::binary | ios::app);
					  if (!stu_o)
						  cout << "\t\t Can't Create the File ." << endl;
					  else
					  {
						  stu_o.write((char*)&n, sizeof(int));
						  stu_o.write((char*)s, n* sizeof(student));
						  cout << "\t\t The DataBase is Saved on Harddisk . " << endl;
					  }
					  stu_o.close();

					  cout << "\nPress 'c' to clear screen : ";
					  cin >> cls;
					  cls = toupper(cls);
					  if (cls == 'C')
						  system("cls");
					  else
						  break;
		}
			break;

		case '8': // Input file Case
		{
					  ifstream stu_input;

					  stu_input.open("Result Card.dat", ios::binary);
					  if (!stu_input)
						  cout << "\t\t Can't open the File ." << endl;
					  else
					  {
						  stu_input.read((char*)&n, sizeof(int));
						  stu_input.read((char*)s, n* sizeof(student));
						  cout << "\t\t The DataBase has been Restored . " << endl;
					  }

					  stu_input.close();

					  cout << "\nPress 'c' to clear screen : ";
					  cin >> cls;
					  cls = toupper(cls);
					  if (cls == 'C')
						  system("cls");
					  else
						  break;
		}
			break;

		case 'X': // Exit 
			exit(-1);
			break;

		default:
			cout << "\n\t\t\tINVILAD PLEASE TRY AGAIN\n";
		}


	} while (TRUE);
}

/*int searchReg(student ss[], int sinfo, int nn)
{
	int	pos = -1;

	for (int i = 0; i < nn; i++)
	{
		if (ss[i].regCh() == sinfo)
		{
			pos = i;
			break;
		}
		else
			pos = -1;
	}

	return pos;
}*/