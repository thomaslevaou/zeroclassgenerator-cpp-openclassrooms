# TP du ZeroClassGenerator du cours en ligne OpenClassrooms

TP du "ZeroClassGenerator", réalisé dans le cadre de la formation en C++ proposée par le
site OpenClassrooms, à l'adresse suivante : https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1900961-tp-zeroclassgenerator


Ce TP consiste à réaliser une interface graphique, à l'aide du framework Qt, permettant
de générer le code d'une classe via un formulaire.
Après avoir renseigné le nom de la classe, son éventuelle classe mère, le contenu
de son éventuel commentaire et quelques options (protection contre les inclusions multiples,
présence ou non d'un constructeur par défaut ou d'un destructeur), l'interface retourne
dans une nouvelle fenêtre le code C++ à fournir pour obtenir une classe correspondant
aux critères renseignés dans le formulaire.


Après avoir cloné ce projet, le programme peut être exécuté en entrant les commandes suivantes
à sa racine, dans une fenêtre de commande Linux (le compilateur g++, Qt et l'éditeur de texte Vim
doivent préalablement être installés):
```
qmake -project
sudo vim ${PWD##*/}.pro
```
Puis dans le fichier ouvert par Vim, ajouter la ligne `QT += gui widgets`, puis quitter
le fichier Vim (Echap puis :wq) pour entrer les commandes suivantes dans la fenêtre de commande Linux :
```
qmake ${PWD##*/}.pro
make
./${PWD##*/}
```
