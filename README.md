# SpaceInvaders
Projet Zinzins de l'Espace

Réalisés par : 
Alexandre DURY
Grégory SALLE
Imrane GREINCH 
Valentin SIBELLE

Ce projet avait pour but de créer un jeu au choix par groupe de 3 ou 4 personnes.
Nous avons donc choisi de faire un jeu type Space Invaders appelé "Zinzins de l'Espace".

Compilation et exécution :

compilation : make (utilise le makefile)

exécution : ./bin/Jeu : exécute le mainSDL. 
            ./bin/JeuTXT : exécute le mainTXT.
            ./bin/TestRegression : exécute le mainRegression.

=> Dossier src : Ce dossier contient tous les fichiers nécessaires au bon fonctionnement du jeu
(sans compter le Makefile). Les extensions des fichiers sont en .h (pour headers qui permettent de 
définir les prototypes des fonctions) et .cpp (pour C++ qui permettent quant à eux de définir
les fonctions pour le jeu. Chaque fichier .cpp et .h du même nom sont associés. Certains fichiers
ne nécessitent par ailleurs pas de fichier .h associé

Voici la liste exhaustive des fichiers présents dans ce dossier src dont nous allons expliquer
l'utilité pour chacun brièvement :

- Bonus : Ces fichiers permettent la gestion des bonus en jeu, il faut que les bonus tombent
aléatoirement des ennemis éliminés avec un pourcentage de chance d'en avoir également.

- Ennemie : Ces fichiers permettent la gestion des ennemis avec notamment leurs déplacements 
ainsi que les tirs qu'ils envoient sur votre vaisseau.


- Image : Ces fichiers Contiennent les fonctions basiques de la SDL.

- ImageTXT : Différentes fonctions nécessaires pour l'affichage du jeu en TXT.

- Jeu : Ces fichiers gèrent le jeu global, c'est à dire le déroulement de la partie, que chaque
niveau s'enchaîne lorsque l'on les termine, la gestion du score, le positionnement des ennemis...

- Missile : Ces fichiers permettent la gestion des missiles, c'est à dire les collisions entre
eux-mêmes et tout élement du terrain (vaisseau, ennemis, mur...), mais également le fait qu'il
soit nécessaire d'appuyer sur une touche pour les déclencher (automatique et aléatoire pour les 
missiles ennemis).

- Niveau : Ces fichiers permettent la création des niveaux en plaçant les ennemis avec une 
disposition souhaitée au préalable par l'équipe. Le placement des ennemis dans le terrain est
implémenté dans un fichier .txt. Les procédures du fichier Niveau.cpp permettent donc d'aller 
chercher directement dans le fichier .txt au lieu de mettre directement les niveaux directement
dans le code en dur.

- SDL_Basique : Différentes fonctions nécessaires pour l'affichage du jeu en SDL.

- SpaceShip : Ces fichiers permettent la gestion du vaisseau allié que vous controlerez pendant
une partie. Cela comprend son placement et son déplacement, le nombre de missiles dont ils disposent, le nombre de
vies ainsi que la gestion des tirs.

- Terrain : Ces fichiers permettent la construction du terrain, ils vérifient également si la 
position des alliés ou des ennemis sont correctes.

- mainRegression : Effectue des tests de regression de chaque classe. Le programme s'arrete si les test de régression ne fonctionnent pas.

- mainSDL : Affichage du jeu en SDL

- mainTXT : Affichage du jeu en TXT

- winTXT : Bibliothèque d'affichage en TXT



=> Dossier doc : Ce dossier contient la partie de documentation du projet, avec tout ce qui
est lié à Doxygen notamment. Ce dernier permet de générer une documentation complète du projet 
dans une page html où toutes les classes et les fonctions sont rassemblées et expliquées. 
Il y a aussi le diagramme de gantt et le diagramme de classes.



=> Dossier data : Ce dossier contient toutes les images liées au projet tel que le
fond d'écran du jeu, les ennemis, les bonus etc. 
Il contient aussi la police d'écriture, et aussi les différents niveaux en .txt

=> Fichier Makefile : Partie all -> Créer les éxecutables finaux.
            : Partie obj -> permet de compiler tous les fichiers .h et .cpp contenant le code 
                    source pour ensuite vérifier le bon fonctionnement du programme.
            : Partie bin -> permet de créer un éxecutablep.
            : Partie clean -> permet de réinitialiser le contenu du Makefile à zéro.

=> Fichier Makefile : Partie all -> Appel des fonctions de bin
            : Partie obj -> permet de compiler tous les fichiers .h et .cpp contenant le code 
                            source et de créer un fichier .o .
            : Partie bin -> permet d'obtenir tous les fichiers exécutables.
            : Partie clean -> permet de réinitialiser le contenu du dossier obj/ à zéro.
	    : Partie veryclean -> permet de réinitialiser le contenu du dossier obj/ et /bin à zéro.



