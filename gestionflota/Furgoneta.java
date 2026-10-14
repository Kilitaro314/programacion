package gestionflota;

public class Furgoneta extends Vehiculo {
    private boolean tieneRefrigeracion;

    public Furgoneta(String patente, String marca, double costoBaseKm, boolean tieneRefrigeracion) {
        super(patente, marca, costoBaseKm);
        this.tieneRefrigeracion = tieneRefrigeracion;
    }

    @Override 
    public double calcularCostoViaje(double distanciaKm){
        if (tieneRefrigeracion){
            return super.calcularCostoViaje(distanciaKm) + 5000;
        }
        return super.calcularCostoViaje(distanciaKm);
    }

    @Override
    public double calcularCostoViaje(double distanciaKm, double peajes){
        if (tieneRefrigeracion){
            return super.calcularCostoViaje(distanciaKm, peajes) + 5000;
        }
        return super.calcularCostoViaje(distanciaKm, peajes);
    }

    @Override
    public void mostrarFicha() {
        super.mostrarFicha();
        System.out.println(" | Refrigerado: " + (tieneRefrigeracion ? "Sí" : "No"));
    }
}