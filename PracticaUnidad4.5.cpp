//MAVI - Unidad 4 - Ejercicio 5
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
Texture fondoTexture;
Sprite fondoSprite;

int main() {

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ventana Principal");

	//Representar imagen como fondo
	fondoTexture.loadFromFile("Unidad4_Assets/fondo.jpg");
	fondoSprite.setTexture(fondoTexture);
	float sizeTx = (float)fondoTexture.getSize().x;
	float sizeTy = (float)fondoTexture.getSize().y;
	fondoSprite.setScale(App.getSize().x/ sizeTx, App.getSize().y / sizeTy);

	//Valores Máximos y Mínimos de resolución
	int maxResolucion_x = 1000;
	int maxResolucion_y = 1000;
	int minResolucion_x = 100;
	int minResolucion_y = 100;
	int sizeWindow_x;  //Tamaño de la ventana x, y
	int sizeWindow_y;
	
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			}
		}
		//Obtener el tamaño de la pantalla
		sizeWindow_x = (int)App.getSize().x;
		sizeWindow_y = (int)App.getSize().y;

		//Verificar si el tamaño en cada eje sobrepasa los límites establecidos
		if (sizeWindow_x > maxResolucion_x) {
			App.setSize(sf::Vector2u(maxResolucion_x, sizeWindow_y));
		}
		if (sizeWindow_y > maxResolucion_y) {
			App.setSize(sf::Vector2u(sizeWindow_x, maxResolucion_y));
		}
		if (sizeWindow_x < minResolucion_x) {
			App.setSize(sf::Vector2u(minResolucion_x, sizeWindow_y));
		}
		if (sizeWindow_y < minResolucion_y) {
			App.setSize(sf::Vector2u(sizeWindow_x, minResolucion_y));
		}

		App.clear(sf::Color::Blue);

		App.draw(fondoSprite);
		App.display();
	}
	return 0;
}
