#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main(){

	// Providing a seed value
	// srand((unsigned) time(NULL));

	// Loop to get 5 random numbers
	for(int i=1; i<=5000; i++){
		
		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		int random = 1000 + (rand() % 1001);

		// Print the random number
		cout<<random<<",";
	}

	return 1;
}