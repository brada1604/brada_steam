// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
#include <ctype.h> 
// PEMANGGILAN LIBRARY - END

// PEMANGGILAN FILE HEADER
#include "antrian.h"
// PEMANGGILAN FILE HEADER - END

// DEKLARASI MODUL FUNCTION
int exit_aplikasi_antrian();		// MODUL UNTUK KELUAR APLIKASI
int salah_input_menu_antrian();		// MODUL UNTUK ERROR HANDLE APABILA SALAH INPUT PADA MENU
// DEKLARASI MODUL FUNCTION - END

// DEKLARASI VARIABEL GLOBAL
typedef struct antrian_cuci *address;
struct antrian_cuci{
	char nopol[15];
	int golongan;
	int durasi;
	address next;
};

antrian_cuci *tempat_cuci_1 = NULL;
antrian_cuci *tempat_cuci_2 = NULL;

int jumlah_durasi[2];
int pilihan_durasi[3] = {20,30,40};
int durasi_simulasi = 10;
int antrean;
int jumlah_kendaraan;
int jumlah_waktu;
// DEKLARASI VARIABEL GLOBAL - END


// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM
int main_antrian(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	int pil;

	system("cls");

	header_aplikasi();

	data_antrian(); // MENAMPILKAN ANTRIAN KENDARAAN YANG SEDANG DICUCI DAN SEDANG MENGANTRI

	// LIST MENU APLIKASI
	printf("\n");
	printf("\n");
	printf("|=================================================|\n");
	printf("|          Silahkan Pilih Menu Dibawah :          |\n");
	printf("|=================================================|\n");
	printf("| 1. Input Kendaraan                              |\n");
	printf("| 2. Keluarkan Kendaraan Dari Antrian             |\n");
	printf("| 3. Simulasi waktu (%d menit)                    |\n",durasi_simulasi);
	printf("| 4. Bantuan                                      |\n");
	printf("| 5. Selesai                                      |\n");
	printf("|                                                 |\n");
	printf("|=================================================|\n");
	printf("             Copyright 2022 - BradaSteam           \n");
    
    printf("\n\n");
    printf("Masukkan Pilihan : ");
	scanf("%d", &pilihan);

	// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
    switch (pilihan) { 
		case 1:
			input_kendaraan(); // MODUL UNTUK MENAMBAHKAN KENDARAAN YANG AKAN DI CUCI

			tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

			main_antrian(); // MODUL UTAMA
			
			break;

		case 2:
			cancel_kendaraan();

			main_antrian(); // MODUL UTAMA
			
			break;

		case 3:
			simulasi_waktu();

			main_antrian(); // MODUL UTAMA
			
			break;

		case 4:
			bantuan_aplikasi();
			
			tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

			main_antrian(); // MODUL UTAMA
			break;

		case 5:
			pil = cek_antrian();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

				main_antrian(); // MODUL UTAMA
				
				break;	
			}
			
			system("cls");
			printf("Hari ini, dengan total waktu kerja %d menit, didapat total kendaraan yang dicuci sebanyak %d mobil\n",jumlah_waktu,jumlah_kendaraan);
			printf("THANK YOU!!!\n\n");
			header_aplikasi();	
			break;

	 	default:
	 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
			break;
    }
}
// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM - END

void header_aplikasi(){
	printf("|===========================================================================================================|\n");
	printf("|                                                                                                           |\n");
	printf("|                                               BRADA STEAM                                                 |\n");
	printf("|                                                                                                           |\n");
	printf("|===========================================================================================================|\n");
}

void bantuan_aplikasi(){
	printf("\n");
	printf("BANTUAN PADA APLIKASI BRADA STEAM (PANDUAN) : \n");
	printf("- Tabel paling atas merupakan list antrian mobil beserta tempat pencuciannya\n");
	printf("- ketik '1' pada menu untuk input kendaraan\n");
	printf("- ketik '2' pada menu apabila ada kendaraan yang tidak jadi di cuci namun masih pada antrian\n");
	printf("- ketik '3' pada menu untuk melakukan pencucian selama 15 menit ke depan\n");
	printf("- ketik '4' pada menu untuk bantuan penggunaan aplikasi\n");
	printf("- ketik '5' pada menu untuk keluar dari aplikasi\n");
}

