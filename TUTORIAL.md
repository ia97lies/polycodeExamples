General Tutorial
================
# Introduction
All my examples are done under Linux/Ubuntu and in Lua.
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

# Run Examples
## With IDE
All examples can be load into the IDE. In Polycode you finde the IDE under
```
cd ~/workspace/Polycode/IDE/Build/Linux/Build
```
and run it with 
```
./Polycode
```
It wont work outside this Build directory and currently I did not manage to have a selfcontained Installation so I could start Polycode from anywhere.

## With Player
Under 
```
cd ~/workspace/Polycode/IDE/Build/Linux/Build/Standalone/Player
```
```
./PolycodePlayer
```
You have to specify the project xml

```
./PolycodePlayer ~/workspace/polycodeExamples/<path-to-project>/<projectName>.polyproject
```
If you start it you get an error, because currently Polycode Player do not insert properly the / before Scripts/Main.lua, so you have to insert this in the &lt;projectName&gt;.polyproject where the path to the main script is specified.
