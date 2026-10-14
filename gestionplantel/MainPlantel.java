public class MainPlantel{

    public static void main(String[] args) {
        
        Plantel plantel1 = new Plantel(3);
    
        Jugador jugador1 = new Jugador("QQ", 3, 2);
        Jugador jugador2 = new Jugador("GG", 7, 4);
        Jugador jugador3 = new Jugador("MM", 3, 5);
        Jugador jugador4 = new Jugador("DD", 1, 0);

        plantel1.agregar(jugador1);
        plantel1.agregar(jugador2);
        plantel1.agregar(jugador3);
        plantel1.agregar(jugador4);

        Jugador jugador_buscado = plantel1.buscarPorDorsal(3);
        if (jugador_buscado != null){
            System.out.println("Se encontró el jugador con dorsal 3: " + jugador_buscado.getNombre());
        }
        else {
            System.out.println("No se encontró el jugador con dorsal 3");
        }

        Jugador jugador_buscado_fallido = plantel1.buscarPorDorsal(99);
        if (jugador_buscado_fallido != null){
            System.out.println("Se encontró el jugador con dorsal 99: " + jugador_buscado_fallido.getNombre());
        }
        else {
            System.out.println("No se encontró el jugador con dorsal 99");
        }

        plantel1.ordenarPorGoles();

        for (int i = 0; i < plantel1.getCantidad(); i++){
            System.out.println(plantel1.getJugadores()[i].getNombre() + " tiene " + plantel1.getJugadores()[i].getGoles() + " goles");
        }

        plantel1.eliminar(3);

        System.out.println("Despues de eliminar el jugador con dorsal 3");
        for (int i = 0; i < plantel1.getCantidad(); i++){
            System.out.println(plantel1.getJugadores()[i].getNombre() + " tiene " + plantel1.getJugadores()[i].getGoles() + " goles");
        }
    }
        
    }