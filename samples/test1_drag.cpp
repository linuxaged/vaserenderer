/*config.h is generated by fltk in your system
 * this file is used with fltk 1.3 with gl enabled.
 * compile by: fltk-config --use-gl --compile test1_drag.cpp
 * or something like: g++ -lX11 -lGL 'test1_drag.cpp' -o 'test1_drag'
*/
#include <math.h>
#include <stdio.h>

#include "config.h" //config.h must always be placed before any Fl header
#include <FL/gl.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Radio_Light_Button.H>

struct Vec2 { double x,y;};
struct Color { float r,g,b,a;};
#include "../include/vase_renderer_draft1_2.cpp"

void test_draw();
#include "test1_base.cpp"

const int buf_size=20;

Vec2 AP[buf_size]; int size_of_AP=0;
Color AC[buf_size];
double Aw[buf_size];

Fl_Window* main_wnd;
Gl_Window* gl_wnd;
Fl_Slider *weight, *feathering;
Fl_Button *feather, *no_feather_at_cap, *no_feather_at_core;
Fl_Button *jt_miter, *jt_bevel, *jt_round;
Fl_Button *np2, *np3, *np4, *np5, *np6;
Fl_Button *colored, *alphaed, *weighted;
//anchor only//Fl_Button *inward_first, *cap_first, *cap_last;

void line_update()
{
	Color cc[3];
	Color grey = {.4,.4,.4, 1};
	
	{ Color col={1 , 0, 0, 1}; cc[0]=col;}
	{ Color col={.8,.8, 0, 1}; cc[1]=col;}
	{ Color col={ 0, 0, 1, 1}; cc[2]=col;}
	
	for ( int i=0; i<size_of_AP; i++)
	{
		if ( colored->value())
			AC[i] = cc[i%3];
		else
			AC[i] = grey;
		
		if ( alphaed->value())
			AC[i].a = 0.5f;
		else
			AC[i].a = 1.0f;
			
		if ( weighted->value())
		{
			Aw[i] = weight->value() * (0.05 + double(i*2)/size_of_AP);
		}
		else
		{
			Aw[i] = weight->value();
		}
	}
}
void line_init( int N)
{
	switch (N)
	{
	case 2:
		AP[0].x=180; AP[0].y=270;
		AP[1].x=220; AP[1].y=30;
		size_of_AP = 2;
	break;
	
	case 3:
		AP[0].x=200; AP[0].y=100;
		AP[1].x=100; AP[1].y=200;
		AP[2].x=300; AP[2].y=200;
		size_of_AP = 3;
	break;
	
	case 4:
		AP[0].x=200; AP[0].y=50;
		AP[1].x=100; AP[1].y=150;
		AP[2].x=300; AP[2].y=150;
		AP[3].x=200; AP[3].y=250;
		size_of_AP = 4;
	break;
	
	case 5:
		AP[0].x=60; AP[0].y=250;
		AP[1].x=120; AP[1].y=50;
		AP[2].x=180; AP[2].y=250;
		AP[3].x=240; AP[3].y=50;
		AP[4].x=300; AP[4].y=250;
		size_of_AP = 5;
	break;
	
	case 6:
		AP[0].x=280; AP[0].y=110;
		AP[1].x=200; AP[1].y=50;
		AP[2].x=100; AP[2].y=150;
		AP[3].x=300; AP[3].y=150;
		AP[4].x=200; AP[4].y=250;
		AP[5].x=120; AP[5].y=190;
		size_of_AP = 6;
	break;
	}
	line_update();
	gl_wnd->set_drag_target( AP, size_of_AP); 
}
char get_joint_type()
{
	if ( jt_miter->value())
		return LJ_miter;
	else if ( jt_bevel->value())
		return LJ_bevel;
	else if ( jt_round->value())
		return LJ_round;
	else
		return 0;
}
void enable_glstates()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glDisableClientState(GL_EDGE_FLAG_ARRAY);
	glDisableClientState(GL_FOG_COORD_ARRAY);
	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_SECONDARY_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
