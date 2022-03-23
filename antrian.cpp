// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
// PEMANGGILAN LIBRARY - END



// PEMANGGILAN FILE HEADER
#include "antrian.h"
#include "sys_compare.h"
// PEMANGGILAN FILE HEADER - END



// DEKLARASI MODUL FUNCTION
int exit_aplikasi_antrian();		// MODUL UNTUK KELUAR APLIKASI
int salah_input_menu_antrian();		// MODUL UNTUK ERROR HANDLE APABILA SALAH INPUT PADA MENU
// DEKLARASI MODUL FUNCTION - END



// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM
int main_antrian(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	int pil;

	system("cls");

	header_aplikasi();

	printf("\n");
	konversi_waktu();

	if(pukul_waktu >= waktu_tutup){
		printf("\n");
		printf("  Brada Steam waktunya tutup\n");
		printf("  Total waktu mencuci mobil adalah %d menit, dengan total kendaraan yang dicuci sebanyak %d mobil\n",jumlah_waktu,jumlah_kendaraan);
		printf("  Terimakasih! Sampai Jumpa Kembali\n\n");
		footer_aplikasi();
    	exit(1);
	}
	else if(pukul_waktu >= waktu_mulai_istirahat && pukul_waktu <= waktu_selesai_istirahat){
		printf("\n");
		printf("  Brada Steam Sedang Istirahat dari jam 12:00 - 13:00");
		printf("\n");
	}
	else{
		data_antrian(); // MENAMPILKAN ANTRIAN KENDARAAN YANG SEDANG DICUCI DAN SEDANG MENGANTRI
	}

	// LIST MENU APLIKASI
	if(pukul_waktu >= waktu_mulai_istirahat && pukul_waktu <= waktu_selesai_istirahat){
		printf("\n");
		printf("\n");
		printf("|=================================================|\n");
		printf("|          Silahkan Pilih Menu Dibawah :          |\n");
		printf("|=================================================|\n");
		printf("| 3.  Simulasi waktu (%d menit)                   |\n",durasi_simulasi);
		printf("|                                                 |\n");
		printf("|=================================================|\n");
		printf("             Copyright 2022 - BradaSteam           \n");

		printf("\n\n");
	    printf("Masukkan Pilihan : ");
		scanf("%d", &pilihan);

		// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
	    switch (pilihan) { 
			case 3:
				simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

				main_antrian(); // MODUL UTAMA
				
				break;

		 	default:
		 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
				break;
	    }
	}
	else{
		if((tempat_cuci_1 == NULL) && (tempat_cuci_2 == NULL)){
			printf("\n");
			printf("\n");
			printf("|=================================================|\n");
			printf("|          Silahkan Pilih Menu Dibawah :          |\n");
			printf("|=================================================|\n");
			printf("| 1.  Input Kendaraan                             |\n");
			printf("| 2.  Keluarkan Kendaraan Dari Antrian            |\n");
			printf("| 3.  Simulasi waktu (%d menit)                   |\n",durasi_simulasi);
			printf("| 4.  Bantuan                                     |\n");
			printf("| 5.  Selesai                                     |\n");
			printf("| 6.  Skip (10 Menit)                             |\n");
			printf("| 7.  Skip (15 Menit)                             |\n");
			printf("| 8.  Skip (30 Menit)                             |\n");
			printf("| 9.  Skip (45 Menit)                             |\n");
			printf("| 10. Skip (60 Menit)                             |\n");
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
					cancel_kendaraan(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN

					main_antrian(); // MODUL UTAMA
					
					break;

				case 3:
					simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

					main_antrian(); // MODUL UTAMA
					
					break;

				case 4:
					bantuan_aplikasi(); // MENAMPILKAN SEMACAM PANDUAN APABILA ADA USER YANG KURANG FAMILIAR DENGAN APLIKASI
					
					tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

					main_antrian(); // MODUL UTAMA

					break;

				case 5:
					pil = cek_antrian();
					if(pil != 0){ // JIKA RETURN NILAI NYA ADALAH 0, MAKA ARTINYA SUDAH TIDAK ADA MOBIL YANG DI CUCI ATAU MENGANTRI
						printf("Masih ada mobil yang sedang dicuci! Tidak bisa keluar dari program.\n");
						tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

						main_antrian(); // MODUL UTAMA
						
						break;	
					}
					
					system("cls");

					header_aplikasi();	
					printf("\n");
					printf("  Total waktu mencuci mobil adalah %d menit, dengan total kendaraan yang dicuci sebanyak %d mobil\n",jumlah_waktu,jumlah_kendaraan);
					printf("  Terimakasih! Sampai Jumpa Kembali\n\n");
					footer_aplikasi();	

					break;

				case 6:
					skip_waktu_berjalan(10); // MODUL UNTUK SKIP WAKTU
					main_antrian(); // MODUL MAIN
					break;

				case 7:
					skip_waktu_berjalan(15); // MODUL UNTUK SKIP WAKTU
					main_antrian(); // MODUL MAIN
					break;

				case 8:
					skip_waktu_berjalan(30); // MODUL UNTUK SKIP WAKTU
					main_antrian(); // MODUL MAIN
					break;

				case 9:
					skip_waktu_berjalan(45); // MODUL UNTUK SKIP WAKTU
					main_antrian(); // MODUL MAIN
					break;

				case 10:
					skip_waktu_berjalan(60); // MODUL UNTUK SKIP WAKTU
					main_antrian(); // MODUL MAIN
					break;

			 	default:
			 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
					break;
		    }
		}
		else{
			printf("\n");
			printf("\n");
			printf("|=================================================|\n");
			printf("|          Silahkan Pilih Menu Dibawah :          |\n");
			printf("|=================================================|\n");
			printf("| 1.  Input Kendaraan                             |\n");
			printf("| 2.  Keluarkan Kendaraan Dari Antrian            |\n");
			printf("| 3.  Simulasi waktu (%d menit)                   |\n",durasi_simulasi);
			printf("| 4.  Bantuan                                     |\n");
			printf("| 5.  Selesai                                     |\n");
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
					cancel_kendaraan(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN

					main_antrian(); // MODUL UTAMA
					
					break;

				case 3:
					simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

					main_antrian(); // MODUL UTAMA
					
					break;

				case 4:
					bantuan_aplikasi(); // MENAMPILKAN SEMACAM PANDUAN APABILA ADA USER YANG KURANG FAMILIAR DENGAN APLIKASI
					
					tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

					main_antrian(); // MODUL UTAMA

					break;

				case 5:
					pil = cek_antrian();
					if(pil != 0){ // JIKA RETURN NILAI NYA ADALAH 0, MAKA ARTINYA SUDAH TIDAK ADA MOBIL YANG DI CUCI ATAU MENGANTRI
						printf("Masih ada mobil yang sedang dicuci! Tidak bisa keluar dari program.\n");
						tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

						main_antrian(); // MODUL UTAMA
						
						break;	
					}
					
					system("cls");

					header_aplikasi();	
					printf("\n");
					printf("  Total waktu mencuci mobil adalah %d menit, dengan total kendaraan yang dicuci sebanyak %d mobil\n",jumlah_waktu,jumlah_kendaraan);
					printf("  Terimakasih! Sampai Jumpa Kembali\n\n");
					footer_aplikasi();	

					break;

			 	default:
			 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
					break;
		    }
		}
	}	    
}
// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI BRADA STEAM - END



