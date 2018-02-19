/********************************************
* Titre: Travail pratique #3 - Fournisseur.h
* Date: 
* Auteur: 
*******************************************/

#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
const int NIVEAUX_SATISFACTION = 5;
struct Satisfaction {
	int niveaux_[NIVEAUX_SATISFACTION];
};

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
using namespace std;
class Produit;
class Fournisseur : public Usager
{
public:
	Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
		
	vector<Produit*> obtenirCatalogue() const;
	Satisfaction obtenirSatisfaction() const;
	
	void modifierSatisfaction(Satisfaction satisfaction);	
	void noter(int appreciation);

	void ajouterProduit(Produit* produit);
	void enleverProduit(Produit* produit);	
	Fournisseur& operator=(const Fournisseur& fournisseur);

	friend ostream& operator<<(ostream & os, Fournisseur& fournisseur);

private:
	Satisfaction satisfaction_;
	vector<Produit*> contenuCatalogue_;	
};

#endif