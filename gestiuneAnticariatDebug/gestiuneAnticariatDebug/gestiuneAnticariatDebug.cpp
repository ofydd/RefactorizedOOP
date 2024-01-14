#include "Comanda.h"


void showMenu() {
	cout << "Va rog alegeti un numar pentru a verifica functionalitatea unei cerinte:" << endl;
	cout << "1. Supraincarcarea operatorului += pentru a adauga un element in vector." << endl;
	cout << "2. Supraincarcarea operatorului -= pentru a sterge un element din vector. " << endl;
	cout << "3. Operatorul de acces pe baza de index." << endl;
	cout << "4. Serializarea si deserializarea in si din fisiere binare." << endl;
	cout << "5. Supraincarcarea operatorului << " << endl; 
	cout << "6. Supraincarcarea operatorului >> " << endl;
	cout << "0. Exit" << endl;

	cout << endl << endl << "Introduceti un numar: ";
}

void showOperatori()
{
	cout << "1. Pentru clasa Produs." << endl;
	cout << "2. Pentru clasa Carte. " << endl;
	cout << "3. Pentru clasa Vinyl. " << endl;
	cout << "4. Pentru clasa Comanda" << endl;
}


int main()
{
	try
	{	
		
		Produs* pRandom = new Produs(12345, 1, 1, Status::Inactiv);

		Vinyl* mercyfulFate = new Vinyl(1, 1, 150, Status::Activ, "Don't break the oath", "Mercyful Fate", 10, 48, genMuzical::Metal);
		Vinyl* ironMaiden = new Vinyl(666, 1, 100, Status::Activ, "The Number Of The Beast", "Iron Maiden", 8, 39, genMuzical::Metal);
		Vinyl* deepPurple = new Vinyl(2, 1, 170, Status::Activ, "Deep Purple in Rock", "Deep Purple", 7, 44, genMuzical::Rock);
		Vinyl* beethoven9 = new Vinyl(3, 1, 20, Status::Activ, "Simfonia Nr. 9 in Re Minor. Dirijor: Iosif Conta", "Ludwig van Beethoven", 1, 74, genMuzical::Clasica);

		Carte* eliadeHistoire1 = new Carte(4, 2, 50, Status::Activ, "Istoria credintelor si ideilor religioase, vol. 1", "Mircea Eliade", "Polirom", 424, 2011, genLiterar::IstoriaReligiilor);
		Carte* kantCRP = new Carte(5, 1, 75, Status::Activ, "Critica Ratiunii Pure", "Immanuel Kant", "Editura Stiintifica", 1969, 699, genLiterar::Filosofie);
		Carte* dostoievskiCP = new Carte(6, 1, 20, Status::Activ, "Crima si Pedeapsa", "F.M Dostoievski", "Venus", 1993, 537, genLiterar::Proza);

		Comanda co;
		co.setIDComanda(122);
		co.setNumeClient("Oprea");
		co.setPrenumeClient("Ovidiu");
		co.setValoareComanda(400); //TODO: Ar trebui sa schimbam asta, ca sa calculeze pretul

		co += mercyfulFate;
		co += ironMaiden;
		co += deepPurple;
		co += beethoven9;

		co += eliadeHistoire1;
		co += dostoievskiCP;

		ifstream ifs;
		ofstream ofs;
		string filename = "comenzi\\" + to_string(co.getIDComanda()) + ".bin";
		
		Produs* pTemp = new Produs();
		Carte* cTemp = new Carte();
		Vinyl* vTemp = new Vinyl();

		Comanda coTemp;

		showMenu();
		short int choice;
		cin >> choice;

		switch (choice)
			{
			case 1:
				cout << "Inainte de adaugare: " << endl;
				cout << co << endl << endl << endl;
				co += kantCRP;
				cout << "Dupa adaugare: " << endl;
				cout << co;
				co -= kantCRP; //readuc vectorul de comenzi de produse de baza la normal.

				break;
			case 2:
				cout << "Inainte de stergere: " << endl;
				cout << co;
				co -= eliadeHistoire1;
				cout << "Dupa stergere: " << endl;
				cout << co;
				co += eliadeHistoire1; // readuc vectorul de comenzi de produse de baza la normal.
				break;

			case 3:
				system("cls");
				cout << co << endl;
				cout << "Introduceti un index:";
				short int index;
				cin >> index;
				cout << endl << co[index];
				break;

			case 4:
				system("cls");
				ofs.open(filename, ios::out | ios::binary);
				if (!ofs.is_open()) {
					cerr << "Could not open file " << filename << endl;
				}
				else {
					co.writeBinary(ofs);
					ofs.close();
				}

				ifs.open(filename, ios::in | ios::binary);
				if (!ifs.is_open())
				{
					cerr << "Could not open file" << filename << endl;
				}
				else
				{
					co.readBinary(ifs);
					ifs.close();
				}
				break;

			case 5:
				showOperatori();
				short int choiceOperatori;
				cout << "Introduceti un numar: ";
				cin >> choiceOperatori;
				switch (choiceOperatori) {
				case 1:
					cout << pRandom << endl;
					break;
				case 2:
					cout << eliadeHistoire1 << endl;
					break;
				case 3:
					cout << ironMaiden << endl;
					break;
				case 4:
					cout << co << endl;
					break;
				}

				break;

			case 6:
				showOperatori();
				short int choiceOperatorIn;
				cout << "Introduceti un numar: ";
				cin >> choiceOperatorIn;
				switch (choiceOperatorIn) {
				case 1:
					cin >> pTemp;
					cout << endl;
					cout << pTemp << endl;
					break;
				case 2:
					cin >> cTemp;
					cout << endl;
					cout << cTemp << endl;
					break;

				case 3:
					cin >> vTemp;
					cout << endl;
					cout << vTemp << endl;
					break;

				case 4:
					cin >> coTemp;
					cout << endl << coTemp << endl;
					//TODO: cin >> coTemp nu functioneaza;
					break;
				}

			case 0:
				cout << "La revedere!";
				break;
			default:
				cout << "Alegerea nu a fost recunoscuta." << endl;
				break;
			}

		
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}


	return 0;
}