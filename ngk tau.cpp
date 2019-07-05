#include <iostream> 	//library input/output
#include <conio.h>		//disini digunakan untuk menyediakan fungsi getch();
#include <time.h>		//disini digunakan untuk menyediakan fungsi time();
#include <fstream>		//digunakan untuk menyediakan fungsi file akses
#include <sstream>		
#include <windows.h>	

using namespace std;
void gotoxy (int x, int y ){
	COORD coord; // Mendeklarasikan kordinat
	coord.X = x;
	coord.Y =  y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct semua{
	string status;
	int pilih;
	int bayar;
	int total;
	int berat=1;
	char nama[100];
	char alamat[70];
	char nomor_hp[15];
	int tanggal;
	int kode;
	int danis;
	string nota;
}ai;

struct database{
	string nama[200];
	string kode[200];
	string paket[200];
	string status[200];
}db;

class programkasir_JCO{
	public:
		void menu();
		void conversation();
		void toeflpre();
		void ieltspre();
		void teenspro();
		void kiddiepro();
		void privatepro();
	private:
		int pil;
		int total, pembayaran, kembalian;
};

class all{
	public:
		
//fungsi hitung
	string hitung(float hg, float brt, float byr){
	string hsil;
	ai.total=byr-(hg*brt);
	if(ai.total>0){
		hsil="Sisa";
	}else if(ai.total<0){
		ai.total-=2*ai.total;
		hsil="Hutang";
	}
	else{
		hsil="Lunas";
	}
	return hsil;
}

//fungsi load
	int load(){
	int i=1;
	ifstream load("data.txt");
	if(!load.is_open())
		cout<<"File Tidak Bisa Dibuka"<<endl;
	while(load.good()){
		getline(load,db.kode[i],',');
	   	getline(load,db.nama[i],',');
	   	getline(load,db.paket[i],',');
	   	getline(load,db.status[i],'\n');
	   	i++;
	}
	load.close();
	return i-2;
}

//fungsi convert
	string convert(int a){
	stringstream ubah;
	ubah<<a;
	return ubah.str()+".txt";
}
}cl;

void menu_utama();
void cek_data();
void header(){
	cout<<"             +=========================================================================+\n";
	cout<<"             +                                     J.CO                                +"<<endl;
	cout<<"             +=========================================================================+"<<endl;
	cout<<"             +                        Jalan Adi SUdjipto, Yogyakarta                   +"<<endl;
	cout<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	cout<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
}

main(){
	system("color 70");
	menu_utama();
}
//Menu Utama
void menu_utama(){
	programkasir_JCO masuk;
	menuawal:
	system("cls");
	header();
	cout<<"             [1] DAFTAR MENU"<<endl;
	cout<<"             [2] CEK DATA PELANGGAN"<<endl;
	cout<<"             [3] Keluar"<<endl<<endl;
	cout<<"             [ ] Masukkan Pilihan : ";	cin>>ai.pilih;
	if(ai.pilih==1){
		masuk.menu();
	}
	else if(ai.pilih==2){
		cek_data();
	}
	else if(ai.pilih==3){
		system("exit");
	}
	else{
		cout<<"Masukkan Tidak Benar";	getch();
		goto menuawal;
	}
}
//Menu 1
//pendeklarasian function untuk bisa dipanggil pada function dibawahnya!!!
//function untuk menu laundry
void pendataan();
void donut();
void paket();
void coffe();
void hitung();
void programkasir_JCO::menu(){
	
	awal:
	system("cls");
	header();
	cout<<"             MENU\n\n";
	cout<<"              - [1]. DONUT\n";
	cout<<"              - [2]. COFFEE\n";
	cout<<"              - [3]. PAKET\n";
	cout<<"              - [6]. Menu Utama\n\n";
	cout<<"              - Masukkan Pilihan : ";	cin>>ai.pilih;
	if(ai.pilih==1){
		donut();
		goto awal;
	}
	else if(ai.pilih==2){
		coffe();
		goto awal;
	}
	else if(ai.pilih==3){
		paket();
		goto awal;
	}
	else if(ai.pilih==6){
		menu_utama();
	}
	else{
		cout<<"Pilihan Anda Tidak Ada";
		getch();
		goto awal;
	}
}
void pendataan(){
	srand((unsigned)time(0)); 
	cout<<"             +=========================================================================+\n";
	cout<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	cout<<"             +=========================================================================+"<<endl;
	cout<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	cout<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	cout<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"             Masukkan Nama                 : ";	cin.get(); gets(ai.nama);
	cout<<"             ___________________________________________________________________________"<<endl;
	cout<<"             Masukkan Tanggal Masuk        : "; 	cin>>ai.tanggal;
	cout<<"             ___________________________________________________________________________"<<endl;
	cout<<"             Masukkan Alamat               : ";	cin.get(); gets(ai.alamat);
	cout<<"             ___________________________________________________________________________"<<endl;
	cout<<"             Masukkan No.Hp                : ";	gets(ai.nomor_hp);
	cout<<"             ___________________________________________________________________________"<<endl;

	ai.kode = (rand()%1000);
}

void hasil(int hrg, int wkt, string kd){
	
	//Menampilkan Data Pelanggan	
	
	system("cls");
	cout<<"{}=============================================================={}"<<endl;
	for(int j=1; j<15; j++){
		gotoxy(0,j); cout<<"||";
	}
	for(int j=1; j<15; j++){
		gotoxy(64,j); cout<<"||";
	}
	cout<<endl<<"{}=============================================================={}"<<endl;
	gotoxy(27,1); 	cout<<"SWIFT COURSE"<<endl;
	gotoxy(17,2); 	cout<<"Jalan Selokan Mataram No.1 Condongcatur"<<endl;
	gotoxy(6,4);	cout<<"Nama            : "<<ai.nama<<endl;
	gotoxy(6,5);	cout<<"Alamat          : "<<ai.alamat<<endl;
	gotoxy(6,6);	cout<<"No.Hp           : "<<ai.nomor_hp<<endl;
	gotoxy(6,7);	cout<<"Tanggal Masuk   : "<<ai.tanggal<<" Juni 2018";
	//gotoxy(35,7);	cout<<"Tgl Selesai     : "<<ai.tanggal+wkt<<" Juli 2018";
	gotoxy(35,5);	cout<<"Pilihan Paket   : "<<kd<<endl;
	gotoxy(35,6);	cout<<"Kode Program    : "<<ai.kode<<endl;
	gotoxy(2,3);	cout<<"==============================================================";
	if(ai.status=="Lunas"){
		gotoxy(35,4);	cout<<"Status          : "<<ai.status;
		gotoxy(50,14);	cout<<"Rp."<<ai.total;
	}else if(ai.status=="Sisa"){
		gotoxy(35,4);	cout<<"Status          : "<<ai.status;
		gotoxy(33,14);	cout<<"Sisa Bayar";
		gotoxy(50,14);	cout<<"Rp."<<ai.total;
	}else{
		gotoxy(35,4);	cout<<"Status          : "<<ai.status;
		gotoxy(33,14);	cout<<"Utang Bayar";
		gotoxy(50,14);	cout<<"Rp."<<ai.total;
	}				
	gotoxy(5,8);	cout<<" ============================================================ "<<endl;
	gotoxy(5,9);	cout<<" | Banyak Pendaftar |       INVESTMENT       |   TOTAL      | "<<endl;
	gotoxy(5,10);	cout<<" |                  |                        |              | "<<endl;
	gotoxy(5,11);	cout<<" |------------------|------------------------|--------------| "<<endl;
	gotoxy(5,12);	cout<<" |                  |                        |              | "<<endl;
	gotoxy(5,13);	cout<<" |                  |                        |              | "<<endl;
					
	gotoxy(12,10);	cout<<ai.berat<<" Orang"<<endl;
	gotoxy(33,10);	cout<<"Rp."<<hrg;
	gotoxy(50,10);	cout<<"Rp."<<ai.berat*hrg;	
	gotoxy(7,13);	cout<<"__________________________________________________________ ";
	gotoxy(33,12);	cout<<"Dibayar";
	gotoxy(52,12);	cout<<"Rp."<<ai.bayar;
	
	//Menyimpan Data Ke File Txt

	ai.nota=cl.convert(ai.kode);
	ofstream nota(ai.nota.c_str());
	nota<<"             +=========================================================================+\n";
	nota<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	nota<<"             +=========================================================================+"<<endl;
	nota<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	nota<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	nota<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	nota<<"             +=========================================================================+"<<endl<<endl;
	nota<<"              - Nama          : "<<ai.nama<<endl; 				
	nota<<"              - Alamat        : "<<ai.alamat<<endl; 					
	nota<<"              - No.Hp         : "<<ai.nomor_hp<<endl; 		
	nota<<"              - Tgl Masuk     : "<<ai.tanggal<<endl; 	
	//nota<<"              - Tgl Selesai   : "<<ai.tanggal+wkt<<" Per Mei 2018"<<endl;
	nota<<"              - Status        : "<<ai.status<<endl;
	nota<<"              - Pilihan Paket : "<<kd<<endl;	
	nota<<"              - Kode Program  : "<<ai.kode<<endl;
	nota<<"             +=========================================================================+"<<endl;
	nota<<"              - Pendaftar\t\t: "<<ai.berat<<endl;
	nota<<"              - INVESTMENT\t\t: Rp. "<<hrg<<",-"<<endl;
	nota<<"              - TOTAL\t\t\t: Rp. "<<ai.berat*hrg<<",-"<<endl;
	nota<<"              - Dibayar\t\t\t: Rp. "<<ai.bayar<<",-"<<endl;
	nota<<"              - Status\t\t\t: "<<ai.status<<" Rp. "<<ai.total<<",-"<<endl;
	nota.close();
	
	nota.open("NOTA SWIFT COURSE.txt");
	nota<<"             +=========================================================================+\n";
	nota<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	nota<<"             +=========================================================================+"<<endl;
	nota<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	nota<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	nota<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	nota<<"             +=========================================================================+"<<endl<<endl;
	nota<<"              - Nama          : "<<ai.nama<<endl; 				
	nota<<"              - Alamat        : "<<ai.alamat<<endl; 					
	nota<<"              - No.Hp         : "<<ai.nomor_hp<<endl; 		
	nota<<"              - Tgl Masuk     : "<<ai.tanggal<<endl; 	
//	nota<<"              - Tgl Selesai   : "<<ai.tanggal+wkt<<" Per Mei 2018"<<endl;
	nota<<"              - Status        : "<<ai.status<<endl;
	nota<<"              - Pilihan Paket : "<<kd<<endl;	
	nota<<"              - Kode Program  : "<<ai.kode<<endl;
	nota<<"             +=========================================================================+"<<endl<<endl;
	nota<<"              - Banyaknya Pendaftar\t: "<<ai.berat<<endl;
	nota<<"              - INVESTMENT\t\t: Rp. "<<hrg<<",-"<<endl;
	nota<<"              - TOTAL\t\t\t: Rp. "<<ai.berat*hrg<<",-"<<endl;
	nota<<"              - Dibayar\t\t\t: Rp. "<<ai.bayar<<",-"<<endl;
	nota<<"              - Status\t\t\t: "<<ai.status<<" Rp. "<<ai.total<<",-"<<endl;
	
	//membuat nota 
	//Membuat Database
	ofstream data_pelanggan("data.txt",ios::app);
	data_pelanggan<<ai.kode<<","<<ai.nama<<","<<kd<<","<<ai.status<<endl;
	data_pelanggan.close();
	gotoxy(30,18); cout<<"Enter Untuk kembali";	getch();
}

void programkasir_JCO::donut(){
	int harga=8000;
	int waktu=4;
	int pil;
	string kode="Donut";
	system("cls");
	cout<<"             +=========================================================================+\n";
	cout<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	cout<<"             +=========================================================================+"<<endl;
	cout<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	cout<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	cout<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                                                 DONUT"<<endl;
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"				>>=====PILIHAN VARIANT================HARGA====<<:||\n";
    cout<<"				|| 1.  Alcapone   	    		 	  Rp.8.000,-  ||\n";
  	cout<<"				|| 2.  Tira Miss U   	    		  Rp.8.000,-  ||\n";
  	cout<<"				|| 3.  Choco Caviar Chocolate   	  Rp.8.000,-  ||\n";
  	cout<<"				|| 4.  Mixed Favorite   	    	  Rp.8.000,-  ||\n";
	cout<<"				|| 5.  Choco Caviar Strawberry   	  Rp.8.000,-  ||\n";
  	cout<<"				|| 6.  Oreology   	    		 	  Rp.8.000,-  ||\n";
	cout<<"				|| 7.  Coco Loco   	    		      Rp.8.000,-  ||\n";
    cout<<"				|| 8.  Glazzy   	    		 	  Rp.8.000,-  ||\n";	
  	cout<<"				|| 9.  Crunchy Crunchy   	    	  Rp.8.000,-  ||\n";
  	cout<<"				|| 10. Forest Glam    	    		  Rp.8.000,-  ||\n";
    cout<<"				|| 11. Heaven Berry   	    		  Rp.8.000,-  ||\n";
    cout<<"				|| 12. Avocado   	    		 	  Rp.8.000,-  ||\n";
  	cout<<"				||=================================================||\n";cout<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
	
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"             - Tekan 1 Untuk Mendaftar\n";
	cout<<"             - Tekan 2 Untuk Kembali Ke Menu\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Masukkan Pilihan : "; cin>>pil;
	if(pil==1){
		system("cls");
		pendataan();
	}
	else{
		menu();
	}
	cout<<"             Total Harga\t\t: Rp."<<ai.berat*harga<<endl;
	cout<<"             Masukkan Jumlah Bayar\t: "; 
	cin>>ai.bayar;
	ai.status=cl.hitung(harga, ai.berat, ai.bayar);
	hasil(harga, waktu, kode);
	getch();
}

void programkasir_JCO::toeflpre(){
	int harga=3000000;
	int waktu=30;
	string kode="TOEFL";
	system("cls");
	header();
	cout<<"             +=========================================================================+\n";
	cout<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	cout<<"             +=========================================================================+"<<endl;
	cout<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	cout<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	cout<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                                                  TOEFL Class"<<endl<<endl;
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"                   DESKRIPSI\n\n";
	cout<<"             Semua soal dalam TOEFL mempunyai tipe yang sama, jadi hampir bisa\n";
	cout<<"             dipastikan bahwa tipe soal tertentu akan keluar dalam TOEFL. Jadi\n";
	cout<<"             untuk bisa menaklukan soal TOEFL, yang kita perlukan adalah mengetahui\n";
	cout<<"             tipe soal yang biasa keluar dan cara mengerjakannya.\n\n";
	cout<<"             Dalam program TOEFL Preparation akan dibahas tiga bagian dalam TOEFL\n";
	cout<<"             PBT yaitu Listening Comprehension, Structure and Written Expression dan\n";
	cout<<"             Reading Comprehension.\n\n";
	cout<<"             Di program TOEFL Preparation di SWIFT ENGLISH SCHOOL ditujukan untuk\n";
	cout<<"             mengupas tuntas jenis-jenis soal-soal yang keluar dalam TOEFL dan cara\n";
	cout<<"             mengatasinya.\n\n";
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                   FASILITAS\n\n";
	cout<<"             - INVESTMENT Rp. 3000.000,-\n";
	cout<<"             - 18x pertemuan, 90 menit/pertemuan\n";
	cout<<"             - Modul\n";
	cout<<"             - Materi digital tambahan\n";
	cout<<"             - Speaking Club\n";
	cout<<"             - Kelas semi privat\n";
	cout<<"             - Garansi skor TOEFL 450\n";
	cout<<"             - Konsultasi seumur hidup\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Tekan 1 Untuk Mendaftar\n";
	cout<<"             - Tekan 2 Untuk Kembali Ke Menu\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Masukkan Pilihan : "; cin>>pil;
	if(pil==1){
		system("cls");
		pendataan();
	}
	else{
		menuprogram(;
	}
	cout<<"             Total Harga\t\t: Rp. "<<ai.berat*harga<<",-"<<endl;
	cout<<"             Masukkan Jumlah Bayar\t: "; cin>>ai.bayar;
	ai.status=cl.hitung(harga, ai.berat, ai.bayar);
	hasil(harga, waktu, kode);	
}

void ::ieltspre(){
	int harga=4000000;
	int waktu=30;
	string kode="IELTS";
	system("cls");
	header();
	cout<<"             +=========================================================================+\n";
	cout<<"             +                              SWIFT ENGLISH COURSE                       +"<<endl;
	cout<<"             +=========================================================================+"<<endl;
	cout<<"             +                      Jalan Selokan Mataram No.1 Condongcatur            +"<<endl;
	cout<<"             +                          Kecamatan Depok Kabupaten Sleman               +"<<endl;
	cout<<"             +                          Daerah Istimewa Yogyakarta 55283               +"<<endl;
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                                                IELTS Program"<<endl<<endl;
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"                     DESKRIPSI IELTS PROGRAM\n\n";
	cout<<"             Program ini diperuntukkan bagi kalian yang membutuhkan tes IELTS sebagai\n";
	cout<<"             syarat melanjutkan study ke Aussie maupun Inggris. Tes IELTS mempunyai -\n";
	cout<<"             empat bagian tes dengan tingkat kesulitan khusus Listening, Reading, -\n";
	cout<<"             Writing dan Speaking. Masing-masing bagian tersebut perlu strategi yang\n";
	cout<<"             berbeda-beda. Untuk bisa mendapatkan skor maksimal kita harus tahu stra\n";
	cout<<"             tegi yang tepat untuk menghadapi masing-masing bagian tersebut.\n\n";
	cout<<"             Program IELTS preparation memberikan simulasi tes IELTS beserta dengan\n";
	cout<<"             pembahasannya. Dalam program ini kalian akan mendapatkan teknik-teknik\n";
	cout<<"             keren buat naklukin IELTS seperti paraphrasing, skimming dan scanning,-\n";
	cout<<"             lying for good, dan banyak teknik lain yang akan kalian dapatkan. Program\n";
	cout<<"             ini diampu oleh tutor lokal dan juga native speaker. kita harus tahu stra\n";
	cout<<"             tegi yang tepat untuk menghadapi masing-masing bagian tersebut.\n\n";
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                     FASILITAS\n\n";
	cout<<"             - INVESTMENT (Rp. 2.500.000)\n";
	cout<<"             - 30x pertemuan, 90 menit/pertemuan\n";
	cout<<"             - Modul, Materi tambahan digital\n";
	cout<<"             - Native speaker\n";
	cout<<"             - Speaking Club\n";
	cout<<"             - Kelas semi privat\n";
	cout<<"             - Garansi skor IELTS 5.5\n";
	cout<<"             - Konsultasi seumur hidup\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Tekan 1 Untuk Mendaftar\n";
	cout<<"             - Tekan 2 Untuk Kembali Ke Menu\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Masukkan Pilihan : "; cin>>pil;
	if(pil==1){
		system("cls");
		pendataan();
	}
	else{
		menuprogram();
	}
	cout<<"             Total\t\t\t   : Rp. "<<ai.berat*harga<<",-"<<endl;
	cout<<"             Masukkan Jumlah Bayar\t   : "; cin>>ai.bayar;
	ai.status=cl.hitung(harga, ai.berat, ai.bayar);
	hasil(harga, waktu, kode);
	getch();
}

void programkursus::teenspro(){
	int harga=2000000;
	int waktu=30;
	string kode="TeensClass";
	system("cls");
	header();
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                                     Conversation Class\n\n"<<endl;
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             	Deskripsi Teens Program\n\n";
	cout<<"             Dalam program ini kalian mendapatkan materi listening, reading, writing"<<endl;
	cout<<"             dan speaking serta tata bahasa. Materi dalam program ini mengacu pada"<<endl;
	cout<<"             kurikulum nasional. Jadi tujuan akhir dari program ini selain membiasakan"<<endl;
	cout<<"             kalian untuk secara langsung menggunakan bahasa Inggris dalam aktfitas\n";
	cout<<"             sehari-hari juga agar kalian terbiasa menghadapi soal bahasa Inggris.\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             	FASILITAS\n\n";
	cout<<"             - 30x pertemuan\n";
	cout<<"             - 60 menit/pertemuan\n";
	cout<<"             - CD dan modul pembelajaran\n";
	cout<<"             - Konsultasi gratis seumur hidup\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Tekan 1 Untuk Mendaftar\n";
	cout<<"             - Tekan 2 Untuk Kembali Ke Menu\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Masukkan Pilihan : "; cin>>pil;
	if(pil==1){
		system("cls");
		pendataan();
	}
	else{
		menuprogram();
	}
	cout<<"             Total\t\t\t   : Rp. "<<ai.berat*harga<<",-"<<endl;
	cout<<"             Masukkan Jumlah Bayar\t   : ";
	cin>>ai.bayar;
	ai.status=cl.hitung(harga, ai.berat, ai.bayar);
	hasil(harga, waktu, kode);
	getch();
}

void programkursus::kiddiepro(){
	int harga=1000000;
	int waktu=30;
	string kode="KiddyProgram";
	system("cls");
	header();
	cout<<"             +=========================================================================+"<<endl<<endl;
	cout<<"                                     KIDDY Program\n"<<endl;
	cout<<"             Deskripsi\n\n";
	cout<<"             Dalam program ini kalian mendapatkan materi listening, reading, writing"<<endl;
	cout<<"             dan speaking serta tata bahasa. Materi dalam program ini mengacu pada"<<endl;
	cout<<"             kurikulum nasional. Jadi tujuan akhir dari program ini selain membiasakan"<<endl;
	cout<<"             kalian untuk secara langsung menggunakan bahasa Inggris dalam aktfitas\n";
	cout<<"             sehari-hari juga agar kalian terbiasa menghadapi soal bahasa Inggris.\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             FASILITAS\n\n";
	cout<<"             - INVESTMENT (Rp. 1000.000)\n";
	cout<<"             - 18x pertemuan\n";
	cout<<"             - 90 menit/pertemuan\n";
	cout<<"             - Modul, CD pembelajaran\n";
	cout<<"             - Speaking Club\n";
	cout<<"             - Kelas semi private\n";
	cout<<"             - Konsultasi seumur hidup\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Tekan 1 Untuk Mendaftar\n";
	cout<<"             - Tekan 2 Untuk Kembali Ke Menu\n\n";
	cout<<"             ___________________________________________________________________________"<<endl<<endl;
	cout<<"             - Masukkan Pilihan : "; cin>>pil;
	if(pil==1){
		system("cls");
		pendataan();
	}
	else{
		menu();
	}
	cout<<"             Total\t\t\t   : Rp. "<<ai.berat*harga<<",-"<<endl;
	cout<<"             Masukkan Jumlah Bayar\t   : ";
	cin>>ai.bayar;
	ai.status=cl.hitung(harga, ai.berat, ai.bayar);
	hasil(harga, waktu, kode);
	getch();
}


void baca_nota(string nm){
	system("cls");
	char bc;
	ifstream bc_nota(nm.c_str());
	if(!bc_nota.fail()){
	while(!bc_nota.eof()){
		bc_nota.get(bc);
		cout<<bc;
	}cout<<"             Enter Untuk Kembali";	getch();
	}else{
		cout<<"             File Tidak Ditemukan"; getch();
	}
	bc_nota.close();	
}

void data_pelanggan(){
	system("cls");
	int a=1;
	int batas=cl.load();
	cout<<"                               DATA PELANGGAN                      "<<endl;
	cout<<"[]========================================================================[]"<<endl;
	cout<<"|| NO | KODE |         NAMA PELANGGAN         | NAMA PROGRAM |   STATUS   ||"<<endl;
	cout<<"[]========================================================================[]"<<endl;
	for(a; a<=batas; a++){
		gotoxy(0,a+3);
		cout<<"||";
		gotoxy(3,a+3);
		cout<<a;
		gotoxy(6,a+3);
		cout<<"|";
		gotoxy(8,a+3);
		cout<<db.kode[a];
		gotoxy(13,a+3);
		cout<<"|";
		gotoxy(16,a+3);
		cout<<db.nama[a];
		gotoxy(46,a+3);
		cout<<"|";
		gotoxy(48,a+3);
		cout<<db.paket[a];
		gotoxy(60,a+3);
		cout<<"|";
		gotoxy(64,a+3);
		cout<<db.status[a];
		gotoxy(73,a+3);
		cout<<"||";
	}
	cout<<endl<<"[]=======================================================================[]"<<endl<<endl;
	cout<<"Total Pelanggan : "<<batas<<endl;
}

void cek_data(){
	programkursus masuk;
	menudata:
	data_pelanggan();
	cout<<"Masukkan Kode Program Untuk Lihat Detail\n";
	cout<<"Atau Tekan 0 Untuk Kembali : ";
	cin>>ai.kode;
	if(ai.kode==0){
		menu_utama();
	}else{
		ai.nota=cl.convert(ai.kode);
		baca_nota(ai.nota);
		goto menudata;
	}	
}
