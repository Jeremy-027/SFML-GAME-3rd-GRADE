#include<iostream>
#include<math.h>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include<vector>
#include<cstdlib>
#include<cmath>

using namespace sf;
using namespace std;

class BulletKanan
{
public:
	Sprite shape;

	BulletKanan(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletKanan() {}
};

class BulletKiri
{
public:
	Sprite shape;

	BulletKiri(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletKiri() {}
};

class BulletAtas
{
public:
	Sprite shape;

	BulletAtas(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletAtas() {}
};

class BulletBawah
{
public:
	Sprite shape;

	BulletBawah(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletBawah() {}
};

class BulletKananBoss
{
public:
	Sprite shape;

	BulletKananBoss(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletKananBoss() {}
};

class BulletKiriBoss
{
public:
	Sprite shape;

	BulletKiriBoss(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletKiriBoss() {}
};

class BulletAtasBoss
{
public:
	Sprite shape;

	BulletAtasBoss(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletAtasBoss() {}
};

class BulletBawahBoss
{
public:
	Sprite shape;

	BulletBawahBoss(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.09f, 0.09f);
		this->shape.setPosition(pos);
	}
	~BulletBawahBoss() {}
};

class Pesawat
{
public:	
	int HP;
	int HPMax;
	int direction;

	Sprite shape;
	Texture *texture;

	vector<BulletKanan> bulletKanan;
	vector<BulletKiri> bulletKiri;
	vector<BulletAtas> bulletAtas;
	vector<BulletBawah> bulletBawah;

	Pesawat(Texture *texture)
	{
		//DEKLARASI NYAWA
		this-> HPMax = 10;
		this->HP = this->HPMax;


		//PENGATURAN TEXTURE DAN UKURAN
		this->texture = texture;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.14f, 0.14f);
	}

	~Pesawat()
	{}
};

class Teman
{
public:
	Sprite shape;
	int HP;
	int HPMax;
	Texture *texture;

	Teman(Texture *texture, Vector2u windowSize)
	{
		this->HPMax = 5;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.08f, 0.08f);
		this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}

	~Teman()
	{}
};

class Musuh
{
public :
	Sprite shape;
	int HP;
	int HPMax;
	Texture *texture;

	Musuh(Texture *texture, Vector2u windowSize)
	{
		this->HPMax = rand() % 3 + 1;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.08f, 0.08f);
		this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}

	~Musuh()
	{}
};

class Musuh2
{
public:
	Sprite shape;
	int HP;
	int HPMax;
	Texture *texture;

	Musuh2(Texture *texture, Vector2u windowSize)
	{
		this->HPMax = rand() % 3 + 1;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.18f, 0.18f);
		this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}

	~Musuh2()
	{}
};

class Boss
{
public:
	Sprite shape;
	int HP;
	int HPMax;
	Texture *texture;

	vector<BulletKananBoss> bulletKananBoss;
	vector<BulletKiriBoss> bulletKiriBoss;
	vector<BulletAtasBoss> bulletAtasBoss;
	vector<BulletBawahBoss> bulletBawahBoss;

	Boss(Texture *texture, Vector2u windowSize)
	{
		this->HPMax = 15;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.4f, 0.4f);
		this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}

