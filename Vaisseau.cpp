#include <iostream>
#include "Vaisseau.h"

Vaisseau::Vaisseau(sf::Color const& couleur) {
	//cercle.setFillColor(couleur);
	if (!texture.loadFromFile("ressources/vaisseau.png")) {
		std::cerr << "L'image n'as pas été correctement chargée" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setColor(couleur);
	sprite.setOrigin(sprite.getLocalBounds.width / 2, sprite.getLocalBounds.height / 2);
	sprite.setPosition( 50,50 );
}
Vaisseau::~Vaisseau() {
	std::cout << "En revoir";
}
/*
Vaisseau::Vaisseau(float rayon, sf::Color couleur) : cercle{ rayon } {
	cercle.setFillColor(couleur);
}*/
void Vaisseau::actualiserEtat() {
		/*isKeyPressed est une méthode de la classe keyboard, elle renvoie
		si oui ou non la touche à ete pressée*/
		accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
void Vaisseau::mettreAJour(float temps) {
	if (accelerationEnCours) {
		vitesse += Vecteur::CreerDepuisAngle(ACCELERATION * temps,sprite.getRotation());
	}
	vitesse -= vitesse * COEFFICIENT_FROTTEMENTS * temps;
	auto deplacement = vitesse * temps;
	sprite.move(deplacement.x, deplacement.y);
	if (tourneAGauche) {
		sprite.rotate( -VITESSE_ANGULAIRE * temps );
	}
	if (tourneADroite) {
		sprite.rotate( VITESSE_ANGULAIRE * temps );
	}
}
void Vaisseau::afficher(sf::RenderWindow& window) const {
	window.draw(sprite);
}
