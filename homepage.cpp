// PEMANGGILAN LIBRARY
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// PEMANGGILAN LIBRARY - END

// PEMANGGILAN HEADER FILE
#include "program.h"
#include "antrian.h"
// PEMANGGILAN HEADER FILE - END

// DEKLARASI MODUL FUNCTION
int exit_aplikasi();		// MODUL UNTUK KELUAR APLIKASI
int salah_input_menu();		// MODUL UNTUK ERROR HANDLE APABILA SALAH INPUT PADA MENU
// DEKLARASI MODUL FUNCTION - END

// FUNCTION UTAMA UNTUK HOMEPAGE DARI APLIKASI BRADA STEAM
int homepage(){
	// DEKLARASI VARIABEL LOKAL
	int menu;

	// LIST MENU APLIKASI
	system("cls");
	header_aplikasi(); // HEADER APLIKASI

	printf("| Silahkan Pilih Menu dibawah ini :                                                                         |\n");
	printf("|===========================================================================================================|\n");
	printf("| 1. Mulai Aplikasi                                                                                         |\n");
	printf("| 2. Keluar Aplikasi                                                                                        |\n");
	printf("|                                                                                                           |\n");

	footer_aplikasi(); // FOOTER APLIKASI
    
    printf("\n\n");
    printf("Masukkan pilihan : "); // DI ISI DENGAN '1' ATAU '2', SELAIN DARI ITU MAKA PROGRAM AKAN MENGELUARKAN NOTIFIKASI ALERT
	scanf("%d", &menu);

	system("cls");
	
	// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
    switch (menu) { 
        case 1:
			main_antrian(); 	// REDIRECT KE main_antrian() UNTUK MULAI SISTEM ANTRIAN - LOKASI FILE : antrian.h --> antrian.cpp
			break;
		case 2:
		    exit_aplikasi(); 	// REDIRECT KE exit_aplikasi() UNTUK KELUAR DARI APLIKASI - LOKASI FILE : homepage.cpp
			break;
	 	default:
	 		salah_input_menu(); // REDIRECT KE salah_input_menu() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : homepage.cpp
			break;
    }
}
// FUNCTION UTAMA UNTUK HOMEPAGE DARI APLIKASI BRADA STEAM - END

// FUNCTION UNTUK KELUAR DARI APLIKASI
int exit_aplikasi(){
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
		// REDIRECT TO homepage.cpp
		system("cls");
		homepage(); // FILE : program.h --> homepage.cpp
	}
}
// FUNCTION UNTUK KELUAR DARI APLIKASI - END

// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU
int salah_input_menu(){
	printf("Maaf Inputan Salah!\n");
	printf("Silahkan Tekan Apapun Untuk Kembali Ke Homepage...");
	getchar();

	// REDIRECT TO homepage.cpp
	system("cls");
	homepage(); // FILE : program.h --> homepage.cpp
}
// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU - END