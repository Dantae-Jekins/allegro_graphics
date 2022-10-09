#include <allegro5/system.h>
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h> 
#include <iostream> 
//! stdio para o que permanece no código
//! iostream apenas para testes (iostream não é performático)

#include "../3D/Base.h"
#include "../3D/Point.h"
#include "../3D/Vector.h"

#define WIN_HEIGHT 480
#define WIN_WIDTH 720
#define FPS 60.0
#define ERR(a) printf("ERRO : %s", a); success = false

int main()
{
	/// SETUP


	// variáveis -------------------------------------
	struct
	{
		bool running = true;
		bool paused = false;
	} program;

	
	/// estruturas -----------------------------------




	/// estruturas allegro --------------------------
	ALLEGRO_DISPLAY* display = 0;
	ALLEGRO_EVENT_QUEUE* queue = 0;
	ALLEGRO_TIMER* timer = 0;
	
	/// Área de código teste ou de setup --------------
	/// -----------------------------------------------


	/// -----------------------------------------------
	/// prepara o allegro -----------------------------
	bool success = true; // para não renderizar 
	if (success == false)
		goto libmem;

	if (!al_init())
	{
		ERR("al_init");
	}

	if (!al_install_keyboard())
	{
		ERR("al_install_keyboard");
	}

	if (!al_install_mouse())
	{
		ERR("al_install_mouse");
	}

	if (!al_init_primitives_addon())
	{
		ERR("al_init_primitives_addon");
	}
	
	if (success == false)
		goto libmem;

	/// prepara as estruturas allegro -----------------
	display = al_create_display(WIN_WIDTH, WIN_HEIGHT);
	if (display == NULL)
	{
		ERR("al_create_display");
	}

	queue = al_create_event_queue();
	if (queue == NULL)
	{
		ERR("al_create_event");
	}

	timer = al_create_timer(1.0 / FPS);
	if (timer == NULL)
	{
		ERR("al_create_timer");
	}

	if (success == false)
		goto libmem;



	/// registramos eventos ---------------------------
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));



	/// game loop -------------------------------------
	al_start_timer(timer);
	while (program.running)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(queue, &evento);
		if (evento.display.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			program.running = false;
		}
		else
		{

			if (evento.timer.type == ALLEGRO_EVENT_TIMER)
			{
				if (!program.paused)
				{
					// move();
				}

				// render();
		
				// update();

				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 20, 0));
			}
		}

	}


	// removemos os registros dos eventos
	if (queue)
	{
		if (timer)
			al_unregister_event_source(queue, al_get_timer_event_source(timer));

		if (display)
			al_unregister_event_source(queue, al_get_display_event_source(display));
	}

	
	// libera memória
libmem:
	if (display)
		al_destroy_display(display);
	if (timer)
		al_destroy_timer(timer);
	if (queue)
		al_destroy_event_queue(queue);

	int x; std::cin >> x;
	return 0;
}