// gcc -c cg2dBoi.c
// gcc p1_1-4.c -o p1_1 cg2dBoi.o -lm -lX11
#include "cg2dBoi.h"

int p1_1(int argc, char ** argv) {
  
  	palette * palheta;
  	bufferdevice * dispositivo;
  	bufferdevice * view1;
  	bufferdevice * view2;
  	bufferdevice * view3;
  	bufferdevice * view4;
  	window * janela;
  	object * poligono1, * poligono2, * poligono3;
  
  	SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  	palheta = CreatePalette(6);  
  	SetColor(0,0,0,palheta);
  	SetColor(1,0,0,palheta);
  	SetColor(0,1,0,palheta);
  	SetColor(0,0,1,palheta);
  	SetColor(1,1,1,palheta);
  
  	poligono1 = CreateObject(5);
  	poligono2 = CreateObject(4);
  
  	SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  	SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  	SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  	SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  	SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  	SetObject(SetPoint(-6.0,-2.0,3), poligono2);
  	SetObject(SetPoint(-1.0,-2.0,3), poligono2);
  	SetObject(SetPoint(-1.0,-6.0,3), poligono2);
  	SetObject(SetPoint(-6.0,-6.0,3), poligono2);
  
  	janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  	// janela = CreateWindow(-10.0,0.0,-10.0,0.0);  
  
  	DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  	DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  
  /* 
   * Dispositivo gráfico matricial.
   * A janela de visualização considerada não está adequada para visualizar completamente os dois objetos.
   * Poderiamos considerar a janela definida pelos pontos (-10,-10) e (0,0)
   */
  
  	DumpX(dispositivo,palheta);
  	//DumpOpenGL(argc,argv,dispositivo,palheta);
  
  	return 0;
}

int p1_2(int argc, char ** argv) {
  
  	palette * palheta;
  	bufferdevice * dispositivo;
  	window * janela;
  	object * poligono1, * poligono2, * poligono3;
  	ColorValues * rgb, * hsv;
  
  	SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  	palheta = CreatePalette(8);  
  	SetColor(0,0,0,palheta);
  	SetColor(1,0,0,palheta);
  	SetColor(0,1,0,palheta);
  	SetColor(0,0,1,palheta);
  	SetColor(1,1,1,palheta);
  
  	rgb = (ColorValues *) malloc(sizeof(ColorValues));
  	hsv = (ColorValues *) malloc(sizeof(ColorValues));
  
  	hsv->red = 261;
  	hsv->green = 0.87;
  	hsv->blue = 0.50;
  	rgb = HSV2RGB(hsv);  
  	SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  	hsv->red = 355;
  	hsv->green = 0.89;
  	hsv->blue = 0.43;
  	rgb = HSV2RGB(hsv);  
  	SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  	hsv->red = 129;
  	hsv->green = 0.70;
  	hsv->blue = 0.46;
  	rgb = HSV2RGB(hsv);  
  	SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  
  	poligono1 = CreateObject(5);
  	poligono2 = CreateObject(4);
  
  	SetObject(SetPoint(-9.0,-8.0,5), poligono1);
  	SetObject(SetPoint(-7.0,-3.0,5), poligono1);
  	SetObject(SetPoint(-4.0,-4.0,5), poligono1);
  	SetObject(SetPoint(-3.0,-6.0,5), poligono1);
  	SetObject(SetPoint(-6.0,-9.0,5), poligono1);
  
  	SetObject(SetPoint(-6.0,-2.0,6), poligono2);
  	SetObject(SetPoint(-1.0,-2.0,6), poligono2);
  	SetObject(SetPoint(-1.0,-6.0,6), poligono2);
  	SetObject(SetPoint(-6.0,-6.0,6), poligono2);
  
  	janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  	//janela = CreateWindow(-20.0,10.0,-20.0,15.0);
  
  	DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  	DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  
  	poligono3 = Rotate(poligono1,45);
  	poligono3 = ChangeColor(poligono3,7);
  	DrawObject(poligono3,janela,dispositivo); // desenha o poligono 3 dentro da janela no buffer do dispositivo
  
  /*
   * Junto com a operação de rotação temos uma translação.
   * Para verificar se os limites do mundo estão adequados para as operações do exercício
   * basta considerar uma janela do tamanho do mundo e verificar se todos os objetos
   * são desenhados corretamente. No caso, a resposta é sim, pois todos os pontos estão dentro do mundo.
   */
  
  	DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);
  
  	return 0;
}


int p1_3(int argc, char ** argv) {
  
  	palette * palheta;
  	bufferdevice * dispositivo;
  	window * janela;
  	object * poligono1, * poligono2, * poligono3;
  
  	SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  	palheta = CreatePalette(4);
  	SetColor(0,0,0,palheta);  
  	SetColor(1,0,0,palheta);
  	SetColor(0,0,1,palheta);
  	SetColor(1,1,0,palheta);
  
  	poligono1 = CreateObject(5);
  	poligono2 = CreateObject(4);
  
  	SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  	SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  	SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  	SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  	SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  	SetObject(SetPoint(-6.0,-2.0,2), poligono2);
  	SetObject(SetPoint(-1.0,-2.0,2), poligono2);
  	SetObject(SetPoint(-1.0,-6.0,2), poligono2);
  	SetObject(SetPoint(-6.0,-6.0,2), poligono2);
  
  	poligono1 = Translate(poligono1,5,5);        // centraliza em relação a origem do sistema
  	poligono2 = Translate(poligono2,5,5); 

  	poligono3 = Translate(poligono2,-1.5,-1.0);   
  	poligono3 = Rotate(poligono3,45);
  	poligono3 = Translate(poligono3,1.5,1.0);
  	poligono3 = ChangeColor(poligono3,3);
  
  	poligono1 = Scale(poligono1,0.4,0.4);
  	poligono2 = Scale(poligono2,0.4,0.4);
  	poligono3 = Scale(poligono3,0.4,0.4);
  
  	janela = CreateWindow(-2.0,2.0,-2.0,2.0); // define uma janela de visualização
  
  	DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  	DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  	DrawObject(poligono3,janela,dispositivo); // desenha o poligono 3 dentro da janela no buffer do dispositivo  
  
  /*
   * O sistema RGB é aditivo pois cada cor nesse modelo é representada por uma soma ponderada de três componentes
   * primárias (o vermelho, o verde e o azul).
   */
  
  	DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);
  
  	return 0;
}

int p1_4(int argc, char ** argv) {
  
  	palette * palheta;
  	bufferdevice * dispositivo;
  	window * janela;
  	object * poligono1, * poligono2, * poligono3;
  	ColorValues * rgb, * hsv;  
  
  	SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  	palheta = CreatePalette(4);  
  	SetColor(0,0,0,palheta);
  	SetColor(1,0,0,palheta);
  	SetColor(0,0,1,palheta);
  
  	rgb = (ColorValues *) malloc(sizeof(ColorValues));
  	hsv = (ColorValues *) malloc(sizeof(ColorValues));
  
  	hsv->red = 129;
  	hsv->green = 0.70;
  	hsv->blue = 0.46;
  	rgb = HSV2RGB(hsv);  
  	SetColor(rgb->red,rgb->green,rgb->blue,palheta);  
  
  	poligono1 = CreateObject(5);
  	poligono2 = CreateObject(4);
  	poligono3 = CreateObject(4);
  
  	SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  	SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  	SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  	SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  	SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  	SetObject(SetPoint(-6.0,-2.0,2), poligono2);
  	SetObject(SetPoint(-1.0,-2.0,2), poligono2);
  	SetObject(SetPoint(-1.0,-6.0,2), poligono2);
  	SetObject(SetPoint(-6.0,-6.0,2), poligono2);
  
  	SetObject(SetPoint(-6.0,-3.3,3), poligono3);
  	SetObject(SetPoint(-4.0,-4.0,3), poligono3);
  	SetObject(SetPoint(-3.0,-6.0,3), poligono3);
  	SetObject(SetPoint(-6.0,-6.0,3), poligono3);  

  	janela = CreateWindow(-10.0,0.0,-10.0,0.0); // define uma janela de visualização 
  
  	DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  	DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  
  	Fill(poligono3,janela,dispositivo,3); // preenche o poligono 3 

  	DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);  
  
  	return 0;
  
}

int main(int argc, char**argv){
//	p1_1(argc, argv);
//	p1_2(argc, argv);
//	p1_3(argc, argv);
	p1_4(argc, argv);
}
