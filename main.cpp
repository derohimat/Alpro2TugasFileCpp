#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "Utils.h"

Utils utils;
fstream myFile;
string fileName, fileData;
string TXT_EXT = ".txt";

void choiceMenu();

void tambahFile();

void writeFile();

void bacaFile();

void hapusFile();

void exitMenu();

using namespace std;

int main() {
    choiceMenu();
    return 0;
}

//Menu Function
void showMenu() {
    cout << "Pilih Salah satu menu dibawah :" << endl << endl
         << "1. Buat File teks" << endl
         << "2. Tambah data file" << endl
         << "3. Tampilkan data file" << endl
         << "4. Hapus File teks" << endl
         << "5. Exit" << endl << endl;
}

void choiceMenu() {
    int choice;

    //constants for menu choices
    const int ADD_FILE = 1,
            WRITE_FILE = 2,
            SHOW_FILE = 3,
            DELETE_FILE = 4,
            QUIT_CHOICE = 5;

    cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place

    do {
        showMenu();

        choice = utils.inputInt("Please select menu : ");

        //Validate menu selectio
        while (choice < ADD_FILE || choice > QUIT_CHOICE) {
            choice = utils.inputInt("Please enter a valid menu choice");
        }

        //If user does not want to quit, proceed.
        if (choice != QUIT_CHOICE) {
            switch (choice) {
                case ADD_FILE:
                    tambahFile();
                    break;
                case WRITE_FILE:
                    writeFile();
                    break;
                case SHOW_FILE:
                    bacaFile();
                    break;
                case DELETE_FILE:
                    hapusFile();
                    break;
                default:
                    exitMenu();
                    break;
            }
        }
    } while (choice != QUIT_CHOICE);
}

void tambahFile() {
//    fileName = utils.inputString("Masukan Nama file : ");

    cout << "Masukan Nama File: ";
    cin >> fileName;
    myFile.open(fileName + TXT_EXT, ios::out);
    utils.println("File " + fileName + " telah berhasil dibuat!");
    myFile.close();
}

void writeFile() {
    cout << "Masukan Nama File: ";
    cin >> fileName;
    myFile.open(fileName + TXT_EXT, ios::in);
    if (myFile.is_open()) {
        ofstream temp; // variable temp for edit file.
        temp.open(fileName, ios::out);
        utils.print("Masukan kata atau kalimat : ");
        cin.ignore();
        getline(cin, fileData);
        temp << fileData;
        temp.close();
        utils.println("Kata atau Kalimat " + fileData + " berhasil dimasukan!");
    } else {
        utils.println("Maaf anda harus membuat file terlebih dahulu!");
    }
    myFile.close();
}

void bacaFile() {
    cout << "Masukan Nama File: ";
    cin >> fileName;
    myFile.open(fileName + TXT_EXT, ios::in);
    if (myFile.is_open()) {
        getline(myFile, fileData);
        if (fileData != "") {
            utils.println("Kata atau Kalimat yang tertulis dalam file adalah : " + fileData);
        } else {
            utils.println("File masih kosong. Silahkan isi!!");
        }
        myFile.close();
    } else {
        utils.println("Maaf anda harus membuat file terlebih dahulu!");
    }
}

void hapusFile() {
    cout << "Masukan Nama File: ";
    cin >> fileName;
    myFile.open(fileName + TXT_EXT, ios::in);
    if (myFile.is_open()) {
        myFile.close();
//        if (remove(strcat(fileName, TXT_EXT)) != 0)
//            perror("Error deleting file");
//        else
//            puts("File successfully deleted");
//        utils.println("File   " + fileData + " telah berhasil dihapus!");
    } else {
        utils.println("Maaf anda harus membuat file terlebih dahulu!");
    }
    myFile.open(fileName, ios::in);
}

void exitMenu() {
    system("cls");
    utils.print("Terima kasih !!");
}
