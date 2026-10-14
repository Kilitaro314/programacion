public class MainFlota {
    public static void main(String[] args) {
        double totalOperativo = 0;

        Vehiculo[] flota = new Vehiculo[3];
        flota[0] = new Camion("AA123BB", "Scania", 500.0, 18.0);
        flota[1] = new Furgoneta("AF456CD", "Mercedes-Benz", 400.0, true);
        flota[2] = new MotoEnvios("A099XYZ", "Honda", 180.0);

        System.out.println("=== Reporte de Operaciones de Flota ===");

        for (Vehiculo vehiculo : flota) {
            vehiculo.mostrarFicha();
            double costo = vehiculo.calcularCostoViaje(150.0);
            System.out.println("Costo de viaje (150.0 km): $" + costo);
            System.out.println("--------------------------------------------------");
            totalOperativo += costo;
        }

        System.out.println("Costo total operativo de la flota: $" + totalOperativo);
    }
}
