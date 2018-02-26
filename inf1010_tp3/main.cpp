/**************************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 
* Auteur: 
**************************************************/

#include "Fournisseur.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int  NB_PRODUCTS = 15;

/**
*Répondez aux questions ici :
* 1/ Parce que ProduitOrdinire et ProduitAux Enchere sont des produits
* 2/
* 2.1 Un static_cast permet d'utiliser la surcharge d'operateur << d'une classe parent.
* 2.2 On aura une methode d'affichage qui affichera juste les attributs de l'objet de la classe
*	  sans afficher ceux de la classe parent ou il faudrat gerer l'affichage a travers les methodes d'acces de la classe parents
*	  en faisant attention a ce que l'affiche des deux classe respecte la meme structure.
**/

int main()
{
	/* initialize random seed: */
	srand(time(nullptr));

	// Creez un objet de classe client à l'aide du constructeur
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// creez un objet de la classe client à l'aide du constructeur de copie
	// et modifier son identifiant
	Client maCopie(martine);
	maCopie.modifierIdentifiant(777);

	// vérifier si les copies sont identiques;

	if (maCopie == martine)
		cout << "clients identitiques" << endl;
	else
		cout << "non Identiques " << endl;

	Client unAutreClient("Client", "autre", 2222, "h3T3A7", 20180212);
	unAutreClient = maCopie;

	cout << unAutreClient;

	// Creez un fournisseur
	Fournisseur poly = Fournisseur("Ecole", "Polytechnique", 123456789, "H3T 1J4");
	// afficher le fournisseur
	cout << poly;

	// Creation de 15 Produits Ordinaire
	ProduitOrdinaire* produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] =
	{ 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new ProduitOrdinaire(poly, "p" + to_string(i), i, echantillonPrix[i], TypeProduitOrdinaire, true);

	// Creez un produit aux encheres
	ProduitAuxEncheres* prodAuxEncheres = new ProduitAuxEncheres(poly, "pAuxEncheres", 20,
		100, TypeProduitAuxEncheres);

	// Le client achete les 7 premiers porduits
	for (int i = 0; i < 7; i++)
		martine.acheter(produits[i]);

	// Afficher Panier du client
	cout << martine;

	//// afficher le fournisseur
	cout << poly;

	//// Client mise sur le produit aux encheres 
	martine.miserProduit(prodAuxEncheres, 500);

	cout << "\nMartine vient de faire une mise sur le produit voici son total a payer:";
	cout << martine.obtenirPanier()->obtenirTotalApayer() << std::endl;

	//// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	//// Ma copie mise aussi  sur le produit  aux enchères
	maCopie.miserProduit(prodAuxEncheres, 555);

	// On essaye encore avec une mise plus base pour montrer que la mise n'est pas assez haute
	martine.miserProduit(prodAuxEncheres, 500);

	// afin de montrer qu'elle n'a plus le produit au enchere dans son panier
	cout << "\nMartine vient de faire surmiser donc elle n'a plus le produit aux enchere dans son panier:";
	cout << martine.obtenirPanier()->obtenirTotalApayer() << std::endl;

	//// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	//// Afficher Panier du client
	cout << martine << endl;

	// trouver le produit le plus cher du panier
	cout << "##############################################\n";
	cout << " Produit le plus cher\n"<< *martine.obtenirPanier()->trouverProduitPlusCher();
	cout << "##############################################\n\n\n";
	//
	//// livrer le panier du client martine
	martine.livrerPanier();

	//// Afficher lefournisseur
	cout << poly << endl;
	//		ProduitOrdinaire* temp = static_cast<ProduitOrdinaire*>(prod);

	// Nettoyer la memoire 
	for (int i = 0; i < NB_PRODUCTS;i++) {
		delete produits[i];
	}
	delete prodAuxEncheres;
	int maman = 15;
	
}
