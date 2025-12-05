package service;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class VolService {


    //.\main.exe LIST
    public void afficherTousLesVols() {
        String output = lancerCommande("LIST");
        System.out.println(output);
    }

    //.\main.exe DIRECT depart arrivee
    public boolean volDirect(String depart, String arrivee) {
        String output = lancerCommande("DIRECT", depart, arrivee);
        System.out.println(output);
        return output.contains("Vol direct trouve");
    
    }



    //.\main.exe CORRESP depart arrivee
    public boolean volCorrespondance(String depart, String arrivee) {
        String output = lancerCommande("CORRESP", depart, arrivee);
        System.out.println(output);
        return output.contains("Vol avec correspondance");
    }


    //.\main.exe WRITE_DIRECT depart arrivee
    public void writeDirect(String depart, String arrivee) {
        lancerCommande("WRITE_DIRECT", depart, arrivee);
    }


    //.\main.exe WRITE_CORRESP depart arrivee
    public void writeCorrespondance(String depart, String arrivee) {
        lancerCommande("WRITE_CORRESP", depart, arrivee);
    }


    //export txt to csv
    public void exportHistorique() {
         try {
            
            BufferedReader reader = new BufferedReader(new java.io.FileReader("volhistorique.txt"));
            java.io.PrintWriter writer = new java.io.PrintWriter("volhistorique.csv");
            //tete csv
            writer.println("id,depart,pays_depart,arrivee,pays_arrivee,heure_depart,heure_arrivee,prise_le");
        
            String line;
            String id="", depart="", paysDepart="", arrivee="", paysArrivee="", hDepart="", hArrivee="", priseLe="";
        
            while ((line = reader.readLine()) != null) {

                if (line.startsWith("Vol :")) {
                    id = line.substring(6).trim();
                }
                    
                if (line.startsWith("Trajet :")) {
                    
                    String trajet = line.substring(8).trim();
                    String[] parts = trajet.split("->");

                    String p1 = parts[0].trim(); 
                    String p2 = parts[1].trim(); 

                    depart = p1.substring(0, p1.indexOf("(")).trim();
                    paysDepart = p1.substring(p1.indexOf("(")+1, p1.indexOf(")"));

                    arrivee = p2.substring(0, p2.indexOf("(")).trim();
                    paysArrivee = p2.substring(p2.indexOf("(")+1, p2.indexOf(")"));
                }

                if (line.startsWith("Heure depart")) {
                    hDepart = line.substring(line.indexOf(":") + 1).trim();
                }

                if (line.startsWith("Heure arrivee")) {
                    hArrivee = line.substring(line.indexOf(":") + 1).trim();
                }

                if (line.startsWith("Pris le")) {
                    priseLe = line.substring(9).trim();

                    // Ligne CSV
                    writer.printf("%s,%s,%s,%s,%s,%s,%s,%s\n",
                            id, depart, paysDepart, arrivee, paysArrivee, hDepart, hArrivee, priseLe);
                }
            }

            reader.close();
            writer.close();
            System.out.println("Export volhistorique.csv DONE!");

        } catch (Exception e) {
            System.out.println("Erreur export CSV : " + e.getMessage());
        }
    }


    
    // lance commande externe
        private String lancerCommande(String... args) {
        StringBuilder output = new StringBuilder();
        try {
            String[] cmd = new String[args.length + 1];
            cmd[0] = "C:/Users/PC/Documents/S5/Algo-java/C/File/app.exe";

            for (int i = 0; i < args.length; i++) {
                cmd[i + 1] = args[i];
            }

            ProcessBuilder pb = new ProcessBuilder(cmd);
            Process p = pb.start();

            p.waitFor();
            // Lire STDOUT
            BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
            String line;
            while ((line = r.readLine()) != null) {
                output.append(line).append("\n");
            }

            // 🔥 Lire STDERR aussi !
            BufferedReader err = new BufferedReader(new InputStreamReader(p.getErrorStream()));
            String errLine;
            while ((errLine = err.readLine()) != null) {
                output.append(errLine).append("\n");
            }

            return output.toString();

        } catch (Exception e) {
            return "Erreur : " + e.getMessage();
        }
    }
}
