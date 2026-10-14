public class Camion extends Vehiculo {
    private double capacidadToneladas;

    Camion(String patente, String marca, double costoBaseKm, double capacidadToneladas) {
        super(patente, marca, costoBaseKm);
        this.capacidadToneladas = capacidadToneladas;
    }

    @Override
    public double calcularCostoViaje(double distanciaKm) {
        return super.calcularCostoViaje(distanciaKm) * (1 + capacidadToneladas * 0.05);
    }

    @Override
    public double calcularCostoViaje(double distanciaKm, double peajes) {
        return super.calcularCostoViaje(distanciaKm, peajes) * (1 + capacidadToneladas * 0.05);
    }

    @Override 
    public void mostrarFicha() {
        super.mostrarFicha();
        System.out.println(" | Toneladas: " + capacidadToneladas);
    }
}