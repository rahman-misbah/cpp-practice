// to find uniqes, XOR operator is the best choice. The following properties of XOR are used
// a XOR 0 = a
// a XOR a = 0
//
// The question has pairs and a unique elements, perfect for XOR trick
#include <iostream>

int unique(int* arr, int size);
void printArray(int* arr, int size);

int main() {
    int arr[] = {1, 2, 1, 4, 7, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);
    std::cout << unique(arr, size) << std::endl;

    return 0;
}

int unique(int* arr, int size) {
    int n = 0;

    for(int i = 0; i < size; i++) n = n ^ arr[i];

    return n;
}

void printArray(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) std::cout << arr[i] << ", ";
    if(size > 0) std::cout << arr[size - 1] << std::endl;
}