void footer_aplikasi(){
	printf("|===========================================================================================================|\n");
	printf("|                                         Copyright 2022 - BradaSteam                                       |\n");
	printf("|===========================================================================================================|\n");
}

void tombol_selanjutnya(){
	printf("\n");
	printf("Silahkan Tekan Apapun!");
	getch();
}

void data_antrian(){
	antrian_cuci *tempat1, *tempat2;

	printf("\nTempat Cuci Mobil 1 ");

	if(tempat_cuci_1 == NULL){
		printf("[ Kosong ]");
	}else{
		tempat1 = tempat_cuci_1;
		printf("[ %s, waktu sisa : %d menit] ",tempat1->nopol,tempat1->durasi);
		tempat1 = tempat1->next;
		while(tempat1 != NULL){
			printf("<-- %s (%d menit) ",tempat1->nopol,tempat1->durasi);
			tempat1 = tempat1->next;
		}		
	}
	
	printf("\nTempat Cuci Mobil 2 ");

	if(tempat_cuci_2 == NULL){
		printf("[ Kosong ]");
	}else{
		tempat2 = tempat_cuci_2;
		printf("[ %s, waktu sisa : %d menit] ",tempat2->nopol,tempat2->durasi);
		tempat2 = tempat2->next;
		while(tempat2 != NULL){
			printf("<-- %s (%d menit) ",tempat2->nopol,tempat2->durasi);
			tempat2 = tempat2->next;
		}		
	}
	
	printf("\n");
	printf("\n");
	printf("Total waktu  	: %d Menit\n",jumlah_waktu);
	printf("Total Kendaraan : %d Mobil\n",jumlah_kendaraan);
}

// FUNCTION UNTUK KELUAR DARI APLIKASI
int exit_aplikasi_antrian(){
	char pil_out;
	printf("Anda Yakin Akan Keluar Dari Aplikasi BradaSteam? (Y/N) : "); 
	pil_out = getche(); 

	system("cls");

    printf("\n"); 
    if ((pil_out == 'Y') || (pil_out == 'y'))
    {
    	// BYPASS TO EXIT APPLICATION
    	system("cls");
    	exit(1);
	}
	else{
		// REDIRECT TO antrian.cpp
		system("cls");
		main_antrian(); // FILE : program.h --> antrian.cpp
	}
}
// FUNCTION UNTUK KELUAR DARI APLIKASI - END

// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU
int salah_input_menu_antrian(){
	printf("Maaf Inputan Salah\n");
	printf("Silahkan Tekan Enter Untuk Kembali...");
	getchar();

	// REDIRECT TO antrian.cpp
	system("cls");
	main_antrian(); // FILE : program.h --> antrian.cpp
}
// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU - END

// FUNCTION UNTUK INPUT DATA KENDARAAN
void input_kendaraan(){
	char no_plat[15];
	int cek, jenis, tanda_tempat;

	jenis = jenis_kendaraan();
	if(jenis == 0){ // JIKA INPUTAN ADALAH 0 MAKA AKAN DI ARAHKAN KEMBALI KE MAIN, DAN DI ANGGAP MEMBATALKAN PROSES INPUT DATA
		main_antrian(); // MODUL UTAMA
	}

	do{
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan : ");
		scanf("%s", &no_plat);

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek != 0){ // JIKA CEK BERNILAI BUKAN 0 MAKA SUDAH ADA DATA KENDARAAN PADA TEMPAT CUCI ATAU PADA ANTRIAN
			printf("Nomor Polisi kendaraan sudah terdaftar! silahkan ganti.\n");
		}
	}while(cek != 0);

	pra_enqueue(no_plat, jenis); // PROSES SEBELUM DATA DI ENQUEUE KE LIST

	notifikasi_status(no_plat, jenis); // PROSES UNTUK MENGELUARKAN NOTIFIKASI
}
// FUNCTION UNTUK INPUT DATA KENDARAAN - END

void cancel_kendaraan(){
	int pil;
	char no_plat[15];
	int cek, tanda_tempat;

	pil = cek_antrian();
	if(pil == 0){
		printf("ERROR! antrian kosong.");
		tombol_selanjutnya();  // MODUL UNTUK ALTERNATIF BY PASS

		main_antrian(); // MODUL UTAMA
	}
	do{
		tanda_tempat = 0;
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan yang ingin dikeluarkan dari antrian : ");
		scanf("%s",&no_plat);

		if(no_plat[0]=='0'){  // Jika mengetik "0" Maka program akan di break
			break;
		}

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek == 0){
			printf("Tidak ada Kendaraan dengan Nomor Polisi tersebut. silahkan isi kembali.\n");
		}
	}while(cek == 0);

	keluarin(tanda_tempat,no_plat);
}

// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN
int cek_nopol(char no_plat[], int *tanda_tempat){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat1, *tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	int cek = 0;

	if(tempat1 != NULL){
		while(tempat1 != NULL){
			if(strcmp(no_plat,tempat1->nopol) == 0){
				cek++;
				*tanda_tempat = 1;	
			}
			tempat1 = tempat1->next;
		}	
	}

	if(tempat2 != NULL){
		while(tempat2 != NULL){
			if(strcmp(no_plat,tempat2->nopol) == 0){
				cek++;
				*tanda_tempat = 2;
			}
			tempat2 = tempat2->next;
		}	
	}
	
	return cek;
}
// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN - END

int jenis_kendaraan(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan_jenis_kendaraan;

	printf("|=====================================================================================================|\n");
	printf("|                                            JENIS KENDARAAN                                          |\n");
	printf("|=====================================================================================================|\n");
	printf("| NO | JENIS | KETERANGAN  |                            SAMPEL                             |  DURASI  |\n");
	printf("| 1. |   A   | Mobil Kecil | KIA Picanto, Daihatsu Ceria, Suzuki Karimun, Toyota Yaris dll | %d menit |\n",pilihan_durasi[0]);
	printf("| 2. |   B   | Minibus     | Toyota Avanza, Honda Freed, Suzuki Ertiga, dll                | %d menit |\n",pilihan_durasi[1]);
	printf("| 3. |   C   | Mobil Besar | Metromini, Truk, dll                                          | %d menit |\n",pilihan_durasi[2]);
	printf("|=====================================================================================================|\n");

	do{
		printf("Masukan Pilihan (1-3) : ");
		scanf("%d", &pilihan_jenis_kendaraan);

		if((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 3)){ // JIKA INPUTAN KURANG DARI 0 ATAU LEBIH DARI 3 MAKA KELUAR ALERT
			printf("Inputan Salah ! Pilihan diantara 1 - 3, silahkan input lagi.\n\n");
		}
	}while((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 3));

	return pilihan_jenis_kendaraan;
}

void keluarin(int tanda_tempat, char no_plat[]){
	antrian_cuci *tempat1,*tempat2; 
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;

	
	switch(tanda_tempat){
		case 1:
			keluar_kendaraan(no_plat,tempat1);
			break;
		case 2:
			keluar_kendaraan(no_plat,tempat2);
			break;	
	}
	tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS	
}

int cek_antrian(){
	int cek;

	cek = 0;

	if(tempat_cuci_1 != NULL){
		cek++;	
	}

	if(tempat_cuci_2 != NULL){
		cek++;
	}

	return cek;
}

int keluar_kendaraan(char no_plat[], antrian_cuci *tempat){
	antrian_cuci *freed;
	if(strcmp(no_plat,tempat->nopol) == 0){
		printf("\n");
		printf("Kendaraan yang sedang dicuci tidak bisa dikeluarkan! silahkan tunggu sampai selesai.\n");
	}else{
		while(strcmp(no_plat,tempat->next->nopol)!=0){
			tempat = tempat->next;
		}
		freed = tempat->next;
		tempat->next = tempat->next->next;
		free(freed);
	}
}

void simulasi_waktu(){
	if(tempat_cuci_1 != NULL){
		tempat_cuci_1->durasi -= durasi_simulasi;
	}
	if(tempat_cuci_2 != NULL){
		tempat_cuci_2->durasi -= durasi_simulasi;
	}
	cek_sisawaktu_cuci();
}

void cek_sisawaktu_cuci(){
	if(tempat_cuci_1 != NULL){
		if(tempat_cuci_1->durasi == 0){
			dequeue(0);
		}
	}
	if(tempat_cuci_2 != NULL){
		if(tempat_cuci_2->durasi == 0){
			dequeue(1);
		}
	}
}

