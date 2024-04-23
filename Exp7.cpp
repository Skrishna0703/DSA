#include<iostream>
#include<iomanip>
using namespace std;
const int MAX = 30;
class node {
 node* next;
 string city;
 double timeCost; // Changed to double to represent time in hours
public:
 friend class graph;
 node() {
 next = NULL;
 city = "";
 timeCost = -1.0;
 }
 node(string city, double weight) {
 next = NULL;
 this->city = city;
 timeCost = weight;
 }
};
class graph {
 node* head[MAX];
 int n;
public:
 graph(int num) {
 n = num;
 for (int i = 0; i < n; i++)
 head[i] = NULL;
 }
 void insert(string city1, string city2, double time); // Changed int to double for time
 void insertUndirected(string city1, string city2, double time); // Changed int to double for time
 void readdata(int gType);
 int getindex(string s1);
 void outFlights();
 void inFlights();
};
void graph::inFlights() {
 int count[MAX];
 for (int i = 0; i < n; i++)
 count[i] = 0;
 cout << "======In degree=====\n";
 for (int i = 0; i < n; i++) {
 cout << "\n" << setw(8) << "Source" << setw(8) << "Destin." << setw(8) << "Time";
 for (int j = 0; j < n; j++) {
 node* p = head[j];
 while (p != NULL) {
 if (p->city == head[i]->city) {
 count[i] = count[i] + 1;
 cout << "\n" << setw(8) << head[j]->city << setw(8) << head[i]->city << setw(8) << p->timeCost;
 }
 p = p->next;
 }
 }
 cout << "\nFlights to " << head[i]->city << " = " << count[i] << endl;
 cout << "================\n";
 }
}
void graph::outFlights() {
 for (int i = 0; i < n; i++) {
 node* p = head[i];
 int count = 0;
 cout << "\n" << setw(8) << "Source" << setw(8) << "Destin." << setw(8) << "Time";
 if (p == NULL) {
 cout << "\nNo Flights from " << head[i]->city;
 }
 else {
 while (p != NULL) {
 cout << "\n" << setw(8) << head[i]->city << setw(8) << p->city << setw(8) << p->timeCost;
 count++;
 p = p->next;
 }
 }
 cout << "\nNo. of flights: " << count << endl;
 cout << "-------------\n";
 }
}
int graph::getindex(string s1) {
 for (int i = 0; i < n; i++) {
 if (head[i]->city == s1)
 return i;
 }
 return -1;
}
void graph::insert(string city1, string city2, double time) { // Changed int to double for time
 node* source;
 node* dest = new node(city2, time);
 int ind = getindex(city1); //for getting head nodes index in array
 if (head[ind] == NULL)
 head[ind] = dest;
 else {
 source = head[ind];
 while (source->next != NULL)
 source = source->next;
 source->next = dest;
 }
}
void graph::insertUndirected(string city1, string city2, double time)
{ // Changed int to double for 
time;
 insert(city1, city2, time);
 insert(city2, city1, time);
}
void graph::readdata(int gType) {
 string city1, city2;
 double fcost; // Changed to double to represent time in hours
 int flight;
 cout << "\nEnter City details:\n";
 for (int i = 0; i < n; i++) {
 head[i] = new node;
 cout << "Enter city " << i + 1 << ": ";
 cin >> head[i]->city;
 }
 cout << "\nEnter Number of flights to insert: ";
 cin >> flight;
 if (gType == 1) {
 for (int i = 0; i < flight; i++) {
 cout << "\nEnter source: ";
 cin >> city1;
 cout << "Enter destination: ";
 cin >> city2;
 cout << "Enter time (in hours): ";
 cin >> fcost;
 insert(city1, city2, fcost);
 }
 }
 else {
 for (int i = 0; i < flight; i++) {
 cout << "\nEnter source: ";
 cin >> city1;
 cout << "Enter destination: ";
 cin >> city2;
 cout << "Enter time (in hours): ";
 cin >> fcost;
 insertUndirected(city1, city2, fcost);
 }
 }
}
int main() {
 int number, choice, graphType;
 cout << "Enter Flight data insertion type (0 for Undirected): ";
 cin >> graphType;
 cout << "\nEnter number of airport stations: ";
 cin >> number;
 graph g1(number);
 g1.readdata(graphType);
 do {
 cout << "-----Menu-----"
 << "\n1. Incoming Flights (in degree)"
 << "\n2. Outgoing flights (out degree)"
 << "\n3. Exit"
 << "\nEnter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << endl;
 g1.inFlights();
 break;
 case 2:
 g1.outFlights();
 break;
 case 3:
 break;
 default:
 cout << "\nWrong choice";
 }
 } while (choice != 3);
 return 0;
}