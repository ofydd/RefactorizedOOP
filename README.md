# RefactorizedOOP
Proiect pentru Programare Orientata Obiect
Tema proiectului: Sistem de gestiune pentru o librarie anticariat.

Structura proiectului:

Clasa de baza este **Produs**, care contine:
  unsigned int **idProdus**
  unsigned int **stoc**
  float **pret**
  Status **statusProdus**

Prima clasa derivata este **Carte**, care contine:
  char* **titlu**;
  char* **autor**;
  char* **editura**;
  unsigned int **numarPagini**
  unsigned int **anAparitie**
  genLiterar **gen_literar**

Cea de-a doua clasa derivata este **Vinyl**, care contine:
  char* **numeAlbum**
  char* **artist**
  unsigned int **numarPiese**
  float **durata**
  genMuzical **gen_muzical**

Clasa care contine un vector de clase de baza este **Comanda**:
  unsigned int **idComanda**
  char* **numeClient**
  char* **prenumeClient**
  float **valoareComanda**
  int **numarProduse**
  Produs(**) **numarProduse**;

Fisierul dependencies.h contine declararile enum-urilor folosite in cadrul proiectului:
Status
  Activ,
  Inactiv

Categorie
  Carte,
  Vinyluri,
  Nedefinit

genLiterar
  Filosofie,
  IstoriaReligiilor,
  Istorie,
  Proza,
  Poezie,
  Psihologie,
  LiterarNedefinit

genMuzical
  Rock,
  Metal,
  Clasica,
  Pop,
  Populara,
  MuzicalNedefinit

Fisierul dependencies.cpp contine supraincarcarea operatorilor << si >> pentru fiecare enum in parte.

Fiecare clasa contine constructori impliciti, expliciti si de copiere, supraincarcarea operatorului =, functii de acces pentru campurile private si suporta citire si scriere din fisiere binare. Operatorii de citire de la stdin si de afisare la stdout au fost virtualizati. Clasa **Comanda** nu contine setter pentru campul **numarProduse**, pentru a impiedica utilizatorul din a modifica comportamentul vectorului.

Acest proiect contine cod scris deja in versiunea de baza, care poate fi gasita la https://github.com/ofydd/proiectAnticariatOOP, cu mentiunea ca fiecare clasa a fost impartita in fisiere proprii, pentru a usura procesul de debugging - de aici vine si numele - RefactorizedOOP.
