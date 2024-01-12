#include "Comanda.h"

ofstream& operator<<(ofstream& ofs, Comanda& c)
{
	string filename = "comenzi\\" + to_string(c.idComanda) + ".bin";
	ofs.open(filename, ios::binary);
	cout << "scriu in " << filename << endl;
	ofs.write(reinterpret_cast<char*>(&c.idComanda), sizeof(c.idComanda));
	int length = sizeof(c.numeClient);
	ofs.write((char*)&length, sizeof(length));
	ofs.write(c.numeClient, length+1);
	length = sizeof(c.prenumeClient);
	ofs.write((char*)&length, sizeof(length));
	ofs.write(c.prenumeClient, length+1);
	ofs.write(reinterpret_cast<char*>(&c.valoareComanda), sizeof(c.valoareComanda));
	ofs.write(reinterpret_cast<char*>(&c.numarProduse), sizeof(c.numarProduse));
	for (int i = 0; i < c.numarProduse; i++) {
		ofs << c.produse[i];
	}
	
	return ofs; //BIG TODO: Ne uitam peste asta maine dimineata.
}

ifstream& operator>>(ifstream& ifs, Comanda& c)
{
	string filename = "comenzi\\" + to_string(c.idComanda) + ".bin";
	ifs.open(filename, ios::binary);
	cout << "citesc din " << filename << endl;

	//BIG TODO: De schimbat cu variabile temporare;
	int length;
	unsigned int idComandaTemp;
	ifs.read(reinterpret_cast<char*>(&idComandaTemp), sizeof(c.idComanda));
	cout << idComandaTemp;
	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
	if(c.numeClient)
		delete[] c.numeClient;
	c.numeClient = new char[length + 1];
	ifs.read(c.numeClient, length + 1);
	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
	if(c.prenumeClient)
		delete[] c.prenumeClient;
	c.prenumeClient = new char[length + 1];
	ifs.read(c.prenumeClient, length + 1);
	ifs.read(reinterpret_cast<char*>(&c.valoareComanda), sizeof(c.valoareComanda));
	ifs.read(reinterpret_cast<char*>(&c.numarProduse), sizeof(c.numarProduse));

	for (int i = 0; i < c.numarProduse; i++)
		ifs >> c.produse[i];
	return ifs;
}

Comanda::Comanda() 
{
	this->idComanda = 0;
	this->numeClient = new char[10];
	strcpy_s(this->numeClient, 10, "undefined");
	this->prenumeClient = new char[10];
	strcpy_s(this->prenumeClient, 10, "undefined");
	this->valoareComanda = 0;
	this->produse = new Produs * [0];
	this->numarProduse = 0;
}

