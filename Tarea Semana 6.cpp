#include <iostream>
#include <string>
using namespace std;

const int MAX_VENTAS = 100;

int numeroFactura[MAX_VENTAS];
string cedula[MAX_VENTAS];
string nombre[MAX_VENTAS];
int localidad[MAX_VENTAS];
int cantidadEntradas[MAX_VENTAS];
string nombreLocalidad[MAX_VENTAS];
double precioPorEntrada[MAX_VENTAS];
double subtotal[MAX_VENTAS];
double cargosServicios[MAX_VENTAS];
double totalPagar[MAX_VENTAS];
int numVentas = 0;

void mostrarEstadisticas(int entradasSol, double dineroSol, int entradasSombra, double dineroSombra, int entradasPreferencial, double dineroPreferencial);
void agregarVenta();
void consultarVenta();
void modificarVenta();
void borrarVenta();

int main() {
    char opcion;
    int entradasSol = 0;
    double dineroSol = 0.0;
    int entradasSombra = 0;
    double dineroSombra = 0.0;
    int entradasPreferencial = 0;
    double dineroPreferencial = 0.0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar venta\n";
        cout << "2. Consultar venta\n";
        cout << "3. Modificar venta\n";
        cout << "4. Borrar venta\n";
        cout << "5. Mostrar estadisticas\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                agregarVenta();
                break;
            case '2':
                consultarVenta();
                break;
            case '3':
                modificarVenta();
                break;
            case '4':
                borrarVenta();
                break;
            case '5':
                for (int i = 0; i < numVentas; i++) {
                    switch (localidad[i]) {
                        case 1:
                            entradasSol += cantidadEntradas[i];
                            dineroSol += subtotal[i];
                            break;
                        case 2:
                            entradasSombra += cantidadEntradas[i];
                            dineroSombra += subtotal[i];
                            break;
                        case 3:
                            entradasPreferencial += cantidadEntradas[i];
                            dineroPreferencial += subtotal[i];
                            break;
                    }
                }
                mostrarEstadisticas(entradasSol, dineroSol, entradasSombra, dineroSombra, entradasPreferencial, dineroPreferencial);
                break;
            case '6':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != '6');

    return 0;
}

void mostrarEstadisticas(int entradasSol, double dineroSol, int entradasSombra, double dineroSombra, int entradasPreferencial, double dineroPreferencial) {
    cout << "\nEstadisticas finales:\n";
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << entradasSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << dineroSol << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << entradasSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << dineroSombra << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << entradasPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << dineroPreferencial << endl;
}

void agregarVenta() {
    if (numVentas >= MAX_VENTAS) {
        cout << "No se pueden registrar más ventas.\n";
        return;
    }

    int indice = numVentas;
    cout << "Ingrese numero de factura: ";
    cin >> numeroFactura[indice];
    cout << "Ingrese cedula: ";
    cin >> cedula[indice];
    cout << "Ingrese nombre del comprador: ";
    cin.ignore();
    getline(cin, nombre[indice]);
    do {
        cout << "Ingrese localidad (1- Sol Norte/Sur, 2- Sombra Este/Oeste, 3- Preferencial): ";
        cin >> localidad[indice];
    } while (localidad[indice] < 1 || localidad[indice] > 3);
    do {
        cout << "Ingrese cantidad de entradas (maximo 4): ";
        cin >> cantidadEntradas[indice];
    } while (cantidadEntradas[indice] < 1 || cantidadEntradas[indice] > 4);

    switch (localidad[indice]) {
        case 1:
            precioPorEntrada[indice] = 10500;
            nombreLocalidad[indice] = "Sol Norte/Sur";
            break;
        case 2:
            precioPorEntrada[indice] = 20500;
            nombreLocalidad[indice] = "Sombra Este/Oeste";
            break;
        case 3:
            precioPorEntrada[indice] = 25500;
            nombreLocalidad[indice] = "Preferencial";
            break;
    }

    subtotal[indice] = cantidadEntradas[indice] * precioPorEntrada[indice];
    cargosServicios[indice] = cantidadEntradas[indice] * 1000;
    totalPagar[indice] = subtotal[indice] + cargosServicios[indice];

    numVentas++;

    cout << "Venta registrada exitosamente.\n";
}

