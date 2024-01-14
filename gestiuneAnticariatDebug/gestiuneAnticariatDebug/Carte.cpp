#include "Carte.h"


Carte::Carte() : Produs()
{
	if (this->titlu != NULL)
	{
		delete[] this->titlu;
	}
	this->titlu = new char[10];
	strcpy_s(this->titlu, 10, "undefined");

	if (this->autor != NULL)
	{
		delete[] this->autor;
	}
	this->autor = new char[10];
	//Eroare aici:
	strcpy_s(this->autor, 10, "undefined");

	if (this->editura != NULL)
		delete[] this->editura;
	this->editura = new char[10];
	strcpy_s(this->editura, 10, "undefined");

	this->numarPagini = 0;
	this->anAparitie = 0;
	this->gen_literar = genLiterar::LiterarNedefinit;
}

Carte::Carte(unsigned int idProdus, unsigned int stoc, float pret, Status status,
	const char* titlu, const char* autor, const char* editura,
	unsigned int nrPag, unsigned int anAparitie, genLiterar gl) : Produs(idProdus, stoc, pret, status)
{
	if (strlen(titlu) != 0)
	{
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	}
	else
	{
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[10];
		strcpy_s(this->titlu, 10, "undefined");
	}

	if (strlen(autor) > 0)
	{
		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[strlen(autor) + 1];
		strcpy_s(this->autor, strlen(autor) + 1, autor);
	}
	else
	{
		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[10];
		strcpy_s(this->autor, 10, "undefined");
	}

	if (strlen(editura) > 0)
	{
		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[strlen(editura) + 1];
		strcpy_s(this->editura, strlen(editura) + 1, editura);
	}
	else
	{
		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[10];
		strcpy_s(this->editura, 10, "undefined");
	}

	if (nrPag > 0)
		this->numarPagini = nrPag;
	else
		this->numarPagini = 0;

	if (anAparitie > 0)
		this->anAparitie = anAparitie;
	else
		this->anAparitie = 0;

	this->gen_literar = gl;
}

Carte::Carte(const Carte& carte) {
	if (this->titlu != NULL)
		delete[] this->titlu;
	this->titlu = new char[strlen(carte.titlu) + 1];
	strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);

	if (this->autor != NULL)
		delete[] this->autor;
	this->autor = new char[strlen(carte.autor) + 1];
	strcpy_s(this->autor, strlen(carte.autor) + 1, carte.autor);

	if (this->editura != NULL)
		delete[] this->editura;
	this->editura = new char[strlen(carte.editura) + 1];
	strcpy_s(this->editura, strlen(carte.editura) + 1, carte.editura);

	this->numarPagini = carte.numarPagini;
	this->anAparitie = carte.anAparitie;
	this->gen_literar = carte.gen_literar;
}

Carte& Carte::operator=(const Carte& c)
{
	if (&c != this)
	{
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[strlen(c.titlu) + 1];
		strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);

		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[strlen(c.autor) + 1];
		strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);

		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[strlen(c.editura) + 1];
		strcpy_s(this->editura, strlen(c.editura) + 1, c.editura);

		this->numarPagini = c.numarPagini;
		this->anAparitie = c.anAparitie;
		this->gen_literar = c.gen_literar;
	}
	else
		throw exception("Autoasignare");
	return *this;
}

char* Carte::getTitlu() { return this->titlu; }
void Carte::setTitlu(char* titlu)
{
	if (strlen(titlu) > 0)
	{
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	}

}

char* Carte::getAutor() { return this->autor; }
void Carte::setAutor(char* autor)
{
	if (strlen(autor) > 0)
	{
		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[strlen(autor) + 1];
		strcpy_s(this->autor, strlen(autor) + 1, autor);
	}
}

char* Carte::getEditura() { return this->editura; }
void Carte::setEditura(char* editura)
{
	if (strlen(editura) > 0)
	{
		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[strlen(editura) + 1];
		strcpy_s(this->editura, strlen(editura) + 1, editura);
	}
}

unsigned int Carte::getNumarPagini() { return this->numarPagini; }
void Carte::setNumarPagini(unsigned int nrPag)
{
	if (nrPag > 0)
		this->numarPagini = nrPag;
}

unsigned int Carte::getAnAparitie() { return this->anAparitie; }
void Carte::setAnAparitie(unsigned int an)
{
	if (an > 0)
		this->anAparitie = an;
}

genLiterar Carte::getGenLiterar() { return this->gen_literar; }
void Carte::setGenLiterar(genLiterar gen) { this->gen_literar = gen; }

