#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// LIMAS
float hitung_volume_limas(float sisi, float tinggi) {
    return (sisi * sisi * tinggi) / 3;
}

float hitung_luas_limas(float sisi, float tinggi) {
    float tinggi_sisi_tegak = sqrt((sisi / 2) * (sisi / 2) + tinggi * tinggi);
    float luas_sisi_tegak = (sisi * tinggi_sisi_tegak) / 2;
    return (sisi * sisi + 4 * luas_sisi_tegak);
}

// PRISMA
float hitung_luas_segitiga(float alas, float tinggi_segitiga) {
    return (alas * tinggi_segitiga) / 2;
}

float hitung_volume_prisma(float alas, float tinggi_prisma, float tinggi_segitiga) {
    float luas_alas = hitung_luas_segitiga(alas, tinggi_segitiga);
    return luas_alas * tinggi_prisma;
}

float hitung_luas_permukaan_prisma(float alas, float tinggi_segitiga, float tinggi_prisma) {
    float luas_alas = hitung_luas_segitiga(alas, tinggi_segitiga);
    float keliling_alas = 3 * alas;
    return (2 * luas_alas) + (keliling_alas * tinggi_prisma);
}

// validasi input
float validasi_input(const char* prompt) {
    float value;
    char input[100];  
    char *endptr;

    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL) {  
           
            input[strcspn(input, "\n")] = 0;

            // Konversi string ke float 
            value = strtof(input, &endptr);
            
            if (endptr != input && *endptr == '\0') {  
                return value;
            } else {
                printf("Input tidak valid. Masukkan angka!\n");
            }
        }
    }
}

// validasi pilihan
int validasi_pilihan() {
    int pilihan;
    char input[100];
    char *endptr;

    while (1) {
        printf("Masukkan pilihan (1 atau 2): ");
        
        
        if (fgets(input, sizeof(input), stdin) != NULL) {
            
          
            input[strcspn(input, "\n")] = 0;

            // Konversi string ke integer
            pilihan = strtol(input, &endptr, 10);

            if (endptr != input && *endptr == '\0' && (pilihan == 1 || pilihan == 2)) {
                return pilihan;
            } else {
                printf("Pilihan tidak valid! Masukkan angka 1 atau 2.\n");
            }
        }
    }
}

void clear_screen() {
    system("cls");
}

int main() {
    int pilihan;
    float sisi, tinggi, alas, tinggi_segitiga, tinggi_prisma, volume, luas_permukaan;
    char ulang;

    do {
   
        clear_screen();

       
        printf("|=====================================|\n");
        printf("|   Program Perhitungan Bangun Ruang  |\n");
        printf("|=====================================|\n");
        
        // Pilihan
        printf("Pilih bangun ruang yang ingin dihitung:\n");
        printf("  1. Limas Segi Empat\n");
        printf("  2. Prisma Segitiga\n");
        printf("-------------------------------------\n");
        
        // validasi pilihan
        pilihan = validasi_pilihan();

       
        clear_screen();

        if (pilihan == 1) {
            // LIMAS
            printf("|=====================================|\n");
            printf("|    Perhitungan Limas Segi Empat     |\n");
            printf("|=====================================|\n");
            
            // Input valid 
            sisi = validasi_input("Masukkan sisi alas limas: ");
            tinggi = validasi_input("Masukkan tinggi limas: ");

            volume = hitung_volume_limas(sisi, tinggi);
            luas_permukaan = hitung_luas_limas(sisi, tinggi);

            printf("\nHasil Perhitungan:\n");
            printf("-----------------------------------------------\n");
            printf("Volume limas segi empat: %.2f\n", volume);
            printf("Luas permukaan limas segi empat: %.2f\n", luas_permukaan);
            printf("------------------------------------------------\n");

        } else if (pilihan == 2) {
            // PRISMA
            printf("|=====================================|\n");
            printf("|     Perhitungan Prisma Segitiga     |\n");
            printf("|=====================================|\n");

            // Input valid 
            alas = validasi_input("Masukkan alas segitiga: ");
            tinggi_segitiga = validasi_input("Masukkan tinggi segitiga: ");
            tinggi_prisma = validasi_input("Masukkan tinggi prisma: ");

            volume = hitung_volume_prisma(alas, tinggi_prisma, tinggi_segitiga);
            luas_permukaan = hitung_luas_permukaan_prisma(alas, tinggi_segitiga, tinggi_prisma);

            printf("\nHasil Perhitungan:\n");
            printf("----------------------------------------\n");
            printf("Volume prisma segitiga: %.2f\n", volume);
            printf("Luas permukaan prisma segitiga: %.2f\n", luas_permukaan);
            printf("----------------------------------------\n");
        }

        // Tanya pengulangan
        printf("\nApakah Anda ingin melakukan perhitungan lagi? (Y untuk Ya, N untuk Tidak): ");
        scanf(" %c", &ulang);  
    
    } while (ulang == 'y' || ulang == 'Y');

    printf("|=====================================|\n");
    printf("|            Program Selesai          |\n");
    printf("|=====================================|\n");

    return 0;
}
