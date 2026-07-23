#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global Variables

const int MAX = 100;

string donorNames[MAX];
double donorAmounts[MAX];

string studentNames[MAX];
string studentDepartments[MAX];
int studentSemesters[MAX];
double requiredAmounts[MAX];

int donorCount = 0;
int studentCount = 0;

double availableFund = 500000.0;

// Function Prototypes

void login();
void displayMenu();
void requestAssistance();
void donateFunds();
void viewFundStatus();
void searchStudent();
void searchDonor();

// Login Function

void login()
{
    string username;
    string phone;
    string department;
    int semester;

    cout << "=============================================\n";
    cout << " Student Fee Assistance Management System\n";
    cout << "=============================================\n\n";

    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Semester: ";
    cin >> semester;
    cin.ignore();

    cout << "\nWelcome, " << username << "!\n\n";
}

// Display Menu

void displayMenu()
{
    cout << "\n=====================================\n";
    cout << "           MAIN MENU\n";
    cout << "=====================================\n";
    cout << "1. Request Fee Assistance\n";
    cout << "2. Donate Funds\n";
    cout << "3. View Fund Status\n";
    cout << "4. Search Student\n";
    cout << "5. Search Donor\n";
    cout << "6. Exit\n";
    cout << "Choose Option: ";
}

// Request Assistance

void requestAssistance()
{
    if(studentCount >= MAX)
    {
        cout << "\nStudent record is full.\n";
        return;
    }

    string name, department;
    int semester;
    double amount;

    cout << "\nStudent Name: ";
    getline(cin, name);

    cout << "Department: ";
    getline(cin, department);

    cout << "Semester: ";
    cin >> semester;

    cout << "Required Fee Amount: ";
    cin >> amount;
    cin.ignore();

    studentNames[studentCount] = name;
    studentDepartments[studentCount] = department;
    studentSemesters[studentCount] = semester;
    requiredAmounts[studentCount] = amount;

    studentCount++;

    if(amount <= availableFund)
    {
        availableFund -= amount;

        cout << "\nRequest Approved!\n";
        cout << "Amount Granted: Rs. " << amount << endl;
    }
    else
    {
        cout << "\nRequest Recorded.\n";
        cout << "Currently insufficient funds.\n";
    }
}

// Donate Funds

void donateFunds()
{
    if(donorCount >= MAX)
    {
        cout << "\nDonor list is full.\n";
        return;
    }

    string name;
    double amount;

    cout << "\nDonor Name: ";
    getline(cin, name);

    cout << "Donation Amount: ";
    cin >> amount;
    cin.ignore();

    if(amount <= 0)
    {
        cout << "Invalid donation amount.\n";
        return;
    }

    donorNames[donorCount] = name;
    donorAmounts[donorCount] = amount;

    donorCount++;

    availableFund += amount;

    cout << "\nThank you for your generous donation!\n";
}

// View Fund Status

void viewFundStatus()
{
    cout << fixed << setprecision(2);

    cout << "\n=====================================\n";
    cout << "Available Fund: Rs. " << availableFund << endl;

    cout << "\n------------ DONORS -----------------\n";

    if(donorCount == 0)
    {
        cout << "No donations yet.\n";
    }

    for(int i=0;i<donorCount;i++)
    {
        cout << i+1 << ". " << donorNames[i] << "  Rs. " << donorAmounts[i] << endl;
    }

    cout << "\n------ STUDENT REQUESTS ------------\n";

    if(studentCount==0)
    {
        cout << "No requests submitted.\n";
    }

    for(int i=0;i<studentCount;i++)
    {
        cout << i+1 << ". "  << studentNames[i]  << " | "  << studentDepartments[i]  << " | Semester "  << studentSemesters[i]  << " | Needed Rs. "
          << requiredAmounts[i]
             << endl;
    }
}

// Search Student

void searchStudent()
{
    string name;

    cout << "\nEnter Student Name: ";
    getline(cin,name);

    bool found=false;

    for(int i=0;i<studentCount;i++)
    {
        if(studentNames[i]==name)
        {
            cout<<"\nRecord Found\n";
            cout<<"Name: "<<studentNames[i]<<endl;
            cout<<"Department: "<<studentDepartments[i]<<endl;
            cout<<"Semester: "<<studentSemesters[i]<<endl;
            cout<<"Required Amount: Rs. "<<requiredAmounts[i]<<endl;
            found=true;
            break;
        }
    }

    if(!found)
        cout<<"Student not found.\n";
}

// Search Donor

void searchDonor()
{
    string name;

    cout<<"\nEnter Donor Name: ";
    getline(cin,name);

    bool found=false;

    for(int i=0;i<donorCount;i++)
    {
        if(donorNames[i]==name)
        {
            cout<<"\nDonor Found\n";
            cout<<"Name: "<<donorNames[i]<<endl;
            cout<<"Donation: Rs. "<<donorAmounts[i]<<endl;
            found=true;
            break;
        }
    }

    if(!found)
        cout<<"Donor not found.\n";
}

// Main Function

int main()
{
    login();

    int choice;

    do
    {
        displayMenu();
        cin>>choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                requestAssistance();
                break;

            case 2:
                donateFunds();
                break;

            case 3:
                viewFundStatus();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                searchDonor();
                break;

            case 6:
                cout<<"\nThank you for using the system.\n";
                break;

            default:
                cout<<"\nInvalid Choice.\n";
        }

    }while(choice!=6);

    return 0;
}

