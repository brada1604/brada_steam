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

// DEKLARASI VARIABEL GLOBAL
typedef struct antre *address;
struct antre{
	char nama[10];
	int tipe;
	int umur;
	address next;
};

antre *startSatu = NULL;
antre *startDua = NULL;


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

int main_antrian(){
	int pilih;
	int keluar;
	
	tampilanAwal();

	do{
		system("cls");

		header_aplikasi();

		data_antrian();

		menu(&pilih);

		menuTerpilih(pilih,&keluar);

	}while(keluar != 1);

	return 0;
}

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
	antre *tempat1, *tempat2;

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
	
	printf("\nPendapatan hari ini : Rp.%d",jumlah_pendapatan);
}

void menu(int *pilihan){
	printf("\n");
	printf("\n");
	printf("Silahkan Pilih Menu Dibawah :\n");
	printf("|=================================================|\n");
	printf("| 1. Input Kendaraan                              |\n");
	printf("| 2. Keluarkan Kendaraan Dari Antrian             |\n");
	printf("| 3. Simulasi waktu ( %d menit)                   |\n",clock);
	printf("| 4. Petunjuk                                     |\n");
	printf("| 5. Selesai                                      |\n");
	printf("|=================================================|\n");
	do{
		printf("Masukkan angka pada menu yang dipilih : ");
		scanf("%d",pilihan);
		if(*pilihan<1 || *pilihan>5){
			printf("Inputan Salah! silahkan isi lagi.\n");
		}
	}while(*pilihan<1 || *pilihan>5);	
}



// ////////////////////////////////////////////////////////////////




void menuTerpilih(int mt, int *exit){
	char alias[15];int dec, tipe, temp_waktu,flag,pil;
	switch(mt){
		case 1:
			do{
				printf("\nmasukkan nama (sebagai identitas dari mobil) :");scanf("%s",&alias);
				dec = cekNama(alias,&flag);
				if(dec != 0){
					printf("ada nama pemilik mobil yang sama. silahkan isi dengan nama yang berbeda.\n");
				}
			}while(dec != 0);
			tipe = tipeCuci();
			if(tipe == 4){break;}
			enqueue(alias, tipe);
			notif(alias, tipe);
			tombol_selanjutnya();
			*exit = 0;
			break;
		case 2:
			pil = isEmpty();
			if(pil == 0){
				printf("tidak ada mobil.");
				tombol_selanjutnya();
				break;
			}
			do{
				flag = 0;
				printf("\nmasukkan nama pemilik mobil yang mobilnya ingin dikeluarkan (jika tidak jadi isi 0) : ");scanf("%s",&alias);
				if(alias[0]=='0'){
					break;
				}
				dec = cekNama(alias,&flag);
				if(dec == 0){
					printf("tidak ada mobil dengan nama pemilik tersebut. silahkan isi dengan nama yang berbeda.\n");
				}
			}while(dec == 0);
			keluarin(flag,alias);
			*exit = 0;
			break;
		case 3:
			simulasiWaktu();
			*exit = 0;
			break;
		case 4:
			bantuan_aplikasi();
			*exit = 0;
			tombol_selanjutnya();
			break;
		case 5:
			pil = isEmpty();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				tombol_selanjutnya();
				*exit = 0;
				break;	
			}
			*exit = 1;
			system("cls");
			printf("Hari ini, dengan total waktu kerja %d menit, didapat penghasilan sebesar Rp.%d\n",jumlah_waktu,jumlah_pendapatan);
			printf("THANK YOU!!!\n\n");
			header_aplikasi();	
			break;
	}
}



int cekNama(char alias[], int *flag){
	antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;
	
	int check = 0;

	if(temp1 != NULL){
		while(temp1 != NULL){
			if(strcmp(alias,temp1->nama) == 0){
				check++;
				*flag = 1;	
			}
			temp1 = temp1->next;
		}	
	}
	if(temp2 != NULL){
		while(temp2 != NULL){
			if(strcmp(alias,temp2->nama) == 0){
				check++;
				*flag = 2;
			}
			temp2 = temp2->next;
		}	
	}
	
	return check;
}

int tipeCuci(){
	int ch;
	printf("\nNo.\t| Tipe\t\t\t\t| Lama Pengerjaan\t| harga\n");
	printf("1.\t| Standard\t\t\t| %d menit\t\t| Rp.%d\n",age[0],harga[0]);
	printf("2.\t| Standard + Kolong\t\t| %d menit\t\t| Rp.%d\n",age[1],harga[1]);
	printf("3.\t| Standard + Kolong + Mesin\t| %d menit\t\t| Rp.%d\n",age[2],harga[2]);
	printf("4. Tidak Jadi\n");
	do{
		printf("Pilihan : ");scanf("%d",&ch);
		if(ch<1 || ch>4){
			printf("pilihan diantara 1 - 4, silahkan isi lagi.\n");
		}
	}while(ch<1 || ch>4);
	return ch;
}

