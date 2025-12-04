package service;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class VolService {


    //.\main.exe LIST
    public void afficherTousLesVols() {
        lancerCommande("LIST");
    }
    //.\main.exe DIRECT depart arrivee
    public void volDirect(String depart, String arrivee) {
        lancerCommande("DIRECT", depart, arrivee);
    }
    //.\main.exe CORRESP depart arrivee
    public void volCorrespondance(String depart, String arrivee) {
        lancerCommande("CORRESP", depart, arrivee);
    }


    // lance commande externe
    private void lancerCommande(String... args) {
        try {
            String[] cmd = new String[args.length + 1]; 
            cmd[0] = "app.exe"; 

            for (int i = 0; i < args.length; i++) {
                cmd[i + 1] = args[i];
            }

            //lancement du programme externe
            ProcessBuilder pb = new ProcessBuilder(cmd); 
            Process p = pb.start(); 


            //lire  + affiche la sortie 
            BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream())); 
            String line;

            
            while ((line = r.readLine()) != null) {
                System.out.println(line);
            }

        } catch (Exception e) {
            System.out.println("Erreur : " + e.getMessage());
        }
    }
}