void disable_glstates()
{
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
void np_cb(Fl_Widget* W, void*)
{
	int n=3;
	sscanf( W->label(), "%d", &n);
	line_init(n);
	gl_wnd->redraw();
}
void drag_cb(Fl_Widget* W, void*)
{
	gl_wnd->redraw();
}
void make_form()
{
	//weight and feathering
	weight = new Fl_Value_Slider(400,0,200,20,"weight");
	weight->type(FL_HOR_SLIDER);
	feathering = new Fl_Value_Slider(400,40,200,20,"feathering");
	feathering->type(FL_HOR_SLIDER);
	weight->bounds(0.01,20.0);
	feathering->bounds(1.0,10.0);
	weight->callback(drag_cb);
	feathering->callback(drag_cb);
	
	weight->value(8.0);
	feathering->value(1.0);
	
	//feather, no_feather_at_cap, no_feather_at_core
	feather		   = new Fl_Light_Button(400,80,100,15,"feather");
	no_feather_at_cap  = new Fl_Light_Button(450,95,150,15,"no_feather_at_cap");
	no_feather_at_core = new Fl_Light_Button(450,110,150,15,"no_feather_at_core");
	feather		  ->value(1);
	no_feather_at_cap ->value(0);
	no_feather_at_core->value(0);
	feather		  ->callback(drag_cb);
	no_feather_at_cap ->callback(drag_cb);
	no_feather_at_core->callback(drag_cb);
	
	//joint type
	{
	Fl_Group* o = new Fl_Group(400,130,200,100);
		new Fl_Box(400,130,80,15,"joint type:");
		jt_miter = new Fl_Radio_Light_Button(440,145,80,15,"miter");
		jt_bevel = new Fl_Radio_Light_Button(520,145,80,15,"bevel");
		jt_round = new Fl_Radio_Light_Button(440,160,80,15,"round");
	o->end();
	jt_miter->value(1);
	jt_bevel->value(0);
	jt_round->value(0);
	jt_miter->callback(drag_cb);
	jt_bevel->callback(drag_cb);
	jt_round->callback(drag_cb);
	}
	
	//number of points
	np2 = new Fl_Button(400,280,40,20,"2 pts");
	np2->callback(np_cb);
	np3 = new Fl_Button(450,280,20,20,"3");
	np3->callback(np_cb);
	np4 = new Fl_Button(470,280,20,20,"4");
	np4->callback(np_cb);
	np5 = new Fl_Button(490,280,20,20,"5");
	np5->callback(np_cb);
	np6 = new Fl_Button(510,280,20,20,"6");
	np6->callback(np_cb);
	
	//test options
	colored = new Fl_Light_Button(400,250,80,15,"colored");
	colored->callback(drag_cb);
	colored->value(1);
	alphaed = new Fl_Light_Button(480,250,80,15,"alpha-ed");
	alphaed->callback(drag_cb);
	alphaed->value(1);
	weighted = new Fl_Light_Button(420,265,80,15,"weighted");
	weighted->callback(drag_cb);
	
	//anchor only
	/*cap_first = new Fl_Light_Button(400,180,80,15,"cap_first");
	cap_last = new Fl_Light_Button(480,180,80,15,"cap_last");
	cap_first->callback(drag_cb);
	cap_last ->callback(drag_cb);
	cap_first->value(1);
	cap_last ->value(1);
	inward_first = new Fl_Light_Button(600-110,265,110,15,"inward first");
	inward_first->callback(drag_cb);
	*/
}
void test_draw()
{
	enable_glstates();
	
	line_update();
	
	polyline_opt opt={0};
	
	opt.feather    = feather->value();
	opt.feathering = feathering->value();
	opt.no_feather_at_cap = no_feather_at_cap->value();
	opt.no_feather_at_core = no_feather_at_core->value();
	opt.joint = get_joint_type();
	
	polyline( AP, AC, Aw, size_of_AP, &opt);
	
	/*{
	Color cc[3];
	cc[0].r=1.0f; cc[0].g=0.0f; cc[0].b=0.5f; cc[0].a=1.0f;
	cc[1].r=0.5f; cc[1].g=0.0f; cc[1].b=1.0f; cc[1].a=1.0f;
	cc[2].r=0.8f; cc[2].g=0.8f; cc[2].b=0.0f; cc[2].a=1.0f;
	vertex_array_holder tri;
	tri.set_gl_draw_mode(GL_TRIANGLES);
	for ( int i=0; i<10; i++)
	{
		tri.push( Point(10+i*30,200),cc[0]);
		tri.push( Point(25+i*30,100),cc[1]);
		tri.push( Point(40+i*30,200),cc[2]);
	}
	vah_knife_cut( tri, AP[0], AP[1], AP[2]);
	tri.draw();
	}*/
	
	disable_glstates();
}

int main(int argc, char **argv)
{
	vaserend_actual_PPI = 111.94;
	//
	main_wnd = new Fl_Window( 600,300,"test1 (fltk-opengl)");
		make_form(); //initialize
		gl_wnd = new Gl_Window( 0,0,400,300);  gl_wnd->end(); //create gl window
		line_init(4);
	main_wnd->end();
	main_wnd->show();
	main_wnd->redraw();
	
	return Fl::run();
}
