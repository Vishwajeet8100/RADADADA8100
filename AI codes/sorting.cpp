#include<iostream>
#include<vector>
using namespace std;
void selection_sort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < size  ; j++)
        {
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
            
        }
        if (min_index != i)
            {
                swap(arr[i], arr[min_index]);
            }
            
            cout<<"After "<<i<<" iteration : ";        
        for (int k = 0; k < size; k++)
            {
                cout<<arr[k]<<" ";

            }
            cout<<endl;
    }
    
}

int main()
{
    int arr[] = {4,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    selection_sort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}