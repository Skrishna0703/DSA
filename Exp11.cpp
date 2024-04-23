#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Student {
public:
 int rollNo;
 char name[50];
 char div;
 char address[100];
 void accept() {
 cout << "\nEnter Roll Number: ";
 cin >> rollNo;
 cout << "Enter Name: ";
 cin >> name;
 cout << "Enter Division: ";
 cin >> div;
 cout << "Enter Address: ";
 cin >> address;
 }
 void display() {
 cout << "\n\t" << rollNo << "\t" << name << "\t" << div << "\t" << address;
 }
 int getRollNo() const {
 return rollNo;
 }
 bool operator==(const char* otherName) const {
 return strcmp(name, otherName) == 0;
 }
};
int main() {
 int choice;
 int rec;
 char name[50];
 Student student;
 fstream file;
 do {
 cout << "\n>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<\n";
 cout << "1. Insert and overwrite\n";
 cout << "2. Show\n";
 cout << "3. Search & Edit (number)\n";
 cout << "4. Search & Edit (name)\n";
 cout << "5. Delete a Student Record\n";
 cout << "6. Exit\n";
 cout << "Enter the Choice: ";
 cin >> choice;
 switch (choice) {
 case 1: {
 file.open("StuRecord.txt", ios::out | ios::binary);
 if (!file) {
 cout << "Error opening file!" << endl;
 return 1;
 }
 while (true) {
 student.accept();
 file.write(reinterpret_cast<char*>(&student), sizeof(Student));
 cout << "Do you want to enter more records? (1.Yes/2.No): ";
 int ch;
 cin >> ch;
 if (ch != 1)
 break;
 }
 file.close();
 break;
 }
 case 2: {
 file.open("StuRecord.txt", ios::in | ios::binary);
 if (!file) {
 cout << "Error opening file!" << endl;
 return 1;
 }
 cout << "\n\tRoll No.\tName\tDivision\tAddress";
 while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
 student.display();
 }
 file.close();
 break;
 }
 case 3: {
 cout << "\nEnter the roll number you want to find: ";
 cin >> rec;
 file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
 if (!file) {
 cout << "Error opening file!" << endl;
 return 1;
 }
 while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
 if (rec == student.getRollNo()) {
 cout << "\nRecord found";
 int pos = file.tellg();
 file.seekp(pos - sizeof(Student));
 student.accept();
 file.write(reinterpret_cast<char*>(&student), sizeof(Student));
 break;
 }
 }
 file.close();
 if (file.eof())
 cout << "\nRecord not found";
 break;
 }
 case 4: {
 cout << "\nEnter the name you want to find and edit: ";
 cin >> name;
 file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
 if (!file) {
 cout << "Error opening file!" << endl;
 return 1;
 }
 while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
 if (student == name) {
 cout << "\nName found";
 int pos = file.tellg();
 file.seekp(pos - sizeof(Student));
 student.accept();
 file.write(reinterpret_cast<char*>(&student), sizeof(Student));
 break;
 }
 }
 file.close();
 if (file.eof())
 cout << "\nName not found";
 break;
 }
 case 5: {
 int roll;
 cout << "\nPlease Enter the Roll No. of Student Whose Info You Want to Delete: ";
 cin >> roll;
 file.open("StuRecord.txt", ios::in | ios::binary);
 if (!file) {
 cout << "Error opening file!" << endl;
 return 1;
 }
 ofstream temp("temp.txt", ios::out | ios::binary);
 while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
 if (student.getRollNo() != roll) {
 temp.write(reinterpret_cast<char*>(&student), sizeof(Student));
 }
 }
 file.close();
 temp.close();
 remove("StuRecord.txt");
 rename("temp.txt", "StuRecord.txt");
 cout << "The record with the roll no. " << roll << " has been deleted" << endl;
 break;
 }
 case 6:
 cout << "\nThank you" << endl;
 break;
 default:
 cout << "\nInvalid choice. Please enter a valid option." << endl;
 }
 } while (choice != 6);
 return 0;
}
