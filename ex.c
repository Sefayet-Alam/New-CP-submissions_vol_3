#include <stdio.h>
int BinarySearch(int arr[], int search, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (search > arr[mid])
        {
            low = mid + 1;
        }
        else if (search < arr[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int j = 0; j < Q; j++)
    {
        int search;
        scanf("%d", &search);
        int ans = BinarySearch(arr, search, 0, N-1);
        printf("%d\n", ans);
        
    }
    return 0;
}