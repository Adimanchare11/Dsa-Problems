//MaxProduct
#include <iostream>

int MaxProduct(int arr[], int length) {
    if (length == 0)
        return 0;

    int maxProduct = arr[0];
    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] < 0) {
            int temp = maxEndingHere;
            maxEndingHere = minEndingHere;
            minEndingHere = temp;
        }

        maxEndingHere = (arr[i] > maxEndingHere * arr[i]) ? arr[i] : maxEndingHere * arr[i];
        minEndingHere = (arr[i] < minEndingHere * arr[i]) ? arr[i] : minEndingHere * arr[i];

        maxProduct = (maxProduct > maxEndingHere) ? maxProduct : maxEndingHere;
    }

    return maxProduct;
}

int main() {
    
    int length ;
    std:: cout<<"Enter length: ";
    std:: cin>> length;
    int *arr = new int[length];

    std:: cout<<"Enter elements: ";
    for(int i=0; i<length; i++){
        std:: cin>>arr[i];
    }

    int result = MaxProduct(arr, length);
    std::cout << result << std::endl;

    return 0;
}