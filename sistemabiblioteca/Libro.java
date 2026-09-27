package sistemabiblioteca;

public class Libro {
    
    private static final String TITULO_POR_DEFECTO = "Sin título";
    private static final String AUTOR_POR_DEFECTO = "Autor desconocido";
    private static final String ISBN_POR_DEFECTO = "ISBN pendiente";
    private static final int COPIAS_POR_DEFECTO = 0;
    private static final double PRECIO_POR_DEFECTO = 15000.0;

    private final String titulo;
    private final String autor;
    private final String isbn;
    private int copiasDisponibles;
    private double precioReposicion;

    public Libro(String titulo, String autor, String isbn,
        int copiasDisponibles, double precioReposicion) {

        if (titulo == null || titulo.isBlank()) {
            System.out.println("Título inválido, se usó \"" + TITULO_POR_DEFECTO + "\" por defecto.");
            titulo = TITULO_POR_DEFECTO;
        }

        if (autor == null || autor.isBlank()) {
            System.out.println("Autor inválido, se usó \"" + AUTOR_POR_DEFECTO + "\" por defecto.");
            autor = AUTOR_POR_DEFECTO;
        }

        if (isbn == null || isbn.isBlank()) {
            System.out.println("ISBN inválido, se usó \"" + ISBN_POR_DEFECTO + "\" por defecto.");
            isbn = ISBN_POR_DEFECTO;
        }

        this.titulo = titulo;
        this.autor = autor;
        this.isbn = isbn;

        if (copiasDisponibles < 0) {
            System.out.println("Copias inválidas (" + copiasDisponibles
                            + "). Se usó " + COPIAS_POR_DEFECTO + " por defecto.");
            copiasDisponibles = COPIAS_POR_DEFECTO;
        }
        this.copiasDisponibles = copiasDisponibles;

        this.precioReposicion = PRECIO_POR_DEFECTO;
        if (!setPrecioReposicion(precioReposicion)) {
            System.out.println("Se usará el precio de reposición por defecto: $" + PRECIO_POR_DEFECTO + ".");
        }
    }

    public Libro(String titulo, String autor, String isbn) {
        this(titulo, autor, isbn, 1, PRECIO_POR_DEFECTO);
    }

    public boolean prestar() {
        if (copiasDisponibles > 0) {
            copiasDisponibles--;
            System.out.println("Préstamo registrado: \"" + titulo + "\". Copias disponibles: " + copiasDisponibles);
            return true;
        }
        System.out.println("Error: no hay copias disponibles de \"" + titulo + "\" para prestar.");
        return false;
    }

    public void devolver() {
        copiasDisponibles++;
        System.out.println("Devolución registrada: \"" + titulo + "\". Copias disponibles: " + copiasDisponibles);
    }

    public boolean setPrecioReposicion(double precio) {
        if (precio > 0) {
            double precioAnterior = precioReposicion;
            precioReposicion = precio;
            System.out.println("Precio de reposición actualizado de \"" + titulo + "\": $"
                    + precioAnterior + " -> $" + precioReposicion);
            return true;
        }

        System.out.println("Precio de reposición inválido: " + precio
                + ". Se mantiene el anterior: $" + precioReposicion);
        return false;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public String getIsbn() {
        return isbn;
    }

    public int getCopiasDisponibles() {
        return copiasDisponibles;
    }

    public double getPrecioReposicion() {
        return precioReposicion;
    }

    public void mostrarFicha() {
        System.out.println("========== Ficha del libro ==========");
        System.out.println("Título:  " + titulo);
        System.out.println("Autor:   " + autor);
        System.out.println("ISBN:    " + isbn);
        System.out.println("Copias disponibles: " + copiasDisponibles);
        System.out.println("Precio de reposición: $" + precioReposicion);
        System.out.println("======================================");
    }
}