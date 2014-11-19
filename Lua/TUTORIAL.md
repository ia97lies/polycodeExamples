General Tutorial
================
# Introduction
All Lua examples are done under Linux/Ubuntu.
I personaly create a workspace in my home and place all my projects under this directory.

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
