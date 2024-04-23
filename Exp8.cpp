#include<iostream> 
#include<climits> // Include for INT_MAX
using namespace std; 
void con_obst(); 
void print(int, int);
float a[20], b[20], wt[20][20], c[20][20]; 
int r[20][20], n;
int main() {
 int i;
 cout << "\n****** PROGRAM FOR OBST ******\n";
 cout << "Enter the no. of nodes: ";
 cin >> n;
 cout << "Enter the probability for successful search:\n";
 for(i = 1; i <= n; i++) {
 cout << "p[" << i << "]: ";
 cin >> a[i];
 }
 cout << "Enter the probability for unsuccessful search:\n";
 for(i = 0; i <= n; i++) {
 cout << "q[" << i << "]: ";
 cin >> b[i];
 }
 con_obst();
 print(0, n);
 cout << endl;
 return 0;  }
void con_obst() {
 int i, j, k, l, min;
 for(i = 0; i < n; i++) {
 // Initialisation 
 c[i][i] = 0; 
 r[i][i] = 0; 
 wt[i][i] = b[i]; 
 }
 c[n][n] = 0;
 r[n][n] = 0;
 wt[n][n] = b[n];
 // for j - i = 1
 for(i = 0; i < n; i++) {
 r[i][i + 1] = i + 1;
 wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
 c[i][i + 1] = wt[i][i + 1];
 }
 // for j - i = 2, 3, 4 ,...., n
 for(int gap = 2; gap <= n; gap++) {
 for(int j = 0; j <= n - gap; j++) {
 int i = j + gap;
 wt[j][i] = wt[j][i - 1] + a[i] + b[i];
 c[j][i] = INT_MAX;
 for(int k = j + 1; k <= i; k++) {
 int temp = c[j][k - 1] + c[k][i];
 if(temp < c[j][i]) {
 c[j][i] = temp;
 r[j][i] = k;  }
 }
 c[j][i] += wt[j][i];
 }
 }
 cout << endl;
 cout << "\n\nOptimal BST is::";
 cout << "\nw[0][" << n << "] :: " << wt[0][n]; 
 cout << "\nc[0][" << n << "] :: " << c[0][n]; 
 cout << "\nr[0][" << n << "] :: " << r[0][n];
}
void print(int i, int j) {
 if (i >= j)
 return;
 if (r[i][j] != 0) {
 cout << "\nLeft child of " << r[i][j] << " :: " << r[i][r[i][j] - 1];
 cout << "\nRight child of " << r[i][j] << " :: " << r[r[i][j]][j];
 print(i, r[i][j] - 1);
 print(r[i][j], j);
 }
}

