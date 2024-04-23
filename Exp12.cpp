#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Employee {
private:
 int code;
 char name[20];
 float salary;
public:
 void read();
 void display();
 int getEmpCode() { return code; }
 int getSalary() { return salary; }
 void updateSalary(float s) { salary = s; }
};
void Employee::read() {
 cout << "Enter employee code: ";
 cin >> code;
 cout << "Enter name: ";
 cin.ignore();
 cin.getline(name, 20);
 cout << "Enter salary: ";
 cin >> salary;
}
void Employee::display() {
 cout << code << " " << name << "\t" << salary << endl;
}
fstream file;
void deleteExistingFile() {
 remove("EMPLOYEE.DAT");
}
void appendToFile() {
 Employee x;
 x.read();
 file.open("EMPLOYEE.DAT", ios::binary|ios::app);
 if (!file) {
 cout << "ERROR IN CREATING FILE\n";
 return;
 }
 file.write((char*)&x, sizeof(x));
 file.close();
 cout << "Record added successfully.\n";
}
void displayAll() {
 Employee x;
 file.open("EMPLOYEE.DAT", ios::binary|ios::in);
 if (!file) {
 cout << "ERROR IN OPENING FILE \n";
 return;
 }
 while (file.read((char*)&x, sizeof(x))) {
 if (x.getSalary() >= 100000 && x.getSalary() <= 400000)
 x.display();
 }
 file.close();
}
void searchForRecord() {
 Employee x;
 int c;
 int isFound = 0;
 cout << "Enter employee code: ";
 cin >> c;
 file.open("EMPLOYEE.DAT", ios::binary|ios::in);
 if (!file) {
 cout << "ERROR IN OPENING FILE \n";
 return;
 }
 while (file.read((char*)&x, sizeof(x))) {
 if (x.getEmpCode() == c) {
 cout << "RECORD FOUND\n";
 x.display();
 isFound = 1;
 break;
 }
 }
 if (isFound == 0) {
 cout << "Record not found!!!\n";
 }
 file.close();
}
int main() {
 char ch;
 deleteExistingFile();
 do {
 int n;
 cout << "ENTER CHOICE\n"
 << "1. ADD AN EMPLOYEE\n"
 << "2. DISPLAY\n"
 << "3. SEARCH\n";
 cout << "Make a choice: ";
 cin >> n;
 switch (n) {
 case 1:
 appendToFile();
 break;
 case 2:
 displayAll();
 break;
 case 3:
 searchForRecord();
 break;
 default:
 cout << "Invalid Choice\n";
 }
 cout << "Do you want to continue? (Y/N): ";
 cin >> ch;
 } while (ch == 'Y' || ch == 'y');
 return 0;
}
