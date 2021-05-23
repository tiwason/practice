#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>


using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

int findLargest(vector<int>& vec, int k)
{
    int largest = 0;
    for(int i=0; i<k; i++)
    {
        if(vec[i] > vec[largest])
            largest = i;
    }
    return largest;
}

void findKSmallest(vector<int>& vec, int k)
{
    
    for (int i=k; i<vec.size(); i++)
    {
        int largest = findLargest(vec, k); //index of largest
        if(vec[i] < vec[largest])
        {
            int temp = vec[largest];
            for(int j=largest+1; j<k; j++) //shift elements to left
                vec[j-1] = vec[j];
            
            vec[k-1] = vec[i];
            vec[i] = temp;
        }
    }

     for(int i=0; i<k; i++)
        cout << vec[i] <<" ";
    cout<<endl;

}


int main()
{
    vector<int> vec = {4, 2, 6, 1, 5}; //4 
    //vector<int> vec = {4, 12, 16, 21, 25}; //3

    findKSmallest(vec, 4);
    return 0;
}