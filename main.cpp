#include <iostream>
#include "tubes.h"

using namespace std;

List_Parent Parent;
List_Child Child;

int main(){
    address_Parent P;
    address_Child C;
    address_Relasi R;
    infotype_P infoP;
    infotype_C infoC;


    createListParent(Parent);
    createListChild(Child);



    int Pilihan = selectMenu();
    while (Pilihan != 0){
        switch(Pilihan){
        case 1:
            Pilihan_1(Parent);
            break;
        case 2:
            Pilihan_2(Parent);
            break;
        case 3:
            Pilihan_3(Parent);
            break;
        case 4:
            Pilihan_4(Parent);
            break;
        case 5:
            Pilihan_5(Child, Parent);
            break;
        case 6:
            Pilihan_6(Child, Parent);
            break;
        case 7:
            Pilihan_7(Child);
            break;
        case 8:
            Pilihan_8(Parent, Child);
            break;
        case 9:
            Pilihan_9(Parent);
            break;
        case 10:
            Pilihan_10(Parent, P, R);
            break;
        case 11:
            Pilihan_11(Parent, infoP.Namabarang);
            break;
        }
        Pilihan = selectMenu();
    }
    return 0;
}
