#include <iostream>
using namespace std;

int main()
{
    //membuat isi dari try untuk pengujian eror
    try 
    {
        cout << "Selmat belajar dari prodi TI UMY" << endl;
        //thow 0.5 //melempaekan sebuah integer maka
        cout << "pernyataan tidak akan ditampilakn" << endl;
    }

    //kondisi jika throw yang bertipe data integer
    catch (int a)
    {
        cout << "Pengecualian akan di eksekusi" << endl;
    }

    //kondisi jika throw bertipe data selain integer
    catch (...)
    {
        cout << "default pengecualian diekseskusi" << endl;
    }
    return 0;

}