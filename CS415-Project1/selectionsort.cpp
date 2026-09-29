#include "selectionsort.h"

void selectionSort(std::vector<int>& arr, long& comparisons){
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j)
        {
            comparisons++;

            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        std::swap(arr[i], arr[min_idx]);
    }
}
