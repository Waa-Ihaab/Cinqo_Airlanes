package app;

import service.VolService;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        VolService service = new VolService();
       
        Scanner sc = new Scanner(System.in);

       
        while (true) {
            // Display menu options
            System.out.println("\n*** Cinqo Airlines ***");
            System.out.println("1. Afficher tous les vols");         
            System.out.println("2. Vol direct");                      
            System.out.println("3. Vol correspondance");              
            System.out.println("4. Exporter historique");              
            System.out.println("5. Quitter");                          
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

              
                boolean trouve = service.volDirect(d, a);

                if (trouve) {
                    System.out.print("Avez-vous pris ce vol ? (O/N) : ");
                    String rep = sc.nextLine();

                    
                    if (rep.equalsIgnoreCase("O") || rep.equalsIgnoreCase("Y")) {
                        service.writeDirect(d, a);
                        System.out.println("Vol enregistré dans volhistorique.txt !");
                    }
                }
            }

          
            else if (choix == 3) {
                System.out.print("Depart : ");
                String d = sc.nextLine();    
                System.out.print("Arrivee : ");
                String a = sc.nextLine();      

                boolean trouve = service.volCorrespondance(d, a);

                
                if (trouve) {
                    System.out.print("Avez-vous pris cette correspondance ? (O/N) : ");
                    String rep = sc.nextLine();

                 
                    if (rep.equalsIgnoreCase("O") || rep.equalsIgnoreCase("Y")) {
                        service.writeCorrespondance(d, a);
                        System.out.println("Correspondance enregistrée !");
                    }
                }
            }

            else if (choix == 4) {
                service.exportHistorique();
            }
            
            else if (choix == 5) {
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
