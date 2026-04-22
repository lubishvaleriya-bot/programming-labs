#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// виводимо
void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

vector<int> generateRandom(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    return a;
}

vector<int> generateSorted(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    return a;
}

vector<int> generateReverse(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = n - i;
    return a;
}

//Insertion sort
void insertionSort(vector<int>& a, bool show = false) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        if (show) printArray(a);
    }
}

// Quicksort
int partition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int r, bool show = false) {
    if (l < r) {
        int p = partition(a, l, r);
        if (show) printArray(a);
        quickSort(a, l, p - 1, show);
        quickSort(a, p + 1, r, show);
    }
}

//Merge sort 
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r, bool show = false) {
    if (l >= r) return;

    int m = (l + r) / 2;
    mergeSort(a, l, m, show);
    mergeSort(a, m + 1, r, show);
    merge(a, l, m, r);

    if (show) printArray(a);
}

//комбінування
void hybridSort(vector<int>& a, int l, int r, int threshold) {
    if (r - l + 1 <= threshold) {
        vector<int> temp(a.begin() + l, a.begin() + r + 1);
        insertionSort(temp);
        for (int i = 0; i < temp.size(); i++)
            a[l + i] = temp[i];
        return;
    }

    if (l < r) {
        int p = partition(a, l, r);
        hybridSort(a, l, p - 1, threshold);
        hybridSort(a, p + 1, r, threshold);
    }
}

// Benchmark 
double testTime(void (*sortFunc)(vector<int>&), vector<int> a) {
    clock_t start = clock();
    sortFunc(a);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// обгортки
void insertionWrapper(vector<int>& a) { insertionSort(a); }
void quickWrapper(vector<int>& a) { quickSort(a, 0, a.size() - 1); }
void mergeWrapper(vector<int>& a) { mergeSort(a, 0, a.size() - 1); }

int main() {
    srand(time(0));

    int n;
    cout << "Введи розмір масиву: ";
    cin >> n;

    vector<int> a = generateRandom(n);

    cout << "\nПочатковий масив:\n";
    printArray(a);

    // Демонстрація
    cout << "\nInsertion sort:\n";
    vector<int> b = a;
    insertionSort(b, true);

    cout << "\nQuick sort:\n";
    b = a;
    quickSort(b, 0, b.size() - 1, true);

    cout << "\nMerge sort:\n";
    b = a;
    mergeSort(b, 0, b.size() - 1, true);

    // Benchmark
    cout << "\n--- Benchmark --\n";
    vector<int> test = generateRandom(5000);

    cout << "Insertion: " << testTime(insertionWrapper, test) << " сек\n";
    cout << "Quick: " << testTime(quickWrapper, test) << " сек\n";
    cout << "Merge: " << testTime(mergeWrapper, test) << " сек\n";

    //комбінований
    int threshold = 10;
    vector<int> c = test;

    clock_t start = clock();
    hybridSort(c, 0, c.size() - 1, threshold);
    clock_t end = clock();

    cout << "Hybrid (threshold=" << threshold << "): "
         << (double)(end - start) / CLOCKS_PER_SEC << " сек\n";

    return 0;
}