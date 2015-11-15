#include <SFML/Graphics.hpp>

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
int main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "KOSTROMIN FIGHTER"); //������ ����

	Image heroimage; //������� ������ Image (�����������)
	heroimage.loadFromFile("images/heroO.png");//��������� � ���� ����

	Texture herotexture;//������� ������ Texture (��������)
	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)

	Sprite herosprite;//������� ������ Sprite(������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setTextureRect(IntRect(9, 8, 93, 135));//�������� ������ ��� ������������� � ������
	herosprite.setPosition(250, 250);//������ ��������� ���������� ��������� �������


	float CurrentFrame = 0;//������ ������� ����
	Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� ��������/������������� ����������). 

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
		//���� �� ������ ������� ����� & �� ������ ����� & ���� & ������, �� ������ �������� ���������
		if ((!Keyboard::isKeyPressed(Keyboard::W) || (!Keyboard::isKeyPressed(Keyboard::S)) || (!Keyboard::isKeyPressed(Keyboard::D)) || (!Keyboard::isKeyPressed(Keyboard::A)))) {
			CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
		
			herosprite.setTextureRect(IntRect(110 * int(CurrentFrame), 10, 110, 125)); //���������� �� ����������� �. ������ ����� 96 � ������������ �������������� �� ����. ������ 96 � ���������� �����. ������ � ������ ��������������, ��������� ����� � ��� ������.
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			CurrentFrame += 0.0005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 6) CurrentFrame -= 6; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(120 * int(CurrentFrame), 168, 120, 120)); //���������� �� ����������� �. ������ �����  � ������������ �������������� �� ����. ������ � ���������� �����. ������ � ������ ��������������, ��������� ����� � ��� ������.
			herosprite.move(-0.1*time, 0);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.0005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 6) CurrentFrame -= 6; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(120 * int(CurrentFrame), 293, 120, 120)); //���������� �� ����������� �.  ������ �����  � ������������ �������������� �� ����. ������  � ���������� �����. ������ � ������ ��������������, ��������� ����� � ��� ������.

			herosprite.move(0.1*time, 0);//���������� ���� �������� ��������� ������

		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			herosprite.move(0, -0.1*time);//���������� ���� �������� ��������� �����
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			herosprite.move(0, 0.1*time);//���������� ���� �������� ��������� �����


		}

		window.clear();//������� �����
		window.draw(herosprite);//������� ������ �� �����
		window.display();//���������� ������
	}

	return 0;
}