// FUNCTION UNTUK MENAMPILKAN HEADER APLIKASI
void header_aplikasi(){
	printf("|===========================================================================================================|\n");
	printf("|                                                                                                           |\n");
	printf("|                                               BRADA STEAM                                                 |\n");
	printf("|                                                                                                           |\n");
	printf("|===========================================================================================================|\n");
}
// FUNCTION UNTUK MENAMPILKAN HEADER APLIKASI - END



// FUNCTION UNTUK BANTUAN APABILA ADA KESULITAN DALAM PENGGUNAAN APLIKASI
void bantuan_aplikasi(){
	printf("\n");
	printf("BANTUAN PADA APLIKASI BRADA STEAM (PANDUAN) : \n");
	printf("- Tabel paling atas merupakan list antrian mobil beserta tempat pencuciannya\n");
	printf("- Ketik '0' pada setiap inputan, jika kamu tidak akan jadi melakukan hal tersebut (input data)\n");
	printf("- ketik '1' pada menu untuk input kendaraan\n");
	printf("- ketik '2' pada menu apabila ada kendaraan yang tidak jadi di cuci namun masih pada antrian\n");
	printf("- ketik '3' pada menu untuk melakukan pencucian selama 5 menit ke depan\n");
	printf("- ketik '4' pada menu untuk bantuan penggunaan aplikasi\n");
	printf("- ketik '5' pada menu untuk keluar dari aplikasi\n");
}
// FUNCTION UNTUK BANTUAN APABILA ADA KESULITAN DALAM PENGGUNAAN APLIKASI - END



