#include <iostream>
#include <random>

using namespace std;
// Ⅿ∑∈

// ∑(N-1)(i=0) 1 = N ∈ O(N)
// N - 1 - 0 + 1
bool static sequentialSearchInc(int* arr, int N, int value)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == value)
            return true;
    }

    return false;
}

// Ⅿ(N) = 1 + Ⅿ(N-1)
// M(N-1) = 1 + M(N-2)
// Ⅿ(0) = 1
// Ⅿ(N) = i + Ⅿ(N-i) = N + 1 ∈ O(N+1)
bool static sequentialSearchRec(int* arr, int N, int value)
{
    if (N <= 0)
    {
        return false;
    }
    if (arr[N - 1] == value)
    {
        return true;
    }

    return sequentialSearchRec(arr, N - 1, value);
}

bool static isSortedAsc(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}

// ∑(i=0)(N-2) ∑(j=0)(N-2) 1 = ∑(i=0)(N-2) (N-1) = (N-1) * ∑(i=0)(N-2) 1 = (N-1) * (N-1) = N^2 - 2N + 1 ∈ O(N^2)
// N - 2 - 0 + 1 = N - 1
void static bubbleSort(int* arr, int N)
{
    bool swapped = false;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }
    }
    if (!swapped) return;
}

// ∑(i=0)(N-2) ∑(j=0)(N-i-2) 1 = ∑(i=0)(N-2) (N-i-1) = ∑(i=0)(N-2) (N-1) - ∑(i=0)(N-2) i = (N-1)^2 - ((N-1)*(N-2) / 2) = N^2 -2N + 1 - ((N^2 + ...) / 2) = N^2 - (N^2)/2 =~ N^2 ∈ O(N^2)
// N - i - 2 - 0 + 1 = N - i - 1
// N*(max+min) / 2
void static bubbleSort2(int* arr, int N)
{
    bool swapped = false;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }
    }
    if (!swapped) return;
}

// Умножение матриц N*M & R*S, должно быть M=R, размер итоговой будет N*S
// ∑(i=0)(N-1) ∑(j=0)(S-1) ∑(k=0)(R-1) 1 = ∑(i=0(N-1) ∑(j=0)(S-1) R = R * ∑(i=0)(N-1) S = R * S * N
// Худший вариант N*N N*N N*N, тогда R * S * N = N^3 (kubicka slozitost)

void static selectionSort(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void static printArray(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int static kthBiggest(int* arr, int N, int k)
{
    selectionSort(arr, N);
    return arr[N - k];
}

int static biggestProduct(int* arr, int N)
{
    //selectionSort(arr, N);
    //int temp1 = arr[N - 1] * arr[N - 2];
    //int temp2 = arr[0] * arr[1];
    //return (temp1 > temp2) ? temp1 : temp2;

    int max1 = max(arr[0], arr[1]);
    int max2 = min(arr[0], arr[1]);

    int min1 = min(arr[0], arr[1]);
    int min2 = max(arr[0], arr[1]);

    for (int i = 2; i < N; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else
        {
            if (arr[i] > max2)
            {
                max2 = arr[i];
            }
        }
        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else
        {
            if (arr[i] < min2)
            {
                min2 = arr[i];
            }
        }
    }

    int product1 = max1 * max2;
    int product2 = min1 * min2;
    return (product1 > product2) ? product1 : product2;
}

void static insertionSort(int* arr, int N)
{
    for (int i = 1; i < N; i++)
    {
        int tmp = arr[i];
        int k = i - 1;
        while (k >= 0 && arr[k] > tmp)
        {
            arr[k+1] = arr[k];
            k--;
        }

        arr[k + 1] = tmp;
    }
}

bool binarySearchIter(int* arr, int N, int value)
{
    int l = 0;
    int r = N - 1;

    while (l <= r)
    {
        int M = (l + r) / 2;

        if (value == arr[M])
            return true;

        if (value < arr[M])
            r = M - 1;

        if (value > arr[M])
            l = M + 1;
    }

    return false;
}

bool binarySearchRec(int* arr, int l, int r, int value)
{
    if (!(l > r))
        return false;

    int M = (l + r) / 2;

    if (value < arr[M])
        return binarySearchRec(arr, l, M - 1, value);

    if (value > arr[M])
        return binarySearchRec(arr, M + 1, r, value);

    return true;
}

int partition(int* arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(int* arr, int l, int r)
{
    if (l >= r)
        return;

    int pivotIndex = partition(arr, l, r);

    quickSort(arr, l, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, r);
}

int main()
{
    srand(time(nullptr));

    int N = 100000000;
    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = (rand() % N) - (N / 2);
        //arr[i] = i;
    }

    quickSort(arr, 0, N - 1);

    cout << binarySearchRec(arr, 0, N - 1, 5) << endl;

    //printArray(arr, N);

    //printArray(arr, N);
    //cout << sequentialSearchRec(arr, N, 10) << endl;

    /*time_t startTime = time(nullptr);
    //bubbleSort(arr, N);
    time_t endTime = time(nullptr);

    cout << "Elapsed time: " << endTime - startTime << " s" << endl;

    cout << "Sorted: " << (isSortedAsc(arr, N) ? "yup" : "nah") << endl;

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    //printArray(arr, N);
    //cout << sequentialSearchRec(arr, N, 10) << endl;

    startTime = time(nullptr);
    selectionSort(arr, N);
    endTime = time(nullptr);

    cout << "Elapsed time: " << endTime - startTime << " s" << endl;

    cout << "Sorted: " << (isSortedAsc(arr, N) ? "yup" : "nah") << endl;*/

    return 0;
}