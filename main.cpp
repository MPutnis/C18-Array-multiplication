/*
A*B=C
max A[30] * B[30] = C[59]
    678
   *543
-------
   2034
  2712
 3390
-------
 368154
*/
#include <iostream>
using namespace std;
const int arrSizeSmall = 31;
const int arrSizeBig = 60;

// Funkcija simbolu masiva parveidosanai par skaitlu masivu, atgriež masīva garumu
int convertCharToIntArray( char a[], int A[], int n)
{
    int i = 0;
    for (; i < arrSizeSmall; ++i)
    {
        if (a[i] < 48 or a[i] > 57) break; // Ja simbols nav cipars, tad partrauc konvertaciju
        A[i] = int(a[i]) - 48;
    }
    return i;
}
//Funkcija dazadu datu tipu masivu izdrukai
void printArray( int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0 or a[i] > 9) break; // Ja simbols nav cipars, tad partrauc izdruku
        cout << a[i];
    }
    cout << endl;
}
//Funkcija masivu aizpilditas dalas noteiksana( masiva realais izmers)
int arraySize( int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        {
           if (a[i] >= 0 and a[i] <= 9) count++;
           else break;
        }
    return count;
}

int main()
{
    int A[arrSizeSmall], B[arrSizeSmall], C[arrSizeBig];
    //Lietotaja izveletie masivi
    char a[arrSizeSmall];
    cout << "Ievadiet skaitlu virkni a, max 30 cipari: \n";
    cin >> a;
    char b[arrSizeSmall];
    cout << "Ievadiet skaitlu virkni b, max 30 cipari: \n";
    cin >> b;
    //Masivu konvertacija
//TO DO: ja masiva sakuma ir 0, tad jaizdara ta lai to ignoretu
    int arrSize_A = convertCharToIntArray(a, A, arrSizeSmall);
    convertCharToIntArray(b, B, arrSizeSmall);
    cout << "masivs a, ka int:\n";
    printArray(A, arrSizeSmall);
    cout << "masivs b, ka int:\n";
    printArray(B, arrSizeSmall);
    //Masivu aizpilditas dalas noteiksana( masiva realais izmers)
    cout << "Masiva a izmers: " << arrSize_A << endl;
    cout << "Masiva b izmers: " << arraySize(B, arrSizeSmall) << endl;
    //Masivu reizinasana
    
    
    
    


    return 0;
}
