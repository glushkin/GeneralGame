#include <iostream> 
#include <SFML/Graphics.hpp>
#include "map.h" //���������� ��� � ������
#include "view.h"//���������� ��� � ����� ������

using namespace sf;



////////////////////////////////////////////////////����� ������////////////////////////
class Player {  // ����� ������
private: float x, y = 0;
public:
	float w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������

	Player(String F, float X, float Y, float W, float H) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
		image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
		texture.loadFromImage(image);//���������� ���� ����������� � ��������
		sprite.setTexture(texture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
		sprite.setTextureRect(IntRect(0, 0, w, h));  //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
	}



	void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
	{
		switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
		{
		case 0: dx = speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
		case 1: dx = -speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
		case 2: dx = 0; dy = speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
		case 3: dx = 0; dy = -speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
		}

		x += dx*time;//��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
		y += dy*time;//���������� �� ������

		speed = 0;//�������� ��������, ����� �������� �����������.
		sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	}

	float GetPlayerCoordinateX() {	//���� ������� ����� �������� ���������� �	
		return x;
	}
	float GetPlayerCoordinateY() {	//���� ������� ����� �������� ���������� Y 	
		return y;
	}
};


int main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "KOSTROMIN FIGHTER"); //������ ����
	view.reset(sf::FloatRect(0, 0, 1024, 768));//������ "����" ������ ��� �������� ������� ���� ������. (����� ����� ������ ��� �����) ��� �� ���� �������������.



	Image map_image;//������ ����������� ��� �����
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������
	float CurrentFrame = 0;//������ ������� ����
	Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� ��������/������������� ����������). 

	Player p("heroO.png", 250, 250, 93.0, 135.0);//������� ������ p ������ player,������ "heroO.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������.

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 500; //�������� ����))


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////

		if ((!Keyboard::isKeyPressed(Keyboard::W) || (!Keyboard::isKeyPressed(Keyboard::S)) || (!Keyboard::isKeyPressed(Keyboard::D)) || (!Keyboard::isKeyPressed(Keyboard::A)))) {
			CurrentFrame += 0.004*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(110 * int(CurrentFrame), 10, 110, 125)); //���������� �� ����������� �. ������ ����� 96 � ������������ �������������� �� ����. ������ 96 � ���������� �����. ������ � ������ ��������������, ��������� ����� � ��� ������.
			GetPlayerCoordinateforview(p.GetPlayerCoordinateX(), p.GetPlayerCoordinateY());//�������� ���������� ������ � ������� ���������� �������


		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed = 0.1;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���
			CurrentFrame += 0.0004*time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			p.sprite.setTextureRect(IntRect(120 *int(CurrentFrame), 168, 120, 120)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
			GetPlayerCoordinateforview(p.GetPlayerCoordinateX(), p.GetPlayerCoordinateY());//�������� ���������� ������ � ������� ���������� �������

		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed = 0.1;//����������� ������, �� ����
			CurrentFrame += 0.0004*time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			p.sprite.setTextureRect(IntRect(120 * int(CurrentFrame), 293, 120, 120));  //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
			GetPlayerCoordinateforview(p.GetPlayerCoordinateX(), p.GetPlayerCoordinateY());//�������� ���������� ������ � ������� ���������� �������

		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; p.speed = 0.1;//����������� ����, �� ����
			GetPlayerCoordinateforview(p.GetPlayerCoordinateX(), p.GetPlayerCoordinateY());//�������� ���������� ������ � ������� ���������� �������

		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			p.dir = 2; p.speed = 0.1;//����������� �����, �� ����
			GetPlayerCoordinateforview(p.GetPlayerCoordinateX(), p.GetPlayerCoordinateY());//�������� ���������� ������ � ������� ���������� �������

		}

		p.update(time);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������

		viewmap(time);//������� ���������� �����, �������� �� ����� sfml
		changeview();//������������� � ������� ����
		window.setView(view);//"��������" ������ � ���� sfml
		window.clear();

		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


				s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);//������ ���������� �� �����
			}


		window.draw(p.sprite);//������ ������ ������� p ������ player
		window.display();
	}

	return 0;
}