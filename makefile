game: main.cpp  MainMenu.cpp
	g++ main.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system MainMenu.cpp Boss.cpp Enemy.cpp Bullet.cpp EnemyBullet.cpp Entity.cpp MainGame.cpp Player.cpp