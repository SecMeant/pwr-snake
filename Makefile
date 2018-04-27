CC=g++
CFLAGS=-Wextra -Wall -std=c++14
sfmlso=-lsfml-graphics -lsfml-window -lsfml-system
OBJS=main.o scene.o scenemanager.o mainmenu.o highscores.o gamescene.o board.o logic.o\
		 snake.o texturemanager.o
OBJDIR=obj

ifdef ComSpec
appname=snake.exe
removeObj=del /Q obj\*
else
appname=snake.out
removeObj=rm ./obj/*
endif 

OBJ = $(addprefix $(OBJDIR)/, $(OBJS))

.PHONY : clean

all linux: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(sfmlso) -o $(appname)

windows: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(sfmlso) -o $(appname)

$(OBJDIR)/main.o: main.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/scene.o: Scene/Scene.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/scenemanager.o: SceneManager/SceneManager.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/mainmenu.o: Scene/MainMenu/MainMenu.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/highscores.o: Scene/Highscores/Highscores.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/gamescene.o: Scene/GameScene/GameScene.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/board.o: Scene/GameScene/Board/Board.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/logic.o: Scene/GameScene/Logic/Logic.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/snake.o: Scene/GameScene/Snake/Snake.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/texturemanager.o: TextureManager/TextureManager.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	$(removeObj)
