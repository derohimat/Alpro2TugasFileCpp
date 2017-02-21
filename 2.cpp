#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void pMenu() {
	cout<<"Pilih Salah satu menu dibawah: "<<endl;
	cout<<"1. Buat File teks"<<endl;
	cout<<"2. Tambah data file"<<endl;
	cout<<"3. k kajskda sk"<<endl;
	cout<<"4. Hapus File teks"<<endl;
	cout<<"5. Exit"<<endl<<endl;
}

int main() {
	int menu;
	int go = 1;
	char filename[100];
	string filedata;
	fstream myFile;
		
	while(go == 1) {
		pMenu();
		cout<<"Pilih Menu: ";cin>>menu;
		go = 1;
		switch(menu) {
			case 1:
				cout<<"Masukan Nama File: ";cin>>filename;
				strcat(filename,".txt"); 
				myFile.open(filename, ios::out);	
				cout<<"File "<<filename<<" telah dibuat!!"<<"\n\n";
				myFile.close();
				break;                   
			case 2:
				myFile.open(filename, ios::in);
				if(myFile.is_open()) {
					ofstream temp; // variable temp for edit file.
					temp.open(filename, ios::out);
					cout<<"Masukan kata atau kalimat: ";
					cin.ignore(); getline(cin, filedata);
					temp<<filedata;
					temp.close();	
					cout<<"Kata atau Kalimat '"<<filedata<<"' berhasil dimasukan!"<<"\n\n";
				} else {
					cout<<"Maaf anda harus membuat file terlebih dahulu!"<<"\n\n";
				}
				myFile.close();
				break;
			case 3:
				myFile.open(filename, ios::in);
				if(myFile.is_open()) {
					getline(myFile, filedata);
					if(filedata != "") {
						cout<<"Kata atau Kalimat yang tertulis dalam file adalah: "<<filedata<<"\n\n";
					} else {
						cout<<"File masih kosong. Silahkan isi!! \n\n";
					}
					myFile.close();	
				} else {
					cout<<"Maaf anda harus membuat file terlebih dahulu!"<<"\n\n";
				}
				break;
			case 4:
				myFile.open(filename, ios::in);
				if(myFile.is_open()) {
					myFile.close();
					remove(filename);
					cout<<"File '"<<filename<<"' telah berhasil dihapus!"<<"\n\n";
				} else {
					cout<<"Maaf anda harus membuat file terlebih dahulu!"<<"\n\n";
				}
				break;
			case 5:
				go = 0;
				system("cls");
				cout<<"Terima Kasih !!!";
				return 0;
				break;
			default:
				cout<<"Menu yang anda masukan tidak Valid"<<"\n\n";
		}	
	}
	
	return 0;
}
