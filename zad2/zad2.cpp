using namespace std;

#include <iostream>
#include <chrono>
#include <thread>

void copyarray(char array1[20][40], char array2[20][40]) {


    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 40; j++)
        {

            array2[i][j] = array1[i][j];

        }


    }





}
void nacrtaj(char graf[20][40]) {



    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 40; j++)
        {

            cout << graf[i][j];

        }
        cout << endl;

    }




}

void loadpolje(char graf[20][40]) {


    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 40; j++)
        {

            graf[i][j] = '-';

        }

    }

    for (int i = 0; i < 10; i++)
    {
        graf[i][15] = '*';
    }



}
void wait() {
    std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(100));

}

int main()
{

    char graf[20][40];


    loadpolje(graf);
    char ogpolje[20][40];

    int a1, a2, b1, b2;
    cout << "A redak: ";
    cin >> a1;
    cout << "A stupac: ";
    cin >> a2;
    cout << "B redak: ";
    cin >> b1;
    cout << "B stupac: ";
    cin >> b2;
    graf[a1 - 1][a2 - 1] = 'A';
    graf[b1 - 1][b2 - 1] = 'B';
    copyarray(graf, ogpolje);
    nacrtaj(graf);




    if (a2 > b2) {

        while (a2 != b2) {
            system("cls");



            while (graf[a1 - 1][a2 - 2] == '*') {
                a1++;
                graf[a1 - 1][a2 - 1] = 'x';
                nacrtaj(graf);
                copyarray(ogpolje, graf);
                wait();
                system("cls");
            }



            a2--;
            graf[a1 - 1][a2 - 1] = 'x';
            nacrtaj(graf);
            copyarray(ogpolje, graf);
            wait();





        }



    }
    else {

        while (a2 != b2) {

            system("cls");

            while (graf[a1 - 1][a2] == '*') {
                a1++;
                graf[a1 - 1][a2 - 1] = 'x';
                nacrtaj(graf);
                copyarray(ogpolje, graf);
                wait();
                system("cls");
            }


            a2++;
            graf[a1 - 1][a2 - 1] = 'x';
            nacrtaj(graf);
            copyarray(ogpolje, graf);
            wait();





        }






    }







    if (a1 > b1) {

        while (a1 != b1) {

            system("cls");

            a1--;
            graf[a1 - 1][a2 - 1] = 'x';
            nacrtaj(graf);
            copyarray(ogpolje, graf);
            wait();




        }



    }
    else {

        while (a1 != b1) {
            system("cls");
            a1++;
            graf[a1 - 1][a2 - 1] = 'x';
            nacrtaj(graf);
            copyarray(ogpolje, graf);
            wait();





        }






    }


    system("PAUSE");
    return 0;
}