// FUNCTION UNTUK MENAMPILKAN FOOTER APLIKASI
void footer_aplikasi(){
	printf("|===========================================================================================================|\n");
	printf("|                                         Copyright 2022 - BradaSteam                                       |\n");
	printf("|===========================================================================================================|\n");
}
// FUNCTION UNTUK MENAMPILKAN FOOTER APLIKASI - END



// FUNCTION UNTUK MENAMPILKAN ALERT
void tombol_selanjutnya(){
	printf("\n");
	printf("Tekan Apapun Untuk Melanjutkan!");
	getch();
}
// FUNCTION UNTUK MENAMPILKAN ALERT



// FUNCTION UNTUK MENAMPILKAN SIMULASI ANTRIAN PADA TEMPAT CUCI MOBIL
void data_antrian(){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat1, *tempat2;

	printf("\n");
	printf("TEMPAT CUCI MOBIL 1 ");

	if(tempat_cuci_1 == NULL){
		printf("[ Kosong ]");
	}else{
		tempat1 = tempat_cuci_1;
		printf("[ %s - sisa : %d menit - in : ",tempat1->nopol,tempat1->durasi);
		konversi_waktu_cuci(tempat1->waktu_in);
		printf(" - proses : ");
		konversi_waktu_cuci(tempat1->waktu_proses);
		printf(" - out : ");
		konversi_waktu_cuci(tempat1->waktu_out);
		printf(" ] ");

		tempat1 = tempat1->next;
		while(tempat1 != NULL){
			printf("\n");
			printf("                    ^ %s (%d menit - in : ",tempat1->nopol,tempat1->durasi);
			konversi_waktu_cuci(tempat1->waktu_in);
			printf(" ) ");
			tempat1 = tempat1->next;
		}		
	}
	
	printf("\n");
	printf("\n");
	printf("TEMPAT CUCI MOBIL 2 ");

	if(tempat_cuci_2 == NULL){
		printf("[ Kosong ]");
	}else{
		tempat2 = tempat_cuci_2;
		printf("[ %s - sisa : %d menit - in : ",tempat2->nopol,tempat2->durasi);
		konversi_waktu_cuci(tempat2->waktu_in);
		printf(" - proses : ");
		konversi_waktu_cuci(tempat2->waktu_proses);
		printf(" - out : ");
		konversi_waktu_cuci(tempat2->waktu_out);
		printf(" ] ");

		tempat2 = tempat2->next;
		while(tempat2 != NULL){
			printf("\n");
			printf("                    ^ %s (%d menit - in : ",tempat2->nopol,tempat2->durasi);
			konversi_waktu_cuci(tempat2->waktu_in);
			printf(" ) ");
			tempat2 = tempat2->next;
		}		
	}
	
	printf("\n");
	printf("\n");
	printf("Total waktu  	: %d Menit\n",jumlah_waktu);
	printf("Total Kendaraan : %d Mobil\n",jumlah_kendaraan);
}
// FUNCTION UNTUK MENAMPILKAN SIMULASI ANTRIAN PADA TEMPAT CUCI MOBIL - END



// FUNTION UNTUK KONVERSI WAKTU
void konversi_waktu(){
	int j, m, d, detik;

	detik = pukul_waktu * 60;

	j = (detik / 3600) + 7; // TAMBAH 7 KARENA BUKA DARI JAM 7
	m = (detik % 3600/60);
	d = detik % 60;

	printf("Pukul : %d:%d:%d \n", j, m, d);

}

