class Jugador {

    private static final String NOMBRE_DEFECTO = "Sin nombre";
    private static final int DORSAL_DEFECTO = 99;
    private static final int GOLES_DEFECTO = 0;

    private final String nombre;
    private final int dorsal;
    private int goles;

    public Jugador(String nombre, int dorsal, int goles){
        
        if (nombre == null || nombre.isBlank()){
            System.out.println("Nombre invalido. Se asignará: " + NOMBRE_DEFECTO);
            nombre = NOMBRE_DEFECTO;
        }

        if (dorsal <= 0){
            System.out.println("Numero de dorsal invalido (<= 0). Se asignará: " + DORSAL_DEFECTO);
            dorsal = DORSAL_DEFECTO;
        }

        if (goles < 0){
            System.out.println("Numero de goles invalido (< 0). Se asignará: " + GOLES_DEFECTO);
            goles = GOLES_DEFECTO;
        }

        this.nombre = nombre;
        this.dorsal = dorsal;
        this.goles = goles;
    }

    public String getNombre(){
        return nombre;
    }

    public int getDorsal(){
        return dorsal;
    }

    public int getGoles(){
        return goles;
    }

    public void anotarGoles(int cantidad){
        if (cantidad > 0){
            goles += cantidad;
            System.out.println("Al jugador " + nombre + " se le sumó " + cantidad + " de goles");
            System.out.println(nombre + "tiene: " + goles + " goles");
        }
        else {
            System.out.println("La cantidad de goles a asignar es invalida");
            System.out.println(nombre + "tiene: " + goles + " goles");
        }
    }

    @Override public String toString(){
        return "Jugador: " + nombre + ", Dorsal: " + dorsal + ", Goles: " + goles;
    }
    
}