//TORRES DE HANOI
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAMMAX 10
#define true 1
#define false 0
using namespace std;


typedef struct
{
	char torreA[TAMMAX];
	int tope;
} tipo_pila;

void inicializa(tipo_pila &A,tipo_pila &B,tipo_pila &C)
{
	for(int i=0;i<TAMMAX;i++)
	{
		A.torreA[i]='|';
		B.torreA[i]='|';
		C.torreA[i]='|';
	}
	A.tope = -1;
	B.tope = -1;
	C.tope = -1;
}


void inicializaOrigen(tipo_pila &torre,tipo_pila &ganadora,int discos)
{
	int posiciones[TAMMAX],validado=0,posR;
	bool revisar = false;
	char discosA[TAMMAX] = {'0','1','2','3','4','5','6','7','8','9'};
	
	for(int i=0,d=discos-1;i<discos;i++,d--)
	{
		torre.torreA[i]= discosA[d];
	}
	for(int i=0;i<TAMMAX;i++)
	{
		ganadora.torreA[i] = torre.torreA[i];
	}
	
	torre.tope = discos-1;
		
}

bool vacia(tipo_pila &torre)
{
	if(torre.tope==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool llena(tipo_pila &torre)
{
	if(torre.tope==TAMMAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(tipo_pila *torre,char dato)
{
	if(llena(*torre))
	{
		cout<<"\nTorre llena no puede hacer mas movimientos";
		return;
	}
	else
	{
		torre->tope = torre->tope +1;
		torre->torreA[torre->tope] = dato; 
	}
}

char pop(tipo_pila *torre)
{
	char disco;
	
	if(vacia(*torre))
	{
		cout<<"\nTorre vacia no puede hacer mas movimientos";
		return 'N';
	}
	else
	{
		disco = torre->torreA[torre->tope];
		torre->torreA[torre->tope]= '|';
		torre->tope = torre->tope - 1;
		return disco; 
	}
}

void imprime(tipo_pila &torreO,tipo_pila &torreA,tipo_pila &torreD)
{
	for(int i=TAMMAX-1;i>=0;i--)
	{
		cout<<"\n" << torreO.torreA[i]<<"\t\t"<<torreA.torreA[i]<<"\t\t"<<torreD.torreA[i];
	}
	cout<<"\n_\t\t_\t\t_";
	cout<<"\nA\t\tB\t\tC";
	cout<<"\n\n*****************************";
}




bool ganar(tipo_pila C,tipo_pila G)
{
	for(int i = 0;i<TAMMAX;i++)
	{
		if(C.torreA[i]!=G.torreA[i])
		{
			return false;
		}
	}
	
	return true;
	
}

int movimientoValido(tipo_pila *O, tipo_pila *D,char Destino)
{
	char disco;
	if(vacia(*O))
	{
		cout<<"\nINVALIDO ORIGEN VACIO";
		return 0;
	}
		
	else if(O->torreA[O->tope]> D->torreA[D->tope]&&D->tope!=-1)
	{
		cout<<"\nINVALIDO ORIGEN" <<O->torreA[O->tope-1]<<" MAYOR A DESTINO "<< D->torreA[D->tope-1];
		return 0;
	}
	else
	{
		cout<<"\nVALIDO";
		disco = pop(O);
		if(disco!='N')
		{
			cout<<"\nDisco:" <<disco<<" pasa a torre "<<Destino;
			push(D,disco);
		}
		return 1;
	}
}

void iniciar(int modo)
{
	int op,movimientos=0;
	
	tipo_pila A,B,C,G;
	srand (time(NULL));
	inicializa(A,B,C);
	inicializaOrigen(A,G,modo);
	imprime(A,B,C);
	do
	{
		cout<<"\n\t P A R T I D A";
		cout<<"\n1.Mover de A a B";
		cout<<"\n2.Mover de A a C";
		cout<<"\n3.Mover de B a A";
		cout<<"\n4.Mover de B a C";
		cout<<"\n5.Mover de C a A";
		cout<<"\n6.Mover de C a B";
		cout<<"\n7.Regresar";
		cout<<"\nOpcion:";
		cin>>op;
		
		switch(op)
		{
			case 1:			
				movimientos = movimientos + movimientoValido(&A,&B,'B');		
			break;
			case 2:			
				movimientos = movimientos +movimientoValido(&A,&C,'C');			
			break;
			case 3:		
				movimientos = movimientos +movimientoValido(&B,&A,'A');			
			break;
			case 4:	
				movimientos = movimientos +movimientoValido(&B,&C,'C');				
			break;
			case 5:		
				movimientos = movimientos +movimientoValido(&C,&A,'A');				
			break;
			case 6:		
				movimientos = movimientos +movimientoValido(&C,&B,'B');				
			break;
			case 7:			
				return;				
			break;
			default:			
				cout<<"\nInvalido vuelva a elegir";			
			break;

		}
		imprime(A,B,C);
		
	}while(ganar(C,G)!=true);
	
	cout<<"\n\t G A N A S T E";
	cout<<"\n MODO:"<<modo<<" Discos";
	cout<<"\n MOVIMIENTOS: "<<movimientos;

}

void juego()
{
	int op;
	int modo[4] = {0,3,5,10};
	do
	{
		cout<<"\n\t M E N U  J U E G O";
		cout<<"\n1.Nivel facil(3 discos)";
		cout<<"\n2.Nivel medio(5 discos)";
		cout<<"\n3.Nivel dificil(10 discos)";
		cout<<"\n4.Regresar";
		cout<<"\nOpcion:";
		cin>>op;
		if(op==1||op==2||op==3)
		{
			iniciar(modo[op]);
		}
		
	}while(op!=4);
}

void instrucciones()
{
	cout<<"\n\tT O R R E S  D E  H A N O I";
	cout<<"\n\nInstrucciones:";
	cout<<"\n\nEl usuario debe cambiar los discos del A (origen) al B(auxiliar) o C(destino)\n si el disco que quiere cambiar es mas grande que el anterior entonces no podra hacerlo. ";
	cout<<"\n\nSi elige A entonces debera elegir el destino, por ejemplo lo mueve a torre C";
	cout<<"\n\nY asi sucesivamente lo que el usuario elija hasta que las pilas esten acomodadas en el destino de la misma forma que en el origen.";
	
}


int main()
{
	int op;
	do
	{
		cout<<"\n****************************************";
		cout<<"\n\t M E N U";
		cout<<"\n1.Iniciar Juego";
		cout<<"\n2.Instrucciones";
		cout<<"\n3.Salir";
		cout<<"\nOpcion:";
		cin>>op;
		if(op==1)
		{
			juego();
		}
		else if(op==2)
		{
			instrucciones();
		}
		else
		{
			cout<<"HASTA PRONTO!!";
		}

	}while(op!=3);
	return 0;
}