	~Boss()
	{}
};

int main()
{
	srand(time(NULL));
	//setel reso sama ganti nama
	RenderWindow window(VideoMode(1600, 900), "Ngetes game tembak tembakan");
	window.setFramerateLimit(45);

	Texture BGtexture;
	if (!BGtexture.loadFromFile("Textures/tesbg.png"))
	{
		cout << "Load Failed" << endl;
		system("pause");
	}
	Sprite Tbackground(BGtexture);

	Music music;
	if (!music.openFromFile("Audio/music.ogg"))
		return -1;
	music.play();

	SoundBuffer bossSB;
	Sound boss;

	//------------------------- PILIH FONT ----------------------//
	Font font;
	font.loadFromFile("Fonts/BERNHC.TTF");
	//--------------------------- ------------------------------//

	//----------------- INISIALISASI TEXTURE -------------------//
	Texture PesawatTexture;
	Texture idlePesawat;
	PesawatTexture.loadFromFile("Textures/pesawat_diam.png");

	Texture temanTexture;
	temanTexture.loadFromFile("Textures/teman.png");

	Texture musuhTexture;
	musuhTexture.loadFromFile("Textures/musuh.png");

	Texture musuh2Texture;
	musuh2Texture.loadFromFile("Textures/musuh2.png");

	Texture BossTexture;
	BossTexture.loadFromFile("Textures/BOSS.png");

	Texture BulletKananTexture;
	BulletKananTexture.loadFromFile("Textures/rokety.png");

	Texture BulletKiriTexture;
	BulletKiriTexture.loadFromFile("Textures/rokety2.png");

	Texture BulletBawahTexture;
	BulletBawahTexture.loadFromFile("Textures/roketz1.png");

	Texture BulletAtasTexture;
	BulletAtasTexture.loadFromFile("Textures/roketz3.png");

	Texture BulletKananBossTexture;
	BulletKananBossTexture.loadFromFile("Textures/rokety.png");

	Texture BulletKiriBossTexture;
	BulletKiriBossTexture.loadFromFile("Textures/rokety2.png");

	Texture BulletBawahBossTexture;
	BulletBawahBossTexture.loadFromFile("Textures/roketz1.png");

	Texture BulletAtasBossTexture;
	BulletAtasBossTexture.loadFromFile("Textures/roketz3.png");
	//-----------------------------------------------------------//


	//----------------- INISIALISASI TEXT SCORE -----------------//
	Text skorText;
	skorText.setFont(font);
	skorText.setCharacterSize(30);
	skorText.setFillColor(Color::White);
	skorText.setPosition(10.f, 10.f);
	//-----------------------------------------------------------//



	//----------------- INISIALISASI GAME OVER ------------------//
	Text kalahText;
	kalahText.setFont(font);
	kalahText.setCharacterSize(150);
	kalahText.setFillColor(Color::Red);
	kalahText.setOutlineThickness(2);
	kalahText.setOutlineColor(Color::Black);
	kalahText.setPosition((window.getSize().x / 2)-350, (window.getSize().y / 2)-100);
	kalahText.setString("GAME OVER!");
	//-----------------------------------------------------------//

	//----------------- INISIALISASI PLAYER ---------------------//
	int shootTimer = 10;
	int skor = 0;
	int skor_min = 0;

	Pesawat pesawat(&PesawatTexture);
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(20);
	hpText.setFillColor(Color::Yellow);
	//-----------------------------------------------------------//

	//----------------- INISIALISASI TEMAN ---------------------//
	int temanSpawnTimer = 0;
	vector<Teman> temanvector;
	Text ThpText;
	ThpText.setFont(font);
	ThpText.setCharacterSize(15);
	ThpText.setFillColor(Color::Yellow);
	//-----------------------------------------------------------//

	//----------------- INISIALISASI MUSUH ---------------------//
	int musuhSpawnTimer = 0;
	vector<Musuh> musuhvector;
	Text MhpText;
	MhpText.setFont(font);
	MhpText.setCharacterSize(15);
	MhpText.setFillColor(Color::White);
	//-----------------------------------------------------------//

	//----------------- INISIALISASI MUSUH 2--------------------//
	int musuh2SpawnTimer = 80;
	vector<Musuh2> musuh2vector;
	Text Mhp2Text;
	Mhp2Text.setFont(font);
	Mhp2Text.setCharacterSize(15);
	Mhp2Text.setFillColor(Color::White);
	//-----------------------------------------------------------//

	//----------------- INISIALISASI BOSS -----------------------//
	int BossSpawnTimer = 300;
	vector<Boss> bossvector;
	Text BossText;
	BossText.setFont(font);
	BossText.setCharacterSize(15);
	BossText.setFillColor(Color::White);
	//-----------------------------------------------------------//



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}

