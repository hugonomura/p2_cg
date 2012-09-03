#include <stdlib.h>

#include "cg2dHugo.h"

int main(){
	// define dois pontos arbitrarios
	point *p1, *p2;
	bufferdevice * dispositivo;
	palette * palheta;
	window * janela;

	SetWorld(0, 30, 0, 30); // Define o tamanho do mundo  
	dispositivo = CreateBuffer(640,480); // cria um dispositivo

	palheta = CreatePalette(6);  
	SetColor(0,0,0,palheta);
	SetColor(1,0,0,palheta);
	SetColor(0,1,0,palheta);
	SetColor(0,0,1,palheta);
	SetColor(1,1,1,palheta);
	
	p1 = SetPoint(5, 5, 1);
	p2 = SetPoint(10,4, 1);

	janela = CreateWindow(0, 10, 0, 10);
	DrawLine(p1, p2, janela, dispositivo, 1);

	DumpX(dispositivo, palheta);

	return 0;
}
