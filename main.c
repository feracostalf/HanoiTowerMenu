#include <stdio.h>
#include <stdlib.h>

int menu();
int facit(int);
int facre(int);
void hanoi(int,char,char,char);
int fiboi(int);
int fibor(int);
int fit(int);
int fit_(int,int*);

int main(int argc, char *argv[]) {
	menu();
	return 0;
}

int menu(){
	int a,n;
	char origen='A';
	char auxiliar='B';
	char destino='C';
	printf("Menu\n1.-Factorial Iterativo\n2.-Factorial Recursivo\n3.-Serie Fibonacci Iterativo\n4.-Serie Fibonacci Recursivo\n5.-Serie Fibonacci Recursivo Tabular\n6.-Torres de Hanoi\n7.-Salir\n");
	scanf("%d",&a);
	system("cls");
	switch (a){
		case 1:
			printf("Factorial Iterativo\nNumero:");
			scanf("%d",&n);
			printf("Factorial de %d es: %d",n,facit(n));
		break;
		case 2:
			printf("Factorial Recursivo\nNumero:");
			scanf("%d",&n);
			printf("Factorial de %d es: %d",n,facre(n));		
		break;
		case 3:
			printf("Serie Fibonacci Iterativo\nPosicion:");
			scanf("%d",&n);
			printf("En la posicion %d esta el numero: %d",n,fiboi(n));	
		break;
		case 4:
			printf("Serie Fibonacci Recursivo\nPosicion:");
			scanf("%d",&n);
			printf("En la posicion %d esta el numero: %d",n,fibor(n));	
		break;
		case 5:
			printf("Serie Fibonacci Recursivo Tabular\nNumero en la posicion:");
			scanf("%d",&n);
			printf("En la posicion %d esta el numero: %d",n,fit(n));
		break;
		case 6:
			printf("Torres de Hanoi\nNumero de discos:");
			scanf("%d",&n);
			hanoi(n,origen,auxiliar,destino);		
		break;
		case 7:
			exit(0);
		break;
	}
}

int facit(int n){
	int f=1;
	if(n==0||n==1||n==2){
		return n;
	}
	while(n!=1){
		f*=n--;
	}
	return f;
}

int facre(int n){
	if(n==0||n==1||n==2){
		return n;
	}
	return (n*facre(n-1));
}

int fiboi(int n){
	int a=0,b=1,c,i;
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		return 1;
	}
	for(i=1; i<n; i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int fibor(int n){
	if(n>2){
		return fibor(n-1)+fibor(n-2);	
	}
	else{
		if(n==0){
			return 0;
		}
		if(n==1||n==2){
			return 1;
		}
	}
}

int fit(int n){
	int R[n+1];
	int i;
	R[0]=0;
	R[1]=1;
	for(i=2; i<=n; i++){
		R[i]=-1;
	}
	return fit_(n,&R[0]);
}

int fit_(int n, int*A){
	if(n==0||n==1){
		return n;
	}
	if(A[n]>-1){
		return A[n];
	}
	A[n-1]=fit_(n-1,A);
	return fit_(n-2,A)+A[n-1];
}

void hanoi(int n,char O,char A, char D){
	if(n==1){
		printf("\nMover el disco %d de %c a %c",n,O,D);
	}
	else{
		hanoi(n-1,O,D,A);
		printf("\nMover disco %d de %c a %c",n,O,D);
		hanoi(n-1,A,O,D);
	}
}

