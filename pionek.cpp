#include <allegro.h>

int main()
{
  allegro_init();
  install_keyboard();
  set_color_depth( 16 );
  set_gfx_mode( GFX_AUTODETECT_WINDOWED, 400, 400, 0, 0 );
  clear_to_color( screen, makecol( 128, 128, 128 ) );
  
  install_mouse();
  show_mouse( screen );
  unscare_mouse();
  

  int wyb_x=0; //wybor pola
  int wyb_y=0; //wybor pola
  int poz_x=0; //pozycja x figury
  int poz_y=0; //pozycja y figury
  int pom1=350;
  int pom2=300;
  /*
  int p1_x=1;
  int p1_y=7;
  int p2_x=2;
  int p2_y=7;
  int p3_x=3;
  int p3_y=7;
  int p4_x=4;
  int p4_y=7;
  int p5_x=5;
  int p5_y=7;
  int p6_x=6;
  int p6_y=7;
  int p7_x=7;
  int p7_y=7;
  int p8_x=8;
  int p8_y=7;
  */
  BITMAP * pion = NULL;
  BITMAP * goniec = NULL;
  BITMAP * wieza = NULL;
  BITMAP * skoczek = NULL;
  BITMAP * krol = NULL;
  BITMAP * dama = NULL;
  BITMAP * puste =NULL;
    
  //PUSTE//
  puste = create_bitmap( 50, 50 );
  if( !puste )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować puste !" );
      allegro_exit();
      return 0;
    }
  
  clear_to_color( puste, makecol( 128, 128, 128 ) );


  //PION//
  pion = create_bitmap( 50, 50 );
  if( !pion )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować piona !" );
      allegro_exit();
      return 0;
    }
  
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
 
  

  //GONIEC//
  goniec = create_bitmap( 50, 50 );
  if( !goniec )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować gonca !" );
      allegro_exit();
      return 0;
    }
  
  
  
  clear_to_color( goniec, makecol( 255, 255, 255 ) );
  textout_ex( goniec, font, "G", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( goniec, screen, 0, 0, 100, 350, goniec->w, goniec->h );
  blit( pion, screen, 0, 0, 250, 350, pion->w, pion->h );


  //WIEZA//
  wieza = create_bitmap( 50, 50 );
  if( !wieza )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować wieza !" );
      allegro_exit();
      return 0;
    }
  
  
  
  clear_to_color( wieza, makecol( 255, 255, 255 ) );
  textout_ex( wieza, font, "W", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( wieza, screen, 0, 0, 350, 350, wieza->w, wieza->h );
  blit( wieza, screen, 0, 0, 0, 350, wieza->w, wieza->h );

  
  //SKOCZEk//
  skoczek = create_bitmap( 50, 50 );
  if( !skoczek )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować skoczek !" );
      allegro_exit();
      return 0;
    }
  
  
  
  clear_to_color( skoczek, makecol( 255, 255, 255 ) );
  textout_ex( skoczek, font, "S", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( skoczek, screen, 0, 0, 50, 350, skoczek->w, skoczek->h );
  blit( skoczek, screen, 0, 0, 300, 350, skoczek->w, skoczek->h );


  //KROL//
  krol = create_bitmap( 50, 50 );
  if( !krol )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować krola !" );
      allegro_exit();
      return 0;
    }
  
  
  
  clear_to_color( krol, makecol( 255, 255, 255 ) );
  textout_ex( krol, font, "K", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( krol, screen, 0, 0, 150, 350, krol->w, krol->h );


  //DAMA//
  dama = create_bitmap( 50, 50 );
  if( !dama )
    {
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "nie mogę załadować damy !" );
      allegro_exit();
      return 0;
    }
  
  
  
  clear_to_color( dama, makecol( 255, 255, 255 ) );
  textout_ex( dama, font, "D", 22, 20, makecol( 0, 0, 0 ), - 1 );
  blit( dama, screen, 0, 0, 200, 350, dama->w, dama->h );






  while( !key[ KEY_ESC ] )
    {
      /*
      //WYBOR POLA//
      if(mouse_b ==1)
	{
	  if(mouse_x>0 && mouse_x<=50)
	    wyb_x = 1;
	  else if(mouse_x>50 && mouse_x<=100)
	    wyb_x = 2;
	  else if(mouse_x>100 && mouse_x<=150)
	    wyb_x = 3;
	  else if(mouse_x>150 && mouse_x<=200)
	    wyb_x = 4;
	  else if(mouse_x>200 && mouse_x<=250)
	    wyb_x = 5;
	  else if(mouse_x>250 && mouse_x<=300)
	    wyb_x = 6;
	  else if(mouse_x>300 && mouse_x<=350)
	    wyb_x = 7;
	  else if(mouse_x>350 && mouse_x<=400)
	    wyb_x = 8;
	  
	  
	  
	  if(mouse_y>0 && mouse_y<=50)
	    wyb_y = 1;
	  else if(mouse_y>50 && mouse_y<=100)
	    wyb_y = 2;
	  else if(mouse_y>100 && mouse_y<=150)
	    wyb_y = 3;
	  else if(mouse_y>150 && mouse_y<=200)
	    wyb_y = 4;
	  else if(mouse_y>200 && mouse_y<=250)
	    wyb_y = 5;
	  else if(mouse_y>250 && mouse_y<=300)
	    wyb_y = 6;
	  else if(mouse_y>300 && mouse_y<=350)
	    wyb_y = 7;
	  else if(mouse_y>350 && mouse_y<=400)
	    wyb_y = 8;
      
	}
      */
      //RUCH//
      if(mouse_b ==1)
	{
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
	  
	  
	  
	  blit( puste, screen, 0, 0, pom1, pom2, pion->w, pion->h );
	  scare_mouse();
	  blit( pion, screen, 0, 0, poz_x, poz_y, pion->w, pion->h );
	  unscare_mouse();
	  pom1=poz_x;
	  pom2=poz_y;
	}
      
      
      clear_keybuf();
    }
  
  destroy_bitmap( pion );

  
  allegro_exit();
  return 0;
}
END_OF_MAIN();