Comanda::Comanda(unsigned int idComanda, const char* numeClient, const char* prenumeClient, float valoareComanda, Produs** produse, int numarProduse)
{
	if (strlen(numeClient) > 0)
	{
		if (this->numeClient != NULL)
			delete[] this->numeClient;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	}
	else
	{
		if (this->numeClient != NULL)
			delete[] this->numeClient;
		this->numeClient = new char[10];
		strcpy_s(this->numeClient, 10, "undefined");
	}

	if (strlen(prenumeClient) > 0)
	{
		if (this->prenumeClient != NULL)
			delete[] this->prenumeClient;
		this->prenumeClient = new char[strlen(prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
	}
	else
	{
		if (this->prenumeClient != NULL)
			delete[] this->prenumeClient;
		this->prenumeClient = new char[10];
		strcpy_s(this->prenumeClient, 10, "undefined");
	}
	if (valoareComanda > 0)
		this->valoareComanda = valoareComanda;
	else
		this->valoareComanda = 0;
	if (numarProduse > 0)
		this->numarProduse = numarProduse;
	else
	{
		this->numarProduse = 0;
		if (this->produse != NULL)
			delete[] produse;
		this->produse = new Produs * [0];
	}

	for (int i = 0; i < this->numarProduse; i++)
	{
		this->produse[i] = produse[i];
	}
}

Comanda::Comanda(const Comanda& comanda)
{
	this->idComanda = comanda.idComanda;
	if (this->numeClient != NULL)
		delete[] this->numeClient;
	this->numeClient = new char[strlen(comanda.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(comanda.numeClient) + 1, comanda.numeClient);

	if (this->prenumeClient != NULL)
		delete[] this->prenumeClient;
	this->prenumeClient = new char[strlen(comanda.prenumeClient) + 1];
	strcpy_s(this->prenumeClient, strlen(comanda.prenumeClient) + 1, comanda.prenumeClient);
	this->valoareComanda = comanda.valoareComanda;
	this->numarProduse = comanda.numarProduse;
	for (int i = 0; i < this->numarProduse; i++)
		this->produse[i] = comanda.produse[i];
}

Comanda& Comanda::operator=(const Comanda& co)
{
	if (&co != this)
	{
		this->idComanda = co.idComanda;
		if (this->numeClient != NULL)
			delete[] this->numeClient;
		this->numeClient = new char[strlen(co.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(co.numeClient) + 1, co.numeClient);

		if (this->prenumeClient != NULL)
			delete[] this->prenumeClient;
		this->prenumeClient = new char[strlen(co.prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(co.prenumeClient) + 1, co.prenumeClient);
		this->valoareComanda = co.valoareComanda;
		this->numarProduse = co.numarProduse;
		for (int i = 0; i < this->numarProduse; i++)
			this->produse[i] = co.produse[i];

	}
	else {
		throw exception("Autoasignare");

	}
	return *this;
}

char* Comanda::getNumeClient() { return this->numeClient; }
void Comanda::setNumeClient(const char* numeClient)
{
	if (strlen(numeClient) > 0)
	{
		if (this->numeClient != NULL)
			delete[] this->numeClient;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	}
}

unsigned int Comanda::getIDComanda() { return this->idComanda; }
void Comanda::setIDComanda(unsigned int comanda) { this->idComanda = comanda; }

char* Comanda::getPrenumeClient() { return this->prenumeClient; }
void Comanda::setPrenumeClient(const char* prenumeClient)
{
	if (strlen(prenumeClient) > 0)
	{
		if (this->prenumeClient != NULL)
			delete[] this->prenumeClient;
		this->prenumeClient = new char[strlen(prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
	}
}

float Comanda::getValoareComanda() { return this->valoareComanda; } //momentan ramane asa, desi am banuiala ca valoareComanda o sa devina calculeazaValoareComanda();
void Comanda::setValoareComanda(float valoareComanda) {
	this->valoareComanda = valoareComanda; //Nu mai stau sa fac validarea
}

int Comanda::getNumarProduse() { return this->numarProduse; }
// setNumarProduse nu are sens, caci nu vreau ca utilizatorul sa poata sa modifice numarul de produse, caci va strica vectorul.

void Comanda::operator+=(Produs* produs)
{
	Produs** temp = new Produs * [this->numarProduse + 1];
	for (int i = 0; i < this->numarProduse; i++)
	{
		temp[i] = this->produse[i];
	}
	temp[this->numarProduse] = produs;
	delete[] this->produse;
	this->produse = temp;
	this->numarProduse++;
}

void Comanda::operator-=(Produs* produs)
{
	Produs** temp = new Produs * [this->numarProduse - 1];
	int deSters = produs->getIDProdus();
	int indexTemp = 0;
	for (int i = 0; i < this->numarProduse; i++)
	{
		if (deSters == this->produse[i]->getIDProdus())
			continue;
		else {
			temp[indexTemp] = this->produse[i];
			indexTemp++;
		}

	}
	delete[] this->produse;
	this->produse = temp;
	this->numarProduse--;
}

Produs* Comanda::operator[](int index)
{
	if (index >= this->numarProduse || index < 0)
		throw out_of_range("Index invalid");
	return this->produse[index];
}

ostream& operator<<(ostream& os, const Comanda& c)
{
	os << "id comanda" << c.idComanda << endl;
	os << "nume client: " << c.numeClient << endl;
	os << "prenume client: " << c.prenumeClient << endl;
	os << "valoare comanda: " << c.valoareComanda << endl;
	os << "numar produse: " << c.numarProduse << endl;
	os << "produse: " << endl;
	for (int i = 0; i < c.numarProduse; i++)
	{
		cout << i + 1 << ". " << c.produse[i]->getIDProdus() << endl;
	}
	return os;
}

istream& operator>>(istream& is, Comanda& c)
{
	cout << "Introduceti numarul comenzii: ";
	cin >> c.idComanda;
	cout << "Introduceti numele clientului: ";
	cin >> c.numeClient;
	cout << "Introduceti prenumele clientului:";
	cin >> c.prenumeClient;
	cout << "Introduceti valoarea comenzii";
	cin >> c.valoareComanda;
	//TODO: Introducem categoria. Facem Carte::read() sau Vinyl::read();

	return is;
}

Comanda::~Comanda()
{
	delete[] this->numeClient;
	delete[] this->prenumeClient;
	delete[] this->produse;
}