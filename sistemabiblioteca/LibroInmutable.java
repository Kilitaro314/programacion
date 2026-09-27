package sistemabiblioteca;

public final class LibroInmutable {

    private final String titulo;
    private final String autor;
    private final String isbn;

    public LibroInmutable(String titulo, String autor, String isbn) {
        this.titulo = titulo;
        this.autor = autor;
        this.isbn = isbn;
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
}