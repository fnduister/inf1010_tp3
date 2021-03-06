/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference, double prix,
	TypeProduit type):
	Produit(fournisseur, nom, reference, prix, type),prixBase_(0),identifiantClient_(0),ptrGagnant_(nullptr)
{
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

Client * ProduitAuxEncheres::obternirPtrGagnant() const
{
	return ptrGagnant_;
};

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

void ProduitAuxEncheres::modifierPtrGagnant(Client * client)
{
	ptrGagnant_ = client;
}



istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
	return is;
}

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	os << "\n+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	os << "\t Type: Produit aux encheres";
	os << "\n+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;	
	os << static_cast<Produit>(produit) << std::endl;
	os << "\t Prix de base: " << produit.prixBase_<< std::endl;
	os << "\t Identifiant Client: " << produit.identifiantClient_ << std::endl;
	return os;
}