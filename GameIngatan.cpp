#include <iostream>
#include <windows.h>

using namespace std;

void maingame();
void siap();
void result();

const int jml = 6;
int tebak[jml];
int menang=0, kalah=0;
bool statkalah = false;

int main(){
	system("title Game Mengingat !");
	int pil;
	do {
		system("cls");
		cout << "Game mengingat !\n\n";
		cout << "1. Mulai\n2. Keluar\n\nPilihan > "; cin >> pil;
		switch(pil){
			case 1 :{
				siap();
				break;
			}
			case 2 :{
				exit(0);
				break;
			}
			default :{
				cout << "\nPilihan Tidak Ada !\n";
				system("pause");
				break;
			}
		}
	} while (pil != 2);
}

void siap(){
	int detik = 5;
	while (detik != 0){
		system("cls");
		cout << "Siap mengingat dalam ";
		cout << detik;
		cout << " Detik";
		detik -=1;
		Sleep(1000);
	}
	cout << "\n";
	for (int i=0;i<jml;i++){
		tebak[i] = rand() % 2;
	}
	detik = 5;
	while (detik != 0){
		system("cls");
		cout << "Ingat !! \n\n";
		for (int z=0;z<jml;z++){
			if (tebak[z] == 0){
				cout << (z + 1) << ". PING\n";
			} else {
				cout << (z + 1) << ". PONG\n";
			}
		}	
		cout << "\nPermainan Akan dimulai dalam ";
		cout << detik;
		cout << " Detik !";
		detik -=1;
		Sleep(1000);
	}
	maingame();
}

void maingame(){
	int pil;
	for (int i=0;i<jml;i++){
		system("cls");
		cout << "Permainan dimulai \n\n";
		cout << "1. PING\n";
		cout << "2. PONG\n";
		cout << "\nTebakan ke-" << (i+1) << " > "; cin >> pil;
		if (tebak[i] != (pil - 1)){
			statkalah = true;
			i = jml;
		}
	}
	result();
}

void result(){
	if (statkalah == true){
		kalah += 1;
	} else {
		menang += 1;
	}
	system("cls");
	cout << "Hasil permainan !\n\n";
	cout << "Menang : " << menang << "\n";
	cout << "Kalah  : " << kalah << "\n";
	cout << "\n";
	system("pause");
	statkalah = false;
}
