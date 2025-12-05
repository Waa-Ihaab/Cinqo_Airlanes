# Cinqo_Airlanes

[![UIcon Java](https://img.shields.io/badge/UIcon-Java-blue.svg)](https://github.com/)
[![UIcon C](https://img.shields.io/badge/UIcon-C-lightgrey.svg)](https://github.com/)
[![Airlanes](https://img.shields.io/badge/Airlanes-Module-brightgreen.svg)](https://github.com/)

Description
-----------
Cinqo_Airlanes est un projet qui regroupe des composants d'interface utilisateur (UIcon) implémentés en Java et en C ainsi qu'un module "Airlanes" pour la gestion de fonctionnalités liées aux lignes aériennes. Ce dépôt sert de point central pour le code source, la documentation et les exemples d'intégration.

Principales fonctionnalités
---------------------------
- UIcon (Java) : composants UI réutilisables pour applications Java (Swing / JavaFX selon implémentation).
- UIcon (C) : bibliothèques légères pour interfaces graphiques embarquées ou consoles.
- Airlanes : logique métier et utilitaires pour la gestion des lignes aériennes (itinéraires, vols, réservations, etc.).
- Exemples d'intégration et scripts de build pour compiler/run les composants.

Structure du dépôt (suggestion)
-------------------------------
- /uicon-java/      -> code source Java (packages, exemples, README spécifique)
- /uicon-c/         -> code source C (headers, sources, Makefile/CMake)
- /airlanes/        -> module Airlanes (API, services, exemples)
- /docs/            -> documentation, diagrammes et spécifications
- /examples/        -> projets d'exemple montrant l'intégration des composants
- README.md         -> ce fichier

Installation et construction
---------------------------

Prérequis généraux
- Git
- JDK 11+ si vous utilisez la version Java
- gcc/clang et make ou CMake pour la partie C
- Outils de build optionnels : Maven/Gradle (Java), CMake (C)

UIcon (Java)
- Aller dans le dossier uicon-java :
  - Si le projet utilise Maven :
    - mvn clean install
  - Si le projet utilise Gradle :
    - ./gradlew build
- Exécuter les exemples (si fournis) avec : java -jar target/nom-du-jar.jar ou via Gradle run

UIcon (C)
- Aller dans le dossier uicon-c :
  - Avec Makefile :
    - make
    - sudo make install (optionnel)
  - Avec CMake :
    - mkdir build && cd build
    - cmake ..
    - make
- Les bibliothèques compilées seront dans build/ ou lib/ selon configuration.

Airlanes
- Suivre le README spécifique dans /airlanes pour les dépendances et la compilation.
- Éventuellement intégrer les bibliothèques UIcon (Java/C) en liant ou en important les jars.

Utilisation (exemples)
----------------------
- Consulter /examples/ pour des démonstrations d'intégration.
- Exemple rapide (Java) :
  - Importer uicon-java comme dépendance dans votre projet (local maven repo ou jar).
  - Initialiser et utiliser les composants UI fournis.
- Exemple rapide (C) :
  - Inclure les headers depuis uicon-c/include et lier la lib uicon-c lors de la compilation.

Tests
-----
- Exécuter les tests unitaires Java : mvn test ou ./gradlew test
- Pour C, exécuter les tests fournis dans /uicon-c/tests ou via le framework choisi (CTest, Unity, etc.)

Contribuer
----------
Les contributions sont bienvenues. Processus recommandé :
1. Fork du dépôt.
2. Créer une branche feature/bugfix descriptive.
3. Soumettre une Pull Request avec description claire et tests si possible.
4. Respecter le format de commit et les conventions de code du projet.

Guidelines spécifiques :
- Documenter toute nouvelle API dans /docs/.
- Ajouter des exemples dans /examples/ pour montrer l'usage.
- Pour changements majeurs, ouvrir une issue décrivant le besoin avant d'implémenter.

Roadmap (idées)
---------------
- Compléter les implémentations UIcon pour JavaFX et Qt/Cross-platform.
- Ajouter support d'internationalisation dans Airlanes.
- Intégration continue (GitHub Actions) pour build/test automatique.
- Packager des artefacts (jars et libs) pour distribution.

Licence
-------
Indiquer ici la licence du projet (ex : MIT, Apache-2.0). Si non défini, ajouter un fichier LICENSE à la racine.

Contact / Auteurs
-----------------
- Mainteneur principal : Waa-Ihaab
- Pour les contributions ou questions, ouvrir une issue sur le dépôt.

Remarques finales
-----------------
Ce README est une base. Si tu veux, je peux :
- Adapter les instructions de build précisément au contenu actuel du dépôt (en inspectant les dossiers uicon-java, uicon-c et airlanes).
- Générer des badges dynamiques (build, coverage) et un template de CONTRIBUTING.md.
- Créer et pousser directement ce README.md dans le dépôt si tu me le demandes.
