#pragma once
#include "Produs.h"

class Carte : public Produs
{
private:
	char* titlu;
	char* autor;
	char* editura;
	unsigned int numarPagini;
	unsigned int anAparitie;
	genLiterar gen_literar;

public:
	Carte();
	Carte(unsigned int idProdus, unsigned int stoc, float pret, Status status,
		const char* titlu, const char* autor, const char* editura,
		unsigned int nrPag, unsigned int anAparitie, genLiterar gl);

	Carte(const Carte& carte);
	Carte& operator=(const Carte& c);

	char* getTitlu();
	void setTitlu(char* titlu);

	char* getAutor(); 
	void setAutor(char* autor);

	

	char* getEditura();
	void setEditura(char* editura);


	unsigned int getNumarPagini(); 
	void setNumarPagini(unsigned int nrPag);

	unsigned int getAnAparitie(); 
	void setAnAparitie(unsigned int an);
	

	genLiterar getGenLiterar();
	void setGenLiterar(genLiterar gen);

	virtual void display(ostream& os) override;
	
	friend ostream& operator<<(ostream& os, Carte* c);

	virtual void read(istream& is) override;
	
	friend istream& operator>>(istream& is, Carte* c);

	virtual void writeBinary(ofstream& ofs) override;

	friend ofstream& operator<<(ofstream& ofs, Carte* c);

	void readBinary(ifstream& ifs);

	friend ifstream& operator>>(ifstream& ifs, Carte* c);
	~Carte();

};