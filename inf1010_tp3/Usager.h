/********************************************
* Titre: Travail pratique #3 - Usager.h
* Date:
* Auteur:
*******************************************/

#ifndef USAGER_H
#define USAGER_H

#include <string>
using namespace std;
class Usager
{

public:
	Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
	
	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;	
	
	
	void modifierNom(const string& nom);
	void modifierPrenom(const string & prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string & codePostal);

	Usager & operator=(const Usager& usager);
	bool operator==(int identifiant) const;
	bool operator == (const Usager & usager) const;
	friend bool operator==(int indentifiant, const Usager& usager);
	friend ostream& operator<<(ostream& os, const Usager& u);

private:
	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	
};

#endif