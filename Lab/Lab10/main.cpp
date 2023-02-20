#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void PrintArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void swap(int &p1, int &p2){
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(vector<int> &arr, int root, int length){// to adjust the array

    int left = 2*root, right = 2*root + 1, largest;//index
    //cout<<"left= "<<left<<", right= "<<right<<endl;
    if (left <= length && arr[left] > arr[root])
        largest = left;
    else
        largest = root;

    if (right <= length && arr[right] > arr[largest])
        largest = right;

    if (largest != root) {                         // if root aren't the largest in the subtree
        swap(arr[largest], arr[root]);             
        MaxHeapify(arr, largest, length);
    }
}

void HeapSort(vector<int> &arr){

    arr.insert(arr.begin(), 0);// set arr[0] = null

    for (int i = (int)arr.size()/2; i >= 1 ; i--) { // to build Max Heap
        //cout<<"i= "<<i<<endl;
        MaxHeapify(arr, i, (int)arr.size() - 1); // length-1 cause heap store data from arr[1]
    }

    int size = (int)arr.size() -1;// size become the original length
    for (int i = (int)arr.size() -1; i >= 2; i--) {
        swap(arr[1], arr[i]);
        size--;
        MaxHeapify(arr, 1, size);
    }

    arr.erase(arr.begin());                         // delete arr[0]
}


void swap(int *a, int *b){//pass by adress
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partation(vector<int>& arr, int front, int end){
    int pivot = arr[end]; // set pivot as the last num
    int index = front-1; // index is the rightmost num before(less than) pivot, set as -1 cause maybe all num greater than pivot
    for(int i = front; i < end ; i++){
        if(arr[i] < pivot){
            index++;
            swap(&arr[index], &arr[i]);
        }
    }
    index++;
    swap(&arr[index], &arr[end]);// swap the index we find with pivot(arr[end])

    return index;//return pivot's index
}

void QuickSort(vector<int>& arr, int front, int end){ //& ref
    if(front < end){
        int pivot_index = Partation(arr, front, end);
        QuickSort(arr, front, pivot_index-1);
        QuickSort(arr, pivot_index+1, end);
    }
}


int main() {
    fstream file;
    file.open("input2.txt");

    int times = 0;
    file >> times;

    for (int t = 0; t < times; t++) {
        int size = 0;
        file >> size;

        vector<int> array1;
        vector<int> array2;

        for (int i = 0; i < size; i++) {
            int x;
            file >> x;
            array1.push_back(x);
            array2.push_back(x);
        }

        HeapSort(array1);
        cout << "Max Heap Sort : ";
        PrintArray(array1);

        QuickSort(array2,0,size-1);
        cout << "Quick Sort : ";
        PrintArray(array2);

        cout<<endl;
    }
    system("pause");
    return 0;
}