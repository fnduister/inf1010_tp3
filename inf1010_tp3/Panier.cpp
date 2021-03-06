/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient):idClient_(idClient) {
	totalAPayer_ = 0.0;
}

Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return static_cast<int>(contenuPanier_.size());
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}

double Panier::calculerTotalApayer()
{
	for (Produit* prod : contenuPanier_)
	{
		if (prod->retournerType() == TypeProduitAuxEncheres)
		{
			ProduitAuxEncheres* temp = static_cast<ProduitAuxEncheres*>(prod);
			if (idClient_ == temp->obtenirIdentifiantClient())
			{
				totalAPayer_ += temp->obtenirPrix();
			}
		}
	}
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}

void Panier::ajouter(Produit * prod)
{
	if (prod->retournerType() == TypeProduitOrdinaire)
	{
		if (static_cast<ProduitOrdinaire*>(prod)->obtenirEstTaxable())
		{
			totalAPayer_ += prod->obtenirPrix()*TAUX_TAXE;
		}
		else totalAPayer_ += prod->obtenirPrix();
	}
	else totalAPayer_ += prod->obtenirPrix();
 	contenuPanier_.push_back(prod);
	
}

void Panier::enleverProduit(Produit* produit)
{
	for (unsigned i = 0; i < contenuPanier_.size(); i++)
	{
		if (*contenuPanier_[i] == *produit)
		{
			contenuPanier_.erase(contenuPanier_.begin() + i);
			totalAPayer_ -= produit->obtenirPrix();
		}
	}
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	if (panier.obtenirNombreContenu() != 0)
	{
		for (Produit* prod : panier.contenuPanier_)
			if (prod->retournerType() == TypeProduitOrdinaire)
			{
				os << *static_cast<ProduitOrdinaire*>(prod);
			}
			else
			{
				os << *static_cast<ProduitAuxEncheres*>(prod);
			}
		os << "\n----> total a payer : " << panier.totalAPayer_ << "\n\n\n";
	}
	else { os << "Panier est vide!"; }
	
	return os;
}
