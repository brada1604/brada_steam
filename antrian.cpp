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
	char nama[15];
	int tipe;
	int umur;
	address next;
};

antrian_cuci *startSatu = NULL;
antrian_cuci *startDua = NULL;


int jumlahAntre[2];
int jumlahUmurAscending[2];
int jumlahUmur[2];
int age[3] = {20,30,40};
int harga[3] ={40000,50000,60000};
int clock = 10;
int antrean;
int jumlah_pendapatan;
int jumlah_waktu;
// DEKLARASI VARIABEL GLOBAL - END

// int main_antrian(){
// 	int pilih;
// 	int keluar;
	
// 	tampilanAwal();

// 	do{
// 		system("cls");

// 		header_aplikasi();

// 		data_antrian();

// 		menu(&pilih);

// 		menuTerpilih(pilih,&keluar);

// 	}while(keluar != 1);

// 	return 0;
// }

// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM
int main_antrian(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	int pil;

	
	
	// tampilanAwal();

	system("cls");

	header_aplikasi();

	data_antrian();

	// LIST MENU APLIKASI
	printf("\n");
	printf("\n");
	printf("|=================================================|\n");
	printf("|          Silahkan Pilih Menu Dibawah :          |\n");
	printf("|=================================================|\n");
	printf("| 1. Input Kendaraan                              |\n");
	printf("| 2. Keluarkan Kendaraan Dari Antrian             |\n");
	printf("| 3. Simulasi waktu (%d menit)                    |\n",clock);
	printf("| 4. Petunjuk                                     |\n");
	printf("| 5. Selesai                                      |\n");
	printf("|                                                 |\n");
	printf("|=================================================|\n");
	printf("             Copyright 2022 - BradaSteam           \n");
    
    printf("\n\n");
    printf("Masukkan angka pada menu yang dipilih : ");
	scanf("%d", &pilihan);

	
	
	// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
    switch (pilihan) { 
		case 1:
			input_kendaraan();

			tombol_selanjutnya();

			main_antrian();
			
			break;

		case 2:
			cancel_kendaraan();

			main_antrian();
			
			break;

		case 3:
			simulasi_waktu();

			main_antrian();
			
			break;

		case 4:
			bantuan_aplikasi();
			
			tombol_selanjutnya();

			main_antrian();
			break;

		case 5:
			pil = cek_antrian();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				tombol_selanjutnya();

				main_antrian();
				
				break;	
			}
			
			system("cls");
			printf("Hari ini, dengan total waktu kerja %d menit, didapat penghasilan sebesar Rp.%d\n",jumlah_waktu,jumlah_pendapatan);
			printf("THANK YOU!!!\n\n");
			header_aplikasi();	
			break;

	 	default:
	 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
			break;
    }
}
// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM - END

void tampilanAwal(){
	header_aplikasi();

	bantuan_aplikasi();

	footer_aplikasi();

	tombol_selanjutnya();

	system("cls");
}

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
	printf("\n");
	printf("|===========================================================================================================|\n");
	printf("                                         Copyright 2021 - BradaSteam                                         \n");
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

	if(startSatu == NULL){
		printf("[ Kosong ]");
	}else{
		tempat1 = startSatu;
		printf("[ %s, waktu sisa : %d menit] ",tempat1->nama,tempat1->umur);
		tempat1 = tempat1->next;
		while(tempat1 != NULL){
			printf("<-- %s (%d menit) ",tempat1->nama,tempat1->umur);
			tempat1 = tempat1->next;
		}		
	}
	
	printf("\nTempat Cuci Mobil 2 ");

	if(startDua == NULL){
		printf("[ Kosong ]");
	}else{
		tempat2 = startDua;
		printf("[ %s, waktu sisa : %d menit] ",tempat2->nama,tempat2->umur);
		tempat2 = tempat2->next;
		while(tempat2 != NULL){
			printf("<-- %s (%d menit) ",tempat2->nama,tempat2->umur);
			tempat2 = tempat2->next;
		}		
	}
	
	printf("\nWaktu ini : Rp.%d",jumlah_waktu);
	printf("\nPendapatan hari ini : Rp.%d",jumlah_pendapatan);
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

