# RefactorizedOOP
Proiect pentru Programare Orientata Obiect  
Tema proiectului: Sistem de gestiune pentru o librarie anticariat.  

Structura proiectului:  

Clasa de baza este **Produs**, care contine:  
&emsp;unsigned int **idProdus**  
&emsp;unsigned int **stoc**  
&emsp;  float **pret**  
&emsp;  Status **statusProdus**  

Prima clasa derivata este **Carte**, care contine:  
&emsp;  char* **titlu**;  
&emsp;  char* **autor**;  
&emsp;  char* **editura**;  
&emsp;  unsigned int **numarPagini**  
&emsp;  unsigned int **anAparitie**  
&emsp;  genLiterar **gen_literar**  

Cea de-a doua clasa derivata este **Vinyl**, care contine:  
&emsp;  char* **numeAlbum**  
&emsp;  char* **artist**  
&emsp;  unsigned int **numarPiese**  
&emsp;  float **durata**  
&emsp;  genMuzical **gen_muzical**  

Clasa care contine un vector de clase de baza este **Comanda**:  
&emsp;  unsigned int **idComanda**  
&emsp;  char* **numeClient**  
&emsp;  char* **prenumeClient**  
&emsp;  float **valoareComanda**  
&emsp;  int **numarProduse**  
&emsp;  Produs(**) **numarProduse**;  

Fisierul dependencies.h contine declararile enum-urilor folosite in cadrul proiectului:  
Status:  
&emsp;  Activ,  
&emsp;  Inactiv  

Categorie:  
&emsp;  Carte,  
&emsp;  Vinyluri,  
&emsp;  Nedefinit  

genLiterar:  
&emsp;  Filosofie,  
&emsp;  IstoriaReligiilor,  
&emsp;  Istorie,  
&emsp;  Proza,  
&emsp;  Poezie,  
&emsp;  Psihologie,  
&emsp;  LiterarNedefinit  

genMuzical:  
&emsp;  Rock,  
&emsp;  Metal,  
&emsp;  Clasica,  
&emsp;  Pop,  
&emsp;  Populara,  
&emsp;  MuzicalNedefinit  

Fisierul dependencies.cpp contine supraincarcarea operatorilor << si >> pentru fiecare enum in parte.  

Fiecare clasa contine constructori impliciti, expliciti si de copiere, supraincarcarea operatorului =, functii de acces pentru campurile private si suporta citire si scriere din fisiere binare. Operatorii de citire de la stdin si de afisare la stdout au fost virtualizati. Clasa **Comanda** nu contine setter pentru campul **numarProduse**, pentru a impiedica utilizatorul din a modifica comportamentul vectorului.  

Acest proiect contine cod scris deja in versiunea de baza, care poate fi gasita la https://github.com/ofydd/proiectAnticariatOOP, cu mentiunea ca fiecare clasa a fost impartita in fisiere proprii, pentru a usura procesul de debugging - de aici vine si numele - RefactorizedOOP.  
