#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<ctype.h>
using namespace std;
int Opc, Opc2, opc3 = 1;
int NumO;
//Definicion del arreglo de estructuras
struct Orden {
	int Contador = 0;
	string Cod;
	int CantV = 0;
	char DescriP[50]="";
	double Total = 0, PrecioU = 0, Subtotal = 0;
	double IVA = 0;
}Ordenes[100];
//Funciones para mostrar ordenes,ingresar ordenes,Imprimir al archivo,validar codigo y regresar al menu
void MostrarO(Orden[]);
int BorrarO();
void IngresarO();
int RegresarM();
void ImprimirArc();
string ValidarCod(string);
int main()
{
	//Menu de opciones
	cout << "\t\t\t\t\tMenu de opciones" << endl;
	cout << "1): Ingresar Ordenes" << endl;
	cout << "2): Generar lista de Ordenes" << endl;
	cout << "3): Generar el archivo de texto" << endl;
	cout << "4): Borrar Ordenes" << endl;
	cout << "5): Salir del programa" << endl;
	cin >> Opc;
	switch (Opc)
	{
	case 1:
		IngresarO();
		break;
	case 2:
		MostrarO(Ordenes);
		break;
	case 3:
		ImprimirArc();
		break;
	case 4:
		BorrarO();
		break;
	case 5:
		exit(-1);
		break;
	}
	RegresarM();
	system("pause");
	return 0;
}
//Definicion para la funcion de entrada de datos
void IngresarO()
{
	//Numero de ordenes a ingresar
	//Inicio del ciclo en base al numero de ordenes deseadas
	string valor="";
	cout << "Cuantas ordenes desea ingresar:";
	cin >> NumO;
	for (int i = 0; i < NumO; i++)
	{
		cout << "\nCodigo del producto:";
		cin.ignore();
		getline(cin, valor);
		Ordenes[i].Cod = ValidarCod(valor);
		cout << "Descripcion del producto:";
		cin.getline(Ordenes[i].DescriP, 50, '\n');
		cout << "Cantidad para vender" << ":";
		cin >> Ordenes[i].CantV;
		cout << "Precio Unitario del producto" << ": $";
		cin >> Ordenes[i].PrecioU;
		Ordenes[i].Subtotal = Ordenes[i].PrecioU * Ordenes[i].CantV;
		Ordenes[i].IVA = Ordenes[i].Subtotal * 0.16;
		Ordenes[i].Total = Ordenes[i].Subtotal + Ordenes[i].IVA;
		Ordenes[i].Contador=i+1;
	}
	system("cls");
}
//Definicion de la Funcion para mostrar ordenes
void MostrarO(Orden Ord[])
{
	for (int i = 0; i < NumO; i++)
	{
		if (Ord[i].Contador == 0)
			cout << "\n";
		else
		{
			{
				cout << "\n\tOrden numero:" << Ord[i].Contador<< endl;
				cout << "Codigo del producto:" << Ord[i].Cod << endl;
				cout << "Descripcion:" << Ord[i].DescriP << endl;
				cout << "Cantidad para vender: " << Ord[i].CantV << endl;
				cout << "Precio Unitario del producto: $" << Ord[i].PrecioU << endl;
				cout << "Subtotal del producto: $" << Ord[i].Subtotal << endl;
				cout << "IVA del producto: $" << Ord[i].IVA << endl;
				cout << "Total del producto: $" << Ord[i].Total << endl;
			}
		}
	}
}
//Definicion de la Funcion para Regresar al menu
int RegresarM()
{
	cout << "\nDesea regresar al Menu?(Responda con 1 para regresar,2 para salir):  ";
	cin >> Opc2;
	system("cls");
	if (Opc2 == 1)
	{
		return main();
	}
	else
		exit(-1);
}

//Definicion de la Funcion para imprimir en el archivo
void ImprimirArc()
{
	cout << "Archivo creado exisotasamente" << endl;
	ofstream Listas("OrdenesLista", ios_base::out);
	Listas << "\t\tOrdenes de venta" << endl;
	for (int i = 0; i < NumO; i++)
	{
		if (Ordenes[i].Contador == 0)
		{
			Listas << "\n";
		}
		else
		{
			Listas << "\n\t Orden Numero: " << Ordenes[i].Contador<< endl;
			Listas << "Codigo del producto:" << Ordenes[i].Cod << endl;
			Listas << "Descripcion:" << Ordenes[i].DescriP << endl;
			Listas << "Cantidad para vender: " << Ordenes[i].CantV << endl;
			Listas << "Precio Unitario del producto: $" << Ordenes[i].PrecioU << endl;
			Listas << "Subtotal del producto: $" << Ordenes[i].Subtotal << endl;
			Listas << "IVA del producto: $" << Ordenes[i].IVA << endl;
			Listas << "Total del producto: $" << Ordenes[i].Total << endl;
		}
	}
	Listas.close();
}

//Definicion de la funcion para Borrar Ordenes
int BorrarO()
{
	int opcO, opcB;
	do{
		opcO = 0;
	cout << "Que numero de orden desea borrar: ";
	cin >> opcO;
		opcB = opcO - 1;
		for (int i = 0; i < NumO; i++)
		{
			if (opcB == i)
			{
				Ordenes[i].Contador = 0;
				cout << "Orden Borrada exisosamente" << endl;
				opcO = 0;
			}
		}
		if(opcO!=0)
		cout << "No se encontro el numero de orden vuelva a intentarlo" << endl;
	} while (opcO != 0);
	cout << "\nDesea regresar al Menu?(Responda con 1 para regresar,2 para seguir borrando):  ";
	cin >> Opc2;
	system("cls");
	if (Opc2 == 1)
	{
		return main();
	}
	else
		BorrarO();
}

//Definicion de la validacion del codigo
string ValidarCod(string valor) {
	string cad = "";
	bool CodValid = 0;
	int cont = 0;

	do {
		cad = "";
		cont = 0;
		for (int i = 0; i < valor.length(); i++)
			if (isdigit(valor[i])) {
				cad += valor[i];
				cont+=1;
			}
		if (cont == 3) {
			cad = cad.substr(0, 3);
			for (int i = 0; i < 100; i++)
					CodValid = 1;
		}

		if (CodValid == 0) {
			cout << "\n¡Entrada invalida! \n(Requiere 3 numeros.)\tReintentar: ";
			getline(cin, valor);
		}
	} while (CodValid == 0);
	return cad;
}
