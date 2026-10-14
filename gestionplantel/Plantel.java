
import java.util.Arrays;

class Plantel {

    private static final int CAPACIDAD_INICIAL_DEFECTO = 5;

    private Jugador[] jugadores;
    private int cantidad;

    public Plantel(int capacidadInicial){
        
        if (capacidadInicial <= 0){
            capacidadInicial = CAPACIDAD_INICIAL_DEFECTO;
        }

        jugadores = new Jugador[capacidadInicial];
        cantidad = 0;
    }

    public int getCantidad(){
        return cantidad;
    }

    public int getCapacidad(){
        return jugadores.length;
    }

    public boolean agregar(Jugador j){
        if (j != null){

            if (cantidad == jugadores.length){
                jugadores = Arrays.copyOf(jugadores, jugadores.length * 2);
                System.out.println("La capacidad del plantel se ha duplicado a: " + jugadores.length);
            }

            jugadores[cantidad] = j;
            cantidad++;
            return true;
        }
        else {
            
            System.out.println("No se puede agregar un jugador nulo");

        }
        return false;
    }

    public Jugador buscarPorDorsal(int dorsal){
        
        for (int i = 0; i < cantidad; i++){
            if (jugadores[i].getDorsal() == dorsal){
                return jugadores[i];
            }
        }

        return null;
    }

    public Jugador buscarPorNombre(String nombre){

        for (int i = 0; i < cantidad; i++){
            if (jugadores[i].getNombre().equals(nombre)){
                return jugadores[i];
            }
        }

        return null;
    }

    public boolean eliminar(int dorsal) {
        int posicionEncontrada = -1;

        // 1. BUSCAR: Recorremos el arreglo para encontrar la posición del jugador
        for (int i = 0; i < cantidad; i++) {
            if (jugadores[i].getDorsal() == dorsal) {
                posicionEncontrada = i; // Guardamos dónde está
                break;                  // Salimos del ciclo de inmediato
            }
        }

        // 2. VERIFICAR: Si no lo encontramos (sigue en -1), terminamos y devolvemos false
        if (posicionEncontrada == -1) {
            return false; 
        }

        // 3. MOVER: Desplazamos todos los elementos de la derecha un lugar hacia la izquierda
        for (int i = posicionEncontrada; i < cantidad - 1; i++) {
            jugadores[i] = jugadores[i + 1];
        }

        // 4. LIMPIAR: El último elemento queda duplicado tras el movimiento, lo borramos
        jugadores[cantidad - 1] = null; 
        cantidad--; // Ahora tenemos un jugador menos

        return true; // Borrado exitoso
    }


    public void ordenarPorGoles(){
        boolean swapped;

        for (int i = 0; i < cantidad; i++){
            swapped = false;

            for (int j = 0; j < cantidad - i - 1; j++){
                if (jugadores[j].getGoles() < jugadores[j + 1].getGoles()){
                    Jugador temp = jugadores[j];
                    jugadores[j] = jugadores[j + 1];
                    jugadores[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped){
                break;
            }
        }
    }

    public void listar(){

        for (int i = 0; i < cantidad; i++) {
            System.out.println(jugadores[i].getNombre());
        }
    }

    public Jugador[] getJugadores(){
        return Arrays.copyOf(jugadores, cantidad);
    }
}