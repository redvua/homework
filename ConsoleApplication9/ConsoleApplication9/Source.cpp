#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int s = n % 100;
	cout << n - (n % 1000 * 1000) << endl;
	return 0;
}