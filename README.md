NovAlympique
============

Un Programme Blagueur (un faux virus un peu flippant)

Pour compiler en mode Debug : 

g++ -c -DSFML_STATIC cheminIncludeSFML main.cpp Screen.cpp capture.cpp lodepng.cpp

Linker


-s sfml-graphics-s sfml-audio-s sfml-window-s sfml-network-s sfml-system-s cheminLibSFML


Sinon je vous conseille d'aller voir la documentation SFML

http://www.sfml-dev.org/tutorials/2.1/index-fr.php
