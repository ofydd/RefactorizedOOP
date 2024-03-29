#include "Comanda.h"

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
	if (numarProduse > 0) {
		this->numarProduse = numarProduse;
		this->produse = new Produs * [numarProduse];
		for (int i = 0; i < this->numarProduse; i++)
		{
			this->produse[i] = produse[i];
		}
	}

	else
	{
		this->numarProduse = 0;
		if (this->produse != NULL)
			delete[] produse;
		this->produse = new Produs * [0];
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
	return this->produse[index-1];
}

ostream& operator<<(ostream& os, const Comanda& c)
{
	os << "id comanda: " << c.idComanda << endl;
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
	cout << "Introduceti numarul de produse: " << endl;
	cin >> c.numarProduse;
	if (c.produse != NULL) {
		delete[] c.produse;
	}
	c.produse = new Produs*[c.numarProduse];
	for (int i = 0; i < c.numarProduse; i++) {
		c.produse[i] = new Produs();
		cin >> c.produse[i];
	}

	return is;
}

void Comanda::readBinary(ifstream& ifs)
{

	int length;


	unsigned int idComandaTemp;
	ifs.read(reinterpret_cast<char*>(&idComandaTemp), sizeof(idComandaTemp));

	char* numeClientTemp;
	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
	numeClientTemp = new char[length + 1];
	ifs.read(numeClientTemp, length + 1);

	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
	char* prenumeClientTemp = new char[length + 1];
	ifs.read(prenumeClientTemp, length + 1);

	float valoareComandaTemp;
	ifs.read(reinterpret_cast<char*>(&valoareComandaTemp), sizeof(valoareComandaTemp));

	int numarProduseTemp;
	ifs.read(reinterpret_cast<char*>(&numarProduseTemp), sizeof(numarProduseTemp));

	Produs** produseTemp = new Produs * [numarProduseTemp];

	for (int i = 0; i < numarProduseTemp; i++)
	{
		produseTemp[i] = produse[i]->readBinary(ifs);
	}

	//Comanda(unsigned int, char*, char*, float, Produs**, int);
	Comanda coTemp(idComandaTemp, numeClientTemp, prenumeClientTemp, valoareComandaTemp, produseTemp, numarProduseTemp);
	cout << "Citit din fisier binar: " << endl;
	cout << coTemp << endl;
}



void Comanda::writeBinary(ofstream& ofs)
{
	ofs.write(reinterpret_cast<char*>(&idComanda), sizeof(idComanda));

	int length = strlen(numeClient);
	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
	ofs.write(numeClient, length + 1);

	length = strlen(prenumeClient);
	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
	ofs.write(prenumeClient, length + 1);

	ofs.write(reinterpret_cast<char*>(&valoareComanda), sizeof(valoareComanda));
	ofs.write(reinterpret_cast<char*>(&numarProduse), sizeof(numarProduse));

	for (int i = 0; i < numarProduse; i++) {
		produse[i]->writeBinary(ofs);
	}
}


Comanda::~Comanda()
{
	delete[] this->numeClient;
	delete[] this->prenumeClient;
	delete[] this->produse;
}