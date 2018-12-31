#ifndef VASER_H
#define VASER_H
/* Vase Renderer first draft, version 0.3 */

/* Basic usage
* You should provide these structs before any vase_renderer include, using
struct Vec2 { double x,y;};
struct Color { float r,g,b,a;};
* or
typedef your_vec2 Vec2;
typedef your_color Color;
*/

#include "polyline.h"

namespace VASEr
{
const double vaser_pi=3.141592653589793;

struct gradient_stop
{
	double t; //position
	char type; //GS_xx
	union
	{
		Color color;
		double weight;
	};
};
	const char GS_none  =0;
	const char GS_rgba  =1;
	const char GS_rgb   =2; //rgb only
	const char GS_alpha =3;
	const char GS_weight=4;
struct gradient
{
	gradient_stop* stops; //array must be sorted in ascending order of t
	int length; //number of stops
	char unit; //use_GD_XX
};
	const char GD_ratio =0; //default
	const char GD_length=1;

struct Image
{
	unsigned char* buf; //must **free** buffer manually
	short width;
	short height;
};

class renderer
{
public:
	static void init();
	static void before();
	static void after();
	static Image get_image();
};




void segment( Vec2, Vec2, Color, Color, double W1, double W2,  polyline_opt*);
void segment( Vec2, Vec2, Color, double W, const polyline_opt*); //constant color and weight
void segment( Vec2, Vec2, Color, Color, double W, const polyline_opt*); //constant weight
void segment( Vec2, Vec2, Color, double W1, double W2, const polyline_opt*); //const color

struct polybezier_opt
{
	//set the whole structure to 0 will give default options
	const polyline_opt* poly;
};

void polybezier( const Vec2*, const gradient*, int length, const polybezier_opt*);
void polybezier( const Vec2*, Color, double W, int length, const polybezier_opt*);

} //namespace VASEr

#endif
