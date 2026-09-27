package gestioninventario;

public class Producto {
        
    String nombre;
    double precio;
    int id;
    int stock;

    
    public Producto(int id, String nombre, double precio, int stock) {
            this.id = id;
            this.nombre = nombre;
            this.precio = precio;
            this.stock = stock;
    }

    public void cambiarStock(int cantidad) {
        stock += cantidad;
    }

}