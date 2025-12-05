# ✈️ Cinqo_Airlanes — Flight Management System

[![UIcon Java](https://img.shields.io/badge/UIcon-Java-blue?logo=java&logoColor=white)](https://github.com/Waa-Ihaab/Cinqo_Airlanes)
[![UIcon C](https://img.shields.io/badge/UIcon-C-lightgrey?logo=c&logoColor=white)](https://github.com/Waa-Ihaab/Cinqo_Airlanes)
[![Airlanes](https://img.shields.io/badge/Airlanes-Module-brightgreen)](https://github.com/Waa-Ihaab/Cinqo_Airlanes)
[![Licence](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

Cinqo_Airlanes est un système de gestion de vols hybride : le moteur métier est développé en C (application console/CLI) et l'interface utilisateur interactive est fournie en Java. Le système permet de lister les vols, rechercher des vols directs et correspondances, générer des billets et tenir un historique des réservations.

---

## 📋 Fonctionnalités
- Listage complet des vols disponibles (depuis data.csv)
- Recherche de vol direct entre deux villes
- Recherche de correspondance (une escale) si aucun vol direct n'existe
- Génération d'un billet imprimable (billet.txt)
- Enregistrement et export de l'historique des vols en CSV
- Validation basique des données (formats, champs requis)

---

## 🛠️ Stack technique
- Moteur core : C (main.c, vol.c, vol.h)
- Interface utilisateur : Java (app/Main.java, service/VolService.java)
- Stockage des données : fichiers CSV / TXT
- Build C : GCC (Code::Blocks compatible)
- Build Java : JDK 8+

---

## 📁 Structure du dépôt (version actuelle)
Cinqo_Airlanes/
├── main.c              # Entrée C (application CLI)  
├── vol.c               # Logique des vols  
├── vol.h               # Structures et prototypes  
├── data.csv            # Base de vols  
├── volhistorique.txt   # Historique des réservations (texte)  
├── volhistorique.csv   # Historique exporté (CSV)  
├── billet.txt          # Exemple / sortie billet généré  
├── app/  
│   └── Main.java       # Interface Java (menu interactif)  
├── service/  
│   └── VolService.java # Service Java qui appelle l'exécutable C  
├── bin/                # Executables (recommandé)  
└── obj/                # Fichiers objets (C)

> Remarque : adaptez les chemins de compilation ci‑dessous selon vos conventions (par ex. output dans `bin/`).

---

## 📦 Prérequis
- GCC (ou un équivalent compatible) pour compiler l'application C  
- JDK 8+ pour compiler/éxécuter l'interface Java  
- (Optionnel) Code::Blocks si vous préférez un IDE pour le projet C

---

## 🔧 Compilation & installation

### Compiler l'application C (ligne de commande)
Recommandé : placer l'exécutable dans `bin/`.
```bash
# Depuis la racine du dépôt
gcc -o bin/app.exe main.c vol.c
# ou sur Linux sans .exe
gcc -o bin/app main.c vol.c
```
Vous pouvez aussi ouvrir le projet Code::Blocks (.cbp) si fourni et construire depuis l'IDE.

### Compiler l'interface Java
```bash
# Créez un dossier de classes et compilez
mkdir -p bin/classes
javac -d bin/classes app/Main.java service/VolService.java
```
Pour exécuter depuis la racine :
```bash
java -cp bin/classes app.Main
```

---

## 🚀 Utilisation

### Interface CLI (exécutable C)
Exemples d'usage (assurez‑vous que `bin/app` ou `bin/app.exe` est exécutable) :
```bash
# Lister tous les vols
./bin/app LIST

# Rechercher un vol direct Paris -> Nador
./bin/app DIRECT Paris Nador

# Rechercher une correspondance Paris -> Nador (une escale)
./bin/app CORRESP Paris Nador

# Générer un billet pour un vol direct
./bin/app TICKET Paris Nador

# Enregistrer un vol direct dans l'historique
./bin/app WRITE_DIRECT Paris Nador

# Enregistrer une correspondance dans l'historique
./bin/app WRITE_CORRESP Paris Nador
```

### Interface interactive (Java)
Lancez le menu Java :
```bash
java -cp bin/classes app.Main
```
Le menu interactif fournit des options :
1. Afficher tous les vols  
2. Vol direct  
3. Vol correspondance  
4. Exporter historique  
5. Quitter

Le service Java (`service/VolService.java`) appelle l'exécutable C pour déléguer le traitement métier (pattern simple « UI -> service -> exécutable C »).

---

## 📄 Formats des données

### Fichier `data.csv` (base de vols)
Champs :
- id — identifiant du vol (ex : AF1001)  
- pays_depart — pays de départ  
- ville_depart — ville de départ  
- pays_arrivee — pays d'arrivée  
- ville_arrivee — ville d'arrivée  
- heure_depart — heure départ (HH:MM)  
- heure_arrivee — heure arrivée (HH:MM)

Exemple :
```csv
id,pays_depart,ville_depart,pays_arrivee,ville_arrivee,heure_depart,heure_arrivee
AF1001,France,Paris,Maroc,Nador,09:00,11:15
AF1002,France,Paris,Espagne,Barcelona,08:00,10:00
```

### Fichier d'historique exporté `volhistorique.csv`
Format :
```csv
id,depart,pays_depart,arrivee,pays_arrivee,heure_depart,heure_arrivee,prise_le
AF1002,Paris,France,Barcelona,Espagne,08:00,10:00,2025-12-04 15:21:41
```

### Billet généré (`billet.txt`)
Exemple de sortie :
```
*** Cinqo Airlines ***
Vol : AF1001
Trajet : Paris (France) -> Nador (Maroc)
Heure depart  : 09:00
Heure arrivee : 11:15
*** Cinqo Airlines ***
MERCI POUR VOTRE CONFIANCE
```

---

## 🔍 Règles de validation des vols
Le système filtre les entrées invalides selon :
- Tous les champs villes/pays doivent être renseignés  
- Ville de départ ≠ ville d'arrivée  
- Aucun caractère placeholder (« ? ») dans les champs obligatoires  
- Format d'heure valide (HH:MM)

---

## ✈️ Trajets supportés (exemples)
Le jeu de données couvre notamment :
- France : Paris, Lyon, Marseille, Nice, Toulouse, Bordeaux, Lille, Nantes, Strasbourg  
- Espagne : Barcelona, Madrid, Valencia, Seville  
- Maroc : Nador, Casablanca, Rabat, Marrakech, Agadir, Tanger, Fes  
- International : Rome, Berlin, New York, Tokyo

---

## ✅ Bonnes pratiques & recommandations
- Stocker `bin/app` dans `.gitignore` si vous ne souhaitez pas versionner les binaires.  
- Utiliser des sorties date/heure au format ISO pour l'historique (ex. 2025-12-04T15:21:41) si vous prévoyez des traitements automatisés.  
- Ajouter des tests unitaires pour la logique C (stratégie : fonctions pures testables) et des tests d'intégration pour l'interface Java.  
- Prévoir un workflow GitHub Actions pour compilation et tests automatiques.

---

## 🤝 Contribuer
Contribuer est le bienvenu :
1. Ouvrez une issue pour discuter des fonctionnalités majeures.  
2. Forkez, créez une branche descriptive (feature/... | fix/...) et soumettez une Pull Request.  
3. Ajoutez des tests et mettez à jour la documentation (`docs/`).

---

Cinqo_Airlanes — Votre voyage commence ici. ✈️
