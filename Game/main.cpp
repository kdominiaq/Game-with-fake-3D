#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include "Przeszkoda.h"
#include "Pocisk.h"




//Mapa
std::vector<sf::RectangleShape> mapa_sciana;
std::list<sf::RectangleShape> mapa_sciana_fake_3d;
//Przeszkody
std::list<Przeszkoda> pom_przeszkody;
std::list<sf::Vector2f> pom_przeszkody_ruch;
std::list<Przeszkoda> mapa_przeszkoda;
std::list<sf::Vector2f> mapa_przeszkoda_ruch;
//Tworzenie mapy postacie i Meta
sf::Vector2f postac_ustalenie_pozycji;
sf::Vector2f meta_ustalenie_pozycji;
//Pociski
std::list <Pocisk> mapa_pocisk;
std::list<sf::Vector2f> mapa_pocisk_ruch;

//Plik
std::string pom_mapa;
std::string mapa;
std::fstream plik("mapa_do_wczytania.txt", std::ios::in);
bool menu_gra = true;
bool pause_gra = true;
bool czas_gra = false;
int main()
{	
	// sprite
	sf::Texture texture_sciana;
	texture_sciana.loadFromFile("sciana.png");

	sf::Texture texture_sciana_dol;
	texture_sciana_dol.loadFromFile("sciana_1.png");

	sf::Texture texture_sciana_prawo_dol;
	texture_sciana_prawo_dol.loadFromFile("sciana_prawo_dol.png");
	
	sf::Texture texture_sciana_prawo;
	texture_sciana_prawo.loadFromFile("sciana_prawo.png");

	sf::Texture texture_sciana_lewo_dol;
	texture_sciana_lewo_dol.loadFromFile("sciana_lewo_dol.png");

	sf::Texture texture_sciana_lewo;
	texture_sciana_lewo.loadFromFile("sciana_lewo.png");
	
	sf::Texture texture_tlo;
	texture_tlo.loadFromFile("sciana_tlo.png");
	
	sf::Texture texture_tlo_1;
	texture_tlo_1.loadFromFile("sciana_tlo_1.png");

	sf::Texture texture_sciana_gora;
	texture_sciana_gora.loadFromFile("sciana_gora.png");

	sf::Texture texture_meta;
	texture_meta.loadFromFile("meta.png");
	
	sf::Texture texture_pocisk;
	texture_pocisk.loadFromFile("pocisk.png");


	//texture postac
	
	sf::Texture texture_postac_s;
	texture_postac_s.loadFromFile("postac_s.png");
	
	// sprite
	sf::Texture texture_przeszkoda;
	texture_przeszkoda.loadFromFile("przeszkoda.png");

	// wczytwanie mapy

	for (int i = 0; i < 20; i++)
	{
		std::getline(plik, mapa);
		pom_mapa += mapa + '\n';
	}

	int mapa_x = 10;
	int mapa_y = 10;
	int mapa_przechdzenie = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 41; j++)
		{

			if (pom_mapa[mapa_przechdzenie] == 'X')
			{
				sf::RectangleShape sciana(sf::Vector2f(20, 20));			
				sf::RectangleShape sciana_1(sf::Vector2f(20, 20));
				sf::RectangleShape sciana_gora(sf::Vector2f(20, 1));
				sf::RectangleShape sciana_prawo_dol(sf::Vector2f(5, 20));
				sf::RectangleShape sciana_prawo(sf::Vector2f(5, 20));
				sf::RectangleShape sciana_lewo_dol(sf::Vector2f(5, 20));
				sf::RectangleShape sciana_lewo(sf::Vector2f(5, 20));

				sciana.setOrigin(10, 10);
				sciana.setTexture(&texture_sciana);
				sciana.setPosition(mapa_x, mapa_y); 
				mapa_sciana.push_back(sciana);


				sciana_gora.setOrigin(10, -9);
				sciana_gora.setTexture(&texture_sciana_gora);
				sciana_gora.setPosition(mapa_x, mapa_y - 20);
				mapa_sciana_fake_3d.push_back(sciana_gora);

				sciana_prawo_dol.setOrigin(10, 10);
				sciana_prawo_dol.setTexture(&texture_sciana_prawo_dol);
				sciana_prawo_dol.setPosition(mapa_x+20, mapa_y + 20);
				mapa_sciana_fake_3d.push_front(sciana_prawo_dol);

				sciana_prawo.setOrigin(10, 10);
				sciana_prawo.setTexture(&texture_sciana_prawo);
				sciana_prawo.setPosition(mapa_x + 20, mapa_y);
				mapa_sciana_fake_3d.push_back(sciana_prawo);

				

				sciana_lewo_dol.setOrigin(-5, 10);
				sciana_lewo_dol.setTexture(&texture_sciana_lewo_dol);
				sciana_lewo_dol.setPosition(mapa_x - 20, mapa_y + 20);
				mapa_sciana_fake_3d.push_front(sciana_lewo_dol);

				sciana_lewo.setOrigin(-5, 10);
				sciana_lewo.setTexture(&texture_sciana_lewo);
				sciana_lewo.setPosition(mapa_x - 20, mapa_y);
				mapa_sciana_fake_3d.push_back(sciana_lewo);



				sciana_1.setOrigin(10, 10);
				sciana_1.setTexture(&texture_sciana_dol);
				sciana_1.setPosition(mapa_x, mapa_y + 20);
				mapa_sciana_fake_3d.push_back(sciana_1);

			}
			else if (pom_mapa[mapa_przechdzenie] == 'v')
			{
				Przeszkoda przeszkoda(10, mapa_x, mapa_y, false, false, 20);
				przeszkoda.setOrigin(10, 10);
				przeszkoda.setPosition(mapa_x, mapa_y);
				przeszkoda.setTexture(&texture_przeszkoda);
				mapa_przeszkoda.push_back(przeszkoda);				//do kolizji
				sf::Vector2f przeszkoda_ruch = przeszkoda.select_move_();
				mapa_przeszkoda_ruch.push_back(przeszkoda_ruch);
			}
			else if (pom_mapa[mapa_przechdzenie] == 'V')
			{
				Przeszkoda przeszkoda(10, mapa_x, mapa_y, false, true, 20);
				przeszkoda.setOrigin(10, 10);
				przeszkoda.setPosition(mapa_x, mapa_y);
				przeszkoda.setTexture(&texture_przeszkoda);
				mapa_przeszkoda.push_back(przeszkoda);				//do kolizji
				sf::Vector2f przeszkoda_ruch = przeszkoda.select_move_();
				mapa_przeszkoda_ruch.push_back(przeszkoda_ruch);
			}
			else if (pom_mapa[mapa_przechdzenie] == 'h')
			{
				Przeszkoda przeszkoda(10, mapa_x, mapa_y, true, false, 20); 
				przeszkoda.setOrigin(10, 10);
				przeszkoda.setPosition(mapa_x, mapa_y);
				przeszkoda.setTexture(&texture_przeszkoda);
				mapa_przeszkoda.push_back(przeszkoda);				//do kolizji
				sf::Vector2f przeszkoda_ruch = przeszkoda.select_move_();
				mapa_przeszkoda_ruch.push_back(przeszkoda_ruch);
			}
			else if (pom_mapa[mapa_przechdzenie] == 'H')
			{
				Przeszkoda przeszkoda(10, mapa_x, mapa_y, true, true, 20);
				przeszkoda.setOrigin(10, 10);
				przeszkoda.setPosition(mapa_x, mapa_y);			
				przeszkoda.setTexture(&texture_przeszkoda);
				mapa_przeszkoda.push_back(przeszkoda);				//do kolizji
				sf::Vector2f przeszkoda_ruch = przeszkoda.select_move_();
				mapa_przeszkoda_ruch.push_back(przeszkoda_ruch);
			}
			else if (pom_mapa[mapa_przechdzenie] == 'P')
			{
				postac_ustalenie_pozycji = sf::Vector2f(mapa_x, mapa_y);
			}
			else if (pom_mapa[mapa_przechdzenie] == 'M')
			{
				meta_ustalenie_pozycji = sf::Vector2f(mapa_x, mapa_y);
			}
			mapa_przechdzenie++;

			mapa_x += 20;
			pom_przeszkody = mapa_przeszkoda;
			pom_przeszkody_ruch = mapa_przeszkoda_ruch;

		}
		mapa_x = 10;
		mapa_y += 20;
		
	}
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	//postac,meta,tlo,zegar
	
		// POSTAC

		sf::RectangleShape postac(sf::Vector2f(18, 18));
		postac.setOrigin(9, 9);
		postac.setTexture(&texture_postac_s);
		postac.setPosition(postac_ustalenie_pozycji);
		sf::Vector2f pom(0, 0);
		sf::Vector2f move_postac(0, 0);

		//Meta

		sf::RectangleShape meta(sf::Vector2f(20, 20));
		meta.setOrigin(10, 10);
		meta.setTexture(&texture_meta);
		meta.setPosition(meta_ustalenie_pozycji);
		
		sf::RectangleShape menu(sf::Vector2f(400,300));
		menu.setOrigin(200, 150);
		//menu.setTexture(&texture_meta);
		menu.setFillColor(sf::Color::Red);
		menu.setPosition(400,200);
		
		//tlo
		sf::RectangleShape tlo(sf::Vector2f(800, 400));
		tlo.setTexture(&texture_tlo);
		//mapa_sciana_fake_3d.push_front(tlo);

		sf::RectangleShape tlo_1(sf::Vector2f(800, 180));
		tlo_1.setPosition(0, 420);
		tlo_1.setTexture(&texture_tlo_1);
		mapa_sciana_fake_3d.push_front(tlo_1);


		// wyswietlanie tekstu

		sf::Font czcionka;
		czcionka.loadFromFile("arial.ttf");
		std::string tekst_czas;
		sf::Text czas_wyswietlanie;
		czas_wyswietlanie.setCharacterSize(50);
		czas_wyswietlanie.setFont(czcionka);
		czas_wyswietlanie.setFillColor(sf::Color::Black);
		czas_wyswietlanie.setPosition(79, 484);

		std::string tekst_menu("Sterowanie: \n WSAD - Poruszanie \n LPM - Strzal \n R - Reset \n Espace - Pause \n Space - Start");
		sf::Text menu_wyswietlanie;
		menu_wyswietlanie.setString(tekst_menu);
		menu_wyswietlanie.setCharacterSize(40);
		menu_wyswietlanie.setFont(czcionka);
		menu_wyswietlanie.setFillColor(sf::Color::Black);
		menu_wyswietlanie.setPosition(210, 50);

		std::string tekst_pociski;
		sf::Text pociski_ile_zostalo_wyswietlanie;
		pociski_ile_zostalo_wyswietlanie.setCharacterSize(30);
		pociski_ile_zostalo_wyswietlanie.setFont(czcionka);
		pociski_ile_zostalo_wyswietlanie.setFillColor(sf::Color::Black);
		pociski_ile_zostalo_wyswietlanie.setPosition(733, 538);
		int pociskow_ile_zostalo_int = 200;

	
	//zegar
	sf::Time czas;
	sf::Clock zegar;
		
	//logika gry
	bool koniec_gry = false;
	bool czas_start = false;
	double p_czas = 0;
	double pom_czas = 0;
	while (window.isOpen())
	{
		sf::Event EVE;

		//Timer
		if (czas_start != true) { zegar.restart(); }
		if (pause_gra == false)
		{
			pom_czas = czas.asSeconds(); 
		}
		else { p_czas= pom_czas; zegar.restart();  }
		//else

	
		
		std::cout << p_czas <<"   "<<pom_czas << std::endl;
		if (koniec_gry == false) { czas = zegar.getElapsedTime(); }

		while (window.pollEvent(EVE))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)and pociskow_ile_zostalo_int>0)
			{	
			Pocisk pocisk(3.0, postac.getPosition(), sf::Mouse::getPosition(window));
			pocisk.setOrigin(1.5, 1.5);
			pocisk.setPosition(postac.getPosition());
			pocisk.setTexture(&texture_pocisk);
			mapa_pocisk.push_front(pocisk);
			sf::Vector2f postac_ruch = pocisk.select_();
			mapa_pocisk_ruch.push_front(postac_ruch);
			pociskow_ile_zostalo_int -= 1;
			}
			if (EVE.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				zegar.restart();
				postac.setPosition(postac_ustalenie_pozycji);
				pociskow_ile_zostalo_int = 200;
				czas_start = false;  
				mapa_przeszkoda = pom_przeszkody;
				mapa_przeszkoda_ruch = pom_przeszkody_ruch;
				pause_gra = true;
				menu_gra = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { menu_gra = true; pause_gra = true;  czas_gra = false; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { menu_gra = false; pause_gra = false; czas_gra = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { move_postac = sf::Vector2f(0, -.99); czas_start = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { move_postac = sf::Vector2f(0, .99); czas_start = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { move_postac = sf::Vector2f(-.99, 0); czas_start = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { move_postac = sf::Vector2f(.99, 0); czas_start = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { move_postac = sf::Vector2f(.49, -.49); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { move_postac = sf::Vector2f(-.49, -.49); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { move_postac = sf::Vector2f(.49, .49); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { move_postac = sf::Vector2f(-.49, .49); }
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) == false) and (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == false) and (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == false) and (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == false)) { move_postac = sf::Vector2f(0, 0); }
		}
		
		//


	

		//KOLIZJA SCIANA BOCZNA z postacia i pociskami
		bool czy_ruszyc = true;
		for (auto itr = mapa_sciana.begin(); itr != mapa_sciana.end(); itr++)
		{
			if (postac.getGlobalBounds().intersects((*itr).getGlobalBounds()))
			{
				postac.setPosition(pom);  czy_ruszyc = false; break;
			}
			if (mapa_pocisk.size() > 0) 
			{
				auto itr_pocisk_ruch = mapa_pocisk_ruch.begin();
				for (auto itr_pocisk = mapa_pocisk.begin(); itr_pocisk != mapa_pocisk.end();)
				{
					if (itr_pocisk->getGlobalBounds().intersects((*itr).getGlobalBounds()))
					{
						itr_pocisk= mapa_pocisk.erase(itr_pocisk);
						itr_pocisk_ruch = mapa_pocisk_ruch.erase(itr_pocisk_ruch);
						std::cout << 1;
					}
					else
					{
						itr_pocisk++;
						itr_pocisk_ruch++;
					}
				}
			}
		}
		if (czy_ruszyc == true and pause_gra == false)	{ pom = postac.getPosition(); postac.move(move_postac); }
		

		//czas wyswietlanie
		if (czas_start == true)
		{
			tekst_czas = std::to_string(pom_czas+p_czas);
			czas_wyswietlanie.setString(tekst_czas);
		}
		else
		{
			tekst_czas = "0.000000";
			czas_wyswietlanie.setString(tekst_czas);
		}
		if (czas_gra == false) { czas_wyswietlanie.setString("PAUSE"); }
		else{ czas_wyswietlanie.setString(tekst_czas); }
		//ruch przeszkod i pociskow
		
			auto itr_przeszkoda_ruch = mapa_przeszkoda_ruch.begin();
			for (auto itr_przeszkoda = mapa_przeszkoda.begin(); itr_przeszkoda != mapa_przeszkoda.end(); itr_przeszkoda++, itr_przeszkoda_ruch++)
			{
				*itr_przeszkoda_ruch = itr_przeszkoda->runspace(*itr_przeszkoda_ruch);
			}
		
		//kolizja
		for(auto& i : mapa_przeszkoda)
		{
			
			if ((i).isCollision(postac))
			{
				zegar.restart();
				postac.setPosition(postac_ustalenie_pozycji);
				czas_start = false;
			}
		}

		if (mapa_pocisk.size() > 0)
		{
			for (auto itr = mapa_pocisk.begin(); itr != mapa_pocisk.end(); itr++)
			{
				if (mapa_przeszkoda.size() > 0)
				{
					auto itr_przeszkoda_ruch = mapa_przeszkoda_ruch.begin();
					for (auto itr_przeszkoda = mapa_przeszkoda.begin(); itr_przeszkoda != mapa_przeszkoda.end();)
					{
						if (itr_przeszkoda->getGlobalBounds().intersects((*itr).getGlobalBounds()))
						{
							itr_przeszkoda = mapa_przeszkoda.erase(itr_przeszkoda);
							itr_przeszkoda_ruch = mapa_przeszkoda_ruch.erase(itr_przeszkoda_ruch);
							std::cout << 2;
						}
						else
						{
							itr_przeszkoda++;
							itr_przeszkoda_ruch++;
						}
					}
				}
			}
		}
		//koniec gry
		if (mapa_przeszkoda.size()==0 and postac.getGlobalBounds().intersects(meta.getGlobalBounds())) { koniec_gry = true; }

		window.clear();

		if (pause_gra == false) {
			int j_pom = 0;
			for (auto &i : mapa_przeszkoda)
			{
				i.move(*next(mapa_przeszkoda_ruch.begin(), j_pom)); j_pom++;
			}
			int i_pom = 0;
			for (auto &i : mapa_pocisk)
			{
				i.move(*next(mapa_pocisk_ruch.begin(), i_pom)); i_pom++;
			}
		}
		else {}
		//wyswietlanie
			window.draw(tlo);

			
			for (auto i : mapa_sciana_fake_3d)
			{
				window.draw((i));
			}
			window.draw(meta);

			window.draw(postac);


			for (auto i : mapa_przeszkoda)
			{
				window.draw((i));
			}
			for (auto i : mapa_sciana)
			{
				window.draw(i);
			}
			for (auto &i : mapa_pocisk)
			{
				window.draw(i);
			}

			if (menu_gra == true)
			{
				window.draw(menu);
				window.draw(menu_wyswietlanie);
			}
			
			window.draw(czas_wyswietlanie);
			pociski_ile_zostalo_wyswietlanie.setString(std::to_string(pociskow_ile_zostalo_int));
			window.draw(pociski_ile_zostalo_wyswietlanie);
		
		

		window.display();
	}

	return 0;
}