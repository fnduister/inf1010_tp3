/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Client.h"
#include "Fournisseur.h"
#include <stdlib.h> 
#include <time.h> 


Client::~Client()
{
	delete monPanier_;
}

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	Usager(nom, prenom, identifiant, codePostal), dateNaissance_(date)
{
	monPanier_ = nullptr;
};

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	/* initialize random seed: */
	srand(time(NULL));
	int sat = rand() % 10 + 1;
	Satisfaction mySatisfaction = prod->obtenirFournisseur().obtenirSatisfaction();
	mySatisfaction.niveaux_[sat];

	/* generate secret number between 1 and 10: */
	prod->obtenirFournisseur().modifierSatisfaction(mySatisfaction) ;
	// faire la mise à jour de la satisfaction au fournisseur
	
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise)
{
	if (produitAuxEncheres->obtenirPrixBase() < montantMise)
	{
		produitAuxEncheres->modifierPrixBase(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(obtenirIdentifiant());
	}
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(produitAuxEncheres);
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		Usager temp(*this);
		temp = static_cast<Usager> (client);
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Client & client)
{
	os << static_cast<Usager> (client) << std::endl;
	if (client.monPanier_ != nullptr)
	{
		os << *client.monPanier_;
	}
	else { os << "le panier de " << client.obtenirPrenom() << " est vide!"<< std::endl; }
	return os;
}
