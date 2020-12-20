#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr, int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

void commonElems(int arr1[], int arr2[], int arr3[], int size1, 
                    int size2, int size3)
{
    int i=0, j=0, k=0;
    vector<int> result;

    while (i<size1 && j<size2 && k<size3)
    { 
        if (arr1[i] == arr2[j] &&  arr1[i] == arr3[k])
        {
            result.push_back(arr1[i]);
            i++; j++; k++;
        }
        else if(arr1[i] < arr2[j] || arr1[i] <arr3[k])
            i++;
        else if(arr2[j] < arr1[i] || arr2[j] <arr3[k])
            j++;
        else 
            k++;
    }

    if(result.size())
        printArray(result, result.size());
    else
    {
        cout<<"No common elements found"<<endl;
    }
    
}

int main() 
{ 
    //int arr1[] = {1, 5, 10, 20, 40, 80};
    //int arr2[] = {6, 7, 20, 80, 100};
    //int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int arr1[] = {1, 5, 5};
    int arr2[] = {3, 4, 5, 5, 10};
    int arr3[] = {5, 5, 10, 20};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = sizeof(arr3)/sizeof(arr3[0]);

    commonElems(arr1, arr2, arr3, size1, size2, size3);
      
    return 0; 
} 
