#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,len,sum=0,max ,min;
	cout << "Enter size of array : ";
	cin >> n;
	int arr[n];
	cout << "Enter elements of array : ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	len = sizeof(arr)/sizeof(arr[0]);
	cout << "The Number of elements in the array is : "<< len <<endl;
	max=arr[0];
	min = arr[0];
	for(int i=0; i<n; i++){
		sum+= arr[i];
		if (arr[i]>max)
			max = arr[i];
		if(arr[i]<min)
			min = arr[i];
	}

	int temp;
	int avg = sum / len;
	cout << "Average Value : "<< avg << endl << "Maximum Value : "<<max << endl << "Minimum Value : "<< min<< endl;

	for (int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}
	}
	cout << "Sorted array in ascending order is: ";
	for(int i=0; i<n; i++){
		cout << arr[i];
	}
	cout<<endl;

	for (int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]<arr[j+1]){
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout << "Sorted array in descending order is: ";
	for(int i=0; i<n; i++){
		cout << arr[i];
	}
	cout<<endl;
}
