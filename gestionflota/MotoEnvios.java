public class MotoEnvios extends Vehiculo {
    //Aplicar 15% de descuento respecto a la tarifa base

    public MotoEnvios(String patente, String marca, double costoBaseKm) {
        super(patente, marca, costoBaseKm);
    }

    @Override
    public double calcularCostoViaje(double distanciaKm) {
        return super.calcularCostoViaje(distanciaKm) * 0.85;
    }

    @Override
    public void mostrarFicha() {
        super.mostrarFicha();
        System.out.println(" | Mensajería liviana");
    }
}