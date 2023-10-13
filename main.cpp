/*
Mārtiņš Putnis, mp13031

C18. Dotas divas (zema līmeņa) simbolu virknes  a un b (sastāv no cipariem),
kas reprezentē divus veselus pozitīvus skaitļus. Izveidot funkciju,
kas izveido trešo simbolu virkni c, kas reprezentē skaitli un ir simbolu
virkņu a un b reprezentēto skaitļu reizinājums. Algoritms jārealizē tā, lai tiešā veidā
(ar operāciju *) reizināti tiktu ne lielāki kā viencipara skaitļi
(ieteicams pēc principa, kā to dara uz papīra). 
Funkcijai jāspēj apstrādāt simbolu virknes līdz garumam 30 ieskaitot.
*/
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
    int count = 0;
    for (int i = 0; i < arrSizeSmall; ++i)
    {
        // Ja simbols nav cipars, tad partrauc konvertaciju
        if (int(a[i]) < 48 or int(a[i]) > 57) 
            break; 
        A[i] = int(a[i]) - 48;
        count++;
    }
    return count;
}
//Funkcija int masiva izdrukai
void printArray( int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0 or a[i] > 9) break; // Ja simbols nav cipars, tad partrauc izdruku
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int ok = 1;
    do{
        //Lietotaja izveletie masivi  
        char a[arrSizeSmall];
        cout << "Ievadiet skaitlu virkni a, max 30 cipari: \n";
        cin >> a;
        char b[arrSizeSmall];
        cout << "Ievadiet skaitlu virkni b, max 30 cipari: \n";
        cin >> b;

        //Masivu konvertacija
        int A[arrSizeSmall], B[arrSizeSmall];
        int arrSize_A = convertCharToIntArray(a, A, arrSizeSmall);
        int arrSize_B = convertCharToIntArray(b, B, arrSizeSmall);
        cout << "masivs a, ka int:\n";
        printArray(A, arrSize_A);
        cout << "masivs b, ka int:\n";
        printArray(B, arrSize_B);

        //Masivu aizpilditas dalas noteiksana( masiva realais izmers)
        cout << "Masiva a izmers: " << arrSize_A << endl;
        cout << "Masiva b izmers: " << arrSize_B << endl;

        //Masivu reizinasana
        int arrSize_C = arrSize_A + arrSize_B;
        int *C = new int[arrSize_C];
        //Rezultata masiva aizpildisana( lai nebutu kadu nejausu vertibu)
        for( int i = 0; i < arrSize_C; ++i)
            C[i] = 0;
        //Reizinasana
        for( int i = arrSize_B-1; i >= 0; i--)
        {
            for( int j = arrSize_A-1; j >= 0; j--)
            {
                int k = i + j + 1;
                C[k] += A[j] * B[i];
                    // cout << "Pre if C[" << k <<"]: " << C[k]<< endl;
                    // cout << "Pre if C[" << k-1 <<"]: " << C[k-1]<< endl;
                //Parbauda vai reizinajums ir lielaks par 10, ja ir tad sadala pa diviem indeksiem
                if( C[k] > 9)
                {
                    C[k-1] += C[k] / 10;
                    C[k] -= (C[k]-C[k] % 10);
                }
                    // cout << "After if C[" << k <<"]: " << C[k] << endl;
                    // cout << "After if C[" << k-1 <<"]: " << C[k-1] << endl;

            }  
        }
        cout << "Masivu reizinajums C:\n";
        printArray(C, arrSize_C);
        delete[] C;

        cout << "\n\nVai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    }while(ok == 1);    
    
    

    
    return 0;
}