void konversi_waktu_cuci(int menit_cuci){
	int j, m, d, detik;

	detik = menit_cuci * 60;

	j = (detik / 3600) + 7; // TAMBAH 7 KARENA BUKA DARI JAM 7
	m = (detik % 3600/60);
	d = detik % 60;

	printf("%d:%d:%d", j, m, d);

}
// FUNTION UNTUK KONVERSI WAKTU - END



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

	if(waktu_tutup < (pilihan_durasi[jenis-1] + pukul_waktu)){
		printf("Waktu tidak mencukupi dikarenakan sebentar lagi Brada Steam akan tutup");
		tombol_selanjutnya();
		main_antrian(); // MODUL UTAMA
	}

	if((waktu_mulai_istirahat < (pilihan_durasi[jenis-1] + pukul_waktu)) && (waktu_selesai_istirahat > (pilihan_durasi[jenis-1] + pukul_waktu))){
		printf("Waktu tidak mencukupi dikarenakan sebentar lagi Brada Steam akan beristirahat");
		tombol_selanjutnya();
		main_antrian(); // MODUL UTAMA
	}

	do{
		fflush(stdin);
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan : ");
		scanf("%[^\n]", &no_plat);
		fflush(stdin);
		break;

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek != 0){ // JIKA CEK BERNILAI BUKAN 0 MAKA SUDAH ADA DATA KENDARAAN PADA TEMPAT CUCI ATAU PADA ANTRIAN
			printf("Nomor Polisi kendaraan sudah terdaftar! silahkan ganti.\n");
		}
	}while(cek != 0);
	
	pra_enqueue(no_plat, jenis); // PROSES SEBELUM DATA DI ENQUEUE KE LIST

	notifikasi_status(no_plat, jenis); // PROSES UNTUK MENGELUARKAN NOTIFIKASI
}
// FUNCTION UNTUK INPUT DATA KENDARAAN - END



// FUNCTION UNTUK MENGELUARKAN KENDARAAN DARI ANTRIAN DALAM ARTIAN TIDAK JADI MENCUCI MOBIL
void cancel_kendaraan(){
	// DEKLARASI VARIABEL LOKAL
	int pil;
	char no_plat[15];
	int cek, tanda_tempat;

	pil = cek_antrian();
	if(pil == 0){ // JIKA RETURN NILAI NYA 0 MAKA LIST NYA SEDANG KOSONG
		printf("ERROR! antrian kosong.");
		tombol_selanjutnya();  // MODUL UNTUK ALTERNATIF BY PASS

		main_antrian(); // MODUL UTAMA
	}

	do{
		tanda_tempat = 0;

		fflush(stdin);
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan yang ingin dikeluarkan dari antrian : ");
		scanf("%[^\n]",&no_plat);
		fflush(stdin);

		if(no_plat[0]=='0'){  // Jika mengetik "0" Maka program akan di break
			break;
		}

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek == 0){ // JIKA RETURN NILAINYA 0 ARTINYA TIDAK ADA KENDARAAN DENGAN NOPOL YANG DI INPUTKAN
			printf("Tidak ada Kendaraan dengan Nomor Polisi tersebut. silahkan isi kembali.\n");
		}
	}while(cek == 0);

	keluarkan(tanda_tempat,no_plat); // PROSES MENGELUARKAN KENDARAAN
}
// FUNCTION UNTUK MENGELUARKAN KENDARAAN DARI ANTRIAN DALAM ARTIAN TIDAK JADI MENCUCI MOBIL



// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN
int cek_nopol(char no_plat[], int *tanda_tempat){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat1, *tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	int cek = 0;

	if(tempat1 != NULL){
		while(tempat1 != NULL){
			int compare_1 = stringcompare(no_plat,tempat1->nopol); // CALLING STRINGCOMPARE() FUNCTION.  
			if(compare_1 == 0){
				cek++;
				*tanda_tempat = 1; 
			}  
			// if(strcmp(no_plat,tempat1->nopol) == 0){
			// 	cek++;
			// 	*tanda_tempat = 1;	
			// }
			tempat1 = tempat1->next;
		}	
	}

	if(tempat2 != NULL){
		while(tempat2 != NULL){
			int compare_2 = stringcompare(no_plat,tempat2->nopol); // CALLING STRINGCOMPARE() FUNCTION.  
			if(compare_2 == 0){
				cek++;
				*tanda_tempat = 2;
			}
			// if(strcmp(no_plat,tempat2->nopol) == 0){
			// 	cek++;
			// 	*tanda_tempat = 2;
			// }
			tempat2 = tempat2->next;
		}	
	}
	
	return cek;
}
// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN - END



