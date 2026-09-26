package gestioninventario;

import java.util.ArrayList;

public class Inventario { 
        ArrayList<Producto> productos = new ArrayList<>();

        public boolean existeId(int id) {
                return buscarProducto(id) != null;
        }       
        public void agregarProducto(Producto producto) {

                if (existeId(producto.id)){
                        System.out.println("El id " + producto.id + " ya esta en uso");
                } else {
                        productos.add(producto);
                }
        }

        public void mostrarProductos(){
                for (int i = 0; i < productos.size(); i++) {
                    System.out.println(productos.get(i).nombre);
                }
        }

        public Producto buscarProducto(int id){
                for (Producto producto : productos) {
                    if (producto.id == id){
                        return producto;
                    }
                }
                return null;
        }

        public void eliminarProducto(int id) {
                Producto producto = buscarProducto(id);

                if (producto != null) {
                        System.out.println("Producto encontrado: "+ producto.nombre);
                        productos.remove(producto);
                }
                else {
                        System.out.println("Producto no encontrado");
                }
        }

        public void modificarProducto(int id, String nombre, double precio) {
                Producto producto = buscarProducto(id);

                if (producto != null) {
                        System.out.println("Producto encontrado: "+ producto.nombre);
                        productos.remove(producto);
                }
                else {
                        System.out.println("Producto no encontrado");
                }
        }
}