void input_kendaraan(){
	char no_plat[15];
	int cek, jenis, flag;

	do{
		printf("\nmasukkan Nomor Polisi kendaraan : ");
		scanf("%s", &no_plat);

		cek = cek_nopol(no_plat,&flag);
		if(cek != 0){
			printf("Nomor Polisi kendaraan sudah terdaftar! silahkan ganti.\n");
		}
	}while(cek != 0);
	
	jenis = jenis_kendaraan();
	if(jenis == 4){
		main_antrian();
		// break;
	}

	pra_enqueue(no_plat, jenis);

	notif(no_plat, jenis);
}

void cancel_kendaraan(){
	int pil;
	char no_plat[15];
	int cek, flag;

	pil = cek_antrian();
	if(pil == 0){
		printf("ERROR! antrian kosong.");
		tombol_selanjutnya();

		main_antrian();
	}
	do{
		flag = 0;
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan yang ingin dikeluarkan dari antrian : ");
		scanf("%s",&no_plat);

		if(no_plat[0]=='0'){  // Jika mengetik "0" Maka program akan di break
			break;
		}

		cek = cek_nopol(no_plat, &flag);
		if(cek == 0){
			printf("Tidak ada Kendaraan dengan Nomor Polisi tersebut. silahkan isi kembali.\n");
		}
	}while(cek == 0);

	keluarin(flag,no_plat);
}

int cek_nopol(char no_plat[], int *flag){
	antrian_cuci *tempat1, *tempat2;
	tempat1 = startSatu;
	tempat2 = startDua;
	
	int cek = 0;

	if(tempat1 != NULL){
		while(tempat1 != NULL){
			if(strcmp(no_plat,tempat1->nama) == 0){
				cek++;
				*flag = 1;	
			}
			tempat1 = tempat1->next;
		}	
	}
	if(tempat2 != NULL){
		while(tempat2 != NULL){
			if(strcmp(no_plat,tempat2->nama) == 0){
				cek++;
				*flag = 2;
			}
			tempat2 = tempat2->next;
		}	
	}
	
	return cek;
}

int jenis_kendaraan(){
	int ch;

	printf("|================================================================================================================|\n");
	printf("|                                                 JENIS KENDARAAN                                                |\n");
	printf("|================================================================================================================|\n");
	printf("| No.| Jenis | Keterangan  |                            Sampel                             |   Waktu  |   Harga  |\n");
	printf("| 1. |   A   | Mobil Kecil | KIA Picanto, Daihatsu Ceria, Suzuki Karimun, Toyota Yaris dll | %d menit | Rp.%d |\n",age[0],harga[0]);
	printf("| 2. |   B   | Minibus     | Toyota Avanza, Honda Freed, Suzuki Ertiga, dll                | %d menit | Rp.%d |\n",age[1],harga[1]);
	printf("| 3. |   C   | Mobil Besar | Metromini, Truk, dll                                          | %d menit | Rp.%d |\n",age[2],harga[2]);
	printf("| 4. | Tidak Jadi                                                                                                |\n");
	printf("|================================================================================================================|\n");

	do{
		printf("Pilihan : ");
		scanf("%d", &ch);
		if(ch<1 || ch>4){
			printf("pilihan diantara 1 - 4, silahkan isi lagi.\n");
		}
	}while(ch<1 || ch>4);

	return ch;
}

void keluarin(int flag, char no_plat[]){
	antrian_cuci *tempat1,*tempat2; 
	tempat1 = startSatu;
	tempat2 = startDua;

	
	switch(flag){
		case 1:
			keluar_kendaraan(no_plat,tempat1);
			break;
		case 2:
			keluar_kendaraan(no_plat,tempat2);
			break;	
	}
	tombol_selanjutnya();	
}

int cek_antrian(){
	int cek;

	cek = 0;

	if(startSatu != NULL){
		cek++;	
	}

	if(startDua != NULL){
		cek++;
	}

	return cek;
}

int keluar_kendaraan(char no_plat[], antrian_cuci *tempat){
	antrian_cuci *freed;
	if(strcmp(no_plat,tempat->nama) == 0){
		printf("\n");
		printf("Kendaraan yang sedang dicuci tidak bisa dikeluarkan! silahkan tunggu sampai selesai.\n");
	}else{
		while(strcmp(no_plat,tempat->next->nama)!=0){
			tempat = tempat->next;
		}
		freed = tempat->next;
		tempat->next = tempat->next->next;
		free(freed);
	}
}

