#include<iostream>
#include<math.h>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<vector>
#include<cstdlib>

using namespace sf;
using namespace std;

class Bullet
{
public:
	Sprite shape;

	Bullet(Texture *texture)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
	}
	~Bullet() {}
};

class Pesawat
{
public:	
	//int HP;
	//int HPMax;
	int direction;
	Sprite shape;
	Texture *texture;
	vector<Bullet> bullet;

	Pesawat(Texture *texture)
	{
		this->texture = texture;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
	}

	~Pesawat()
	{}
};

class Musuh
{
public :
	int HP;
	int HPMax;
	Sprite shape;
	Texture *texture;

	Musuh(Texture *texture)
	{
		this->texture = texture;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.1f, 0.1f);
	}

};

int main()
{
	srand(time(NULL));
	//setel reso sama ganti nama
	RenderWindow window(VideoMode(1280, 720), "Ngetes game tembak tembakan");
	window.setFramerateLimit(60);

	Font font;
	if (!font.loadFromFile("Fonts/BERNHC.TTF"))
		throw("Font Error");
	
	int skor;
	skor = 0;

	/*
	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(Color::Yellow);
	text.setStyle(Text::Bold);
	text.setStyle(Text::Italic);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2.f);
	text.setString("Mengenai Target : %d", %skor);
	*/

	bool tembak = false;

	/*
	CircleShape Bola;
	Bola.setRadius(40.f);
	Bola.setFillColor(Color::Yellow);
	Bola.setOutlineThickness(2.f);
	Bola.setOutlineColor(Color::Black);
	Bola.setPosition(Vector2f(0, window.getSize().y - Bola.getRadius()*3));
	*/

	CircleShape Target;
	Target.setRadius(80.f);
	Target.setFillColor(Color::Red);
	Target.setOutlineThickness(3.f);
	Target.setOutlineColor(Color::Black);
	int tanda1 = 0;
	Target.setPosition(Vector2f(0, 10.f));

	Texture PesawatTexture;
	Texture idlePesawat;
	PesawatTexture.loadFromFile("Textures/pesawat_diam.png");
	Pesawat pesawat(&PesawatTexture);

	Texture MusuhTexture;
	MusuhTexture.loadFromFile("Textures/musuh.png");
	Musuh musuh(&MusuhTexture);

	Texture BulletTexture;
	BulletTexture.loadFromFile("Textures/roket.png");
	Bullet bullet(&BulletTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			pesawat.bullet.push_back(Bullet(&BulletTexture));
		}

			//untuk close game pake esc tpi gatau kenapa malah ngebug
			/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape);
			{
				window.close();
			}
			*/
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			pesawat.shape.move(0.f, -15.f);
			pesawat.direction = 0;
			PesawatTexture.loadFromFile("Textures/pesawat_atas.png");
		}

		else if (Keyboard::isKeyPressed(Keyboard::A))
		{
			pesawat.shape.move(-15.f, 0.f);
			pesawat.direction = 1;
			PesawatTexture.loadFromFile("Textures/pesawat_kiri.png");
		}

		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			pesawat.shape.move(0.f, 15.f);
			pesawat.direction = 2;
			PesawatTexture.loadFromFile("Textures/pesawat_bawah.png");
		}

		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			pesawat.shape.move(15.f, 0.f);
			pesawat.direction = 3;
			PesawatTexture.loadFromFile("Textures/pesawat_kanan.png");
		}

		else
		{ 
			cout << pesawat.direction << endl;
			switch (pesawat.direction)
			{
			case 0:
				PesawatTexture.loadFromFile("Textures/pesawat_diam.png");
				break;
			case 1:
				PesawatTexture.loadFromFile("Textures/pesawat_diam_kiri.png");
				break;
			case 2:
				PesawatTexture.loadFromFile("Textures/pesawat_diam_bawah.png");
				break;
			case 3:
				PesawatTexture.loadFromFile("Textures/pesawat_diam_kanan.png");
				break;
			}
		}


		//NGECEK UJUNG WINDOW
		if (pesawat.shape.getPosition().x <= 0) //untuk check sebelah kiri
			pesawat.shape.setPosition(0.f, pesawat.shape.getPosition().y);

		if (pesawat.shape.getPosition().x >= window.getSize().x - pesawat.shape.getGlobalBounds().width) //UNTUK CEK KANAN
			pesawat.shape.setPosition(window.getSize().x - pesawat.shape.getGlobalBounds().width, pesawat.shape.getPosition().y);

		if (pesawat.shape.getPosition().y <= 0) //untuk check ATAS
			pesawat.shape.setPosition(pesawat.shape.getPosition().x, 0.f);

		if (pesawat.shape.getPosition().y >= window.getSize().y -pesawat.shape.getGlobalBounds().height) //UNTUK CEK BAGIAN BAWAH
			pesawat.shape.setPosition(pesawat.shape.getPosition().x, window.getSize().y - pesawat.shape.getGlobalBounds().height);

		//Atur background dan items (updates)
		window.clear(Color{ 0x373737FF }); //dipake untuk warnain background
		if (Target.getPosition().x <= 0)
			tanda1 = 1;
		else if (Target.getPosition().x + Target.getRadius()*2 >= window.getSize().x)
			tanda1 = 0;

		if (tanda1 == 0)
		{
			Target.move(-5.f, 0);
		}
		else
		{
			Target.move(5.f, 0);
		}

		//DRAW DULU SBLOM DISPLAY
		window.draw(Target);
		window.draw(pesawat.shape);
		for (size_t i=0; i< pesawat.bullet.size();i++)
		{
			window.draw(pesawat.bullet[i].shape);
		}
		window.draw(musuh.shape);
		//window.draw(Bola);
		window.display();
	}

	return 0;
}