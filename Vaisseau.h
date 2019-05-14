#pragma once
#include <SFML/Graphics.hpp>
#include "Vecteur.h"

class Vaisseau {
	public:
		//Constructeur par défaut, pas obligé de le creer dans le cpp
		//Vaisseau() = default;
		Vaisseau(sf::Color const& couleur);
		~Vaisseau();
		//paramètre par defaut à sf color
		//Vaisseau(float rayon, sf::Color couleur = sf::Color::White);
		void actualiserEtat();
		void mettreAJour(float temps);
		void afficher(sf::RenderWindow& window) const;

	protected:
		//sf::CircleShape cercle{ 30 };
		//Nous indique que les objets sont initialisés
		sf::Texture texture{};
		sf::Sprite sprite{};
		Vecteur vitesse{ 0.f,0.f };
		bool accelerationEnCours{ false };
		bool tourneAGauche{ false };
		bool tourneADroite{ false };

		/*static veut dire que ce n'est pas propre à l'objet mais
		à la classe.
		On ne peut pas définir de valeur avec static et const en même
		temps. 
		On met constexpr à la place de const, on peut comme cela définir
		des valeurs aux constantes*/
		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float COEFFICIENT_FROTTEMENTS{ 2.f };
		static constexpr float VITESSE_ANGULAIRE{ 50.f };
};
