/********************************************
* Titre: Travail pratique #3 - Produit.h
* Date: 
* Auteur: 
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
#include <typeinfo>
#include "Usager.h"
#include "Fournisseur.h"
class Fournisseur;

enum TypeProduit { TypeProduitOrdinaire = 0, TypeProduitAuxEncheres = 1 };

class Produit {

public:
	Produit(Fournisseur& fournisseur, const string& nom ="outil", int reference = 0, 
		    double prix = 0.0, TypeProduit type = TypeProduitOrdinaire);
	~Produit();
	
	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;
	Fournisseur & obtenirFournisseur() const;
	TypeProduit retournerType() const;

	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
		
	bool operator > (const Produit& produit) const;
	bool operator <(const Produit& produit) const;
	bool operator ==(const Produit& produit) const;
	
	friend istream& operator>>(istream& is, Produit& produit);
    friend ostream& operator<<(ostream& os, const Produit& produit);
   
private :
	string nom_;
	int reference_;
    double prix_;
	Fournisseur & fournisseur_;
	TypeProduit type_;

};
#endif 