void countAntre(){
	
	int count;
	antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;

	
	count = 0;
	while(temp1 != NULL){
		temp1 = temp1->next;
		count++;
	}
	jumlahAntre[0] = count;
	
	count = 0;
	while(temp2 != NULL){
		
		temp2 = temp2->next;
		count++;
		
	}
	jumlahAntre[1] = count;
	
}

void countUmur(){
	antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;
	
	jumlahUmur[0] = 0;jumlahUmur[1] = 0;
	
	if(startSatu == NULL){
		jumlahUmur[0] = 0;
	}else{
		while(temp1!=NULL){
			jumlahUmur[0] += temp1->umur;
			temp1 = temp1->next;
		}	
	}
	if(startDua == NULL){
		jumlahUmur[1] = 0;
	}else{
		while(temp2!=NULL){
			jumlahUmur[1] += temp2->umur;
			temp2 = temp2->next;
		}
	}
}

void enqueue(char alias[], int tipe){
	int choice;
	
	antre *make, *temp;
	make = (antre*)malloc(sizeof(antre));
	
	if(make == NULL){
		printf("\nerror, tidak tersedia memori\n");
	}else{
		strcpy(make->nama,alias);
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
		}
	}
	
	countUmur();
	choice = pilih();
	switch(choice){
		case 0:
			temp = startSatu;
			enq(make,temp,choice);
			break;
		case 1:
			temp = startDua;
			enq(make,temp,choice);
			break;
	}
}

int pilih(){
	int c, d, swap;
	jumlahUmurAscending[0] = jumlahUmur[0];
	jumlahUmurAscending[1] = jumlahUmur[1];
	
	for (c = 0 ; c < 1; c++){                     // masih bingung
    	for (d = 0 ; d < 1 - c ; d++){            // masih bingung
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

void enq(antre *make, antre *temp, int choice){
	
	if(temp == NULL){
		switch(choice){
		case 0:
			startSatu = make;
			break;
		case 1:
			startDua = make;
			break;
		}
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		make->next = NULL;
		temp->next = make;		
	}	
}			

void simulasiWaktu(){
	if(startSatu != NULL){
		startSatu->umur -= clock;
	}
	if(startDua != NULL){
		startDua->umur -= clock;
	}
	checkUmurStart();
}

void notif(char alias[], int tipe){
	int temp_waktu;
	printf("\nmobil %s berhasil ditambahkan, perkiraan lama waktu hingga selesai adalah",alias);
	switch(tipe){
		case 1:
			temp_waktu = age[0];break;
		case 2:
			temp_waktu = age[1];break;
		case 3:
			temp_waktu = age[2];break;	
		}
	switch(antrean){
		case 0:
			printf(" %d menit.\n",jumlahUmur[0]+temp_waktu);break;
		case 1:
			printf(" %d menit.\n",jumlahUmur[1]+temp_waktu);break;
		
		}
}

void checkUmurStart(){
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
	antre *temp;
	switch(pilih){
		case 0:
			tambahPendapatan(startSatu->tipe);
			temp = startSatu;
			startSatu = startSatu->next;
			free(temp);
			break;
		case 1:
			tambahPendapatan(startDua->tipe);
			temp = startDua;
			startDua = startDua->next;
			free(temp);
			break;
		
	}
}

void tambahPendapatan(int pilih){
	switch(pilih){
		case 1:
			jumlah_pendapatan += harga[0];break;
			jumlah_waktu += age[0];
		case 2:
			jumlah_pendapatan += harga[1];break;
			jumlah_waktu += age[1];
		case 3:
			jumlah_pendapatan += harga[2];break;
			jumlah_waktu += age[2];
	}
}

void keluarin(int flag, char alias[]){
	antre *temp1,*temp2; 
	temp1 = startSatu;
	temp2 = startDua;

	
	switch(flag){
		case 1:
			out(alias,temp1);
			break;
		case 2:
			out(alias,temp2);
			break;	
	}
	tombol_selanjutnya();	
}

int out(char alias[], antre* temp){
	antre *freed;
	if(strcmp(alias,temp->nama) == 0){
		printf("\nmobil yang sedang dalam pencucian tidak bisa dikeluarkan, silahkan menunggu sebentar.\n");
	}else{
		while(strcmp(alias,temp->next->nama)!=0){
			temp = temp->next;
		}
		freed = temp->next;
		temp->next = temp->next->next;
		free(freed);
	}
}






	
int isEmpty(){
	int check;
	if(startSatu != NULL){
			check++;	
	}
	if(startDua != NULL){
			check++;
	}
	return check;
}

