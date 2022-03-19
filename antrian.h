#ifndef antrian_h
#define antrian_h

// DEKLARASI MODUL
int main_antrian();
void header_aplikasi();
void bantuan_aplikasi();
void footer_aplikasi();
void tombol_selanjutnya();
void data_antrian();
void konversi_waktu();
void input_kendaraan();
void cancel_kendaraan();
int cek_nopol(char no_plat[], int *tanda_tempat);
int jenis_kendaraan();
void keluarkan(int tanda_tempat, char no_plat[]);
int cek_antrian();
int keluar_kendaraan(char no_plat[], struct antrian_cuci *tempat);
void simulasi_waktu();
void cek_sisawaktu_cuci();
void dequeue(int pilih);
void hitung_total(int pilih);
void pra_enqueue(char no_plat[],int golongan);
void hitung_durasi();
int pilih_tempat_cuci();
void enqueue_proses(struct antrian_cuci *data_inputan, struct antrian_cuci *tempat, int pilihan);
void notifikasi_status(char no_plat[], int golongan);
// DEKLARASI MODUL

#endif

