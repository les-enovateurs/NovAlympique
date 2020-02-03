NovAlympique
============
<p align="center">
  <a href="https://www.buymeacoffee.com/enovateurs" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-violet.png" height="41px" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>
</p>

Un Programme Blagueur (un faux virus un peu flippant).

Le programme fonctionne avec la dernière version de la SFML 2.1.

Pour compiler en mode Debug : 

g++ -c -DSFML_STATIC cheminIncludeSFML main.cpp Screen.cpp capture.cpp lodepng.cpp Point.cpp

Linker

-s sfml-graphics-s sfml-audio-s sfml-window-s sfml-network-s sfml-system-s cheminLibSFML


Sinon je vous conseille d'aller voir la documentation SFML

http://www.sfml-dev.org/tutorials/2.1/index-fr.php
