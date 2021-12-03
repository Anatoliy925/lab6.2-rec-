#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void initialization(int* n, const int length, const int low, const int high, int i);
void print(int* n, const int length, int i);
void castling(int* n, const int length, int i);

int main(){
    srand((unsigned) time(NULL));
    
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[2*n];
    initialization(a, 2*n , -10, 10, 0);
    print(a, 2*n, 0);
    castling(a, 2*n, 0);
    print(a, 2*n, 0);
    
    return 0;
}
void print(int* n, const int length, int i)
{
    cout << setw(4) << n[i];
    
    if(i < length - 1)
        print(n, length, i + 1);
    else
        cout << endl;
}
void initialization(int* n, const int length, const int low, const int high, int i)
{
    n[i] = low + rand() % (high - low + 1);
    if(i < length - 1)
        initialization(n, length, low, high, i+1);
}
void castling(int* n, const int length, int i)
{
    int tmp = n[i];
    n[i] = n[length/2 + i];
    n[length/2 + i] = tmp;
    if(i < length/2 - 1)
        castling(n, length, i + 1);
    
}
