#include "dependencies.h"

ostream& operator<<(ostream& os, const Status& status)
{
	switch (status) {
	case Activ:
		cout << "activ ";
		break;
	case Inactiv:
		cout << "inactiv ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, Status& status)
{
	cout << "Alegeti status-ul pentru produs. " << endl;
	cout << "1. Activ" << endl;
	cout << "2. Inactiv" << endl;
	cout << "Va rog sa introduceti un numar: ";
	unsigned short int alegere; // pentru ca lucrez cu numere foarte mici, m-am gandit sa aloc doar 2 bytes
	cin >> alegere;
	switch (alegere) {
	case 1:
		status = Status::Activ;
		break;
	case 2:
		status = Status::Inactiv;
		break;
	default:
		cout << "Status necunoscut. Produsul a fost incadrat automat in categoria inactiv." << endl;
		status = Status::Inactiv;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, const Categorie& categorie)
{
	switch (categorie)
	{
	case Categorie::Carti:
		cout << "carte ";
		break;
	case Categorie::Vinyluri:
		cout << "vinyl ";
		break;
	case Categorie::Nedefinit:
		cout << "nedefinit ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, Categorie& categorie)
{
	cout << "Introduceti categoria produsului." << endl;
	cout << "1. Carte" << endl;
	cout << "2. Vinyl" << endl;
	cout << "Va rog introduceti un numar: ";

	unsigned short int alegere;
	cin >> alegere;

	switch (alegere) {
	case 1:
		categorie = Categorie::Carti;
		break;
	case 2:
		categorie = Categorie::Vinyluri;
		break;
	default:
		cout << "Categorie necunoscuta! Produsul a fost incadrat automat ca fiind nedefinit";
		categorie = Categorie::Nedefinit;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, const genLiterar& gen)
{
	switch (gen) {
	case genLiterar::Filosofie:
		cout << "filosofie ";
		break;
	case genLiterar::IstoriaReligiilor:
		cout << "istoria religiilor";
		break;
	case genLiterar::Istorie:
		cout << "istorie ";
		break;
	case genLiterar::Proza:
		cout << "proza ";
		break;
	case genLiterar::Poezie:
		cout << "poezie ";
		break;
	case genLiterar::Psihologie:
		cout << "psihologie ";
		break;
	case genLiterar::LiterarNedefinit:
		cout << "nedefinit ";
		break;
	}
	return os;
}

istream& operator>>(istream& is, genLiterar& gen)
{
	cout << "Introduceti genul literar." << endl;
	cout << "1. Filosofie" << endl;
	cout << "2. Istoria religiilor" << endl;
	cout << "3. Istorie" << endl;
	cout << "4. Proza" << endl;
	cout << "5. Poezie" << endl;
	cout << "6. Psihologie" << endl;
	cout << "Introduceti un numar: ";
	unsigned short alegere;
	cin >> alegere;
	switch (alegere) {
	case 1:
		gen = genLiterar::Filosofie;
		break;
	case 2:
		gen = genLiterar::IstoriaReligiilor;
		break;
	case 3:
		gen = genLiterar::Istorie;
		break;
	case 4:
		gen = genLiterar::Proza;
		break;
	case 5:
		gen = genLiterar::Poezie;
		break;
	case 6:
		gen = genLiterar::Psihologie;
		break;
	default:
		cout << "Gen literar necunoscut. Cartea a fost incadrata automat in genul literar nedefinit";
		gen = genLiterar::LiterarNedefinit;
		break;
	}

	return is;
}


ostream& operator<<(ostream& os, const genMuzical& gen) {
	switch (gen)
	{
	case genMuzical::Clasica:
		cout << "muzica clasica ";
		break;
	case genMuzical::Metal:
		cout << "metal ";
		break;
	case genMuzical::Pop:
		cout << "pop ";
		break;
	case genMuzical::Populara:
		cout << "muzica populara";
		break;
	case genMuzical::Rock:
		cout << "rock ";
		break;
	case genMuzical::MuzicalNedefinit:
		cout << "nedefinit ";
		break;
	default:
		cout << "nedefinit";
		break;
	}
	return os;
}

istream& operator>>(istream& is, genMuzical& gen)
{
	cout << "Introduceti genul muzical." << endl;
	cout << "1. Muzica Clasica" << endl;
	cout << "2. Metal" << endl;
	cout << "3. Pop" << endl;
	cout << "4. Muzica populara" << endl;
	cout << "5. Rock" << endl;
	cout << "Introduceti un numar: ";
	unsigned short int alegere;
	cin >> alegere;
	switch (alegere)
	{
	case 1:
		gen = genMuzical::Clasica;
		break;
	case 2:
		gen = genMuzical::Metal;
		break;
	case 3:
		gen = genMuzical::Pop;
		break;
	case 4:
		gen = genMuzical::Populara;
		break;
	case 5:
		gen = genMuzical::Rock;
		break;
	default:
		cout << "Gen muzical necunoscut. Vinyl-ul a fost incadrat automat in genul muzical nedefinit";
		gen = genMuzical::MuzicalNedefinit;
		break;
	}
	return is;
}