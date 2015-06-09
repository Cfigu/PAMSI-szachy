#include <allegro.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void allegro_start()
{
  allegro_init();
  install_keyboard();
  set_color_depth( 16 );
  set_gfx_mode( GFX_AUTODETECT_WINDOWED, 400, 400, 0, 0 );
  clear_to_color( screen, makecol( 128, 128, 128 ) );
  
  install_mouse();
  show_mouse( screen );
  unscare_mouse();
}



BITMAP * pion = NULL;
BITMAP * goniec = NULL;
BITMAP * wieza = NULL;
BITMAP * skoczek = NULL;
BITMAP * krol = NULL;
BITMAP * dama = NULL;

BITMAP * pion_c = NULL;
BITMAP * goniec_c = NULL;
BITMAP * wieza_c = NULL;
BITMAP * skoczek_c = NULL;
BITMAP * krol_c = NULL;
BITMAP * dama_c = NULL;

BITMAP * puste =NULL;
BITMAP * puste_b =NULL;




char Field(char Board[][8], int a, int b)
{
  return Board[a][b];
}

int X()
{
  int poz_x;
  if(mouse_x>0 && mouse_x<=50)
    poz_x = 0;
  else if(mouse_x>50 && mouse_x<=100)
    poz_x = 50;
  else if(mouse_x>100 && mouse_x<=150)
    poz_x = 100;
  else if(mouse_x>150 && mouse_x<=200)
    poz_x = 150;
  else if(mouse_x>200 && mouse_x<=250)
    poz_x = 200;
  else if(mouse_x>250 && mouse_x<=300)
    poz_x = 250;
  else if(mouse_x>300 && mouse_x<=350)
    poz_x = 300;
  else if(mouse_x>350 && mouse_x<=400)
    poz_x = 350;

  return poz_x;
}

int Y()
{
  int poz_y;

   if(mouse_y>0 && mouse_y<=50)
     poz_y = 0;
   else if(mouse_y>50 && mouse_y<=100)
     poz_y = 50;
   else if(mouse_y>100 && mouse_y<=150)
     poz_y = 100;
   else if(mouse_y>150 && mouse_y<=200)
     poz_y = 150;
   else if(mouse_y>200 && mouse_y<=250)
     poz_y = 200;
   else if(mouse_y>250 && mouse_y<=300)
     poz_y = 250;
   else if(mouse_y>300 && mouse_y<=350)
     poz_y = 300;
   else if(mouse_y>350 && mouse_y<=400)
     poz_y = 350;
   
   return poz_y;
}
  
void Empty(int a, int b)
{  
  int k = ((a+b)/50)%2;

  if(k==0)
    {
      scare_mouse();
      blit( puste, screen, 0, 0, a, b, puste->w, puste->h );
      unscare_mouse();
    }
  else
    {
      scare_mouse();
      blit( puste_b, screen, 0, 0, a, b, puste_b->w, puste_b->h );
      unscare_mouse();
    }
      
}

void BoardMove(char f,int pom_x, int pom_y)
{
  BITMAP * pom;

  int good =1;
  
  if(f=='P')
    pom = pion;
  if(f=='R')
    pom=wieza;
  if(f=='K')
    pom=skoczek;
  if(f=='B')
    pom=goniec;
  if(f=='Q')
    pom=dama;
  if(f=='A')
    pom=krol;

  if(f=='p')
    pom = pion_c;
  if(f=='r')
    pom=wieza_c;
  if(f=='k')
    pom=skoczek_c;
  if(f=='b')
    pom=goniec_c;
  if(f=='q')
    pom=dama_c;
  if(f=='a')
    pom=krol_c;

  if(f==' ')
    good=0;

    if(good ==1)
      {
	scare_mouse();  
	blit( pom, screen, 0, 0, pom_x, pom_y, pom->w, pom->h );
	unscare_mouse();
      }
	
}

