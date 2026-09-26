package gestioninventario;

import java.util.Scanner;


public class GestionInventario {

    public static void main(String args[]){

        Inventario inventario = new Inventario();
        Scanner scanner = new Scanner(System.in);

        int opción = 0;

        do { 
            System.out.println("========== Menu de Inventario ==========");
            System.out.println("1. Agregar producto");
            System.out.println("2. Mostrar productos");
            System.out.println("3. Buscar producto");
            System.out.println("4. Modificar stock");
            System.out.println("5. Eliminar producto");
            System.out.println("6. Modificar producto");
            System.out.println("7. Salir");

            opción = scanner.nextInt();
            scanner.nextLine();

            switch (opción) {
                case 1:

                    System.out.println("Ingrese ID del producto");
                    int id = scanner.nextInt();
                    scanner.nextLine();

                    System.out.println("Ingrese el nombre del producto");
                    String nombre = scanner.nextLine();

                    System.out.println("Ingrese el precio del producto");
                    double precio = scanner.nextDouble();

                    System.out.println("Ingrese stock del producto");
                    int stock = scanner.nextInt();
                    
                    Producto producto_nuevo = new Producto(id,nombre,precio,stock);

                    inventario.agregarProducto(producto_nuevo);
                    System.out.println("El producto " + producto_nuevo.nombre + " se a agredado correctamente");
                    break;
                
                case 2:
                    inventario.mostrarProductos();
                    break;
                
                case 3:
                    System.out.println("Ingrese el ID del producto a buscar");
                    id = scanner.nextInt();
                    scanner.nextLine();

                    Producto buscado = inventario.buscarProducto(id);

                    if (buscado != null){
                        System.out.println("Producto encontrado!");
                        System.out.println(buscado.nombre);
                    }
                    else {
                        System.out.println("Producto no encontrado");
                    }
                    break;
                
                case 4:
                    System.out.println("Ingrese el ID del producto cuyo stock quiere cambiar");
                    id = scanner.nextInt();
                    scanner.nextLine();

                    buscado = inventario.buscarProducto(id);

                    if (buscado != null){
                        System.out.println("Producto encontrado!");
                        System.out.println("El stock actual de " + buscado.nombre + " es " + buscado.stock);
                        System.out.println("¿Cuanto stock quiere sumar o restar?");
                        stock = scanner.nextInt();
                        scanner.nextLine();

                        buscado.cambiarStock(stock);
                    }
                    else {
                        System.out.println("Producto no encontrado");
                    }
                    break;
                
                case 5:
                    System.out.println("Ingrese el ID del producto que quiere eliminar");
                    id = scanner.nextInt();
                    scanner.nextLine();

                    inventario.eliminarProducto(id);
                    break;
                
                case 6:
                    System.out.println("Ingrese el ID del producto que quiere modificar");
                    id = scanner.nextInt();
                    scanner.nextLine();

                    System.out.println("Ingrese el nuevo nombre del producto");
                    nombre = scanner.nextLine();

                    System.out.println("Ingrese el nuevo precio del producto");
                    precio = scanner.nextDouble();
                    scanner.nextLine();

                    inventario.modificarProducto(id,nombre,precio);
                    break;
                
                case 7:
                    System.out.println("Saliendo del programa...");
                    break;

                default:
                    System.out.println("Opción inválida. Por favor, seleccione una opción válida.");
                    break;
            }


        } while (opción != 7);
    }
}