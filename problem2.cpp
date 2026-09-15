#include <iostream>
using namespace std;

// fungsi buat ngitung panjang string
int hitungPanjang(const char* str){
	int panjang = 0; //panjang pesan
	while (str[panjang] != '\0'){
		panjang++;
	}
	return panjang;
}

// fungsi buat ngubah huruf kecil jadi huruf kapital
char kapital(char c){
	if (c >= 'a' && c <= 'z'){
		return c - 32;
	}
	return c;
}

//fungsi buat enkripsi
void enkripsi(const char* pesan){
	int panjang = hitungPanjang(pesan);
	if (panjang == 0) return;

	// ambil huruf pertama
	char hurufPertama = pesan[0];
	char hurufPertamaKapital = kapital(hurufPertama);

	//verifikasi huruf pertama alfabet
	if (hurufPertamaKapital < 'A' || hurufPertamaKapital > 'Z'){
		cout << hurufPertama;
	}else{
		cout << hurufPertamaKapital;
	}
	//tentukan nilai huruf sebelumnya(A=1, B=2....)
	int nilaiSebelumnya = hurufPertamaKapital - 'A' + 1;

	for (int i=1; i<panjang; i++){
		char c = pesan[i];
		char cKapital = kapital(c);

		// kalo bukan huruf, printout apa adanya
		if(cKapital < 'A' || cKapital > 'Z'){
			cout << c;
			continue;
		}

		int nilaiSekarang = cKapital - 'A' + 1;

		//geser sebanyak nilai dari huruf sebelumnya
		int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

		//pake modulo buat balikin nilainya kalo lebih dari Z(26), balikin lagi ke A
		nilaiBaru = (nilaiBaru - 1) % 26 + 1;
		
		//balikin lagi ke huruf kapital
		char hurufBaru = 'A' + nilaiBaru - 1;
		cout << hurufBaru;

		//perbarui nilai
		nilaiSebelumnya = nilaiSekarang;
	}

	cout << endl;
}


int main(){
	char inputUser[100];//maks 100 biar memori aman
	cout << "Masukkan pesan yang mau dienkripsi (maks 99 karakter): ";
	cin.getline(inputUser, 100);

	cout << "Hasil Sandi : ";
	enkripsi(inputUser);

	return 0;
}
	