// FUNCTION UNTUK MENAMPILKAN PILIHAN JENIS KENDARAAN
int jenis_kendaraan(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan_jenis_kendaraan;
	printf("\n");
	printf("\n");
	printf("|=====================================================================================================|\n");
	printf("|                                            JENIS KENDARAAN                                          |\n");
	printf("|=====================================================================================================|\n");
	printf("| NO | JENIS | KETERANGAN  |                            SAMPEL                             |  DURASI  |\n");
	printf("| 1. |   A   | Mobil Kecil | KIA Picanto, Daihatsu Ceria, Suzuki Karimun, Toyota Yaris dll | %d menit |\n",pilihan_durasi[0]);
	printf("| 2. |   B   | Minibus     | Toyota Avanza, Honda Freed, Suzuki Ertiga, dll                | %d menit |\n",pilihan_durasi[1]);
	printf("| 3. |   C   | Mobil Besar | Metromini, Truk, dll                                          | %d menit |\n",pilihan_durasi[2]);
	printf("|=====================================================================================================|\n");

	do{
		printf("\n");
		printf("Pilih Jenis Kendaraan (1-3) : ");
		scanf("%d", &pilihan_jenis_kendaraan);

		if((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 3)){ // JIKA INPUTAN KURANG DARI 0 ATAU LEBIH DARI 3 MAKA KELUAR ALERT
			printf("Inputan Salah ! Pilihan diantara 1 - 3, silahkan input lagi.\n\n");
		}
	}while((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 3));

	return pilihan_jenis_kendaraan;
}
// FUNCTION UNTUK MENAMPILKAN PILIHAN JENIS KENDARAAN - END



