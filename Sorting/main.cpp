#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
using namespace std;
template<class Comparable>
void insertionSort(vector<Comparable> &a);
template <class Comparable>
void quicksort(vector<Comparable> & a);
template <class Comparable>
void quicksort(vector<Comparable> & a, int left, int right);
template <class Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right);
int r = 0;
int cutoff = 3;
int main()
{
    time_t start,end;
    double tc;
    char m;
    int ar[100], n = 0;
    do {
        system("cls");
        cout << "======================================\n";
        cout << "\t Assignment 4 Sorting\n";
        cout << "\t1.Create Input\n";
        cout << "\t2.Enter Cutoff\n";
        cout << "\t3.Insertion Sort\n";
        cout << "\t4.Quick Sort\n";
        cout << "\t5.Exit\n";
        cout << "======================================\n";
        cout << "Enter Menu : ";
        cin >> m;
        
        if (m == '1') {
            system("cls");
            cout << "\n\t***Create Input***\n";
            cout << "How many Data Size : ";
            cin >> n;
        }
        
        vector<int> d(n);
        
        switch (m)
        {
                
            case '1':
                cout << "\nEnter Data\n";
                for (int i = 0; i < n; i++) {
                    
                    cout << "Input Data [" << i + 1 << "] : ";
                    cin >> ar[i];
                }
                break;
                
            case '2':
                system("cls");
                cout << "\n\t***Enter Cutoff***\n";
                cout << "Enter Cutoff : ";
                cin >> cutoff;
                break;
            case '3':
                start=clock();
                cout << "\t Print DATA \n";
                for(int i=0;i<n;i++)
                {
                    d[i] = ar[i];
                }
                insertionSort(d);
                end=clock();
                tc=(difftime(end,start)/CLOCKS_PER_SEC);
                cout <<"Time Efficiency is "<<tc<<endl;
                break;
                
            case '4':
    
                system("cls");
                cout << "\n\t***Print***\n";
                cout << "Original : ";
                start=clock();
                for (int i = 0; i < n; i++) {
                    d[i] = ar[i];
                    cout << d[i] << " ";
                }
                cout << endl;
                quicksort(d, 0, n - 1);
                system("pause");
                r = 0;
                end=clock();
                tc=(difftime(end,start)/CLOCKS_PER_SEC);
                cout <<"Time Efficiency is "<<tc<<endl;
                break;
                
            case '5':
                cout << "Exit Program! \n";
                break;
                
            default:
                cout << "Don't have this menu, Please try again.\n";
                break;
        }
        
    } while (m != '5');
}
template<class Comparable>

void insertionSort(vector<Comparable> &a, int left, int right) {
    
    for (int p = left; p <= right; p++) {
        
        Comparable tmp = a[p];
        
        int j;
        for (j = p; j>0 && tmp<a[j - 1]; j--) {
            a[j] = a[j - 1];
            
        }
        a[j] = tmp;
    }
}
template <class Comparable>
void quicksort(vector<Comparable> & a) {
    
    quicksort(a, 0, a.size() - 1);
    
}
template <class Comparable>
void quicksort(vector<Comparable> & a, int left, int right) {
    
    if (left + cutoff <= right) {
        
        Comparable pivot = median3(a, left, right);
        
        int i = left, j = right - 1;
        
        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            
            if (i<j)
                swap(a[i], a[j]);
            else
                break;
            
        }
        swap(a[i], a[right - 1]);
        cout << "Round[" << (++r) << "] ";
        for (int i = 0; i<a.size(); i++) {
            
            cout << a[i] << " ";
        }
        cout << " | Pivot = " << pivot << endl;
        quicksort(a, left, i - 1);
        quicksort(a, i + 1, right);
        
    }
    else
    {
        insertionSort(a, left, right);
        cout << "Round[" << (++r) << "] ";
        
        for (int i = 0; i<a.size(); i++) {
            
            cout << a[i] << " ";
        }
        cout << " | No Pivot " << endl;
    }
}

template <class Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right) {
    int center = (left + right) / 2;
    
    if (a[center] < a[left]) {
        swap(a[left], a[center]);
    }
    if (a[right] < a[left]) {
        swap(a[right], a[left]);
    }
    if (a[right] < a[center]) {
        swap(a[right], a[center]);
    }
    swap(a[center], a[right - 1]);
    
    return a[right - 1];
}
template <class Comparable>
void insertionSort(vector<Comparable> &a)
{
    cout << "Original\t";
    
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "P. Moved\n";
    cout << setfill('-') << setw(50) << "-\n";
    for (int p = 1; p < a.size(); p++)
    {
        int count = 0;
        Comparable tmp = a[p];
        
        int j;
        for ( j = p; j > 0 && tmp < a[j - 1]; j--)
        {
            a[j] = a[j - 1];
            count++;
        }
        a[j] = tmp;
        cout << "After p = " << p << "\t";
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << count << endl;
    }
    system("pause");
}