void simulasi_waktu(){
	if(startSatu != NULL){
		startSatu->umur -= clock;
	}
	if(startDua != NULL){
		startDua->umur -= clock;
	}
	cek_sisawaktu_cuci();
}

void cek_sisawaktu_cuci(){
	if(startSatu != NULL){
		if(startSatu->umur == 0){
			dequeue(0);
		}
	}
	if(startDua != NULL){
		if(startDua->umur == 0){
			dequeue(1);
		}
	}
}

void dequeue(int pilih){
	antrian_cuci *tempat;

	switch(pilih){
		case 0:
			tambah_pendapatan(startSatu->tipe);
			tempat = startSatu;
			startSatu = startSatu->next;
			free(tempat);
			break;

		case 1:
			tambah_pendapatan(startDua->tipe);
			tempat = startDua;
			startDua = startDua->next;
			free(tempat);
			break;
	}
}

void tambah_pendapatan(int pilih){
	switch(pilih){
		case 1:
			jumlah_pendapatan += harga[0];
			jumlah_waktu += age[0];
			break;

		case 2:
			jumlah_pendapatan += harga[1];
			jumlah_waktu += age[1];
			break;

		case 3:
			jumlah_pendapatan += harga[2];
			jumlah_waktu += age[2];
			break;
	}
}

void pra_enqueue(char no_plat[], int tipe){
	int choice;
	
	antrian_cuci *make, *tempat;
	make = (antrian_cuci*)malloc(sizeof(antrian_cuci));
	
	if(make == NULL){
		printf("\nerror, tidak tersedia memori\n");
	}else{
		strcpy(make->nama,no_plat);
		make->next = NULL;

		switch(tipe){
			case 1:
				make->tipe = 1;
				make->umur = age[0];
				break;

			case 2:
				make->tipe = 2;
				make->umur = age[1];
				break;

			case 3:
				make->tipe = 3;
				make->umur = age[2];	
				break;
		}
	}
	
	countUmur(); //sampai sini

	choice = pilih();
	switch(choice){
		case 0:
			tempat = startSatu;
			enqueue_proses(make,tempat,choice);
			break;
		case 1:
			tempat = startDua;
			enqueue_proses(make,tempat,choice);
			break;
	}
}

void countUmur(){
	antrian_cuci *tempat1,*tempat2;
	tempat1 = startSatu;
	tempat2 = startDua;
	
	jumlahUmur[0] = 0;
	jumlahUmur[1] = 0;
	
	if(startSatu == NULL){
		jumlahUmur[0] = 0;
	}else{
		while(tempat1!=NULL){
			jumlahUmur[0] += tempat1->umur;
			tempat1 = tempat1->next;
		}	
	}
	if(startDua == NULL){
		jumlahUmur[1] = 0;
	}else{
		while(tempat2!=NULL){
			jumlahUmur[1] += tempat2->umur;
			tempat2 = tempat2->next;
		}
	}
}

int pilih(){
	int c, d, swap;
	jumlahUmurAscending[0] = jumlahUmur[0];
	jumlahUmurAscending[1] = jumlahUmur[1];
	
	for (c = 0 ; c < 1; c++){                     // harus dipahami
    	for (d = 0 ; d < 1 - c ; d++){            
      		if (jumlahUmurAscending[d] > jumlahUmurAscending[d+1]){
        		swap = jumlahUmurAscending[d];
        		jumlahUmurAscending[d] = jumlahUmurAscending[d+1];
        		jumlahUmurAscending[d+1] = swap;
      		}
    	}
	}
	for (c = 0; c < 2; c++){
    	if (jumlahUmur[c] == jumlahUmurAscending[0]){
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
			startSatu = make;
			break;
		case 1:
			startDua = make;
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

void notif(char no_plat[], int tipe){
	int temp_waktu;

	printf("\n");
	printf("mobil %s berhasil ditambahkan, perkiraan lama waktu hingga selesai adalah",no_plat);

	switch(tipe){
		case 1:
			temp_waktu = age[0];
			break;
		case 2:
			temp_waktu = age[1];
			break;
		case 3:
			temp_waktu = age[2];
			break;	
	}

	switch(antrean){
		case 0:
			printf(" %d menit.\n",jumlahUmur[0]+temp_waktu);
			break;
		case 1:
			printf(" %d menit.\n",jumlahUmur[1]+temp_waktu);
			break;
		
	}
}