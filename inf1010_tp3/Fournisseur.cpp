/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"
#include <ctime>

Fournisseur::Fournisseur(const string& nom, const string& prenom, int identifiant, const string& codePostal):
	Usager(nom, prenom, identifiant, codePostal)
{
	for (int niveau : satisfaction_.niveaux_)
	{
		niveau = 0;	
	}
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

void Fournisseur::noter(const int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit * produit)
{
	for (unsigned i = 0; i < contenuCatalogue_.size(); i++)
	{
		if (*contenuCatalogue_[i] == *produit)
		{
			contenuCatalogue_.erase(contenuCatalogue_.begin() + i);
		}
	}
}

Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
	Usager &temp(*this);
	temp = static_cast<Usager>(fournisseur);
	return *this;
}

ostream& operator<<(ostream& os, Fournisseur& fournisseur)
{
	os << static_cast<Usager> (fournisseur);
	os << "notes: \n";
	for (int i = 0 ; i < NIVEAUX_SATISFACTION ; i++ )
	{
		os << i << ":" << fournisseur.satisfaction_.niveaux_[i] << std::endl;
	}
	return os;
}
