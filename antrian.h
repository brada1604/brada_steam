#ifndef antrian_h
#define antrian_h



// DEKLARASI MODUL
int main_antrian();
void data_antrian();
// void menu(int *pm);
// void menuTerpilih(int mt,int *exit);
void tombol_selanjutnya();
int cek_nopol(char no_plat[], int *tanda_tempat);
int jenis_kendaraan();
void hitung_durasi();
void pra_enqueue(char no_plat[],int golongan);
int pilih_tempat_cuci();
void enqueue_proses(struct antrian_cuci *data_inputan, struct antrian_cuci *tempat, int pilihan);
void notifikasi_status(char no_plat[], int golongan);
void simulasi_waktu();
void cek_sisawaktu_cuci();
void dequeue(int pilih);
void hitung_total(int pilih);
void keluarkan(int tanda_tempat, char no_plat[]);
int keluar_kendaraan(char no_plat[], struct antrian_cuci *tempat);
// void tampilanAwal();
void header_aplikasi();
void bantuan_aplikasi();
void footer_aplikasi();
int cek_antrian();
void input_kendaraan();
void cancel_kendaraan();
// DEKLARASI MODUL

#endif
