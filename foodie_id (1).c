#include <stdio.h>

int main() {
    char nama[50];
    char drink[50];
    int umur;

    // 1. Ambil minimal 3 input dari terminal
    printf("Masukkan nama: ");
    scanf("%s", nama);

    printf("Masukkan minuman favorit: ");
    scanf("%s", drink);

    printf("Masukkan umur: ");
    scanf("%d", &umur);

    // Cari huruf terakhir nama secara manual (tanpa string.h)
    int i = 0;
    while (nama[i] != '\0') {
        i++;
    }
    char hurufTerakhir = nama[i - 1];

    char inisialNama  = nama[0];
    char inisialDrink = drink[0];

    // Ubah inisial minuman jadi versi besar & kecil secara manual (tanpa ctype.h)
    char drinkBesar, drinkKecil;
    if (inisialDrink >= 'a' && inisialDrink <= 'z') {
        drinkKecil = inisialDrink;
        drinkBesar = inisialDrink - 32;
    } else {
        drinkBesar = inisialDrink;
        drinkKecil = inisialDrink + 32;
    }

    // Ubah huruf terakhir nama jadi huruf besar
    char akhiranBesar;
    if (hurufTerakhir >= 'a' && hurufTerakhir <= 'z') {
        akhiranBesar = hurufTerakhir - 32;
    } else {
        akhiranBesar = hurufTerakhir;
    }

    int jumlahAscii   = drinkBesar + drinkKecil;   // ASCII huruf besar + huruf kecil
    int selisihUmur   = 1000 - umur;

    char bagian1[20];
    char bagian2[20];
    char id[64];

    // Operasi konkatenasi 1: inisial nama + selisih umur + umur
    sprintf(bagian1, "%c%d%d", inisialNama, selisihUmur, umur);

    // Operasi konkatenasi 2: jumlah ASCII drink + huruf akhir nama
    sprintf(bagian2, "%d%c", jumlahAscii, akhiranBesar);

    // Operasi konkatenasi 3: gabungkan bagian1 dan bagian2 jadi ID akhir
    sprintf(id, "%s%s", bagian1, bagian2);

    printf("\n-----------------------------------\n");
    printf("| ID             : %s\n", id);
    printf("| Name           : %s\n", nama);
    printf("| Favorite Drink : %s\n", drink);
    printf("-----------------------------------\n");

    return 0;
}
