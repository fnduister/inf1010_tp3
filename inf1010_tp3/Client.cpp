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

	const int etoiles = rand() % 4;

	// faire la mise à jour de la satisfaction au fournisseur
	prod->obtenirFournisseur().noter(etoiles);
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
		Client *temp = produitAuxEncheres->obternirPtrGagnant();
		if (temp != nullptr)
			temp->obtenirPanier()->enleverProduit(produitAuxEncheres);
		produitAuxEncheres->modifierPtrGagnant(this);

		//Seulement ajouter au panier si la mise est suffisante.
		if (monPanier_ == nullptr)
			monPanier_ = new Panier(this->obtenirIdentifiant());
		monPanier_->ajouter(produitAuxEncheres);
	}
	else
		std::cout << "vous n'avez pas visez assez haut.\nLa plus haute mise est:" << produitAuxEncheres->obtenirPrixBase() << std::endl;
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		Usager &temp(*this);
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
