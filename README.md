# ✈️ Cinqo Airlines - Flight Management System

A flight management system built with **C** for the core engine and **Java** for the user interface. This application allows users to search for direct flights, find connecting flights, generate tickets, and track flight history.

---

## 📋 Features

- **List All Flights** - View all available flights from the database
- **Direct Flight Search** - Find non-stop flights between two cities
- **Connecting Flights** - Find routes with one layover when no direct flight is available
- **Ticket Generation** - Generate a printable ticket for a selected flight
- **Flight History** - Record and export your booked flights to CSV format

---

## 🛠️ Technical Stack

| Component | Technology |
|-----------|------------|
| Core Engine | C |
| User Interface | Java |
| Data Storage | CSV Files |
| Build System | Code::Blocks / GCC |

---

## 📁 Project Structure

```
Cinqo_Airlanes/
├── main.c              # C entry point (CLI application)
├── vol.c               # Flight logic implementation
├── vol.h               # Flight data structures and function declarations
├── data.csv            # Flight database
├── volhistorique.txt   # Flight booking history (text format)
├── volhistorique.csv   # Exported booking history (CSV format)
├── app/
│   └── Main.java       # Java interactive menu interface
├── service/
│   └── VolService.java # Java service layer calling C executable
├── bin/                # Compiled output
└── obj/                # Object files
```

---

## 📦 Installation

### Prerequisites

- **GCC** (C Compiler)
- **Java JDK 8+**
- **Code::Blocks** (optional, for IDE support)

### Build the C Application

```bash
# Using GCC
gcc -o app.exe main.c vol.c

# Or open File.cbp in Code::Blocks and build
```

### Compile the Java Interface

```bash
javac -d . app/Main.java service/VolService.java
```

---

## 🚀 Usage

### Command Line Interface (C)

```bash
# List all available flights
./app.exe LIST

# Search for direct flights from Paris to Nador
./app.exe DIRECT Paris Nador

# Search for connecting flights from Paris to Nador
./app.exe CORRESP Paris Nador

# Generate a ticket for a direct flight
./app.exe TICKET Paris Nador

# Record a direct flight to history
./app.exe WRITE_DIRECT Paris Nador

# Record a connecting flight to history
./app.exe WRITE_CORRESP Paris Nador
```

### Interactive Java Interface

```bash
java app.Main
```

This launches an interactive menu:

```
*** Cinqo Airlines ***
1. Afficher tous les vols    (Display all flights)
2. Vol direct                 (Direct flight search)
3. Vol correspondance         (Connecting flight search)
4. Exporter historique        (Export history to CSV)
5. Quitter                    (Exit)
Choix :
```

---

## 📄 Data Format

### Flight Database (`data.csv`)

| Field | Description |
|-------|-------------|
| id | Flight ID (e.g., AF1001) |
| pays_depart | Departure country |
| ville_depart | Departure city |
| pays_arrivee | Arrival country |
| ville_arrivee | Arrival city |
| heure_depart | Departure time (HH:MM) |
| heure_arrivee | Arrival time (HH:MM) |

**Example:**
```csv
id,pays_depart,ville_depart,pays_arrivee,ville_arrivee,heure_depart,heure_arrivee
AF1001,France,Paris,Maroc,Nador,09:00,11:15
AF1002,France,Paris,Espagne,Barcelona,08:00,10:00
```

### Flight History Export (`volhistorique.csv`)

```csv
id,depart,pays_depart,arrivee,pays_arrivee,heure_depart,heure_arrivee,prise_le
AF1002,Paris,France,Barcelona,Espagne,08:00,10:00,2025-12-04 à 15:21:41
```

---

## 🔍 Flight Validation Rules

The system validates flights and filters out invalid entries:

- All city and country fields must be filled
- Departure and arrival cities cannot be the same
- Fields cannot contain placeholder characters (e.g., `?`)
- Time format must be valid

---

## ✈️ Supported Routes

The system includes flights connecting:
- **France** (Paris, Lyon, Marseille, Nice, Toulouse, Bordeaux, Lille, Nantes, Strasbourg)
- **Spain** (Barcelona, Madrid, Valencia, Seville)
- **Morocco** (Nador, Casablanca, Rabat, Marrakech, Agadir, Tanger, Fes)
- **International** (Rome, Berlin, New York, Tokyo)

---

## 📝 Generated Ticket Example

When using the `TICKET` command, a `billet.txt` file is created:

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

## 🤝 Contributing

Feel free to contribute to this project by submitting pull requests or opening issues.

---

## 📜 License

This project is open source and available for educational purposes.

---

**Cinqo Airlines** - *Your journey begins here* ✈️