		if (pesawat.HP > 0)
		{
			//----------------- PERGERAKAN PLAYER ---------------------//
			if (pesawat.direction == 0)
			{
				PesawatTexture.loadFromFile("Textures/pesawat_diam.png");
			}

			if (pesawat.direction == 1)
			{
				PesawatTexture.loadFromFile("Textures/pesawat_diam_kiri.png");
			}

			if (pesawat.direction == 2)
			{
				PesawatTexture.loadFromFile("Textures/pesawat_diam_bawah.png");
			}

			if (pesawat.direction == 3)
			{
				PesawatTexture.loadFromFile("Textures/pesawat_diam_kanan.png");
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				pesawat.shape.move(0.f, -15.f);
				pesawat.direction = 0;
				PesawatTexture.loadFromFile("Textures/pesawat_atas.png");
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				pesawat.shape.move(-15.f, 0.f);
				pesawat.direction = 1;
				PesawatTexture.loadFromFile("Textures/pesawat_kiri.png");
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				pesawat.shape.move(0.f, 15.f);
				pesawat.direction = 2;
				PesawatTexture.loadFromFile("Textures/pesawat_bawah.png");
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				pesawat.shape.move(15.f, 0.f);
				pesawat.direction = 3;
				PesawatTexture.loadFromFile("Textures/pesawat_kanan.png");
			}
			//----------------------------------------------------------------//




			//----------------------- TEXT NYAWA PLAYER ----------------------//
			hpText.setPosition(pesawat.shape.getPosition().x, pesawat.shape.getPosition().y - hpText.getGlobalBounds().height);
			hpText.setString(to_string(pesawat.HP) + "/" + to_string(pesawat.HPMax));
			//----------------------------------------------------------------//




			//----------------------- BOUNDARIES WINDOW ----------------------//
			if (pesawat.shape.getPosition().x <= 0)
				pesawat.shape.setPosition(0.f, pesawat.shape.getPosition().y);

			if (pesawat.shape.getPosition().x >= window.getSize().x - pesawat.shape.getGlobalBounds().width)
				pesawat.shape.setPosition(window.getSize().x - pesawat.shape.getGlobalBounds().width, pesawat.shape.getPosition().y);

			if (pesawat.shape.getPosition().y <= 0)
				pesawat.shape.setPosition(pesawat.shape.getPosition().x, 0.f);

			if (pesawat.shape.getPosition().y >= window.getSize().y - pesawat.shape.getGlobalBounds().height)
				pesawat.shape.setPosition(pesawat.shape.getPosition().x, window.getSize().y - pesawat.shape.getGlobalBounds().height);
			//----------------------------------------------------------------//


			if (pesawat.direction == 3);
			{
				//------------------------- ATUR CONTROLS ------------------------//
				if (shootTimer < 40)
					shootTimer++;

				if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 40 && pesawat.direction == 3)
				{
					pesawat.bulletKanan.push_back(BulletKanan(&BulletKananTexture, pesawat.shape.getPosition()));
					shootTimer = 0;
				}
				//---------------------------------------------------------------//




				//------------------------- ATUR BULLET -------------------------//
				for (size_t i = 0; i < pesawat.bulletKanan.size(); i++)
				{		
					pesawat.bulletKanan[i].shape.move(25.f, 0.f);


					//----------------------- BOUNDARIES DENGAN WINDOW --------------------//
					if (pesawat.bulletKanan[i].shape.getPosition().x > window.getSize().x)
					{
						pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
						break;
					}

					if (pesawat.bulletKanan[i].shape.getPosition().y > window.getSize().y)
					{
						pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
						break;
					}

					if (pesawat.bulletKanan[i].shape.getPosition().y <= 0)
					{
						pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
						break;
					}

					if (pesawat.bulletKanan[i].shape.getPosition().x <= 0)
					{
						pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
						break;
					}
					//---------------------------------------------------------------------//



					//------------------------ HITBOX DENGAN MUSUH ------------------------//
					for (size_t k = 0; k < musuhvector.size(); k++)
					{
						if (pesawat.bulletKanan[i].shape.getGlobalBounds().intersects(musuhvector[k].shape.getGlobalBounds()))
						{
							if (musuhvector[k].HP <= 1)
							{
								skor += musuhvector[k].HPMax;
								musuhvector.erase(musuhvector.begin() + k);
							}

							else
								musuhvector[k].HP--;

							pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
							break;
						}
					}

					for (size_t z = 0; z < musuh2vector.size(); z++)
					{
						if (pesawat.bulletKanan[i].shape.getGlobalBounds().intersects(musuh2vector[z].shape.getGlobalBounds()))
						{
							if (musuh2vector[z].HP <= 1)
							{
								skor += musuh2vector[z].HPMax;
								musuh2vector.erase(musuh2vector.begin() + z);
							}

							else
								musuh2vector[z].HP--;

							pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
							break;
						}
					}

					for (size_t z = 0; z < bossvector.size(); z++)
					{
						if (pesawat.bulletKanan[i].shape.getGlobalBounds().intersects(bossvector[z].shape.getGlobalBounds()))
						{
							if (bossvector[z].HP <= 1)
							{
								skor += bossvector[z].HPMax;
								bossvector.erase(bossvector.begin() + z);
							}

							else
								bossvector[z].HP--;

							pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
							break;
						}
					}

					for (size_t r = 0; r < temanvector.size(); r++)
					{
						if (pesawat.bulletKanan[i].shape.getGlobalBounds().intersects(temanvector[r].shape.getGlobalBounds()))
						{
							if (temanvector[r].HP <= 1)
							{
								skor -= temanvector[r].HPMax;
								temanvector.erase(temanvector.begin() + r);
							}

							else
								temanvector[r].HP--;

							pesawat.bulletKanan.erase(pesawat.bulletKanan.begin() + i);
							break;
						}
					}
				}
			}
			//------------------------------------------------------------------------//

