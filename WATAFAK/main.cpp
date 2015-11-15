#include <SFML/Graphics.hpp>

using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "KOSTROMIN FIGHTER"); //размер окна

	Image heroimage; //создаем объект Image (изображение)
	heroimage.loadFromFile("images/heroO.png");//загружаем в него файл

	Texture herotexture;//создаем объект Texture (текстура)
	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)

	Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
	herosprite.setTextureRect(IntRect(9, 8, 93, 135));//получили нужный нам прямоугольник с героем
	herosprite.setPosition(250, 250);//задаем начальные координаты появления спрайта


	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 500; //скорость игры))
		
		
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		//Если не нажата клавиша влево & Не нажата вверх & вниз & вправо, то спрайт стоящего персонажа
		if ((!Keyboard::isKeyPressed(Keyboard::W) || (!Keyboard::isKeyPressed(Keyboard::S)) || (!Keyboard::isKeyPressed(Keyboard::D)) || (!Keyboard::isKeyPressed(Keyboard::A)))) {
			CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 5) CurrentFrame -= 5; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
		
			herosprite.setTextureRect(IntRect(110 * int(CurrentFrame), 10, 110, 125)); //проходимся по координатам Х. первая цифра 96 – передвижение прямоугольника по иксу. вторая 96 – координата игрек. третья – ширина прямоугольника, четвертая цифра – его высота.
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
			CurrentFrame += 0.0005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 6) CurrentFrame -= 6; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(120 * int(CurrentFrame), 168, 120, 120)); //проходимся по координатам Х. первая цифра  – передвижение прямоугольника по иксу. вторая – координата игрек. третья – ширина прямоугольника, четвертая цифра – его высота.
			herosprite.move(-0.1*time, 0);//происходит само движение персонажа влево
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.0005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 6) CurrentFrame -= 6; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(120 * int(CurrentFrame), 293, 120, 120)); //проходимся по координатам Х.  первая цифра  – передвижение прямоугольника по иксу. вторая  – координата игрек. третья – ширина прямоугольника, четвертая цифра – его высота.

			herosprite.move(0.1*time, 0);//происходит само движение персонажа вправо

		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			herosprite.move(0, -0.1*time);//происходит само движение персонажа вверх
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			herosprite.move(0, 0.1*time);//происходит само движение персонажа вверх


		}

		window.clear();//очищаем экран
		window.draw(herosprite);//выводим спрайт на экран
		window.display();//показываем спрайт
	}

	return 0;
}