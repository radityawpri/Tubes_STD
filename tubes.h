#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define relasi(P) P->relasi
#define first(L) L.first


using namespace std;

struct Data_Parent{
    int HargaBarang;
    string Namabarang, IdBarang;
};

struct Data_Child{
    int JumlahBarang;
    string namaPenyewa, namaBarang, alamatPenyewa;
};

typedef struct Data_Parent infotype_P;
typedef struct Data_Child infotype_C;

typedef struct ElmtList_Parent *address_Parent;

typedef struct ElmtList_Child *address_Child;
typedef struct ElmtRelasi *address_Relasi;

//struct for parent

struct ElmtList_Parent{
    infotype_P info;
    address_Relasi relasi;
    address_Parent next;

};

struct ElmtList_Child{
    infotype_C info;
    address_Child next;
};

struct ElmtRelasi{
    address_Child info;
    address_Relasi next;
};

struct List_Parent{
    address_Parent first;
};

struct List_Child{
    address_Child first;
};


//list for parent
void createListParent(List_Parent &LP);
bool IsEmptyParent(List_Parent LP);
address_Parent createElmtParent(infotype_P XP);
void insertFirstParent(List_Parent &LP, address_Parent P);
void inserLastParent(List_Parent &LP, address_Parent P);
address_Parent findParent(string NamaBarang, List_Parent &LP);
void RemoveParent(string Namabarang, List_Parent &LP);
void PrintDataParent(List_Parent LP);


//list for child
void createListChild(List_Child &LC);
bool isEmptyChild(List_Child LC);
address_Child createElmtChild(infotype_C XC);
void insertLastChild(List_Child &LC, address_Child C);
void deleteFirstChild(List_Child &LC, address_Child C);
void deleteAfterChild(List_Child &LC, address_Child C);
void deletelastChild(List_Child &LC, address_Child C);
address_Child findChild(string NamaPenyewa, List_Child &LC);
void RemoveChild(string NamaPenyewa, List_Child &LC);
void PrintDataChild(List_Child LC);

void HargaSewa(List_Parent LP, List_Child LC);

// relasi
address_Relasi createElmtRelasi(address_Child XC);
void insertLastRelasi(List_Parent &LP, List_Child &LC, address_Relasi R);
void insertChildToParent(List_Parent &LP, List_Child &LC, string NamaBarang, string NamaPenyewa);
void ShowAllRelasi(List_Parent LP);

// MENU
int selectMenu();
void Pilihan_1(List_Parent &LP);
void Pilihan_2(List_Parent LP);
void Pilihan_3(List_Parent LP);
void Pilihan_4(List_Parent &LP);
void Pilihan_5(List_Child &LC, List_Parent &LP);
void Pilihan_6(List_Child LC, List_Parent LP);
void Pilihan_7(List_Child LC);
void Pilihan_8(List_Parent &LP, List_Child &LC);
void Pilihan_9(List_Parent LP);
void Pilihan_10(List_Parent LP, address_Parent P, address_Relasi);
void Pilihan_11(List_Parent LP, string NamaBarang);

#endif // TUBES_H_INCLUDED
