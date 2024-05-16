#include <iostream>
#include <stack>
#include <queue>
#include <string>
// Gracias a las clases stack y queue podremos usar las pilas y colas
// de forma respectiva. Las pilas se refieren a que el ultimo elemento
// en entrar es el primero en salir y las colas es el primer elemento en
// entrar es el primero en salir 
struct Tarea { // Tarea se refiere a las tareas que vamos a ingresar
    int id;
    std::string descripcion; 
};

int main() {
    std::stack<Tarea> pilaTareas; // se crea la pila de las tareas
    std::queue<Tarea> colaTareas; // se crea la cola de tareas
    int opcion; // opcion es lo que vamos a utilizar para el menu 
    int idCounter = 1; 

    do {
        std::cout << "Menu de Tareas" << std::endl; // este es el menú de tareas 
        std::cout << "1. Agregar una tarea" << std::endl; // Con esta opción se añade una tarea a la lista 
        std::cout << "2. Completar la ultima tarea" << std::endl; // Con esto utilizamos las pilas para completar la ultima tarea ingresada
        std::cout << "3. Completar la tarea mas antigua" << std::endl; // Con esto usamos las colas para completar la primer tarea ingresada
        std::cout << "4. Mostrar todas las tareas" << std::endl; // se muestra el listado de tareas 
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: "; // se nos pide que elijamos una opción (un numero del 1 al 5)
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) { //para el menu utilizaremos un switch case debido a la diversa cantidad de opciones del menu
            case 1: { // se muestra el caso uno, que es el de añadir una tarea a la lista
            // para ello se ingresa el nombre de la tarea y se genera dentro de la lista
                std::string descripcion;
                std::cout << "Ingrese la descripcion de la tarea: ";
                std::getline(std::cin, descripcion);

                Tarea nuevaTarea = { idCounter++, descripcion };
                pilaTareas.push(nuevaTarea);
                colaTareas.push(nuevaTarea);

                std::cout << "Tarea agregada correctamente." << std::endl;
                break;
            }
            case 2: { // La pila de tareas es la que nos permite completar la ultima tarea ingresarla
            // por ende la ultima tarea se va a eliminar de la lista
                if (!pilaTareas.empty()) { 
                    Tarea tareaCompletada = pilaTareas.top();
                    pilaTareas.pop();
                    std::cout << "Tarea completada: " << tareaCompletada.descripcion << std::endl;
                } else {
                    std::cout << "No hay tareas para completar." << std::endl;
                }
                break;
            }
            case 3: { // Las colas, caso contrario, nos permite completar la primer tarea ingresada a la lista
            // luego de haberse completado esta, se eliminará de la lista.
                if (!colaTareas.empty()) {
                    Tarea tareaAtendida = colaTareas.front();
                    colaTareas.pop();
                    std::cout << "Tarea atendida: " << tareaAtendida.descripcion << std::endl;
                } else {
                    std::cout << "No hay tareas para atender." << std::endl;
                }
                break;
            }
            case 4: { // en el caso número 4 se nos mostraran las tareas que quedan pendientes
            // todas las tareas ingresadas las cuales no se han sacado de la lista ni con pilas ni con colas
                if (!pilaTareas.empty()) {
                    std::cout << "Lista de tareas pendientes:" << std::endl;
                    std::queue<Tarea> copiaColaTareas = colaTareas;
                    int numeroTarea = 1;
                    while (!copiaColaTareas.empty()) {
                        Tarea tarea = copiaColaTareas.front();
                        copiaColaTareas.pop();
                        std::cout << numeroTarea++ << ". " << tarea.descripcion << std::endl;
                    }
                    // en caso de no haber tareas se nos mostrará un mensaje en pantalla
                } else {
                    std::cout << "No hay tareas pendientes." << std::endl;
                }
                break;
                // para el ultimo programa se nos muestra la opcion de salir 
            }
            case 5:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 5);

    return 0;
}

