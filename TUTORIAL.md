General Tutorial
================
# Introduction
All my examples are done under Linux/Ubuntu.
I personaly create a workspace in my home and place all my projects under this directory.

# First Steps
So first make sure you have installed
* cmake
* Lua
* Freetype
* zlib
* libpng
* PhysicsFS
* Ogg Vorbis
* OpenAL
* SDL
* Box2D
* Bullet Physics
* Assimp

Try to build polycode, there is a lot of help in the net if you run into throubles
```
cd ~/workspace
git clone https://github.com/ivansafrin/Polycode.git
cd Polycode
./BuildLinux.sh
```

In the end you have a ready to use polycode IDE or Player.
Due some errors currently not fixed in the IDE text editor I use vim as editor and the IDE as the runner.
But as well it works using the Player, but then the project xml must be adjusted as there seems to be another bug in Polycode Player not properly insert / in building up the path to the Main.lua (or what ever name you specified for the main lua file).

