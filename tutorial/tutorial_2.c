#include <stdio.h>

int max(int arr[], int n) {
    int max_num, i;
    max_num = arr[0];
    for (i=0; i<n; i++) {
        if (max_num <= arr[i]) {
            max_num = arr[i];
        }
    }
    return max_num;
}
            
int min(int arr[], int n) {
    int min_num, i;
    min_num = arr[0];
    for (i=0; i<n; i++) {
        if (min_num >= arr[i]) {
            min_num = arr[i];
        }
    }
    return min_num;
}

double mean(int arr[], int n) {
    int sum, i;
    sum = 0;
    for (i=0; i<n; i++) {
        sum += arr[i];
    }
    return (double)sum/n;
}

int main() {
    //variables
    int max_arr,min_arr;
    double mean_arr;

    //input
    int n,i,arr[100];
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    //calculation
    max_arr = max(arr, n);
    min_arr = min(arr, n);
    mean_arr = mean(arr, n);

    //output
    printf("Max: %d\n", max_arr);
    printf("Min: %d\n", min_arr);
    printf("Mean: %.2f\n", mean_arr);
        
    return 0;
}
