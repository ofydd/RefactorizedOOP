#include "Comanda.h"
int main()
{


	try
	{
		Carte* c = new Carte(1, 1, 10, Status::Activ, "Baltagul", "Mihail Sadoveanu", "Facla", 131, 1973, genLiterar::Proza);
		Vinyl* v = new Vinyl(2, 1, 25, Status::Activ, "Mugur de fluier", "Phoenix", 7, 131, genMuzical::Rock);

		Carte* c1 = c;
		Vinyl* v1 = v;

		//cout << c1 << endl;
		//cout << endl << v1 << endl; 

		Produs* p1 = new Produs(101, 101, 10, Status::Inactiv);
		Produs* p2 = p1;
		//		cout << p2 << endl << endl;

		Carte* c3 = c1;
		//		cout << c3;

		Vinyl* v3 = v1;
		//cout << v3;

		Comanda co;
		co.setNumeClient("Oprea");
		co.setPrenumeClient("Ovidiu-Cristian");
		co.setValoareComanda(1060);
		co += c;
		co += v;

		//cout << co[3];
		//co2 = co2;

		//Produs* pEx = new Produs();
		//pEx = pEx;

		ifstream ifs;
		ofstream ofs;

		Produs* p3 = new Produs();
		ofs << p3;
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