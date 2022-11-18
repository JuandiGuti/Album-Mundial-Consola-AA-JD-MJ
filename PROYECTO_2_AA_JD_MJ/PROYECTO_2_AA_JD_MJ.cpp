#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int leerarchivo(string direccion, string lcategoria[], string lcodigo[], string lnumero_estampa[], string lnombre_estampa[]) {
    ifstream archivo(direccion);
    string linea;
    char delimitador = ',';
    int contador = 0;
    if (archivo.is_open()) {
        getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream stream(linea);
            string categoria, codigo, numero_estampa, nombre_estampa;
            while (getline(stream, categoria, delimitador) && getline(stream, codigo, delimitador) && getline(stream, numero_estampa, delimitador) && getline(stream, nombre_estampa, delimitador)) {
                lcategoria[contador] = categoria;
                lcodigo[contador] = codigo;
                lnumero_estampa[contador] = numero_estampa;
                lnombre_estampa[contador] = nombre_estampa;
            }
            contador++;
        }
        return contador;
    }
    else {
        cout << "No se encontro el archivo" << endl;
        return 0;
    }
}
int menu() {
    int res;
    cout << "1. Visualizar una estampa." << endl;
    cout << "2. Colocar una estampa." << endl;
    cout << "3. Contador de repetidas." << endl;
    cout << "4. Contador de marcadas." << endl;
    cout << "5. Contador de faltantes." << endl;
    cout << "6. Filtrar estampas." << endl;
    cout << "7. Salir." << endl;
    cin >> res;
    return res;
}
int main()
{
    int opcion;
    int cant_estampas;
    string direccion;

    string lcategoria[100], lcodigo[100], lnumero_estampa[100], lnombre_estampa[100];

    cout << "\tUsar archivo base o ingresar uno propio" << endl;
    cout << "1. Base" << endl;
    cout << "2. Propio" << endl;
    cin >> direccion;
    if (direccion == "1") {
        cant_estampas = leerarchivo("archivo.csv", lcategoria, lcodigo, lnumero_estampa, lnombre_estampa);
    }
    else if (direccion == "2") {
        cout << "\tIngrese la direccion donde se encuentra el archivo..." << endl;
        cout << "Ejemplo: C:\\Users\\juand\\OneDrive\\Documents\\archivo.csv" << endl;
        cin >> direccion;
        cant_estampas = leerarchivo(direccion, lcategoria, lcodigo, lnumero_estampa, lnombre_estampa);
        if (cant_estampas == 0) {
            cout << "Saliendo del programa..." << endl;
            return 0;
        }
    }
    else {
        cout << "Saliendo del programa..." << endl;
        return 0;
    }

    string lista_global[100][6];

    for (int i = 0; i < cant_estampas; i++) {
        for (int j = 0; j < 6; j++) {
            if (j == 0) {
                lista_global[i][j] = lcategoria[i];
            }
            else if (j == 1) {
                lista_global[i][j] = lcodigo[i];
            }
            else if (j == 2) {
                lista_global[i][j] = lnumero_estampa[i];
            }
            else if (j == 3) {
                lista_global[i][j] = lnombre_estampa[i];
            }
            else if (j == 4) {
                lista_global[i][j] = "0";
            }
            else if (j == 5) {
                lista_global[i][j] = "0";
            }
        }
    }

    do {
        system("cls");
        cout << "\tBIENVENIDO AL ALBUM DEL MUNDIAL QATAR 2022!" << endl;
        opcion = menu();
        system("cls");
        if (opcion == 1) {
            cout << "\tVisualizar una estampa" << endl;
            int buscando;
            string codigo, nombre, nombre2;
            bool laencontr = false;

            cout << "Desea buscar por. |1. Nombre | 2. Codigo |" << endl;
            cin >> buscando;

            if (buscando == 1) {
                cout << "Escriba el nombre de la estampa o del jugador." << endl;
                cin >> nombre;
                getline(cin, nombre2);
                std::ostringstream ss;
                ss << nombre << nombre2;
                string s = ss.str();
                for (int i = 0; i < cant_estampas; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (laencontr) {
                            break;
                        }
                        if (lista_global[i][3] == s) {
                            laencontr = true;
                            cout << "Categoria: " << lista_global[i][0] << endl;
                            cout << "Codigo: " << lista_global[i][1] << endl;
                            cout << "Numero de Estampa: " << lista_global[i][2] << endl;
                            cout << "Nombre de Jugador : " << lista_global[i][3] << endl;
                            if (lista_global[i][4] == "1") {
                                cout << "La tengo : Si" << endl;
                            }
                            else {
                                cout << "La tengo : No" << endl;
                            }
                            cout << "Cuantas repetidas : " << lista_global[i][5] << endl;
                        }
                    }
                }
                if (laencontr == false) {
                    cout << "No se encontro la estampilla..."<< endl;
                }
            }
            else if (buscando == 2) {
                string codigocom, numeroest, vacio = "";
                ostringstream ss, sss;

                cout << "Escriba el codigo de la estampa. Ejemplo. ARG0 o FWC2" << endl;
                cin >> codigo;

                ss << codigo[0] << codigo[1] << codigo[2];
                codigocom = ss.str();

                sss << codigo[3];
                numeroest = sss.str();
                
                for (int i = 0; i < cant_estampas; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (laencontr) {
                            break;
                        }
                        if (lista_global[i][1] == codigocom) {
                            if (lista_global[i][2] == numeroest) {
                                laencontr = true;
                                cout << "Categoria: " << lista_global[i][0] << endl;
                                cout << "Codigo: " << lista_global[i][1] << endl;
                                cout << "Numero de Estampa: " << lista_global[i][2] << endl;
                                cout << "Nombre de Jugador : " << lista_global[i][3] << endl;
                                if (lista_global[i][4] == "1") {
                                    cout << "La tengo : Si" << endl;
                                }
                                else {
                                    cout << "La tengo : No" << endl;
                                }
                                cout << "Cuantas repetidas : " << lista_global[i][5] << endl;
                            }
                        }
                    }
                }
                if (laencontr == false) {
                    cout << "No se encontro la estampilla..." << endl;
                }
            }
            else {
                cout << "No se encontro la opcion..." << endl;
            }
        }
        else if (opcion == 2) {
            cout << "\tColocar una estampa" << endl;

            cout << "Colocar una estampa o varias estampas por medio de un csv | 1. Una sola | 2. varias |" << endl;
            int unaovarias;
            cin >> unaovarias;
            if (unaovarias == 1) {
                int buscando;
                string codigo, nombre, nombre2;
                bool laencontr = false;

                cout << "Desea buscar por. |1. Nombre | 2. Codigo |" << endl;
                cin >> buscando;

                if (buscando == 1) {
                    cout << "Escriba el nombre de la estampa o del jugador." << endl;
                    cin >> nombre;
                    getline(cin, nombre2);
                    std::ostringstream ss;
                    ss << nombre << nombre2;
                    string s = ss.str();
                    for (int i = 0; i < cant_estampas; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (laencontr) {
                                break;
                            }
                            if (lista_global[i][3] == s) {
                                laencontr = true;
                                if (lista_global[i][4] == "1") {
                                    cout << "Ya tienes la estampa colocada, se sumara una repetida!" << endl;
                                    // METODO DE REPETIDAS !!!!!!!
                                    int repetidas = stoi(lista_global[i][5]);
                                    repetidas++;
                                    lista_global[i][5] = to_string(repetidas);
                                }
                                else {
                                    cout << "Estampa Colocada con exito!" << endl;
                                    cout << "Categoria: " << lista_global[i][0] << endl;
                                    cout << "Codigo: " << lista_global[i][1] << endl;
                                    cout << "Numero de Estampa: " << lista_global[i][2] << endl;
                                    cout << "Nombre de Jugador : " << lista_global[i][3] << endl;
                                    lista_global[i][4] = "1";
                                    cout << "Cuantas repetidas : " << lista_global[i][5] << endl;
                                }
                            }
                        }
                    }
                    if (laencontr == false) {
                        cout << "No se encontro la estampilla..." << endl;
                    }
                }
                else if (buscando == 2) {
                    string codigocom, numeroest, vacio = "";
                    ostringstream ss, sss;

                    cout << "Escriba el codigo de la estampa. Ejemplo. ARG0 o FWC2" << endl;
                    cin >> codigo;

                    ss << codigo[0] << codigo[1] << codigo[2];
                    codigocom = ss.str();

                    sss << codigo[3];
                    numeroest = sss.str();

                    for (int i = 0; i < cant_estampas; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (laencontr) {
                                break;
                            }
                            if (lista_global[i][1] == codigocom) {
                                if (lista_global[i][2] == numeroest) {
                                    laencontr = true;
                                    if (lista_global[i][4] == "1") {
                                        cout << "Ya tienes la estampa colocada, se sumara una repetida!" << endl;
                                        // METODO DE REPETIDAS !!!!!!!
                                        int repetidas = stoi(lista_global[i][5]);
                                        repetidas++;
                                        lista_global[i][5] = to_string(repetidas);
                                    }
                                    else {
                                        cout << "Estampa Colocada con exito!" << endl;
                                        cout << "Categoria: " << lista_global[i][0] << endl;
                                        cout << "Codigo: " << lista_global[i][1] << endl;
                                        cout << "Numero de Estampa: " << lista_global[i][2] << endl;
                                        cout << "Nombre de Jugador : " << lista_global[i][3] << endl;
                                        lista_global[i][4] = "1";
                                        cout << "Cuantas repetidas : " << lista_global[i][5] << endl;
                                    }
                                }
                            }
                        }
                    }
                    if (laencontr == false) {
                        cout << "No se encontro la estampilla..." << endl;
                    }
                }
                else {
                    cout << "No se encontro la opcion..." << endl;
                }
            }
            else if (unaovarias == 2) {

                cout << "\tIngrese la direccion donde se encuentra el archivo..." << endl;
                cout << "Ejemplo: C:\\Users\\juand\\OneDrive\\Documents\\archivo.csv" << endl;
                cin >> direccion;

                ifstream archivo(direccion);
                string linea;
                char delimitador = ',';
                int contador = 0;
                if (archivo.is_open()) {
                    getline(archivo, linea);
                    while (getline(archivo, linea)) {
                        stringstream stream(linea);
                        string categoria, codigo, numero_estampa, nombre_estampa;
                        while (getline(stream, categoria, delimitador) && getline(stream, codigo, delimitador) && getline(stream, numero_estampa, delimitador) && getline(stream, nombre_estampa, delimitador)) {
                            lcategoria[contador] = categoria;
                            lcodigo[contador] = codigo;
                            lnumero_estampa[contador] = numero_estampa;
                            lnombre_estampa[contador] = nombre_estampa;
                        }
                        contador++;
                    }
                }
                else {
                    cout << "No se encontro el archivo" << endl;
                    break;
                }
                string lista_agregando[100][6];

                for (int i = 0; i < contador; i++) {
                    for (int j = 0; j < 6; j++) {
                        if (j == 0) {
                            lista_agregando[i][j] = lcategoria[i];
                        }
                        else if (j == 1) {
                            lista_agregando[i][j] = lcodigo[i];
                        }
                        else if (j == 2) {
                            lista_agregando[i][j] = lnumero_estampa[i];
                        }
                        else if (j == 3) {
                            lista_agregando[i][j] = lnombre_estampa[i];
                        }
                        else if (j == 4) {
                            lista_agregando[i][j] = "1";
                        }
                        else if (j == 5) {

                            lista_agregando[i][j] = "0";
                        }
                    }
                }
                for (int i = 0; i < cant_estampas; i++) {
                    for (int j = 0; j < cant_estampas; j++) {
                        if (lista_global[i][3] == lista_agregando[j][3]) {
                            if (lista_global[j][4] == "0") {
                                lista_global[j][4] = "1";
                            }
                            else {
                                int repetidas = stoi(lista_global[i][5]);
                                repetidas++;
                                lista_global[i][5] = to_string(repetidas);
                            }
                        }
                    }
                }

                cout << "Estampas marcadas correctamente!" << endl;
            }
            else {
                cout << "No se encontro la opcion..." << endl;
                break;
            }
        }
        else if (opcion == 3) {
            cout << "\tContador de repetidas" << endl;
            int contador = 0;
            cout << "CODIGO." << "\t" << "NOMBRE." << "\t\t\t" << "CANT. REPETIDAS" << endl;
            for (int i = 0; i < cant_estampas; i++) {
                if (lista_global[i][5] != "0") {
                    cout << lista_global[i][1] << lista_global[i][2] << "\t" << lista_global[i][3] << "\t\t\t" << lista_global[i][5] << endl;
                    contador++;
                }
            }
            cout << "Tienes: " << contador << " repetidas." << endl;
        }
        else if (opcion == 4) {
            cout << "\tContador de marcadas" << endl;
            int contador = 0;
            cout << "CODIGO." << "\t" << "NOMBRE." << endl;
            for (int i = 0; i < cant_estampas; i++) {
                if (lista_global[i][4] == "1") {
                    cout << lista_global[i][1] << lista_global[i][2] << "\t" << lista_global[i][3] << endl;
                    contador++;
                }
            }
            cout << "Tienes: " << contador << " estampas." << endl;
        }
        else if (opcion == 5) {
            cout << "\tContador de faltantes" << endl;
            int contador = 0;
            for (int i = 0; i < cant_estampas; i++) {
                if (lista_global[i][4] == "1") {
                    contador++;
                }
            }
            cout << "Tienes: " << contador << "/" << cant_estampas << " te faltan: " << (cant_estampas - contador) << endl;
        }
        else if (opcion == 6) {
            cout << "\tFiltrar estampas" << endl;
            cout << "Filtrar por..." << endl;
            cout << "1. Categoria" << endl;
            cout << "2. Seleccion" << endl;
            cout << "3. Repetidas" << endl;
            int op6;
            cin >> op6;
            string res;
            string listaexportar[100][6];
            bool seecontro = false;
            int cont = 0;

            if (op6 == 1) {
                cout << "Que categoria quieres filtar ejemplo. pais" << endl;
                cin >> res;
                for (int i = 0; i < cant_estampas; i++) {
                    if (lista_global[i][0] == res) {
                        listaexportar[cont][0] = lista_global[i][0];
                        listaexportar[cont][1] = lista_global[i][1];
                        listaexportar[cont][2] = lista_global[i][2];
                        listaexportar[cont][3] = lista_global[i][3];
                        listaexportar[cont][4] = lista_global[i][4];
                        listaexportar[cont][5] = lista_global[i][5];
                        seecontro = true;
                        cont++;
                    }
                }
            }
            else if (op6 == 2) {
                cout << "Que pais quieres filtrar ejemplo. BRA" << endl;
                cin >> res;
                for (int i = 0; i < cant_estampas; i++) {
                    if (lista_global[i][1] == res) {
                        listaexportar[cont][0] = lista_global[i][0];
                        listaexportar[cont][1] = lista_global[i][1];
                        listaexportar[cont][2] = lista_global[i][2];
                        listaexportar[cont][3] = lista_global[i][3];
                        listaexportar[cont][4] = lista_global[i][4];
                        listaexportar[cont][5] = lista_global[i][5];
                        seecontro = true;
                        cont++;
                    }
                }
            }
            else if (op6 == 3) {
                for (int i = 0; i < cant_estampas; i++) {
                    if (stoi(lista_global[i][5]) > 0) {
                        listaexportar[cont][0] = lista_global[i][0];
                        listaexportar[cont][1] = lista_global[i][1];
                        listaexportar[cont][2] = lista_global[i][2];
                        listaexportar[cont][3] = lista_global[i][3];
                        listaexportar[cont][4] = lista_global[i][4];
                        listaexportar[cont][5] = lista_global[i][5];
                        seecontro = true;
                        cont++;
                    }
                }
            }
            else {
                cout << "error." << endl;
                break;
            }
            if (seecontro != true) {
                cout << "No Existen elementos de esa categoria." << endl;
                break;
            }

            fstream output;
            output.open("EstampasMundial.csv", ios::out);
            output << "categoria" << "," << "codigo" << "," << "numero_estampa" << "," << "nombre_estampa" << "," << "La_Tengo" << "," << "Repetidas" << endl;
            for (int i = 0; i < cont; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 0) {
                        output << listaexportar[i][j];
                    }
                    else if (j == 1) {
                        output << "," << listaexportar[i][j];
                    }
                    else if (j == 2) {
                        output << "," << listaexportar[i][j];
                    }
                    else if (j == 3) {
                        output << "," << listaexportar[i][j];
                    }
                    else if (j == 4) {
                        if (listaexportar[i][j] == "1") {
                            output << "," << "Si";
                        }
                        else {
                            output << "," << "No";
                        }
                    }
                    else if (j == 5) {
                        output << "," << listaexportar[i][j] << endl;
                    }
                }
            }
            cout << "Archivo Guardado" << endl;
        }
        else {
            cout << "Saliendo del programa..." << endl;
            return 0;
        }
        cout << "Desea visualizar realizar otra opcion | 1. Si | 2. No |" << endl;
        cin >> opcion;
    } while (opcion != 2);
    cout << "Saliendo del programa..." << endl;
    return 0;
}