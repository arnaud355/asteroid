#pragma once

/*Struct est equivalent à classe mais tous ce qui est à l'intérieur
est uniquement publique. nous souhaitons juste lire les données
de Vecteur,inutile donc de créer une classe avec attributs privés*/
struct  Vecteur
{
	void operator+=(Vecteur const& autre);
	void operator-=(Vecteur const& autre);
	Vecteur operator*=(float coefficient) const;
	static Vecteur CreerDepuisAngle(float taille,float angleEnDegre);
	float x{ 0.f };
	float y{ 0.f };
};