void dequeue(int pilih){
	antrian_cuci *tempat;

	switch(pilih){
		case 0:
			tambah_pendapatan(tempat_cuci_1->golongan);
			tempat = tempat_cuci_1;
			tempat_cuci_1 = tempat_cuci_1->next;
			free(tempat);
			break;

		case 1:
			tambah_pendapatan(tempat_cuci_2->golongan);
			tempat = tempat_cuci_2;
			tempat_cuci_2 = tempat_cuci_2->next;
			free(tempat);
			break;
	}
}

void tambah_pendapatan(int pilih){
	switch(pilih){
		case 1:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[0];
			break;

		case 2:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[1];
			break;

		case 3:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[2];
			break;
	}
}

// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2
void pra_enqueue(char no_plat[], int golongan){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	
	antrian_cuci *make, *tempat;
	make = (antrian_cuci*)malloc(sizeof(antrian_cuci));
	
	if(make == NULL){
		printf("\nerror, tidak tersedia memori\n");
	}else{
		strcpy(make->nopol,no_plat);
		make->next = NULL;

		switch(golongan){
			case 1:
				make->golongan = 1;
				make->durasi = pilihan_durasi[0];
				break;

			case 2:
				make->golongan = 2;
				make->durasi = pilihan_durasi[1];
				break;

			case 3:
				make->golongan = 3;
				make->durasi = pilihan_durasi[2];	
				break;
		}
	}
	
	countUmur(); //sampai sini

	pilihan = pilih();
	switch(pilihan){
		case 0:
			tempat = tempat_cuci_1;
			enqueue_proses(make,tempat,pilihan);
			break;
		case 1:
			tempat = tempat_cuci_2;
			enqueue_proses(make,tempat,pilihan);
			break;
	}
}
// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2 - END

void countUmur(){
	antrian_cuci *tempat1,*tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	jumlah_durasi[0] = 0;
	jumlah_durasi[1] = 0;
	
	if(tempat_cuci_1 == NULL){
		jumlah_durasi[0] = 0;
	}else{
		while(tempat1!=NULL){
			jumlah_durasi[0] += tempat1->durasi;
			tempat1 = tempat1->next;
		}	
	}
	if(tempat_cuci_2 == NULL){
		jumlah_durasi[1] = 0;
	}else{
		while(tempat2!=NULL){
			jumlah_durasi[1] += tempat2->durasi;
			tempat2 = tempat2->next;
		}
	}
}

int pilih(){
	int c, d, swap;
	int jumlah_durasi_asc[2];

	jumlah_durasi_asc[0] = jumlah_durasi[0];
	jumlah_durasi_asc[1] = jumlah_durasi[1];
	
	for (c = 0 ; c < 1; c++){                     // harus dipahami
    	for (d = 0 ; d < 1 - c ; d++){            
      		if (jumlah_durasi_asc[d] > jumlah_durasi_asc[d+1]){
        		swap = jumlah_durasi_asc[d];
        		jumlah_durasi_asc[d] = jumlah_durasi_asc[d+1];
        		jumlah_durasi_asc[d+1] = swap;
      		}
    	}
	}
	for (c = 0; c < 2; c++){
    	if (jumlah_durasi[c] == jumlah_durasi_asc[0]){
        	break;
    	}
	}
	antrean = c;
  	return c;
}

void enqueue_proses(antrian_cuci *make, antrian_cuci *tempat, int choice){
	
	if(tempat == NULL){
		switch(choice){
		case 0:
			tempat_cuci_1 = make;
			break;
		case 1:
			tempat_cuci_2 = make;
			break;
		}
	}else{
		while(tempat->next != NULL){
			tempat = tempat->next;
		}
		make->next = NULL;
		tempat->next = make;		
	}	
}

void notifikasi_status(char no_plat[], int golongan){
	int temp_waktu;

	printf("\n");
	printf("mobil %s berhasil ditambahkan, perkiraan lama waktu hingga selesai adalah",no_plat);

	switch(golongan){
		case 1:
			temp_waktu = pilihan_durasi[0];
			break;
		case 2:
			temp_waktu = pilihan_durasi[1];
			break;
		case 3:
			temp_waktu = pilihan_durasi[2];
			break;	
	}

	switch(antrean){
		case 0:
			printf(" %d menit.\n",jumlah_durasi[0]+temp_waktu);
			break;
		case 1:
			printf(" %d menit.\n",jumlah_durasi[1]+temp_waktu);
			break;
		
	}
}