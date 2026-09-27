package sistemabiblioteca;

public class MainBiblioteca {

    public static void main(String[] args){

        // Constructor canonico
        Libro libro1 = new Libro("Don Quijote", "Miguel de Cervantes","978-84-376-0494-7", 10, 45000.0);
        // Constructor de conveniencia
        Libro libro2 = new Libro("1984", "George Orwell", "978-0-451-52493-5");
        // Constructores con datos invalidos
        Libro libro3 = new Libro(null, "Gabriel Marquez", "978-0-307-47472-8", 4, 35000);
        Libro libro4 = new Libro("Ficciones", null, "978-0-307-35041-1", 5, 50000);

        System.out.println("Titulo de libro 3: " + libro3.getTitulo());
        System.out.println("Autor de libro 4: " + libro4.getAutor());

        libro1.mostrarFicha();
        libro2.mostrarFicha();
        libro3.mostrarFicha();
        libro4.mostrarFicha();

        libro4.setPrecioReposicion(18000.0);
        System.out.println("Precio de reposicion de libro 4: " + libro4.getPrecioReposicion());
        if (!libro4.setPrecioReposicion(-5.0)) {
            System.out.println("Rechazado, el precio sigue en: " + libro4.getPrecioReposicion());
        }

        int exitos = 0;
        int intentos = libro3.getCopiasDisponibles() + 2;
        for (int i = 0; i < intentos; i++) {
            if (libro3.prestar()) {
                exitos++;
            }
        }
        System.out.println("Prestamos exitosos: " + exitos + " de " + intentos + " intentos");
        System.out.println("Copias finales: " + libro3.getCopiasDisponibles()
        + " (no debe ser negativo)");

        libro3.devolver();
        System.out.println("Tras devolver, copias: " + libro3.getCopiasDisponibles());
        System.out.println("Prestamos históricos de libro 3: " + libro3.getPrestamosHistoricos());
    }
}