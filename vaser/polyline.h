#include "point.h"

namespace VASEr
{
	struct tessellator_opt
	{
		//set the whole structure to 0 will give default options
		bool triangulation;
		char parts; //use TS_xx
		bool tessellate_only;
		void* holder; //used as (VASErin::vertex_array_holder*) if tessellate_only is true
	};
	//for tessellator_opt.parts
	const char TS_core_fade = 0; //default
	const char TS_core = 1;
	const char TS_outer_fade = 2;
	const char TS_inner_fade = 3;

	struct polyline_opt
	{
		//set the whole structure to 0 will give default options
		const tessellator_opt* tess;
		char joint; //use PLJ_xx
		char cap;   //use PLC_xx
		bool feather;
		double feathering;
		bool no_feather_at_cap;
		bool no_feather_at_core;
	};
	//for polyline_opt.joint
	const char PLJ_miter =0; //default
	const char PLJ_bevel =1;
	const char PLJ_round =2;
	//for polyline_opt.cap
	const char PLC_butt  =0; //default
	const char PLC_round =1;
	const char PLC_square=2;
	const char PLC_rect  =3;
	const char PLC_both  =0; //default
	const char PLC_first =10;
	const char PLC_last  =20;
	const char PLC_none  =30;



	void polyline( const Vec2*, const Color*, const double*, int length, const polyline_opt*);
	void polyline( const Vec2*, Color, double W, int length, const polyline_opt*); //constant color and weight
	void polyline( const Vec2*, const Color*, double W, int length, const polyline_opt*); //constant weight
	void polyline( const Vec2*, Color, const double* W, int length, const polyline_opt*); //constant color
}

namespace VASErin
{
	struct polyline_inopt
	{
		bool const_color;
		bool const_weight;
		bool no_cap_first;
		bool no_cap_last;
		bool join_first;
		bool join_last;
		double* segment_length; //array of length of each segment
	};

	void polyline(
		const Vec2* PP,  //pointer to array of point of a polyline
		const Color* C,  //array of color
		const double* W, //array of weight
		int length, //size of the buffer P
		const VASEr::polyline_opt* options, //options
		const polyline_inopt* in_options); //internal options

}