			if (pesawat.direction == 0);
			{
				//------------------------- ATUR CONTROLS ------------------------//
				if (shootTimer < 40)
					shootTimer++;

				if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 40 && pesawat.direction == 0)
				{
					pesawat.bulletAtas.push_back(BulletAtas(&BulletAtasTexture, pesawat.shape.getPosition()));
					shootTimer = 0;
				}
				//---------------------------------------------------------------//




				//------------------------- ATUR BULLET -------------------------//
				for (size_t a = 0; a < pesawat.bulletAtas.size(); a++)
				{
					pesawat.bulletAtas[a].shape.move(0.f, -25.f);

					//----------------------- BOUNDARIES DENGAN WINDOW --------------------//
					if (pesawat.bulletAtas[a].shape.getPosition().x > window.getSize().x)
					{
						pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
						break;
					}

					if (pesawat.bulletAtas[a].shape.getPosition().y > window.getSize().y)
					{
						pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
						break;
					}

					if (pesawat.bulletAtas[a].shape.getPosition().y <= 0)
					{
						pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
						break;
					}

					if (pesawat.bulletAtas[a].shape.getPosition().x <= 0)
					{
						pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
						break;
					}
					//---------------------------------------------------------------------//



					//------------------------ HITBOX DENGAN MUSUH ------------------------//
					for (size_t k = 0; k < musuhvector.size(); k++)
					{
						if (pesawat.bulletAtas[a].shape.getGlobalBounds().intersects(musuhvector[k].shape.getGlobalBounds()))
						{
							if (musuhvector[k].HP <= 1)
							{
								skor += musuhvector[k].HPMax;
								musuhvector.erase(musuhvector.begin() + k);
							}

							else
								musuhvector[k].HP--;

							pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
							break;
						}
					}

					for (size_t z = 0; z < musuh2vector.size(); z++)
					{
						if (pesawat.bulletAtas[a].shape.getGlobalBounds().intersects(musuh2vector[z].shape.getGlobalBounds()))
						{
							if (musuh2vector[z].HP <= 1)
							{
								skor += musuh2vector[z].HPMax;
								musuh2vector.erase(musuh2vector.begin() + z);
							}

							else
								musuh2vector[z].HP--;

							pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
							break;
						}
					}

					for (size_t z = 0; z < bossvector.size(); z++)
					{
						if (pesawat.bulletAtas[a].shape.getGlobalBounds().intersects(bossvector[z].shape.getGlobalBounds()))
						{
							if (bossvector[z].HP <= 1)
							{
								skor += bossvector[z].HPMax;
								bossvector.erase(bossvector.begin() + z);
							}

							else
								bossvector[z].HP--;

							pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
							break;
						}
					}

					for (size_t r = 0; r < temanvector.size(); r++)
					{
						if (pesawat.bulletAtas[a].shape.getGlobalBounds().intersects(temanvector[r].shape.getGlobalBounds()))
						{
							if (temanvector[r].HP <= 1)
							{
								skor -= temanvector[r].HPMax;
								temanvector.erase(temanvector.begin() + r);
							}

							else
								temanvector[r].HP--;

							pesawat.bulletAtas.erase(pesawat.bulletAtas.begin() + a);
							break;
						}
					}

				}
			}
			//------------------------------------------------------------------------//

			if (pesawat.direction == 2);
			{
				//------------------------- ATUR CONTROLS ------------------------//
				if (shootTimer < 40)
					shootTimer++;

				if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 40 && pesawat.direction == 2)
				{
					pesawat.bulletBawah.push_back(BulletBawah(&BulletBawahTexture, pesawat.shape.getPosition()));
					shootTimer = 0;
				}
				//---------------------------------------------------------------//




				//------------------------- ATUR BULLET -------------------------//
				for (size_t q = 0; q < pesawat.bulletBawah.size(); q++)
				{
					pesawat.bulletBawah[q].shape.move(0.f, 25.f);


					//----------------------- BOUNDARIES DENGAN WINDOW --------------------//
					if (pesawat.bulletBawah[q].shape.getPosition().x > window.getSize().x)
					{
						pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
						break;
					}

					if (pesawat.bulletBawah[q].shape.getPosition().y > window.getSize().y)
					{
						pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
						break;
					}

					if (pesawat.bulletBawah[q].shape.getPosition().y <= 0)
					{
						pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
						break;
					}

					if (pesawat.bulletBawah[q].shape.getPosition().x <= 0)
					{
						pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
						break;
					}
					//---------------------------------------------------------------------//



					//------------------------ HITBOX DENGAN MUSUH ------------------------//
					for (size_t k = 0; k < musuhvector.size(); k++)
					{
						if (pesawat.bulletBawah[q].shape.getGlobalBounds().intersects(musuhvector[k].shape.getGlobalBounds()))
						{
							if (musuhvector[k].HP <= 1)
							{
								skor += musuhvector[k].HPMax;
								musuhvector.erase(musuhvector.begin() + k);
							}

							else
								musuhvector[k].HP--;

							pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
							break;
						}
					}

					for (size_t z = 0; z < musuh2vector.size(); z++)
					{
						if (pesawat.bulletBawah[q].shape.getGlobalBounds().intersects(musuh2vector[z].shape.getGlobalBounds()))
						{
							if (musuh2vector[z].HP <= 1)
							{
								skor += musuh2vector[z].HPMax;
								musuh2vector.erase(musuh2vector.begin() + z);
							}

							else
								musuh2vector[z].HP--;

							pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
							break;
						}
					}

					for (size_t z = 0; z < bossvector.size(); z++)
					{
						if (pesawat.bulletBawah[q].shape.getGlobalBounds().intersects(bossvector[z].shape.getGlobalBounds()))
						{
							if (bossvector[z].HP <= 1)
							{
								skor += bossvector[z].HPMax;
								bossvector.erase(bossvector.begin() + z);
							}

							else
								bossvector[z].HP--;

							pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
							break;
						}
					}

					for (size_t r = 0; r < temanvector.size(); r++)
					{
						if (pesawat.bulletBawah[q].shape.getGlobalBounds().intersects(temanvector[r].shape.getGlobalBounds()))
						{
							if (temanvector[r].HP <= 1)
							{
								skor -= temanvector[r].HPMax;
								temanvector.erase(temanvector.begin() + r);
							}

							else
								temanvector[r].HP--;

							pesawat.bulletBawah.erase(pesawat.bulletBawah.begin() + q);
							break;
						}
					}
				}
			}

			//------------------------------------------------------------------------------//

			if (pesawat.direction == 1);
			{
				//------------------------- ATUR CONTROLS ------------------------//
				if (shootTimer < 40)
					shootTimer++;

				if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 40 && pesawat.direction == 1)
				{
					pesawat.bulletKiri.push_back(BulletKiri(&BulletKiriTexture, pesawat.shape.getPosition()));
					shootTimer = 0;
				}
				//---------------------------------------------------------------//




				//------------------------- ATUR BULLET -------------------------//
				for (size_t e = 0; e < pesawat.bulletKiri.size(); e++)
				{
					pesawat.bulletKiri[e].shape.move(-25.f, 0.f);

					//----------------------- BOUNDARIES DENGAN WINDOW --------------------//
					if (pesawat.bulletKiri[e].shape.getPosition().x > window.getSize().x)
					{
						pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
						break;
					}

					if (pesawat.bulletKiri[e].shape.getPosition().y > window.getSize().y)
					{
						pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
						break;
					}

					if (pesawat.bulletKiri[e].shape.getPosition().y <= 0)
					{
						pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
						break;
					}

					if (pesawat.bulletKiri[e].shape.getPosition().x <= 0)
					{
						pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
						break;
					}
					//---------------------------------------------------------------------//



					//------------------------ HITBOX DENGAN MUSUH ------------------------//
					for (size_t k = 0; k < musuhvector.size(); k++)
					{
						if (pesawat.bulletKiri[e].shape.getGlobalBounds().intersects(musuhvector[k].shape.getGlobalBounds()))
						{
							if (musuhvector[k].HP <= 1)
							{
								skor += musuhvector[k].HPMax;
								musuhvector.erase(musuhvector.begin() + k);
							}

							else
								musuhvector[k].HP--;

							pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
							break;
						}
					}

					for (size_t z = 0; z < musuh2vector.size(); z++)
					{
						if (pesawat.bulletKiri[e].shape.getGlobalBounds().intersects(musuh2vector[z].shape.getGlobalBounds()))
						{
							if (musuh2vector[z].HP <= 1)
							{
								skor += musuh2vector[z].HPMax;
								musuh2vector.erase(musuh2vector.begin() + z);
							}

							else
								musuh2vector[z].HP--;

							pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
							break;
						}
					}

					for (size_t z = 0; z < bossvector.size(); z++)
					{
						if (pesawat.bulletKiri[e].shape.getGlobalBounds().intersects(bossvector[z].shape.getGlobalBounds()))
						{
							if (bossvector[z].HP <= 1)
							{
								skor += bossvector[z].HPMax;
								bossvector.erase(bossvector.begin() + z);
							}

							else
								bossvector[z].HP--;

							pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
							break;
						}
					}

					for (size_t r = 0; r < temanvector.size(); r++)
					{
						if (pesawat.bulletKiri[e].shape.getGlobalBounds().intersects(temanvector[r].shape.getGlobalBounds()))
						{
							if (temanvector[r].HP <= 1)
							{
								skor -= temanvector[r].HPMax;
								temanvector.erase(temanvector.begin() + r);
							}

							else
								temanvector[r].HP--;

							pesawat.bulletKiri.erase(pesawat.bulletKiri.begin() + e);
							break;
						}
					}
				}
			}
			//------------------------------------------------------------------------//


			//-------------------------------- MUSUH ---------------------------------//
			if (musuhSpawnTimer < 70)
				musuhSpawnTimer++;

			if (musuhSpawnTimer >= 70)
			{
				musuhvector.push_back(Musuh(&musuhTexture, window.getSize()));
				musuhSpawnTimer = 0;
			}

			if (musuh2SpawnTimer < 180)
				musuh2SpawnTimer++;

			if (musuh2SpawnTimer >= 180)
			{
				musuh2vector.push_back(Musuh2(&musuh2Texture, window.getSize()));
				musuh2SpawnTimer = 100;
			}

			if (BossSpawnTimer < 750)
				BossSpawnTimer++;

			if (BossSpawnTimer == 500)
			{
				boss.setBuffer(bossSB);
				boss.play();
			}

			if (BossSpawnTimer >= 750)
			{
				bossvector.push_back(Boss(&BossTexture, window.getSize()));
				BossSpawnTimer = 0;
			}

			if (temanSpawnTimer < 300)
				temanSpawnTimer++;

			if (temanSpawnTimer >= 300)
			{
				temanvector.push_back(Teman(&temanTexture, window.getSize()));
				temanSpawnTimer = 0;
			}
			//-----------------------------------------------------------------------//

			for (size_t i = 0; i < musuhvector.size(); i++)
			{
				musuhvector[i].shape.move(rand() % 5, rand() % 5);

				if (musuhvector[i].shape.getPosition().x <= 0 - musuhvector[i].shape.getGlobalBounds().width)
				{
					musuhvector.erase(musuhvector.begin() + i);
					break;
				}

				if (musuhvector[i].shape.getGlobalBounds().intersects(pesawat.shape.getGlobalBounds()))
				{
					musuhvector.erase(musuhvector.begin() + i);
					pesawat.HP--;
					break;
				}
			}


			for (size_t i = 0; i < musuh2vector.size(); i++)
			{

				Vector2f direction;
				direction = pesawat.shape.getPosition() - musuh2vector[i].shape.getPosition();

				musuh2vector[i].shape.move(direction/50.f);

				if (musuh2vector[i].shape.getPosition().x <= 0 - musuh2vector[i].shape.getGlobalBounds().width)
				{
					musuh2vector.erase(musuh2vector.begin() + i);
					break;
				}

				if (musuh2vector[i].shape.getGlobalBounds().intersects(pesawat.shape.getGlobalBounds()))
				{
					musuh2vector.erase(musuh2vector.begin() + i);
					pesawat.HP--;
					break;
				}
			}

			for (size_t i = 0; i < bossvector.size(); i++)
			{

				bossvector[i].shape.move(cos(rand()+ 2560), sin(rand()+2560));

				if (bossvector[i].shape.getPosition().x <= 0 - bossvector[i].shape.getGlobalBounds().width)
				{
					bossvector.erase(bossvector.begin() + i);
					break;
				}

				if (bossvector[i].shape.getGlobalBounds().intersects(pesawat.shape.getGlobalBounds()))
				{
					bossvector.erase(bossvector.begin() + i);
					pesawat.HP--;
					pesawat.HP--;
					break;
				}
			}


			window.clear();
			window.draw(Tbackground);
			window.draw(pesawat.shape);
			//---------------------------GAMBAR ROKET--------------------------------//
			for (size_t i = 0; i < pesawat.bulletKanan.size(); i++)
			{
				window.draw(pesawat.bulletKanan[i].shape);
			}

			for (size_t i = 0; i < pesawat.bulletKiri.size(); i++)
			{
				window.draw(pesawat.bulletKiri[i].shape);
			}

			for (size_t i = 0; i < pesawat.bulletAtas.size(); i++)
			{
				window.draw(pesawat.bulletAtas[i].shape);
			}

			for (size_t i = 0; i < pesawat.bulletBawah.size(); i++)
			{
				window.draw(pesawat.bulletBawah[i].shape);
			}
			//-----------------------------------------------------------------------//



			//---------------------------GAMBAR MUSUH--------------------------------//
			
			for (size_t z = 0; z < temanvector.size(); z++)
			{
				ThpText.setString(to_string(temanvector[z].HP) + "/" + to_string(temanvector[z].HPMax));
				ThpText.setPosition(temanvector[z].shape.getPosition().x, temanvector[z].shape.getPosition().y - ThpText.getGlobalBounds().height);
				window.draw(ThpText);

				for (size_t z = 0; z < temanvector.size(); z++)
				{
					window.draw(temanvector[z].shape);
				}

			}


			for (size_t i = 0; i < musuhvector.size(); i++)
			{
				MhpText.setString(to_string(musuhvector[i].HP) + "/" + to_string(musuhvector[i].HPMax));
				MhpText.setPosition(musuhvector[i].shape.getPosition().x, musuhvector[i].shape.getPosition().y - MhpText.getGlobalBounds().height);
				window.draw(MhpText);

				for (size_t i = 0; i < musuhvector.size(); i++)
				{
					window.draw(musuhvector[i].shape);
				}

			}


			for (size_t rr = 0; rr < musuh2vector.size(); rr++)
			{
				Mhp2Text.setString(to_string(musuh2vector[rr].HP) + "/" + to_string(musuh2vector[rr].HPMax));
				Mhp2Text.setPosition(musuh2vector[rr].shape.getPosition().x, musuh2vector[rr].shape.getPosition().y - Mhp2Text.getGlobalBounds().height);
				window.draw(Mhp2Text);

				for (size_t rr = 0; rr < musuh2vector.size(); rr++)
				{
					window.draw(musuh2vector[rr].shape);
				}

			}

			for (size_t rr = 0; rr < bossvector.size(); rr++)
			{
				BossText.setString(to_string(bossvector[rr].HP) + "/" + to_string(bossvector[rr].HPMax));
				BossText.setPosition(bossvector[rr].shape.getPosition().x, bossvector[rr].shape.getPosition().y - BossText.getGlobalBounds().height);
				window.draw(BossText);

				for (size_t rr = 0; rr < bossvector.size(); rr++)
				{
					window.draw(bossvector[rr].shape);
				}

			}


			if (skor < 0)
			{
				skor = skor_min;
			}
			
			skorText.setString("Score : " + to_string(skor));

		}

			window.draw(skorText);
			window.draw(hpText);

			if(pesawat.HP <= 0)
			{
				window.draw(kalahText);
			}

			window.display();

	}
	return 0;
}