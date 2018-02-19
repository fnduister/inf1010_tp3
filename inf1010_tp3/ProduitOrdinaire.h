/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 
* Auteur:
*******************************************/

#ifndef PRODUITORDINAIRE_H
#define PRODUITORDINAIRE_H

#include <string>
#include <iostream>
#include "Produit.h"

class ProduitOrdinaire : public Produit
{

public:
	
	ProduitOrdinaire(Fournisseur& fournisseur, 
		             const string& nom = "outil", int reference = 0,
		             double prix = 0.0, TypeProduit type = TypeProduitOrdinaire,bool estTaxable = true);
	bool obtenirEstTaxable() const;
	void modifierEstTaxable(bool estTaxable);

	friend ostream& operator<<(ostream& os, const ProduitOrdinaire& produit);
	friend istream& operator>>(istream& is, ProduitOrdinaire& produit);

private:
	bool estTaxable_;
};

#endif