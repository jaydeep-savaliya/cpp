#include <bits/stdc++.h>
#include <vector>
using namespace std;
int countOnes(bool arr[], int n)
{
	int ans;
	int low = 0, high = n - 1;
	while (low <= high) { 
		int mid = (low + high) / 2;
		if (arr[mid] < 1)
			high = mid - 1;
		else if (arr[mid] > 1)
			low = mid + 1;
		else
		{
			if (mid == n - 1 || arr[mid + 1] != 1)
				return mid + 1;
			else
				low = mid + 1;
		}
	}
}

int main()
{
	bool arr[] = { 1, 1, 1, 1, 0, 0, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Count of 1's in given array is "
		<< countOnes(arr, n);
	return 0;
}