int main()
{
 
  allegro_start();

  int poz_x; //wybor pola
  int poz_y; //wybor pola
  char f;
  int pom_x;
  int pom_y;
  
    
  char Board[][8] = {
    //	  a    b    c    d    e    f    g    h
    {'r', 'k', 'b', 'q', 'a', 'b', 'k', 'r'}, // 8
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // 7
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 4
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 3
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // 2
    {'R', 'K', 'B', 'Q', 'A', 'B', 'K', 'R'}};// 1

  

  //PUSTE ZOLTE//
  puste = create_bitmap( 50, 50 );
  clear_to_color( puste, makecol( 255, 255, 0 ) );
 
  blit( puste, screen, 0, 0, 0, 100, puste->w, puste->h );
  blit( puste, screen, 0, 0, 100, 100, puste->w, puste->h );
  blit( puste, screen, 0, 0, 200, 100, puste->w, puste->h );
  blit( puste, screen, 0, 0, 300, 100, puste->w, puste->h );

  blit( puste, screen, 0, 0, 50, 150, puste->w, puste->h );
  blit( puste, screen, 0, 0, 150, 150, puste->w, puste->h );
  blit( puste, screen, 0, 0, 250, 150, puste->w, puste->h );
  blit( puste, screen, 0, 0, 350, 150, puste->w, puste->h );

  blit( puste, screen, 0, 0, 0, 200, puste->w, puste->h );
  blit( puste, screen, 0, 0, 100, 200, puste->w, puste->h );
  blit( puste, screen, 0, 0, 200, 200, puste->w, puste->h );
  blit( puste, screen, 0, 0, 300, 200, puste->w, puste->h );

  blit( puste, screen, 0, 0, 50, 250, puste->w, puste->h );
  blit( puste, screen, 0, 0, 150, 250, puste->w, puste->h );
  blit( puste, screen, 0, 0, 250, 250, puste->w, puste->h );
  blit( puste, screen, 0, 0, 350, 250, puste->w, puste->h );



  //PUSTE BRAZOWE//
  puste_b = create_bitmap( 50, 50 );
 
  clear_to_color( puste_b, makecol( 150, 75, 0 ) );

  blit( puste_b, screen, 0, 0, 50, 100, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 150, 100, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 250, 100, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 350, 100, puste_b->w, puste_b->h );

  blit( puste_b, screen, 0, 0, 0, 150, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 100, 150, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 200, 150, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 300, 150, puste_b->w, puste_b->h );

  blit( puste_b, screen, 0, 0, 50, 200, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 150, 200, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 250, 200, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 350, 200, puste_b->w, puste_b->h );

  blit( puste_b, screen, 0, 0, 0, 250, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 100, 250, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 200, 250, puste_b->w, puste_b->h );
  blit( puste_b, screen, 0, 0, 300, 250, puste_b->w, puste_b->h );


  //PION BIALY//
  pion = create_bitmap( 50, 50 );
 
  clear_to_color( pion, makecol( 255, 255, 255 ) );
  textout_ex( pion, font, "P", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( pion, screen, 0, 0, 0, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 50, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 100, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 150, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 200, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 250, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 300, 300, pion->w, pion->h );
  blit( pion, screen, 0, 0, 350, 300, pion->w, pion->h );
 
  

  //GONIEC BIALY//
  goniec = create_bitmap( 50, 50 );

  clear_to_color( goniec, makecol( 255, 255, 255 ) );
  textout_ex( goniec, font, "G", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( goniec, screen, 0, 0, 100, 350, goniec->w, goniec->h );
  blit( goniec, screen, 0, 0, 250, 350, goniec->w, goniec->h );


  //WIEZA BIALA//
  wieza = create_bitmap( 50, 50 );
  
  clear_to_color( wieza, makecol( 255, 255, 255 ) );
  textout_ex( wieza, font, "W", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( wieza, screen, 0, 0, 350, 350, wieza->w, wieza->h );
  blit( wieza, screen, 0, 0, 0, 350, wieza->w, wieza->h );

  
  //SKOCZEk BIALY//
  skoczek = create_bitmap( 50, 50 );

  clear_to_color( skoczek, makecol( 255, 255, 255 ) );
  textout_ex( skoczek, font, "S", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( skoczek, screen, 0, 0, 50, 350, skoczek->w, skoczek->h );
  blit( skoczek, screen, 0, 0, 300, 350, skoczek->w, skoczek->h );


  //KROL BIALY//
  krol = create_bitmap( 50, 50 );

  clear_to_color( krol, makecol( 255, 255, 255 ) );
  textout_ex( krol, font, "K", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( krol, screen, 0, 0, 200, 350, krol->w, krol->h );


  //DAMA BIALA//
  dama = create_bitmap( 50, 50 );
 
  clear_to_color( dama, makecol( 255, 255, 255 ) );
  textout_ex( dama, font, "D", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( dama, screen, 0, 0, 150, 350, dama->w, dama->h );

  //KONIEC BIALYCH//





  //CZARNE//




  //PION CZARNY//
  pion_c = create_bitmap( 50, 50 );
  
  clear_to_color( pion_c, makecol( 0, 0, 0 ) );
  textout_ex( pion_c, font, "P", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( pion_c, screen, 0, 0, 0, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 50, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 100, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 150, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 200, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 250, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 300, 50, pion_c->w, pion_c->h );
  blit( pion_c, screen, 0, 0, 350, 50, pion_c->w, pion_c->h );

  //GONIEC CZARNY//
  goniec_c = create_bitmap( 50, 50 );

  clear_to_color( goniec_c, makecol( 0, 0, 0 ) );
  textout_ex( goniec_c, font, "G", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( goniec_c, screen, 0, 0, 100, 0, goniec_c->w, goniec_c->h );
  blit( goniec_c, screen, 0, 0, 250, 0, goniec_c->w, goniec_c->h );


  //WIEZA CZARNA//
  wieza_c = create_bitmap( 50, 50 );
 
  clear_to_color( wieza_c, makecol( 0, 0, 0 ) );
  textout_ex( wieza_c, font, "W", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( wieza_c, screen, 0, 0, 350, 0, wieza_c->w, wieza_c->h );
  blit( wieza_c, screen, 0, 0, 0, 0, wieza_c->w, wieza_c->h );


  //SKOCZEK CZARNY//
  skoczek_c = create_bitmap( 50, 50 );

  clear_to_color( skoczek_c, makecol( 0, 0, 0 ) );
  textout_ex( skoczek_c, font, "S", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( skoczek_c, screen, 0, 0, 50, 0, skoczek_c->w, skoczek_c->h );
  blit( skoczek_c, screen, 0, 0, 300, 0, skoczek_c->w, skoczek_c->h );


  //KROL CZARNY//
  krol_c = create_bitmap( 50, 50 );

  clear_to_color( krol_c, makecol( 0, 0, 0 ) );
  textout_ex( krol_c, font, "K", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( krol_c, screen, 0, 0, 200, 0, krol_c->w, krol_c->h );


  //DAMA CZARNA//
  dama_c = create_bitmap( 50, 50 );
 
  clear_to_color( dama_c, makecol( 0, 0, 0 ) );
  textout_ex( dama_c, font, "D", 22, 20, makecol( 255, 255, 255 ), - 1 );
  blit( dama_c, screen, 0, 0, 150, 0, dama_c->w, dama_c->h );






  while( !key[ KEY_ESC ])
    {
      if(mouse_b&1)
	{	  
	  poz_x = X();
	  poz_y = Y();
	  
	  poz_x = poz_x/50;
	  poz_y = poz_y/50;
	  
	  f = Field(Board, poz_y, poz_x);
	}
      
      if(mouse_b&2)
	{
	  pom_x = X();
	  pom_y = Y();
	  
	  BoardMove(f,pom_x,pom_y);
	  Empty(poz_x*50,poz_y*50);
	}
    }
  
      
      
  
  clear_keybuf();
  destroy_bitmap( pion );

  
  allegro_exit();
  return 0;
}
END_OF_MAIN();
