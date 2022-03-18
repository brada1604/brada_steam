/*
Nama Program	: Brada Steam
Deskripsi		: Program simulasi antrian pelayanan cuci mobil di Ciamis
Developer		: Bagus Nugroho (211511034)
Tahun 			: MARET 2022
*/

// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <conio.h>
#include <windows.h>
// PEMANGGILAN LIBRARY - END

// PEMANGGILAN HEADER FILE
#include "program.h"
// PEMANGGILAN HEADER FILE - END

// DEKLARASI MODUL
void gotoxy(int x, int y);
// DEKLARASI MODUL - END

int main() {
	
	// PROSES FITUR SPLASH SCREEN
	int load = 0; // UNTUK MENGHITUNG JUMLAH TITIK
	
	printf("|=================================================|\n");
	printf("|                  BRADA STEAM                    |\n");
	printf("|=================================================|\n");
	printf("|                                                 |\n");
	printf("|Loading - Tunggu Sebentar                        |\n");
	printf("|                                                 |\n");
	printf("|=================================================|\n");
	printf("            Copyright 2022 - BradaSteam            \n");

	for( int i = 0; i <= 100; i++ ) //MENGKALKULASI PROSES DARI 0-100%
	{
		if(i % 10 == 0)
		{
			gotoxy(12 + 15 + load, 4);printf(".");
			load++;
			if(load == 6) //MENGHAPUS SEMUA TITIK
			{
				load = 0; printf("\b\b\b\b\b\b");
			}
		}
		gotoxy(12 + 21, 4);printf("%i",i);
		for(int j = 0; j < 50; j++ )  // DELAY (MEMBEBANKAN COMPUTER SEOLAH-OLAH PROSES MENJADI LAMA)
		{
			for(int l = 0;l < 100000;l++) // DIGUNAKAN UNTUK MENGATUR CEPAT LAMBAT LOADING
			{
				printf(""); //MENCETAK KARAKTER KOSONG, APABILA BARIS INI DIHILANGKAN, APLIKASI AKAN MENJADI SANGAT CEPAT
			}				//MENCETAK KOSONG TIDAK SAMA DENGAN 'DO NOTHING' (TIDAK MENGERJAKAN APA-APA)
		}
	}
	// PROSES FITUR SPLASH SCREEN - END

	// BYPASS KE HOMEPAGE.CPP
	homepage();

	return 0;
}

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
