# Game with fake 3D
Game is based on SFML library and map is generated by file **mapa_do_wczytania.txt**.
```
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X   X   h  XX   h   X       XX   h     X
X P X      X v   h  XXv  H    v    h   X
X h   VX  XX    X    X  XX  H  XXXv X  X
X         X H  XX  H   h XXX           X
XXXXX  h  XX  XX  VX v      h   v  X  XX
X   XXXX   h       X     v    XX    h  X
X  v H   v   v  H    h XX  VXXX  h     X
X h    H  XX   X  V  XXX      X  v XX  X
X  XXX    X  v X v     XX h    h       X
X      h XX   XX  X V XX   X V  v  H   X
X  V    XX h  X   XX    v     X   XX V X
Xv   XXXX       h     H  X v  H  X h   X
X    h  XX  H      H  XXXXX     h     vX
XXv      XXV XX  V  XXX h   vXX   XXX  X
XX  XXXV  X        v  X       XX v     X
X        vXv  h  X    XX  VX  X     h  X
X  h  v         XXV    H   Xv  H Xv M VX
XXX      H    XXX   H   h  X     X  H  X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
```
in which:
- *X* is block of wall,
- *h* is ghost which roams on horizontal line for one block,
- *H* is ghost which roams on horizontal line for two blocks,
- *v* is ghost which roams on vertical line for one block,
- *V* is ghost which roams on vertical line for two blocks,
- *P* is player,
- *M* is campfire, that is purpose of game.

Generated map from file:
![](https://i.ibb.co/7NgBLFF/mapa.png)

### Goal of the game
Kill all enemies and get to the campfire. The counter of bullets is limited, so take care of your ammunition. Remember one bullet can kill more than one ghost.

### Gameplay
**Click in the image**
[![Little red riding hood](https://i.ibb.co/mh6s3YV/mapa.png)](https://www.youtube.com/watch?v=Zq48caiot7g&ab_channel=KacperDominiak "Little red riding hood - Click to Watch!")

### Important
This is my first own project, that was created for learing basics of C++. So please forgive me for the general mess in the code and polish names of varaibles.

