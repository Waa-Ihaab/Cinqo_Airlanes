package app;

import service.VolService;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        VolService service = new VolService();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n*** Cinqo Airlines ***");
            System.out.println("1. Afficher tous les vols");
            System.out.println("2. Vol direct");
            System.out.println("3. Vol correspondance");
            System.out.println("4. Quitter");
            System.out.print("Choix : ");

            
            int choix = sc.nextInt();
            sc.nextLine();

            if (choix == 1) {
                service.afficherTousLesVols();
            }

            else if (choix == 2) {
                System.out.print("Depart : ");
                String d = sc.nextLine();
                System.out.print("Arrivee : ");
                String a = sc.nextLine();
                service.volDirect(d, a);
            }

            else if (choix == 3) {
                System.out.print("Depart : ");
                String d = sc.nextLine();
                System.out.print("Arrivee : ");
                String a = sc.nextLine();
                service.volCorrespondance(d, a);
            }

            else if (choix == 4) {
                System.out.println("Adios !");
                break;
            }
            
            else {
                System.out.println("Erreur, merci de ressaisir.");
            }
        }

        sc.close();
    }
}
