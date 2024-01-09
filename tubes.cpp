#include <iostream>
#include "tubes.h"

//parent
void createListParent(List_Parent &LP){
    first(LP) = NULL;
}

address_Parent createElmtParent(infotype_P XP){
    address_Parent P = new ElmtList_Parent;

    info(P) = XP;
    relasi(P) = NULL;
    next(P) = NULL;

    return P;
}

bool IsEmptyParent(List_Parent LP){
    if (first(LP) == NULL){
        return true;
    }else {
        return false;
    }
}

void insertFirstParent(List_Parent &LP, address_Parent P){
    if (IsEmptyParent(LP)){
        first(LP) = P;
    }else {
        next(P) = first(LP);
        first(LP) = P;
    }
}

void inserLastParent(List_Parent &LP, address_Parent P){
    if (IsEmptyParent(LP)){
        first(LP) = P;
    }else {
        address_Parent Q = first(LP);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

address_Parent findParent(string NamaBarang, List_Parent &LP){
    address_Parent P = first(LP);

    while (P != NULL){
        if (info(P).Namabarang == NamaBarang){
            return P;
        }
        P = next(P);
    }
}

void RemoveParent(string Namabarang, List_Parent &LP){

    if(first(LP) == NULL){
        cout<<"tidak ada Barang"<<endl;
    }else{
        if(next(first(LP)) == NULL){
            first(LP) = NULL;
        }else{
            address_Parent temp1 = first(LP);
            address_Parent temp2 = first(LP);
            while(temp1 != NULL){
                if(info(temp1).Namabarang == Namabarang){
                    next(temp2) = next(temp1);
                    break;
                }else{
                    temp2 = temp1;
                    temp1 = next(temp1);
                }
            }
        }
    }
}


void PrintDataParent(List_Parent LP){
    address_Parent P = first(LP);

    while (P != NULL){
        cout << "Nama Barang    : " << info(P).Namabarang << endl;
        cout << "ID Barang      : " << info(P).IdBarang << endl;
        cout << "Harga Sewa     : " << info(P).HargaBarang << endl;
        cout << " " << endl;

        P = next(P);
    }
}


//CHILD
void createListChild(List_Child &LC){
    first(LC) = NULL;
}

bool isEmptyChild(List_Child LC){
    if (first(LC) == NULL){
        return true;
    }else {
        return false;
    }
}

address_Child createElmtChild(infotype_C XC){
    address_Child C = new ElmtList_Child;
    info(C) = XC;
    next(C) = NULL;

    return C;
}

void insertLastChild(List_Child &LC, address_Child C){
    if (isEmptyChild(LC)){
        first(LC) = C;
    }else {
        address_Child Q = first(LC);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = C;
    }
}

address_Child findChild(string NamaPenyewa, List_Child &LC){
    address_Child C = first(LC);

    while (C != NULL){
        if (info(C).namaPenyewa == NamaPenyewa){
            return C;
        }
        C = next(C);
    }
    return NULL;
}

void RemoveChild(string NamaPenyewa, List_Child &LC){
    if(first(LC) == NULL){
        cout<<"tidak ada Barang"<<endl;
    }else{
        if(next(first(LC)) == NULL){
            first(LC) = NULL;
        }else{
            address_Child temp1 = first(LC);
            address_Child temp2 = first(LC);
            while(temp1 != NULL){
                if(info(temp1).namaPenyewa == NamaPenyewa){
                    next(temp2) = next(temp1);
                    break;
                }else{
                    temp2 = temp1;
                    temp1 = next(temp1);
                }
            }
        }
    }
}


void PrintDataChild(List_Child LC){
     address_Child C = first(LC);

    while (C != NULL){
        cout << "Nama Penyewa              : " << info(C).namaPenyewa << endl;
        cout << "Alamat Penyewa            : " << info(C).alamatPenyewa << endl;
        cout << "Barang Yang Disewa        : " << info(C).namaBarang << endl;

        C = next(C);
    }
}

address_Relasi createElmtRelasi(address_Child XC){
    address_Relasi R = new ElmtRelasi;
    info(R) = XC;
    next(R) = NULL;

    return R;
}

void insertChildToParent(List_Parent &LP, List_Child &LC, string NamaBarang, string NamaPenyewa){
    address_Parent P = findParent(NamaBarang, LP);
    address_Child C = findChild(NamaPenyewa, LC);
    if (P == NULL && C == NULL){
        cout << "Data Tidak Ditemukan" << endl;
    }else{
        address_Relasi R = createElmtRelasi(C);
        if (relasi(P) == NULL){
            relasi(P) = R;
        }else {
            address_Relasi Q = relasi(P);
            while (next(Q) != NULL){
                Q = next(Q);
            }
            next(Q) = R;
        }
    }
}
void ShowAllRelasi(List_Parent LP){
    if (first(LP) == NULL){
        cout << "data kosong/ tidak terhubung ke relasi" << endl;
    }else {
        address_Parent P = first(LP);
        while (P != NULL){
            cout << "Nama Barang    : " << info(P).Namabarang << endl;
            cout << "ID Barang      : " << info(P).IdBarang << endl;
            cout << "Harga Sewa     : " << info(P).HargaBarang << endl;

            address_Relasi R = relasi(P);
            while (R != NULL){
                cout << "Nama Penyewa              : " << info(info(R)).namaPenyewa << endl;
                cout << "Alamat Penyewa            : " << info(info(R)).alamatPenyewa << endl;
                cout << "Barang Yang Disewa        : " << info(info(R)).namaBarang << endl;
                R = next(R);
            }
            P = next(P);

        }
    }
}

int selectMenu(){
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "|                                MENU                                 |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "| 1.  Insert Barang                                                   |" << endl;
    cout << "| 2.  Show all data parent                                            |" << endl;
    cout << "| 3.  Mencari data parent tertentu                                    |" << endl;
    cout << "| 4.  Hapus data parent dan relasinya                                 |" << endl;
    cout << "| 5.  Insert data child                                               |" << endl;
    cout << "| 6.  Show all data child                                             |" << endl;
    cout << "| 7.  Mencari data child tertentu                                     |" << endl;
    cout << "| 8.  Menghubungkan data Penyewa ke Daftar Barang                     |" << endl;
    cout << "| 9.  Tampilkan seluruh data dan relasinya                            |" << endl;
    cout << "| 10. Mencari data child pada parent tertentu                         |" << endl;
    cout << "| 11. Menghitung jumlah data child dari parent tertentu               |" << endl;
    cout << "| 0.  Exit                                                            |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;

    int menu = 0;
    cout << "Pilihan : ";
    cin >> menu;

    return menu;
}

void Pilihan_1(List_Parent &LP){
    int input;
    string x;
    infotype_P info;
    address_Parent P;

    cout << "Masukann Jumlah Barang Yang Akan Ditambahkan : ";
    cin >> input;
    for (int i = 0; i < input; i++){
        cout << "Masukan Nama Barang    : ";
        cin >> info.Namabarang;
        cout << "Id Barang              : ";
        cin >> info.IdBarang;
        cout << "Harga Sewa             : ";
        cin >> info.HargaBarang;
        cout << " " << endl;

        cout << "insert depan/belakang [d][b]" ;
        cin >> x;
        if (x == "d" || x == "D"){
            P = createElmtParent(info);
            insertFirstParent(LP, P);
        }else if (x == "b" || x == "B"){
            P = createElmtParent(info);
            inserLastParent(LP, P);
        }

    }
}

void Pilihan_2(List_Parent LP){
address_Parent P = first(LP);

    if (P == NULL){
        cout << "------------------" << endl;
        cout << "LIST PARENT KOSONG" << endl;
        cout << "------------------" << endl;
        cout << " " << endl;
    }else {
        PrintDataParent(LP);
    }
}

void Pilihan_3(List_Parent LP){
    int input;
    string IdBarang;
    infotype_P info;
    address_Parent P;

    cout<<"Masukan id barang yang ingin dicari :";
    cin>> IdBarang;

    P = findParent(IdBarang, LP);
    if (P != NULL){
        cout << "Nama Barang    : " << info(P).Namabarang << endl;
        cout << "ID Barang      : " << info(P).IdBarang << endl;
        cout << "Harga Sewa     : " << info(P).HargaBarang << endl;
        cout << " " << endl;
    }else{
        cout<<"Maaf, Barang tidak ditemukan"<<endl;
    }


}
void Pilihan_4(List_Parent &LP){
    infotype_P infoP;

    cout << "Masukan Nama Barang : ";
    cin >> infoP.Namabarang;
    if (findParent(infoP.Namabarang, LP) != NULL){
        RemoveParent(infoP.Namabarang, LP);
    }else {
        cout << "Barang tidak ditemukan" << endl;
    }
}


void Pilihan_5(List_Child &LC, List_Parent &LP){
    infotype_C infoC;

    cout << "Nama Penyewa : ";
    cin >> infoC.namaPenyewa;
    cout << "Alamat Penyewa: ";
    cin >> infoC.alamatPenyewa;
    cout << "Nama Barang : ";
    cin >> infoC.namaBarang;
    cout << "Jumlah Barang : ";
    cin >> infoC.JumlahBarang;

   address_Parent P = findParent(infoC.namaBarang, LP);

    if (P != NULL){
        address_Child C = createElmtChild(infoC);
        insertLastChild(LC, C);
        cout << "Berhasil Ditambahkan" << endl ;
    }else {
        cout << "Barang Tidak Tersedia" << endl;
    }
}

void Pilihan_6(List_Child LC, List_Parent LP){
    address_Child C = first(LC);

    if (C == NULL){
        cout << "-----------" << endl;
        cout << "LIST KOSONG" << endl;
        cout << "-----------" << endl;
    }else {
        PrintDataChild(LC);
    }
}

void Pilihan_7(List_Child LC){
    string NamaPenyewa;
    address_Child C;

    PrintDataChild(LC);
    cout << "Masukan Nama Penyewa : ";
    cin >> NamaPenyewa;
    cout << " " << endl;
    C = findChild(NamaPenyewa, LC);

    if (C == NULL){
        cout << "Tidak Ada Penyewa" << endl;
        cout << " " << endl;
    }else {
        cout << "Nama Penyewa              : " << info(C).namaPenyewa << endl;
        cout << "Alamat Penyewa            : " << info(C).alamatPenyewa << endl;
        cout << "Barang Yang Disewa        : " << info(C).namaBarang << endl;
        cout << " " << endl;
    }
}

void Pilihan_8(List_Parent &LP, List_Child &LC){
    string NamaBarang, NamaPenyewa;
    infotype_C infoC;
    infotype_P infoP;

    cout << "Nama Barang : ";
    cin >> NamaBarang;
    cout << "Nama Penyewa : ";
    cin >> NamaPenyewa;

    infoP.Namabarang = NamaBarang;
    infoC.namaPenyewa = NamaPenyewa;
    insertChildToParent(LP, LC, infoP.Namabarang, infoC.namaPenyewa);
}

void Pilihan_9(List_Parent LP){
    ShowAllRelasi(LP);
}

void Pilihan_10(List_Parent LP, address_Parent P, address_Relasi){
    infotype_P infoP;
    cout << "Masukaan Nama Barang : ";
    cin >> infoP.Namabarang;

    P = first(LP);
    address_Relasi R = relasi(P);
    while (R != NULL){
        cout << "Nama Penyewa              : " << info(info(R)).namaPenyewa << endl;
        cout << "Alamat Penyewa            : " << info(info(R)).alamatPenyewa << endl;
        cout << "Barang Yang Disewa        : " << info(info(R)).namaBarang << endl;
        R = next(R);
    }
}

void Pilihan_11(List_Parent LP, string NamaBarang){
    cout << "Masukan Nama Barang : ";
    cin >> NamaBarang;
    address_Parent P = findParent(NamaBarang, LP);
    int jumlah = 0;
    if(P != NULL){
        address_Relasi temp;
        temp = relasi(P);
        while(temp != NULL){
            jumlah++;
            temp = next(temp);
        }
    }else{
        cout<<"tidak ada barang"<<endl;
    }
    cout<<jumlah<<endl;
}
