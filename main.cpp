#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

struct Contact {
    int id;
    string name, surname, phoneNumber, email, address;
};

void loadTextFile(vector <Contact> & _contacts, string fileName) {
    fstream textFile;
    string textLine;
    fileName += ".txt";
    textFile.open(fileName.c_str(), ios::in);
    if (textFile.good() == false) {
        cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
        Sleep(2000);
        exit(0);
    }
    Contact temporaryContact;
    int numberOfLine = 1;
    //teraz wczytujemy z pliku do tablicy
    while (getline(textFile,textLine)) {
        switch (numberOfLine) {
        case 1:
            temporaryContact.id = atoi(textLine.c_str());
            break;
        case 2:
            temporaryContact.name = textLine;
            break;
        case 3:
            temporaryContact.surname = textLine;
            break;
        case 4:
            temporaryContact.phoneNumber = textLine;
            break;
        case 5:
            temporaryContact.email = textLine;
            break;
        case 6:
            temporaryContact.address = textLine;
            break;
        }
        if (numberOfLine == 6) {
            numberOfLine = 0;
            _contacts.push_back(temporaryContact);
        }
        numberOfLine++;
    }
    textFile.close();
}

void loadVectorToFile (vector <Contact> & _contacts, string fileName) {
    fstream textFile;
    textFile.open(fileName.c_str(), ios::out);
    if (textFile.good() == false) {
        cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
        Sleep(2000);
        exit(0);
    }
    int vectorSize = _contacts.size();
    for (int i = 0; i < vectorSize; i++) {
        textFile << _contacts[i].id << "|";
        textFile << _contacts[i].name << "|";
        textFile << _contacts[i].surname << "|";
        textFile << _contacts[i].phoneNumber << "|";
        textFile << _contacts[i].email << "|";
        textFile << _contacts[i].address << "|" << endl;
    }
    textFile.close();
}

int main() {
    vector <Contact> contacts;
    string originalFileName;
    cout << "Podaj nazwe pliku: ";
    getline(cin, originalFileName);
    loadTextFile(contacts, originalFileName);
    string newFileName = originalFileName + "_nowy_format.txt";
    ofstream temp (newFileName.c_str());
    loadVectorToFile (contacts, newFileName);
    cout << "Konwersja zakonczona! ";
    system("pause");
    return 0;
}