void Carte::display(ostream& os) //virtual override
{
	Produs::display(os);
	os << "titlu: " << this->titlu << endl;
	os << "autor: " << this->autor << endl;
	os << "editura: " << this->editura << endl;
	os << "nr. pagini: " << this->numarPagini << endl;
	os << "an aparitie: " << this->anAparitie << endl;
	os << "gen literar: " << this->gen_literar << endl;
}
ostream& operator<<(ostream& os, Carte* c)
{
	c->display(os);
	return os;
}

void Carte::read(istream& is) //virtual override
{
	Produs::read(is);
	cout << "Introduceti titlul: ";
	char* titluTemp = new char[100];
	is >> ws;
	is.getline(titluTemp, 100);
	if (strlen(titluTemp) > 0)
	{
		if (this->titlu != NULL)
			delete[] this->titlu;
		this->titlu = new char[strlen(titluTemp) + 1];
		strcpy_s(this->titlu, strlen(titluTemp) + 1, (char*)titluTemp);
	}

	cout << "Introduceti autorul: ";
	char* autorTemp = new char[100];
	is >> ws;
	is.getline(autorTemp, 100);
	if (strlen(autorTemp) > 0)
	{
		if (this->autor != NULL)
			delete[] this->autor;
		this->autor = new char[strlen(autorTemp) + 1];
		strcpy_s(this->autor, strlen(autorTemp) + 1, autorTemp);
	}

	cout << "Introduceti editura: ";
	char* edituraTemp = new char[100];
	is >> ws;
	is.getline(edituraTemp, 100);
	if (strlen(edituraTemp) > 0)
	{
		if (this->editura != NULL)
			delete[] this->editura;
		this->editura = new char[strlen(edituraTemp) + 1];
		strcpy_s(this->editura, strlen(edituraTemp) + 1, edituraTemp);
	}
	cout << "Introduceti numarul de pagini: ";
	is >> numarPagini; //TODO: validari

	cout << "Introduceti anul aparitiei: ";
	is >> anAparitie;

	is >> gen_literar;
}

istream& operator>>(istream& is, Carte* c)
{
	c->read(is);
	return is;
}
//
//void Carte::writeBinary(ofstream& ofs) //virtual override
//{
//	Produs::writeBinary(ofs);
//	int length = strlen(titlu);
//	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
//	ofs.write(titlu, length + 1);
//	length = strlen(autor);
//	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
//	ofs.write(autor, length + 1);
//	length = strlen(editura);
//	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
//	ofs.write(editura, length + 1);
//	ofs.write(reinterpret_cast<char*>(&numarPagini), sizeof(numarPagini));
//	ofs.write(reinterpret_cast<char*>(&anAparitie), sizeof(anAparitie));
//	ofs.write(reinterpret_cast<char*>(&gen_literar), sizeof(gen_literar));
//}
//
//
//
//ofstream& operator<<(ofstream& ofs, Carte* c)
//{
//	c->writeBinary(ofs);
//	return ofs;
//}
//
//void Carte::readBinary(ifstream& ifs) // virtual override
//{
//	Produs *p = Produs::readBinary(ifs);
//	int length = 0;
//	
//	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
//	char* titluTemp = new char[length + 1];
//	ifs.read(titluTemp, length + 1);
//
//	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
//	char* autorTemp = new char[length + 1];
//	ifs.read(autorTemp, length+1);
//
//	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
//	char* edituraTemp = new char[length + 1];
//	ifs.read(edituraTemp, length + 1);
//
//	unsigned int numarPaginiTemp;
//	ifs.read(reinterpret_cast<char*>(&numarPaginiTemp), sizeof(numarPaginiTemp));
//
//	unsigned int anAparitieTemp;
//	ifs.read((char*)&anAparitieTemp, sizeof(anAparitieTemp));
//
//	genLiterar gen_literarTemp;
//	ifs.read((char*)&gen_literarTemp, sizeof(gen_literarTemp));
//
//	Carte* carteTemp = new Carte(p->getIDProdus(), p->getStoc(), p->getPret(), p->getStatusProdus(),
//		                         titluTemp, autorTemp, edituraTemp, numarPaginiTemp, anAparitieTemp, 
//		                         gen_literarTemp);
//	cout << carteTemp;
//
//	//Pentru ca vreau sa ma asigur ca se dezaloca memoria, desi 
//	// acest lucru ar trebui sa se intample automat la }.
//	p->~Produs();
//	carteTemp->~Carte();
//}
//
//ifstream& operator>>(ifstream& ifs, Carte* c)
//{
//	c->readBinary(ifs);
//	return ifs;
//}

Carte::~Carte()
{
	delete[] this->titlu;
	delete[] this->autor;
	delete[] this->editura;
	Produs::~Produs();
}
