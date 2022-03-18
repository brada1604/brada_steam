#ifndef antrian_h
#define antrian_h



// DEKLARASI MODUL
int main_antrian();
void data_antrian();
void menu(int *pm);
void menuTerpilih(int mt,int *exit);
void tombol_selanjutnya();
int cekNama(char alias[], int *flag);
int tipeCuci();
void countAntre();
void countUmur();
void enqueue(char alias[],int tipe);
int pilih();
void enq(struct antre *make, struct antre *temp, int choice);
void notif(char alias[], int tipe);
void simulasiWaktu();
void checkUmurStart();
void dequeue(int pilih);
void tambahPendapatan(int pilih);
void keluarin(int flag,char alias[]);
int out(char alias[], struct antre* temp);
void tampilanAwal();
void header_aplikasi();
void bantuan_aplikasi();
void footer_aplikasi();
int isEmpty();
// DEKLARASI MODUL

#endif