void consultarVenta() {
    int factura;
    cout << "Ingrese el numero de factura a consultar: ";
    cin >> factura;

    for (int i = 0; i < numVentas; i++) {
        if (numeroFactura[i] == factura) {
            cout << "\nDetalles de la venta:\n";
            cout << "Numero de Factura: " << numeroFactura[i] << endl;
            cout << "Cedula: " << cedula[i] << endl;
            cout << "Nombre Comprador: " << nombre[i] << endl;
            cout << "Localidad: " << nombreLocalidad[i] << endl;
            cout << "Cantidad de Entradas: " << cantidadEntradas[i] << endl;
            cout << "Subtotal: " << subtotal[i] << endl;
            cout << "Cargos por Servicios: " << cargosServicios[i] << endl;
            cout << "Total a Pagar: " << totalPagar[i] << endl;
            return;
        }
    }

    cout << "Factura no encontrada.\n";
}

void modificarVenta() {
    int factura;
    cout << "Ingrese el numero de factura a modificar: ";
    cin >> factura;

    for (int i = 0; i < numVentas; i++) {
        if (numeroFactura[i] == factura) {
            cout << "Ingrese nuevo nombre del comprador: ";
            cin.ignore();
            getline(cin, nombre[i]);
            do {
                cout << "Ingrese nueva localidad (1- Sol Norte/Sur, 2- Sombra Este/Oeste, 3- Preferencial): ";
                cin >> localidad[i];
            } while (localidad[i] < 1 || localidad[i] > 3);
            do {
                cout << "Ingrese nueva cantidad de entradas (maximo 4): ";
                cin >> cantidadEntradas[i];
            } while (cantidadEntradas[i] < 1 || cantidadEntradas[i] > 4);

            switch (localidad[i]) {
                case 1:
                    precioPorEntrada[i] = 10500;
                    nombreLocalidad[i] = "Sol Norte/Sur";
                    break;
                case 2:
                    precioPorEntrada[i] = 20500;
                    nombreLocalidad[i] = "Sombra Este/Oeste";
                    break;
                case 3:
                    precioPorEntrada[i] = 25500;
                    nombreLocalidad[i] = "Preferencial";
                    break;
            }

            subtotal[i] = cantidadEntradas[i] * precioPorEntrada[i];
            cargosServicios[i] = cantidadEntradas[i] * 1000;
            totalPagar[i] = subtotal[i] + cargosServicios[i];

            cout << "Venta modificada exitosamente.\n";
            return;
        }
    }

    cout << "Factura no encontrada.\n";
}

void borrarVenta() {
    int factura;
    cout << "Ingrese el numero de factura a borrar: ";
    cin >> factura;

    for (int i = 0; i < numVentas; i++) {
        if (numeroFactura[i] == factura) {
            for (int j = i; j < numVentas - 1; j++) {
                numeroFactura[j] = numeroFactura[j + 1];
                cedula[j] = cedula[j + 1];
                nombre[j] = nombre[j + 1];
                localidad[j] = localidad[j + 1];
                cantidadEntradas[j] = cantidadEntradas[j + 1];
                nombreLocalidad[j] = nombreLocalidad[j + 1];
                precioPorEntrada[j] = precioPorEntrada[j + 1];
                subtotal[j] = subtotal[j + 1];
                cargosServicios[j] = cargosServicios[j + 1];
                totalPagar[j] = totalPagar[j + 1];
            }
            numVentas--;
            cout << "Venta borrada exitosamente.\n";
            return;
        }
    }

    cout << "Factura no encontrada.\n";
}