// FUNCTION UNTUK PROSES MENGELUARKAN KENDARAAN BERDASARKAN TEMPAT CUCI
void keluarkan(int tanda_tempat, char no_plat[]){
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
// FUNCTION UNTUK PROSES MENGELUARKAN KENDARAAN BERDASARKAN TEMPAT CUCI - END



// FUNTION UNTUK CEK ANTRIAN MOBIL
int cek_antrian(){
	// DEKLARASI VARIABEL LOKAL
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
// FUNTION UNTUK CEK ANTRIAN MOBIL



// FUNCTION UNTUK PROSES MENGELUARKAN MOBIL DARI LIST / ANTRIAN
int keluar_kendaraan(char no_plat[], antrian_cuci *tempat){
	antrian_cuci *kendaraan_siap_keluar_antrian;

	if(strcmp(no_plat,tempat->nopol) == 0){ // JIKA RETURNNYA 0, ITU ARTINYA MOBIL SEDANG DICUCI, KARENA ITU ELEMEN PALING AWAL / KENDARAAN YANG MEMANG SEDANG DI CUCI
		printf("\n");
		printf("Kendaraan sedang dicuci! tunggu hingga selesai.\n");
	}else{
		while(strcmp(no_plat,tempat->next->nopol)!=0){ // PROSES PENCARIAN NOPOL YANG SAMA ANTARA INPUTAN DENGAN YANG ADA DI ANTRIAN
			tempat = tempat->next;
		}
		kendaraan_siap_keluar_antrian = tempat->next;
		tempat->next = tempat->next->next;
		free(kendaraan_siap_keluar_antrian);
	}
}
// FUNCTION UNTUK PROSES MENGELUARKAN MOBIL DARI LIST / ANTRIAN - END



// FUNTION UNTUK SKIP WAKTU SISTEM PENCUCIAN
void skip_waktu_berjalan(int m){
	pukul_waktu += m; // SKIP WAKTU BERJALAN SEBANYAK m MENIT
}
// FUNTION UNTUK SKIP WAKTU SISTEM PENCUCIAN - END



// FUNCTION UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI YANG SUDAH DI SET DI VARIABEL GLOBAL
void simulasi_waktu(){
	pukul_waktu += durasi_simulasi;

	if(tempat_cuci_1 != NULL){
		if(tempat_cuci_1->durasi != 0){ // CEK APAKAH DURASI DI 1 SUDAH 0 ATAU BELUM
			tempat_cuci_1->durasi -= durasi_simulasi;
		}

		if(tempat_cuci_1->durasi == 0){ // CEK APAKAH DURASI DI 1 SUDAH 0 ATAU BELUM
			if (tempat_cuci_2 != NULL){ // CEK APAKAH LIST 2 NULL ATAU TIDAK
				if (tempat_cuci_2->durasi >= durasi_jeda){ // CEK APAKAH DURASI DI 2 MASIH LEBIH DARI 5 ATAU TIDAK
					tempat_cuci_2->durasi -= durasi_jeda; // DURASI DI 2 DIKURANGIN 5 MENIT UNTUK JEDA KE PENCUCIAN SELANJUTNYA
				}
			}
		}
	}

	if(tempat_cuci_2 != NULL){
		if(tempat_cuci_2->durasi != 0){ // CEK APAKAH DURASI DI 2 SUDAH 0 ATAU BELUM
			tempat_cuci_2->durasi -= durasi_simulasi;
		}

		if(tempat_cuci_2->durasi == 0){ // CEK APAKAH DURASI DI 2 SUDAH 0 ATAU BELUM
			if (tempat_cuci_1 != NULL){ // CEK APAKAH LIST 1 NULL ATAU TIDAK
				if (tempat_cuci_1->durasi >= durasi_jeda){ // CEK APAKAH DURASI DI 1 MASIH LEBIH DARI 5 ATAU TIDAK
					tempat_cuci_1->durasi -= durasi_jeda; // DURASI DI 1 DIKURANGIN 5 MENIT UNTUK JEDA KE PENCUCIAN SELANJUTNYA
				}
			}
		}
	}

	if(((tempat_cuci_1 != NULL)&&(tempat_cuci_1->durasi == 0)) || ((tempat_cuci_2 != NULL)&&(tempat_cuci_2->durasi == 0))){
		pukul_waktu += durasi_jeda; // jeda 5 menit dari mobil 1 ke lainnya;
	}

	cek_sisawaktu_cuci();
}
// FUNCTION UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI YANG SUDAH DI SET DI VARIABEL GLOBAL




// FUNTION UNTUK CEK SISA WAKTU MENCUCI MOBIL
void cek_sisawaktu_cuci(){
	if(tempat_cuci_1 != NULL){
		if(tempat_cuci_1->durasi == 0){
			dequeue(0);

			if(tempat_cuci_1 != NULL){
				tempat_cuci_1->waktu_proses = pukul_waktu;
				tempat_cuci_1->waktu_out = pukul_waktu + tempat_cuci_1->durasi;
			}
		}
	}

	if(tempat_cuci_2 != NULL){
		if(tempat_cuci_2->durasi == 0){
			dequeue(1);

			if(tempat_cuci_2 != NULL){
				tempat_cuci_2->waktu_proses = pukul_waktu;
				tempat_cuci_2->waktu_out = pukul_waktu + tempat_cuci_2->durasi;
			}
		}
	}
}
// FUNTION UNTUK CEK SISA WAKTU MENCUCI MOBIL




// FUNCTION UNTUK DEQUE ATAU MENGHAPUS DATA DARI ANTRIAN (QUEUE)
void dequeue(int pilih){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat;

	switch(pilih){
		case 0:
			hitung_total(tempat_cuci_1->golongan);
			tempat = tempat_cuci_1;
			tempat_cuci_1 = tempat_cuci_1->next;
			free(tempat); // DI DEALOKASI
			break;

		case 1:
			hitung_total(tempat_cuci_2->golongan);
			tempat = tempat_cuci_2;
			tempat_cuci_2 = tempat_cuci_2->next;
			free(tempat); // DI DEALOKASI
			break;
	}
}
// FUNCTION UNTUK DEQUE ATAU MENGHAPUS DATA DARI ANTRIAN (QUEUE) - END



// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA
void hitung_total(int pilih){
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
// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA - END



// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2
void pra_enqueue(char no_plat[], int golongan){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	antrian_cuci *data_inputan, *tempat;
	data_inputan = (antrian_cuci*)malloc(sizeof(antrian_cuci)); // ALOKASI VARIABEL
	
	if(data_inputan == NULL){ // JIKA VARIABEL data_inputan NULL, BERARTI TIDAK ADA 1 PUN ELEMEN DALAM LIST ATAU ALOKASI GAGAL DILAKUKAN, MAKA AKAN KELUAR ALERT
		printf("\n");
		printf("ERROR! Tidak tersedia memori\n");
	}else{
		strcpy(data_inputan->nopol,no_plat); // INPUT NOPOL KENDARAAN KE LIST BARU
		data_inputan->next = NULL; // LIST data_inputan->next MENUNJUK NULL

		switch(golongan){
			case 1:
				data_inputan->golongan = 1;
				data_inputan->durasi = pilihan_durasi[0];
				data_inputan->waktu_in = pukul_waktu;
				break;

			case 2:
				data_inputan->golongan = 2;
				data_inputan->durasi = pilihan_durasi[1];
				data_inputan->waktu_in = pukul_waktu;
				break;

			case 3:
				data_inputan->golongan = 3;
				data_inputan->durasi = pilihan_durasi[2];	
				data_inputan->waktu_in = pukul_waktu;	
				break;
		}
	}
	
	hitung_durasi(); // PROSES PENGHITUNGAN DURASI PENCUCIAN MOBIL

	pilihan = pilih_tempat_cuci(); // PROSES PEMILIHAN TEMPAT CUCI BERDASARKAN DURASI TERPENDEK YANG AKAN SELESAI DARI PROSES PENCUCIAN
	switch(pilihan){
		case 0:
			tempat = tempat_cuci_1;
			enqueue_proses(data_inputan,tempat,pilihan);
			break;

		case 1:
			tempat = tempat_cuci_2;
			enqueue_proses(data_inputan,tempat,pilihan);
			break;
	}
}
// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2 - END



// FUNCTION UNTUK MENGHITUNG DURASI PENCUCIAN MOBIL
void hitung_durasi(){
	antrian_cuci *tempat1,*tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	jumlah_durasi[0] = 0;
	jumlah_durasi[1] = 0;
	
	if(tempat_cuci_1 == NULL){
		jumlah_durasi[0] = 0;
	}else{
		while(tempat1 != NULL){
			jumlah_durasi[0] += tempat1->durasi;
			tempat1 = tempat1->next;
		}	
	}

	if(tempat_cuci_2 == NULL){
		jumlah_durasi[1] = 0;
	}else{
		while(tempat2 != NULL){
			jumlah_durasi[1] += tempat2->durasi;
			tempat2 = tempat2->next;
		}
	}
}
// FUNCTION UNTUK MENGHITUNG DURASI PENCUCIAN MOBIL - END



// FUNCTION UNTUK PROSES PENENTUAN TEMPAT CUCI MOBIL
int pilih_tempat_cuci(){
	int c, d, swap;
	int jumlah_durasi_asc[2];

	jumlah_durasi_asc[0] = jumlah_durasi[0];
	jumlah_durasi_asc[1] = jumlah_durasi[1];
	
        
	for (d = 0; d < 1; d++){            
  		if (jumlah_durasi_asc[d] > jumlah_durasi_asc[d+1]){
    		swap = jumlah_durasi_asc[d];
    		jumlah_durasi_asc[d] = jumlah_durasi_asc[d+1];
    		jumlah_durasi_asc[d+1] = swap;
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
// FUNCTION UNTUK PROSES PENENTUAN TEMPAT CUCI MOBIL



// FUNCTION UNTUK ENQUEUE DATA KE LIST
void enqueue_proses(antrian_cuci *data_inputan, antrian_cuci *tempat, int pilihan){
	// DEKLARASI VARIABEL
	antrian_cuci *data_inputan_langsung_cuci;

	data_inputan_langsung_cuci = data_inputan;
	data_inputan_langsung_cuci->waktu_proses = pukul_waktu;
	data_inputan_langsung_cuci->waktu_out = pukul_waktu + data_inputan->durasi;
	
	if(tempat == NULL){
		switch(pilihan){
		case 0:
			tempat_cuci_1 = data_inputan_langsung_cuci;
			break;
		case 1:
			tempat_cuci_2 = data_inputan_langsung_cuci;
			break;
		}
	}else{
		while(tempat->next != NULL){
			tempat = tempat->next;
		}
		data_inputan->next = NULL;
		tempat->next = data_inputan;		
	}	
}
// FUNCTION UNTUK ENQUEUE DATA KE LIST - END



// FUNCTION UNTUK PUSH NOTIFIKASI
void notifikasi_status(char no_plat[], int golongan){
	// DEKLARASI VARIABEL LOKAL
	int temp_waktu;

	printf("\n");
	printf("Mobil dengan Plat Nomor %s berhasil ditambahkan keantrian pada tempat cuci no - %d, perkiraan durasi pencucian",no_plat, antrean+1);

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
			printf(" %d menit dan durasi antri sekitar",temp_waktu);
			printf(" %d menit.\n",jumlah_durasi[0]);
			break;

		case 1:
			printf(" %d menit dan durasi antri sekitar",temp_waktu);
			printf(" %d menit.\n",jumlah_durasi[1]);
			break;
		
	}
}
// FUNCTION UNTUK PUSH NOTIFIKASI - END