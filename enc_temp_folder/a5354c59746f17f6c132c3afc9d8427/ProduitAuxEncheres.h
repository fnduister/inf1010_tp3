/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.h
* Date: 
* Auteur:
*******************************************/
#ifndef PRODUITAUXENCHERES_H
#define PRODUITAUXENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
using namespace std;

class ProduitAuxEncheres : public Produit 
{

public:
	ProduitAuxEncheres(Fournisseur& fournisseur,const string& nom = "outil", int reference = 0,
		               double prix = 0.0,TypeProduit type = TypeProduitOrdinaire);

		
	int obtenirIdentifiantClient() const;
	double obtenirPrixBase() const;

	void modifierIdentifiantClient(int identifiantClient) ;
	void modifierPrixBase(double prixBase) ;

	friend istream& operator>>(istream& is, ProduitAuxEncheres& produit);
	friend ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit);

private:		
	double prixBase_;	
	int identifiantClient_;
};
#endif