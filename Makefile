CC=g++
CFLAGS=-Wextra -Wall -std=c++14
sfmlso=-lsfml-graphics -lsfml-window -lsfml-system
OBJS=main.o scene.o scenemanager.o mainmenu.o highscores.o gamescene.o board.o logic.o\
		 snake.o texturemanager.o savemanager.o complexTypes.o window.o inputwindow.o
OBJDIR=obj

ifdef ComSpec
appname=snake.exe my.res
removeObj=del /Q obj\*
mkobjdir=@if not exist obj\\ mkdir obj\\
else
appname=snake.out
removeObj=rm ./obj/*
mkobjdir=mkdir -p obj/
endif 

OBJ = $(addprefix $(OBJDIR)/, $(OBJS))

.PHONY : clean prepare

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

$(OBJDIR)/savemanager.o: SaveManager/SaveManager.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/complexTypes.o: utility/complexTypes.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/inputwindow.o: Window/Input/InputWindow.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)/window.o: Window/Window.cc
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	$(removeObj)

prepare:
	$(mkobjdir)
