/*
ApplicationApi.h
*/
#pragma once
#ifndef __API_H__
#define __API_H__


#ifdef _WINDOWS
#if defined(_LIBDLL)
#include <Library.h>
#define SDK_API _declspec(dllexport)
#else
#define SDK_API _declspec(dllimport)
#endif
#else
#if defined(_NOEXPORT)
#include <Library.h>
#endif
#define SDK_API
#endif

#ifdef _WIN32_WCE
typedef void (_cdecl *APPLICATION_HANDLEPROC)(int nEvent, void* pData);
#elif defined _WIN32
typedef void (_stdcall *APPLICATION_HANDLEPROC)(int nEvent, void* pData);
#else
typedef void (*APPLICATION_HANDLEPROC)(int nEvent, void* pData);

typedef int				BOOL;
typedef int				INT;
typedef unsigned long	DWORD;
typedef long			LONG;
typedef unsigned char	BYTE;
typedef char			CHAR;
typedef unsigned short	WORD;
typedef short			SHORT;
typedef double			DOUBLE;
typedef unsigned int	UINT;
typedef unsigned short	USHORT;
typedef void*			LPVOID;
typedef wchar_t			WCHAR;
typedef WCHAR			TCHAR;
typedef WCHAR			TCHAR;
typedef TCHAR*			LPTSTR;
typedef const TCHAR*	LPCTSTR;
typedef void*			HWND;

#ifndef MAXLONG
#define MAXLONG     ((LONG)0x7fffffff)
#endif
#ifndef             NULL
#define NULL        0
#endif
#ifndef TRUE
#define TRUE        1
#endif
#ifndef FALSE
#define FALSE       0
#endif

#endif


#define TRUCK_VERSION

#define DEFAULT_MAX_TIME				0

/*! \defgroup events ApplicationEvents
 * @{
 * \brief ApplicationEvents enum enumerates events that Drive can generate.\n
 */
/*! \brief Event occurs when application starts*/
#define EVENT_APP_STARTED				1010
/*! \brief Event occurs when application is terminated*/
#define EVENT_EXIT						1100
/*! \brief Event occurs when application is terminated*/
#define EVENT_APP_CLOSED				1100
/*! \brief Event occurs when user cancel the route.*/
#define EVENT_ROUTE_USERCANCEL			1101
/*! \brief Event occurs when a waypoint is visited.
 * The strData parameter will return the waypoint ID.
 */
#define EVENT_WAIPOINT_VISITED			1102
/*! \brief Event occurs when a waypoint is visited.
 * The strData parameter will return the waypoint ID.
 */
#define EVENT_WAYPOINT_VISITED			1102
/*! \brief Event occurs when user reaches route destination.*/
#define EVENT_ROUTE_FINISH				1103
/*! \brief Event occurs when new route is computed.*/
#define EVENT_ROUTE_COMPUTED			1105
/*! \brief Event occurs when optimization is finished.
 * The strData contains "0" if optimization was successful, other value otherwise.
 */
#define EVENT_OPTIMIZATION_FINISHED		1107
/*! \brief Event occurs when a route is recomputed.*/
#define EVENT_ROUTE_RECOMPUTE			1106

#define EVENT_ITINERARY_CHANGED			1108

#define EVENT_ITINERARY_WARNING			1109

/*! \brief Event occurs when navigation display the next instruction.*/
#define EVENT_NEXT_INSTRUCTION			1110

/*! \brief Event occurs when a invisible waypoint is visited.
 * The strData parameter will return the waypoint ID.
 */
#define EVENT_INVISIBLE_WAYPOINT_VISITED 1111

/*! \brief Event occurs when user click on the navigation window.*/
#define EVENT_MAIN_MENU					1150
/*! \brief Event occurs when user show context menu. Context menu is located at the bottom of the navigation screen.*/
#define EVENT_CONTEXT_MENU				1151
/*! \brief Event occurs when return to navigation from any menu*/
#define EVENT_EXIT_MENU					1152
/*! \brief Event occurs after user clicks on some custom button in the menu.
 * The strData parameter will return the command parameter (defined in menu.ini file) of this button.
 */
#define EVENT_CUSTOM_MENU				1153
/*! \brief Event occurs when user change language of Drive application.
 * The strData contains the name of the lang file, e.g. if user selects English in the menu, it returns "english.lang"
 */
#define EVENT_CHANGE_LANGUAGE			1160
/*! \brief Event occurs when user change screen orientation of Drive application.
 * The strData has the values "1", "2", "3" or "4", according to the screen rotation.
 */
#define EVENT_CHANGEORIENTATION			1161
/*! \brief Event occurs when a radar warning is invoked. The strData parameter has following format: "%d,%d".\n
 * First parameter is speed camera type (see \ref SpeedCameraType enum)\n
 * Second parameter is allowed speed (km / h)
 */
#define EVENT_RADAR_WARNING				1170
/*! \brief Event occurs when a poi warning is invoked. The strData parameter has following format: "%s,%s,{%d,%d}"\n
 * First parameter is category name (use \ref CApplicationAPI::GetPoiCategoryList "GetPoiCategoryList" function to get list of poi categories)\n
 * Second parameter is POI name\n
 * Third parameter is longitude\n
 * Fourth parameter is latitude
 */
#define EVENT_POI_WARNING				1171
/*! \brief Event occurs when a geofence interference is invoked. The strData parameter has following format: "%d,%d"\n
 * First parameter is geofence event type. 0 mean enter to the restricted area, 1 mean leave the restricted area./n
 * Second parameter is restricted area ID
 */
#define EVENT_GEOFENCE					1172
/*! \brief Event occurs when a restricted road interference is invoked.*/
#define EVENT_RESTRICTED_ROAD			1173
/*! \brief Event occurs when the border is crossed*/
#define EVENT_BORDER_CROSSING			1180
/*! \brief Event occurs when the speed limit is exceeded*/
#define EVENT_SPEED_EXCEEDING			1181
/*! \brief Event occurs when the speed limit is changed*/
#define EVENT_SPEED_LIMIT_CHANGED		1182
/*! \brief Event occurs when the user click on bitmap in browsemap*/
#define BITMAP_CLICK					1190
/*! \brief Event occurs when the user click on bitmap in browsemap*/
#define EVENT_BITMAP_CLICK				1190
/*! \brief Event occurs when the user click on POI in browsemap*/
#define EVENT_POI_CLICK					1191
/*! \brief Event occurs when you exit browsing map.*/
#define EVENT_BROWSE_MAP_EXIT			1194
/*! \brief Event occurs when application was closed by user.*/
#define EVENT_APP_ERROR					1200
/*! \brief Event occurs when application was closed by user.*/
#define EVENT_APP_EXIT					1200

#define EVENT_CALLBACK					2000 
/*! @}*/

/*! \file ApplicationApi.h*/
//////////////////////////////////////////////////////////////////////////
// Trip book
//////////////////////////////////////////////////////////////////////////

/*! \brief Trip book record data mode*/
typedef enum{
	/*! \brief No data mode*/
	tbdmNoData			= 1000,
	/*! \brief Full data mode*/
	tbdmFullData		= 1001,
	/*! \brief Full NMEA data mode*/
	tbdmFullNMEA		= 1002

} TripBookRecordDataMode;

///////////////////////////////////////////////////////
// NavigationParams
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
class NavigationParams
{
	private: void _doxygen_() { }
	/*! \brief NavigationParams enum enumerates possibilities of Drive behavior during route computing.*/
	public:
	enum _NavigationParams
	{
		//NpEnable						= 0x00000001,
		/*! \brief NpAskDeleteRoute commands Drive to ask user to delete computed route.\n\n
		 * Drive asks user to delete computed route before computing new route if some route is computed.
		 */
		NpAskDeleteRoute				= 0x00000002,
		/*! \brief NpMessageAvoidMotorwaysUnable commands Drive to notice user that not all motorways can be avoided.\n\n
		 * Drive shows message which notice user that not all motorways can be avoided if user wished to avoid them.
		 */
		NpMessageAvoidMotorwaysUnable	= 0x00000004,
		/*! \brief NpMessageAvoidTollRoadsUnable commands Drive to notice user that not all toll roads can be avoided.\n\n
		 * Drive shows message which notice user that not all toll roads can be avoided if user wished to avoid them.
		 */
		NpMessageAvoidTollRoadsUnable	= 0x00000008,
		/*! \brief NpMessageAvoidFerriesUnable commands Drive to notice user that not all ferries can be avoided.\n\n
		 * Drive shows message which notice user that not all ferries can be avoided if user wished to avoid them.
		 */
		NpMessageAvoidFerriesUnable		= 0x00000010,
		/*! \brief NpMessageRouteUnable commands Drive to notice user that route can not be computed.\n\n
		 * For example this could happen if start or destination point of route are out of loaded maps.
		 */
		NpMessageRouteUnable			= 0x00000020,
		/*! \brief NpMessageWaypointsDistant commands Drive to notice user that route can not be computed because of too big distance between start and destination points.\n\n
		 * For example if route is computed for walking.
		 */
		NpMessageWaypointsDistant		= 0x00000040,
	};
};

// TODO dokumentacia
class DialogId
{
public:
	enum _DialogId
	{
		DlgNavigateTo = 100,
		DlgRoute = 200,
		DlgSearch = 300
	};
};


///////////////////////////////////////////////////////
// poi
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
class PoiService
{
private: void _doxygen_() { }
	/*! \brief PoiService enum enumerates predefined POI categories.*/
public:
	enum _PoiService
	{
		/*! \brief Rent a car facility category*/
		Rent_a_Car_Facility				= 1,
		/*! \brief Tourist information office category*/
		Tourist_Information_Office		= 2,
		/*! \brief Museum category*/
		Museum							= 3,
		/*! \brief Theatre category*/
		Theatre							= 4,
		/*! \brief Cultural centre category*/
		Cultural_Centre					= 5,
		/*! \brief Sports centre category*/
		Sports_Centre					= 6,
		/*! \brief Hospital/polyclinic category*/
		Hospital_Polyclinic				= 7,
		/*! \brief Police station category*/
		Police_Station					= 8,
		/*! \brief City hall category*/
		City_Hall						= 9,
		/*! \brief Post office category*/
		Post_Office						= 10,
		/*! \brief First aid post category*/
		First_Aid_Post					= 11,
		/*! \brief Pharmacy category*/
		Pharmacy						= 12,
		/*! \brief Department store category*/
		Departement_Store				= 13,
		/*! \brief Bank category*/
		Bank							= 14,
		/*! \brief Travel agency category*/
		Travel_Agency					= 15,
		/*! \brief Public phone category*/
		Public_Phone					= 16,
		/*! \brief Warehouse category*/
		Warehouse						= 17,
		/*! \brief Ski lift station category*/
		Ski_Lift_Station				= 18,
		/*! \brief Zoo category*/
		Zoo								= 19,
		/*! \brief Scenic panoramic view category*/
		Scenic_Panoramic_View			= 20,
		/*! \brief Transport company category*/
		Transport_Company				= 21,
		/*! \brief Casino category*/
		Casino							= 22,
		/*! \brief Cinema category*/
		Cinema							= 23,
		/*! \brief Winery category*/
		Winery							= 24,
		/*! \brief Cargo centre category*/
		Cargo_Centre					= 25,
		/*! \brief Car shipping terminal category*/
		Car_Shipping_Terminal			= 26,
		/*! \brief Camping ground category*/
		Camping_Ground					= 28,
		/*! \brief Caravan site category*/
		Caravan_Site					= 29,
		/*! \brief Coach and lorry parking category*/
		Coach_and_Lorry_Parking			= 30,
		/*! \brief Community centre category*/
		Community_Centre				= 31,
		/*! \brief Embassy category*/
		Embassy							= 33,
		/*! \brief Frontier crossing category*/
		Frontier_Crossing				= 34,
		/*! \brief Motoring organization office category*/
		Motoring_Organization_Office	= 35,
		/*! \brief Recreation facility category*/
		Recreation_Facility				= 36,
		/*! \brief Road side diner category*/
		Road_Side_Diner					= 37,
		/*! \brief School category*/
		School							= 38,
		/*! \brief Shopping centre category*/
		Shopping_Centre					= 39,
		/*! \brief Stadium category*/
		Stadium							= 40,
		/*! \brief Toll category*/
		Toll							= 41,
		/*! \brief College university category*/
		College_University				= 42,
		/*! \brief Business facility category*/
		Business_Facility				= 43,
		/*! \brief Airport category*/
		Airport							= 44,
		/*! \brief Bus station category*/
		Bus_Station						= 45,
		/*! \brief Exhibition centre category*/
		Exhibition_Centre				= 46,
		/*! \brief Kindergarten category*/
		Kindergarten					= 47,
		/*! \brief Emergency call station category*/
		Emergency_Call_Station			= 48,
		/*! \brief Emergency medical service category*/
		Emergency_Medical_Service		= 49,
		/*! \brief Fire brigade category*/
		Fire_Brigade					= 50,
		/*! \brief Freeport category*/
		Freeport						= 51,
		/*! \brief Company category*/
		Company							= 52,
		/*! \brief ATM category*/
		ATM								= 53,
		/*! \brief Hippodrome category*/
		Hippodrome						= 54,
		/*! \brief Beach category*/
		Beach							= 55,
		/*! \brief Restaurant area category*/
		Restaurant_Area					= 56,
		/*! \brief Ice skating rink category*/
		Ice_Skating_Rink				= 57,
		/*! \brief Courthouse category*/
		Courthouse						= 58,
		/*! \brief Mountain peak category*/
		Mountain_Peak					= 59,
		/*! \brief Opera category*/
		Opera							= 60,
		/*! \brief Concert hall category*/
		Concert_Hall					= 61,
		/*! \brief Bovag garage category*/
		Bovag_Garage					= 62,
		/*! \brief Tennis court category*/
		Tennis_Court					= 63,
		/*! \brief Skating rink category*/
		Skating_Rink					= 64,
		/*! \brief Water sport category*/
		Water_Sport						= 65,
		/*! \brief Music centre category*/
		Music_Centre					= 66,
		/*! \brief Doctor category*/
		Doctor							= 67,
		/*! \brief Dentist category*/
		Dentist							= 68,
		/*! \brief Veterinarian category*/
		Veterinarian					= 69,
		/*! \brief Cafe pub category*/
		Cafe_Pub						= 70,
		/*! \brief Convention centre category*/
		Convention_Centre				= 71,
		/*! \brief Leisure centre category*/
		Leisure_Centre					= 72,
		/*! \brief Nightlife category*/
		Nightlife						= 73,
		/*! \brief Yacht basin category*/
		Yacht_Basin						= 74,
		/*! \brief Condominium category*/
		Condominium						= 75,
		/*! \brief Commercial building category*/
		Commercial_Building				= 76,
		/*! \brief Industrial building category*/
		Industrial_Building				= 77,
		/*! \brief Natives reservation category*/
		Natives_Reservation				= 78,
		/*! \brief Cemetery category*/
		Cemetery						= 79,
		/*! \brief Breakdown service category*/
		Breakdown_Service				= 81,
		/*! \brief Vehicle equipment provider category*/
		Vehicle_Equipment_Provider		= 82,
		/*! \brief Entertainment category*/
		Entertainment					= 83,
		/*! \brief Abbey category*/
		Abbey							= 84,
		/*! \brief Amusement park category*/
		Amusement_Park					= 85,
		/*! \brief Arts centre category*/
		Arts_Centre						= 86,
		/*! \brief Building footprint category*/
		Building_Footprint				= 87,
		/*! \brief Castle category*/
		Castle							= 88,
		/*! \brief Church category*/
		Church							= 89,
		/*! \brief Factory ground philips category*/
		Factory_Ground_Philips			= 90,
		/*! \brief Fortress category*/
		Fortress						= 91,
		/*! \brief Golf course category*/
		Golf_Course						= 92,
		/*! \brief Holiday area category*/
		Holiday_Area					= 93,
		/*! \brief Library category*/
		Library							= 94,
		/*! \brief Lighthouse category*/
		Lighthouse						= 95,
		/*! \brief Military cemetery category*/
		Military_Cemetery				= 96,
		/*! \brief Monastery category*/
		Monastery						= 97,
		/*! \brief Monument category*/
		Monument						= 98,
		/*! \brief Natural reserve category*/
		Natural_Reserve					= 99,
		/*! \brief Prison category*/
		Prison							= 100,
		/*! \brief Rocks category*/
		Rocks							= 101,
		/*! \brief Sports hall category*/
		Sports_Hall						= 102,
		/*! \brief State police office category*/
		State_Police_Office				= 103,
		/*! \brief Walking area category*/
		Walking_Area					= 104,
		/*! \brief Water mill category*/
		Water_Mill						= 105,
		/*! \brief Windmill category*/
		Windmill						= 106,
		/*! \brief Rent a car parking category*/
		Rent_a_Car_Parking				= 107,
		/*! \brief Car racetrack category*/
		Car_Racetrack					= 108,
		/*! \brief Mountain pass category*/
		Mountain_Pass					= 109,
		/*! \brief Swimming pool category*/
		Swimming_Pool					= 110,
		/*! \brief Government office category*/
		Government_Office				= 111,
		/*! \brief Parking garage category*/
		Parking_Garage					= 150,
		/*! \brief Place of worship category*/
		Place_of_Worship				= 151,
		/*! \brief Ferry terminal category*/
		Ferry_Terminal					= 152,
		/*! \brief Airline access category*/
		Airline_Access					= 153,
		/*! \brief Open parking area category*/
		Open_Parking_Area				= 154,
		/*! \brief Important tourist attraction category*/
		Important_Tourist_Attraction	= 155,
		/*! \brief Railway station category*/
		Railway_Station					= 156,
		/*! \brief Rest area category*/
		Rest_Area						= 157,
		/*! \brief Shop category*/
		Shop							= 158,
		/*! \brief Park and recreation area category*/
		Park_and_Recreation_Area		= 159,
		/*! \brief Forest area category*/
		Forest_Area						= 160,
		/*! \brief Military installation category*/
		Military_Installation			= 161,
		/*! \brief Public transport stop category*/
		Public_Transport_Stop			= 162,
		/*! \brief Car repair facility category*/
		Car_Repair_Facility				= 200,
		/*! \brief Petrol station category*/
		Petrol_Station					= 201,
		/*! \brief Hotel or motel category*/
		Hotel_or_Motel					= 202,
		/*! \brief Restaurant category*/
		Restaurant						= 203,
		/*! \brief Cash dispenser category*/
		Cash_Dispenser					= 204,
		/*! \brief Car dealer category*/
		Car_Dealer						= 205,
		/*! \brief User defined poi category*/
		USERDEFINE						= 255
	};
};

///////////////////////////////////////////////////////
// speed camera
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
class SpeedCameraType
{
private: void _doxygen_() { }
	/*! \brief Enumeration of Speed camera types*/
public:
	enum _SpeedCameraType
	{
		/*! \brief Fixed speed camera*/
		FixedSpeedCamera			= 1,
		/*! \brief Red light camera*/
		RedLightCamera				= 2,
		/*! \brief Semi mobile speed camera*/
		SemiMobileSpeedCamera		= 3,
		/*! \brief Fixed average speed camera*/
		FixedAverageSpeedCamera		= 4,
		/*! \brief Mobile speed camera*/
		MobileSpeedCamera			= 5,
		/*! \brief Fixed red light and speed camera*/
		FixedRedLightAndSpeedCamera	= 6,
		/*! \brief Mobile average speed camera*/
		MobileAverageSpeedCamera	= 7,
		/*! \brief Mobile red light camera*/
		MobileRedLightCamera		= 8
	};
};

////////////////////
// LONGPOSITION
////////////////////
/*! \brief LONGPOSITION structure determines location on map.\n
 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.
 */
extern "C" struct SDK_API LONGPOSITION
{
	/*! \brief LONGPOSITION::lX Field determines X coordinate (geographical longitude) of location in world degrees multiplied by 100 000.*/
	LONG lX;
	/*! \brief LONGPOSITION::lY Field determines Y coordinate (geographical latitude) of location in world degrees multiplied by 100 000.*/
	LONG lY;

	/*! \brief Constructor of LONGPOSITION.*/
	LONGPOSITION()
	{
		lX = 0;
		lY = 0;
	}

	/*! \brief Constructor of LONGPOSITION.
	 * \param x x determines X coordinate (geographical longitude) of location in world degrees multiplied by 100 000.
	 * \param y y determines Y coordinate (geographical latitude) of location in world degrees multiplied by 100 000.
	 */
	LONGPOSITION(LONG x, LONG y)
		: lX(x)
		, lY(y)
	{
	}

	BOOL operator == ( LONGPOSITION position ) const
	{
		return ( position.lX == lX && position.lY == lY );
	}

	BOOL operator != ( LONGPOSITION position ) const
	{
		return position.lX != lX || position.lY != lY;
	}
};
typedef LONGPOSITION  *LPLONGPOSITION;

////////////////////
// LONGRECT
////////////////////
/*! \brief LONGRECT struct bounds rectangle area on map.\n
 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.
 */
extern "C" struct SDK_API LONGRECT
{
	/* \brief Constructor of LONGRECT.*/
	LONGRECT()
	{
		lLeft		= MAXLONG;
		lTop		= 0;
		lRight		= 0;
		lBottom		= MAXLONG;
	}
	/*! \brief lLeft determines left border of rectangle (geographical longitude).*/
	LONG lLeft;
	/*! \brief lTop determines top border of rectangle (geographical latitude).*/
	LONG lTop;
	/*! \brief lRight determines right border of rectangle (geographical longitude).*/
	LONG lRight;
	/*! \brief lBottom determines top border of rectangle (geographical latitude).*/
	LONG lBottom;

	BOOL operator==(LONGRECT &l)
	{
		return (l.lLeft == lLeft && l.lTop == lTop && l.lRight == lRight && l.lBottom == lBottom );
	}
};
typedef LONGRECT  *LPLONGRECT;

////////////////////
// SChangeOption
////////////////////
/*! \brief SChangeOption structure is used to manipulate with basic Drive settings in \ref CApplicationAPI::ChangeApplicationOptions "ChangeApplicationOptions" function.*/
extern "C" struct SDK_API SChangeOption
{
	/*! \brief HAZMAT / Load restrictions*/
	enum LOAD_RESTRICTIONS{
		/*! \brief Class 1 (Explosives) U.S only*/
		Explosives				= 0x00000001,
		/*! \brief Class 2 (Flammable, compressed and poisonous gases) U.S only*/
		FlammableGases			= 0x00000002,
		/*! \brief Class 3 (Flammable and compressed liquids) U.S only*/
		FlammableLiquids		= 0x00000004,
		/*! \brief Class 4 (Flammable solids, spontaneously combustible materials and water reactive substances) U.S only*/
		FlammableSolids			= 0x00000008,
		/*! \brief Class 5 (Oxidizers and organic peroxides) U.S only*/
		Oxidizers				= 0x00000010,
		/*! \brief Class 6 (Poisonous {toxic} and infectious substances) U.S only*/
		Poisonous				= 0x00000020,
		/*! \brief Class 7 (Radioactive Materials) U.S only*/
		Radioactive				= 0x00000040,
		/*! \brief Class 8 (Corrosive Materials) U.S only*/
		Corrosive				= 0x00000080,
		/*! \brief Class 9 (Misc Hazardous Materials) U.S only*/
		Hazardous				= 0x00000100,
		/*! \brief Class I (Poisonous Inhalation Hazards) U.S only*/
		InhalationHazards		= 0x00000200,
		/*! \brief General hazardous materials*/
		General					= 0x00000400,
		/*! \brief Explosive materials*/
		Explosive				= 0x00000800,
		/*! \brief Goods harmful to water*/
		HarmfulToWater			= 0x00001000,
		/*! \brief Agriculture load restriction*/
		Agriculture				= 0x00010000,
		/*! \brief Coal load*/
		Coal					= 0x00020000,
		/*! \brief Building Materials load*/
		Building				= 0x00040000,
		/*! \brief Sanitary waste load*/
		SanitaryVaste			= 0x00080000,
		/*! \brief Sand and Gravel*/
		SandAndGravel			= 0x00100000,
		/*! \brief Commodity load*/
		Commodity				= 0x00200000,
		/*! \brief Natural Resources*/
		NaturalResources		= 0x00400000
	};

	/*! \brief Flag enabling/disabling sounds.
	 *
	 * Possible values are:
	 *	- 1 - sound enabled
	 *	- 0 - sound disabled.
	 */
	BOOL			bSoundEnabled;
	/*! \brief Flag effecting Drive appearance.
	 *
	 * Possible values are:
	 *	- 1 - righthanded appearance
	 *	- 0 - lefthanded appearance
	 */
	BOOL			bOperateRightHanded;

	// 0 .. 10
	/*! \brief Represents the volume in low vehicle speed. (0-10)
	 *
	 * Sound volume changes with changing vehicle speed.\n
	 * It is sound volume used with low vehicle speed.
	 */
	int				nVolumeMin;
	/*! \brief Represents the volume in high vehicle speed. (0-10)
	 *
	 * Sound volume changes with changing vehicle speed.\n
	 * It is sound volume used with high vehicle speed.
	 */
	int				nVolumeMax;

	//MILES(YARDS) = 0, KILOMETERS = 1, MILES(FEETS) = 2
	/*! \brief Flag determining distance units.
	 *
	 * Possible values are:
	 *	- 0 - miles(yards)
	 *	- 1 - kilometers
	 *	- 2 - miles(feets)
	 */
	int				nDistanceUnit;

	//EUROPE = 0, US = 1, UK = 2
	/*! \brief Flag determining clock format.
	 *
	 * Possible values are:
	 *	- 0 - Europe (14:00)
	 *	- 1 - US (2:00)
	 *	- 2 - UK (2:00 PM)
	 */
	int				nClockFormat;

	//DEGREES = 0, MINUTES = 1, SECONDS = 2
	/*! \brief Flag determining GPSUnits format.
	 *
	 * Possible values are:
	 *	- 0 - degrees (0.0�)
	 *	- 1 - degrees, minutes (0�0.0')
	 *	- 2 - degrees, minutes, seconds (0�0'00'')
	 */
	int				nGPSUnits;

	//ABCD = 1, QWERTY = 2, AZERTY = 3, DVORAK = 4
	/*! \brief Flag determining keyboard type.
	 *
	 * Possible values are:
	 *	- 1 - ABCD
	 *	- 2 - QWERTY
	 *	- 3 - AZERTY
	 *	- 4 - DVORAK
	 */
	int				nKeyboardType;

	// ASK = 1, ALWAYS = 2, NEVER = 3
	/*! \brief Flag determining whether Drive avoids toll roads when computing route.
	 *
	 * Possible values are:
	 *	- 1 - Ask to avoid toll roads.
	 *	- 2 - Always avoid toll roads.
	 *	- 3 - Never avoid toll roads.
	 */
	int				nAvoidTollRoads;

	/*! \brief Flag determining whether Drive avoids U-turns when computing route.
	 *
	 * Possible values are:
	 *	- 1 - Ask to avoid U-turns.
	 *	- 2 - Always avoid U-turns.
	 *	- 3 - Never avoid U-turns.
	 */
	BOOL			bAvoidUTurns;

	// ASK=1, FASTEST=2, SHORTEST=3, AVOIDING_MOTORWAYS=4, WALKS=5, BIKES=6, LIMITED=7
	/*! \brief Flag determining what kind of route Drive computes.
	 *
	 * Possible values are:
	 *	- 1 - Drive computes fastest route.
	 *	- 2 - Drive computes economic route.
	 *	- 3 - Drive computes shortest route.
	 *	- 6 - Drive computes route for emergency vehicles.
	 */
	int				nPlanningSettings;

	/*! \brief Parameter determinig vehicle speed limit. Used only if route is computed for vehicles with limited speed. (see \ref SChangeOption::nPlanningSettings "nPlanningSettings")*/
	int				nPlanningSettingsLimitedSpeed;

	/*! \brief Flag determining whether Drive avoids ferries when computing route.
	 *
	 * Possible values are:
	 *	- 1 - Ask to avoid ferries.
	 *	- 2 - Always avoid ferries.
	 *	- 3 - Never avoid ferries.
	 */
	BOOL			bAvoidFerries;

	/*! \brief Flag enabling/disabling main menu.
	 *
	 * Possible values are:
	 *	- 0 - main menu enabled
	 *	- 1 - main menu disabled.
	 */
	BOOL			bDisableMainMenu;
	/*! \brief Flag enabling/disabling recomputing route when deviating from the route.
	 *
	 * Possible values are:
	 *	- 0 - recomputing enabled
	 *	- 1 - recomputing disabled
	 */
	BOOL			bDisableRecompute;

	/*! \brief Flag determining the Estimated Time of Arrival calculated in maximum speed*/
	int				nETAMaximumSpeed;
	/*! \brief Estimate time arrival percentage change*/
	int				nETAPercentageChange;

	/*! \brief Enable speed camera warning.
	 *
	 * Possible values are:
	 *	- 1 - enable
	 *	- 0 - disable
	 *	- -1 - get value
	 */
	BOOL			bRadarsWarnOn;
	/*! \brief Enable speed camera visibility
	 *
	 * Possible values are:
	 *	- 1 - visible
	 *	- 0 - invisible
	 *	- -1 - get value
	 */
	BOOL			bRadarsVisible;
	/*! \brief The distance from speed camera, in which the warning is enabled (range 1..10)
	 *
	 * Possible values are:
	 *	- -1 - get value
	 *	- real distance
	 * \nReal distance equals to <b>distance * 100 (m / yd)</b>
	 */
	int				nRadarDistance;
	/*! \brief The distance from speed camera, in which the warning is enabled (range 1..10) in city
	 *
	 * Possible values are:
	 *	- -1 - get value
	 *	- real distance
	 * \nReal distance equals to <b>distance * 100 (m / yd)</b>
	 */
	int				nRadarDistanceInCity;

	/*! \brief Skin mode
	 *
	 * Possible values are:
	 *	- 0 - DAY
	 *	- 1 - NIGHT
	 *	- 2 - AUTOSKIN
	 */
	int				nSkin; // DAY = 0, NIGHT = 1, AUTO = 2

	/*! \brief Time zone in minutes. Offset from GMT*/
	int				nTimeZone;

	/*! \brief Visibility of Browse map cursor
	 *
	 * Possible values are:
	 *	- 1 - invisible
	 *	- 0 - visible
	 *	- -1 - get value
	 */
	BOOL			bHideMapCursor;

	/*! \brief Speed warning is triggered when the maximum allowed speed in city is exceeded by this value*/
	int				nSpeedExceedInCity;
	/*! \brief Speed warning is triggered when the maximum allowed speed outside city is exceeded by this value*/
	int				nSpeedExceed;
	/*! \brief View mode
	 *
	 * Possible values are:
	 *	- 0 - 2D
	 *	- 1 - 3D
	 *	- 2 - 2D North up
	 */
	int				nView;
	/*! \brief Displayed signposts
	 *
	 * Possible values are:
	 *	- 0 - All directions
	 *	- 1 - Preferred direction
	 *	- 2 - Disabled
	 *	- -1 - Get value
	 */
	int				nSignpostDirection;
	/*! \brief Displayed signposts size
	 *
	 * Possible values are:
	 *	- 0 - single line
	 *	- 1 - simplified
	 *	- 2 - full
	 *	- -1 - get value
	 */
	int				nSignpostSize;
	/*! \brief Allows position snapping to forbidden roads*/
	int				bSnapToEveryRoad;
	/*! \brief Enable acoustic speed exceeding warning
	 *
	 * Possible values are:
	 *	- 1 - enable
	 *	- 0 - disable
	 *	- -1 - get value
	 */
	int				bMaxSpeedWarn;
	/*! \brief Selected sound is TTS*/
	BOOL			bTTSEnabled;
	/*! \brief Visible waypoints reach distance in meters*/
	int				nVisiblePointReachDistance;
	/*! \brief Invisible waypoints reach distance in meters*/
	int				nInvisiblePointReachDistance;
	/*! \brief Allow closed roads in route computing*/
	BOOL			bAllowClosedRoads;

#ifdef TRUCK_VERSION
	// truck attributes
	/*! \brief Flag determining whether a truck attributes are contained in map.\n
	 * This flag is readonly
	 */
	BOOL	bTruckInMap;		//readonly
	/*! \brief Use truck attributes*/
	BOOL	bUseTruckAtt;
	/*! \brief Truck max speed [km/h]*/
	int		nTruckMaxSpeed;		//kmh

	/*! \brief Gross vehicle weight [kg]*/
	int		nTruckWeightTotal;	//kg
	/*! \brief Weight per axle [kg]*/
	int		nTruckWeightAxle;	//kg
	/*! \brief Tandem axle weight [kg]*/
	int		nTruckTandemWeight;		//kg
	/*! \brief Tridem axle weight [kg]*/
	int		nTruckTridemWeight;		//kg
	/*! \brief Other weight [kg]*/
	int		nTruckOtherWeight;		//kg
	/*! \brief Unladen vehicle weight [kg]*/
	int		nTruckUnladenWeight;		//kg
	/*! \brief Total vehicle length [mm]*/
	int		nTruckLenght;		//mm
	/*! \brief Extreme axle length [mm]*/
	int		nTruckAxleLength;		//mm
	/*! \brief Trailer Length [mm]*/
	int		nTrailerLength;		//mm
	/*! \brief Tractor Length [mm]*/
	int		nTractorLength;		//mm
	/*! \brief Kingpin to last axle [mm]*/
	int		nKingpinLastAxle;	//mm
	/*! \brief Kingpin to middle of last tandem [mm]*/
	int		nKingpinLastTandem;	//mm
	/*! \brief Kingpin to end of trailer (last trailer if applicable) [mm]*/
	int		nKingpinEndTrailer;	//mm
	/*! \brief Other length [mm]*/
	int		nTruckOtherLength;		//mm
	/*! \brief Vehicle width [mm]*/
	int		nTruckWidth;		//mm
	/*! \brief Posted height [mm]*/
	int		nTruckHeight;		//mm

	/*! \brief HAZMAT / Load restrictions. See \ref SChangeOption::LOAD_RESTRICTIONS "LOAD_RESTRICTIONS".*/
	int		nLoadRestrictions;	//LOAD_RESTRICTIONS enum
#endif // TRUCK_VERSION

	/*! \brief \ref LONGPOSITION struct determining location of home position.\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.
	 */
	LONGPOSITION	cpHomePosition;
	/*! \brief Name of home position.*/
	TCHAR			strHomeLocation[60];
	/*! \brief Name of lang file.*/
	TCHAR			strLangFile[60];
	/*! \brief Name of voice folder*/
	TCHAR			strVoiceFolder[60];
	/*! \brief Name of voice person*/
	TCHAR			strVoicePerson[60];
	/*! \brief Name of the sound file to play on speed warning*/
	TCHAR			strMaxSpeedSound[60];
	/*! \brief Flag determining whether the user will be allowed to edit itinerary manually.*/
	BOOL bAllowItineraryEdit;

	/*! \brief Constructor of SChangeOption*/
	SChangeOption();

};

////////////////////
// SStopOffPoint
////////////////////
/*! \brief SStopOffPoint structure is used during manipulation with itinerary.*/
extern "C" struct SDK_API SStopOffPoint
{
	/*! \brief [in] Flag determining whether function processing instance of this class searches for address (for example when adding waypoint).
	 *
	 * Possible values are:
	 *	- 1 - search for address
	 *	- 0 - do not search for address
	 *  This Parameter is input only. Navigation doesn't set it.
	 */
	BOOL			bSearchAddress;
	/*! \brief Flag determining whether waypoint was already visited.
	 *
	 * Possible values are:
	 *	- 1 - waypoint was visited
	 *	- 0 - waypoint was not visited.
	 */
	BOOL			bVisited;

	//ViaPoint = 1, Finish = 2, Start = 3, Invisible = 4
	/*! \brief Flag determining type of waypoint.
	 *
	 * Possible values are:
	 *	- 1 - Viapoint
	 *	- 2 - Finish
	 *	- 3 - Start
	 *	- 4 - Invisible
	 *	- 5 - Magnetic
	 */
	int				nPointType;

	/*! \brief \ref LONGPOSITION structure defining position of waypoint on map.*/
	LONGPOSITION	cpLocation;
	/*! \brief Road offset from our map, where the waypoint is located. Use conversion table to obtain the offset from map provider segment ID. When using offset, the ISO code has to be used.*/
	LONG			lOffset;
	/*! \brief Unique ID of a waypoint*/
	DWORD			dwID;
	TCHAR			strIso[4];

	TCHAR			strCaption[120];
	TCHAR			strAddress[120];

	/*! \brief Constructor of SStopOffPoint.*/
	SStopOffPoint();
	/*! \brief Constructor of SStopOffPoint.
	 *
	 * \param lX determines X coordinate (geographical longitude) of location in world degrees multiplied by 100 000.
	 * \param lY determines Y coordinate (geographical latitude) of location in world degrees multiplied by 100 000.s">
	 * \param lpszCaption Name of waypoint shown in itinerary items list.
	 * \param bSearchAddress Flag determining whether waypoint was already visited.
	 *	- 1 - search for address.
	 *	- 0 - do not search for address.
	 */
	SStopOffPoint( LONG lX, LONG lY, LPCTSTR lpszCaption, BOOL bSearchAddress = FALSE );

};

////////////////////
// SPoi
////////////////////
/*! \brief SPoi structure is used to add POIs to Favourites and custom POI category. It is also used during retrieving items lists of these categories.*/
extern "C" struct SDK_API SPoi
{
	/*! \brief Flag determining whether function searches for address when adding POI.
	 *
	 * Possible values are:
	 *	- 1 - search for address
	 *	- 0 - do not search for address
	 */
	BOOL			bSearchAddress;

	/*! \brief \ref LONGPOSITION struct determining POI location on map.*/
	LONGPOSITION	cpLocation;

	/*! \brief Name of POI Category*/
	TCHAR			szCategory[60];
	/*! \brief Name of POI*/
	TCHAR			szName[120];
	/*! \brief Address of POI*/
	TCHAR			szAddress[120];

	/*! \brief Constructor of SPoi.*/
	SPoi();

};

////////////////////
// SPoi
////////////////////
/*! \brief SPoi structure is used to add POIs to Favourites and custom POI category. It is also used during retrieving items lists of these categories.*/
extern "C" struct SDK_API SPoiOnRoute
{
	/*! \brief \ref LONGPOSITION struct determining POI location on map.*/
	LONGPOSITION	cpLocation;

	INT nTimeRemaining;
	INT nDistanceRemaining;

	/*! \brief Name of POI Category*/
	TCHAR			szCategory[60];
	/*! \brief Name of POI*/
	TCHAR			szName[120];
	/*! \brief Address of POI*/
	TCHAR			szAddress[120];

	/*! \brief Constructor of SPoi.*/
	SPoiOnRoute();

};

////////////////////
// SPoiCategory
////////////////////
/*! \brief SPoiCategory structure specifies a POI category.
 *
 * It is used as a parameter for defining POI warnings in \ref CApplicationAPI.SetPoiWarning "SetPoiWarning" function
 */
extern "C" struct SDK_API  SPoiCategory
{
	/*! \brief Notification distance for POI warning.*/
	LONG			lNotificationDistance;
	/*! \brief Flag determining when the POI is notified
	 *
	 * Possible values are:
	 *	- true - drive will notify only when POI is on computed route
	 *	- false - drive will notify everytime POI is in radius from the current position
	 */
	BOOL			bNotifyOnlyWhenOnRoad;

	/*! \brief POI category name. For default categories it is string representation of a number, for UPI(user defined POI) files it is its name.*/
	TCHAR			strName[60];
	/*! \brief Sound file name as from the following pattern "sounds\(name).ogg" which is played in specified POI category warning*/
	TCHAR			strSound[60];

	/*! \brief Constructor of SPoiCategory*/
	SPoiCategory ( void );
};

typedef SPoi SFavorite;

////////////////////
// SHistoryRecord
////////////////////
/*! \brief SHistoryRecord class is used to manipulate with items in history list.
 *
 * Instance of SHistoryRecord represents one item in history list.\n
 * History is list of recent destinations.
 */
extern "C" struct SDK_API SHistoryRecord
{
	//0 = none, 1 = name hierarchy address, 2 = name hierarchy lpPoi
	//3 = name hierarchy postal, 4 = click point, 5 = favourite, 6 = GPS position
	//7 = homebase, 8 = name hierarchy lpPoi custom
	/*! \brief Flag determining type of history item.
	 *
	 * Possible values are:
	 *	- 0 - none
	 *	- 1 - name hierarchy address
	 *	- 2 - name hierarchy poi
	 *	- 3 - name hierarchy postal
	 *	- 4 - click point
	 *	- 5 - favourite
	 *	- 6 - GPS position
	 *	- 7 - homebase
	 *	- 8 - name hierarchy poi custom
	 */
	int				nHistoryType;

	/*! \brief \ref LONGPOSITION struct determining location of history item on map.*/
	LONGPOSITION	cpLocation;

	/*! \brief Name of history item.
	 *
	 * Name of history item is shown in history list.
	 */
	TCHAR			szHistoryCaption[120];

	/*! \brief Address of history item.*/
	TCHAR			szAddress[120];

	/*! \brief Constructor of SHistoryRecord.*/
	SHistoryRecord();

};

////////////////////
// SSatelliteInfo
////////////////////
/*! \brief SSatelliteInfo structure is used to obtain information about satellites.*/
extern "C" struct SDK_API SSatelliteInfo
{
	/*! \brief Satellite elevation in degrees.*/
	int				Elevation;
	/*! \brief Satellite azimuth in degrees.*/
	int				Azimuth;
	/*! \brief Signal quality from satellite.*/
	int				Quality;
	/*! \brief The satellite ID*/
	int				SateliteId;
	/*! \brief Used for fix*/
	int				UsedForFix;

	/*! \brief Constructor of SSatelliteInfo*/
	SSatelliteInfo();
};

////////////////////
// SGpsPosition
////////////////////
/*! \brief SGpsPosition structure is used to obtain information about GPS position, data and quality of GPS signal.*/
extern "C" struct SDK_API SGpsPosition
{
	/*! \brief Number of visible satellites.*/
	INT			nSatellites;

	/*! \brief Latitude represents Y coordinate (geographical latitude) of location in degrees multiplied by 100000.\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.
	 */
	LONG			lLatitude;
	/*! \brief Longitude represents X coordinate (geographical longitude) of location in degrees multiplied by 100000.\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.
	 */
	LONG			lLongitude;
	/*! \brief Altitude in meters*/
	LONG			lAltitude;

	/*! \brief Course represents speed direction in degrees(from gps signal) multiplied by 100000.
	 *
	 * For example if Course=1234567 real course is 12.34567�.\n
	 * Course=0 represents North direction and increases in clockwise direction. The vehicle must be moving to have a precise course.
	 */
	DOUBLE			dCourse;
	/*! \brief Real course(in degrees) - orientation that the car has in Sygic software.\n
	 * RealCourse=0 represents East direction and increases in clockwise direction.
	 */
	DOUBLE			dRealCourse;
	/*! \brief Speed represents velocity in kilometers per hour (km/h).
	 *
	 * If vehicle speed is shown in miles speed must be transformed to this units. Value stored in Speed is still in km/h units.
	 */
	DOUBLE			dSpeed;

	/*! \brief Horizontal dilution of precision.
	 *
	 * Horizontal dilution of precision informs user about accuracy of GPS horizontal position fixes.
	 */
	DOUBLE			dHDoP;
	/*! \brief Actual GPS time.*/
	DOUBLE			dTime;
	/*! \brief Actual GPS date.*/
	DWORD			dwDate;

	/*! \brief Road element offset of the road, to which is the current position snapped.*/
	LONG			lRoadOffset;
	/*! \brief Offset of start graph point of the current road segment*/
	LONG			lFromPointOffset;
	/*! \brief Offset of end graph point of the current road segment*/
	LONG			lToPointOffset;
	/*! \brief ISO code of the map, in which is the current position located*/
	TCHAR			szMapIso[4];

	/*! \brief Satellites info for first 12 satellites*/
	SSatelliteInfo	satellitesInfo[12];

	/*! \brief Constructor of SGpsPosition*/
	SGpsPosition();

	/*! \brief The function returns GMT time given by GPS.*/
	void GetTime( BYTE &nHour, BYTE &nMinute, BYTE &nSeconds, WORD &nMiliseconds );
	/*! \brief The function returns GMT date given by GPS.*/
	void GetDate( BYTE &nDay, BYTE &nMonth, WORD &nYear );
};

////////////////////
// SWayPoint
////////////////////
/*! \brief SWayPoint structure specifies location of one point on map.
 *
 * It is used as parameter determining target location in \ref CApplicationAPI::StartNavigation "StartNavigation" function.
 */
extern "C" struct SDK_API SWayPoint
{
	/*! \brief \ref LONGPOSITION struct defining position of waypoint on map.*/
	LONGPOSITION	cpLocation;

	/*! \brief Address of waypoint in format: "ISO,city,street,house number".*/
	TCHAR			szAddress[120];

	/*! \brief Custom address string that gets voiced at the end of route.*/
	TCHAR			customAddress[256];

	/*! \brief The function returns address of waypoint in format: "ISO,city,street,house number".*/
	LPCTSTR			GetAddress();

	/*! \brief Returns custom address string.*/
	LPCTSTR			GetCustomAddress();

	/*! \brief Constructor of SWayPoint*/
	SWayPoint();

};

typedef SWayPoint SLocation;

////////////////////
// SRouteInfo
////////////////////
/*! \brief SRouteInfo structure is used during retrieving inforamations about computed route by \ref CApplicationAPI::GetRouteInfo "GetRouteInfo" function.*/
extern "C" struct SDK_API SRouteInfo
{
	/*! \brief Total distance of route in meters.*/
	LONG			lTotalDistance;
	/*! \brief Distance from actual position to finish of the route in meters.*/
	LONG			lRemainingDistance;
	/*! \brief \ref LONGRECT structure defining rectangle on BrowseMap in which route is situated.
	 *
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.
	 */
	LONGRECT		rcBoundaryRectangle;
	/*! \brief Status of the route.
	 *
	 * Possible values are:
	 *	- 0 - none
	 *	- 1 - computing
	 *	- 2 - computed
	 *	- 17 - enumerating junctions
	 *	- 33 - reconstruct route
	 */
	DWORD			dwStatus;
	/*! \brief Estimated time of arrival
	 *
	 * Use  function \ref CApplicationAPI::TimeGetTime "TimeGetTime()" for conversion.
	 */
	LONG			lEstimatedTimeArival; // use function CApplicationAPI::TimeGetTime() for conversion
	/*! \brief Remaining time to arrival
	 *
	 * The time is in seconds
	 */
	LONG			lRemaningTime; // (s)
	/*! \brief Total time of the route
	 *
	 * The time is in seconds
	 */
	LONG			lTotalTime; // (s)
	/*! \brief Motorways length in meters*/
	LONG			lMotorwaysLength;
	/*! \brief Tollroads length in meters*/
	LONG			lTollRoadsLength;
	/*! \brief Ferries length in meters*/
	LONG			lFerriesLength;

	/*! \brief Array of estimated time arrivals to remaining waypoints from actual position.*/
	int				*pTimeToWP;
	/*! \brief Array of estimated distances to remaining waypoints from actual position.*/
	int				*pDistToWP;
	/*! \brief Size of TimeToWP and DistToWP arrays.*/
	int				nWPArraySize;

	/*! \brief Constructor of SRouteInfo*/
	SRouteInfo();
};

/*! \brief SRoadInfo structure is providing information about road type. This is retrieved from the <a href="ApplicationAPI.CApplicationAPI.GetLocationInfo_overload_2.html">GetLocationInfo</a> function.*/
extern "C" struct SDK_API SRoadInfo
{
	/*! \brief Road offset is an unique identificator of the road in map. This identificator is used for special routing.*/
	LONG lRoadOffset;
	/*! \brief Road Flag is an identificator of the road type in map.
	 *
	 * Values of the flags are:
	 *	- 0x20000000 - IPM
	 *	- 0x10000000 - Priority Maneuver
	 *	- 0x08000000 - Ferry
	 *	- 0x04000000 - Prohibited
	 *	- 0x01000000 - Special (logistic, taxi, etc. depending on map header)
	 *	- 0x40 - Toll
	 *	- 0x80 - Controlled Access
	 *	- 0x100 - Ramp
	 *	- 0x200 - Congestion Charge
	 *	- 0x400 - Controlled Access
	 *	- 0x800 - Roundabout
	 *	- 0x1000 - With Sign
	 *	- 0x2000 - Urban
	 *	- 0x4000 - With Lanes
	 *	- 0x8000 - Intersection Internal
	 *	- 0x10000 - Special Restriction
	 *	- 0x20000 - Bifurcation
	 *	- 0x40000 - Tunnel
	 */
	DWORD dwRoadFlags;
	/*! \brief ISO code string of the map, where the road is located.*/
	TCHAR szIsoCode[4];

	LONGPOSITION cpOnroadPosition;
	DWORD dwOffroadDistance;
	TCHAR szOpenLRString[256];

	/*! \brief Initializes a new instance of SRoadInfo*/
	SRoadInfo();
};

/*! \brief Summary description for DirectionInfo.*/
extern "C" struct SDK_API SRouteInstruction
{
	/*! \brief Instruction type*/
	enum Instruction
	{
		DirectionKeepRight	    	=  0,
		DirectionKeepLeft	    	=  2,
		DirectionEasyRight	    	=  4,
		DirectionEasyLeft	    	=  6,
		DirectionRight			    =  8,
		DirectionLeft			    = 10,
		DirectionSharpRight	    	= 12,
		DirectionSharpLeft  		= 14,
		DirectionStraight		    = 16,

		DirectionUTurnRight		    = 17,
		DirectionUTurnLeft		    = 18,
		DirectionEnd			    = 19,
		DirectionStart			    = 20,
		DirectionOutOfRoute		    = 21,

		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutSE	    = 23,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutE	    = 24,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutNE	    = 25,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutN	    = 26,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutNW	    = 27,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutW	    = 28,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutSW	    = 29,
		/*! \brief Valid only in the countries where you drive on the right side*/
		DirectionRoundaboutS	    = 30,


		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutSW_LS	= 32,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutW_LS     = 33,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutNW_LS    = 34,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutN_LS	    = 35,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutNE_LS	= 36,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutE_LS	    = 37,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutSE_LS	= 38,
		/*! \brief Valid only in the countries where you drive on the left side*/
		DirectionRoundaboutS_LS     = 39,

		DirectionFerry			    = 40,
		DirectionStateBoundary	    = 41,
		DirectionExitRight		    = 43,
		DirectionExitLeft		    = 44,
		DirectionMotorway		    = 45,
		DirectionExpressRoad	    = 46
	};

	/*! \brief Next turn longitude*/
	LONG lNextTurnX;
	/*! \brief Next turn latitude*/
	LONG lNextTurnY;

	/*! \brief Distance to next turn [m]*/
	LONG lDistanceToNextTurn;

	/*! \brief Next turn instruction. See \ref tagRouteInstruction::Instruction "Instruction" enum.*/
	int nInstruction;
	/*! \brief Roundabout exit index*/
	int nRoundaboutExitIndex;
	/*! \brief Exit index*/
	TCHAR lpszExitIndex[120];

	/*! \brief Constructor of DirectionInfo*/
	SRouteInstruction ( void );

};

/*! \brief The STmcEvent structure defines a single TMC event on a location.*/
extern "C" struct SDK_API STmcEvent
{
	/*! \brief List of the possible Event codes.*/
	enum EventCode
	{
		/*! \brief Represents a general traffic problem.*/
		TMCTrafficProblem				=  0,
		/*! \brief Represents a queuing problem*/
		TMCQueuingProblem				=  1,
		/*! \brief Represents slow traffic*/
		TMCSlowTraffic					=  2,
		/*! \brief Represents heavy traffic*/
		TMCHeavyTraffic					=  3,
		/*! \brief Represents stationary traffic*/
		TMCStationaryTraffic			=  4,
		/*! \brief Represents congestion in traffic*/
		TMCCongestion					=  5,
		/*! \brief Represents normal traffic*/
		TMCNormalTraffic				=  6,
		/*! \brief Represents no problems in traffic*/
		TMCNoProblems					=  7,
		/*! \brief Represents a cleared accident in traffic*/
		TMCAccidentCleared				=  8,
		/*! \brief Represents an accident in traffic*/
		TMCAccidentIncident				=  9,
		/*! \brief Represents a closure in traffic*/
		TMCClosure						= 10,
		/*! \brief Represents a bridge tunel blocked*/
		TMCBridgeTunelBlocked			= 11,
		/*! \brief Represents a service closed*/
		TMCSeviceClosed					= 12,
		/*! \brief Represents a service reopened*/
		TMCServiceReopened				= 13,
		/*! \brief Represents a lane closure*/
		TMCLaneClosure					= 14,
		/*! \brief Represents works on road*/
		TMCRoadWorks					= 15,
		/*! \brief Represents an obstacle in traffic*/
		TMCObstacle						= 16,
		/*! \brief Represents road conditions*/
		TMCRoadConditions				= 17,
		/*! \brief Represents bad weather*/
		TMCWeather						= 18,
		/*! \brief Represents side wind*/
		TMCWind							= 19,
		/*! \brief Represents pure visibility on road*/
		TMCVisibility					= 20,
		/*! \brief Represents temperature*/
		TMCTemperature					= 21,
		/*! \brief Represents an activity on road*/
		TMCActivity						= 22,
		/*! \brief Represents a delay in traffic*/
		TMCDelay						= 23,
		/*! \brief Represents a dangerous vehicle in traffic*/
		TMCDangerousVehicle				= 24,
		/*! \brief Represents exceptional loads vehicles in traffic*/
		TMCExceptionalLoadsVehicles		= 25,
		/*! \brief Represents traffic equipment on road*/
		TMCTrafficEquipment				= 26,
		/*! \brief Represents size and weight limits on road*/
		TMCSizeAndWeightLimits			= 27,
		/*! \brief Represents parking restrictions on road*/
		TMCParkingRestrictions			= 28,
		/*! \brief Reference to audio broadcast*/
		TMCReferenceToAudioBroadcast	= 29,
		/*! \brief Additional info*/
		TMCAdditionalInfo				= 30
	};

	/*! \brief Returns the ID number that was assigned to this event by application. The ID can be later used to delete the event.*/
	WORD wID;

	/*! \brief Determines geographical longitude (X coordinate) of the event in world degrees multiplied by 100 000.*/
	LONG lX;
	/*! \brief Determines geographical latitude (Y coordinate) of the event in world degrees multiplied by 100 000.*/
	LONG lY;

	/*! \brief Code of the TMC event from the EventCode enumeration*/
	int nEventCode;
	/*! \brief Defines if the route computing should always avoid this event.
	 *
	 * Possible values are:
	 *	- 1 - Always avoid this event
	 *	- 0 - Never avoid this event
	 */
	BOOL bUserAvoid;

	/*! \brief Year. Validity time, till which the event remains active. After this time is the event deleted. The events are not stored after application exit.*/
	UINT nValidityYear;
	/*! \brief Month. Validity time, till which the event remains active. After this time is the event deleted. The events are not stored after application exit.*/
	BYTE nValidityMonth;
	/*! \brief Day. Validity time, till which the event remains active. After this time is the event deleted. The events are not stored after application exit.*/
	BYTE nValidityDay;
	/*! \brief Hour. Validity time, till which the event remains active. After this time is the event deleted. The events are not stored after application exit.*/
	BYTE nValidityHour;
	/*! \brief Minute. Validity time, till which the event remains active. After this time is the event deleted. The events are not stored after application exit.*/
	BYTE nValidityMinute;

	/*! \brief Creates the instance of the STmcEvent class with default values.*/
	STmcEvent();

};

/*! \brief SOnlineServicesSettings structure*/
extern "C" struct SDK_API SOnlineServicesSettings
{
	/*! \brief Flag determining if the Weather service is enabled*/
	BOOL bWeatherEnabled;
	/*! \brief Flag determining if the Photos service is enabled*/
	BOOL bPhotosEnabled;
	/*! \brief Flag determining if the Traffic service is enabled*/
	BOOL bTrafficEnabled;
	/*! \brief Flag determining if the Police traps service is enabled*/
	BOOL bTrapsEnabled;
	/*! \brief Flag determining if the Friends service is enabled*/
	BOOL bFriendsEnabled;

	// traffic settings
	/*! \brief Flag determining if the Automatic route recalculation service is enabled*/
	BOOL bTrafficAutoRecompute;
	/*! \brief Flag determining if the Traffic notification service is enabled*/
	BOOL bTrafficShowNotification;
	/*! \brief Flag determining if the Traffic info service is enabled*/
	BOOL bTrafficShowOnMap;

	/*! \brief Constructor of SOnlineServicesSettings*/
	SOnlineServicesSettings();
};

///////////////////////////////////////////
//SError
//////////////////////////////////////////
/*!
 * \brief SError class is used to obtain additional error informations after calling ApplicationAPI function.
 *
 * It is possible to get error code and error description by calling \ref SError::GetCode "GetCode" and \ref SError::GetDescription "GetDescription" functions.\n
 * General error codes that sets each function are:
 *	- 0 - Function not succeeded.
 *	- 1 - Function succeeded.
 *	- 2 - Drive not succeeded.
 *	- 3 - Function reached timeout.
 * Some functions gets also function-specific error codes:
 *	- \ref CApplicationAPI::GetActualGpsPosition "GetActualGpsPosition"
 *		- -1 - No fix.
 *		- -2 - GPS position not available.
 *	- \ref CApplicationAPI::AddStopOffPointsToFavorites "AddStopOffPointsToFavorites"
 *		- -1 - POI was not added because of invalid location syntax.
 *	- \ref CApplicationAPI::RemoveFavoriteFromList "RemoveFavoriteFromList"
 *		- -1 - Favorite was not removed because of invalid location syntax.
 *		- -2 - Favorite was not removed because of missing Favorite with given name.
 *	- \ref CApplicationAPI::AddPoi "AddPoi"
 *		- -2 - POI was not added because of invalid location syntax.
 *	- \ref CApplicationAPI::DeletePoi "DeletePoi"
 *		- -1 - POI was not deleted because of ambiguous location.
 *	- \ref CApplicationAPI::GetLocationInfo "GetLocationInfo"
 *		- -1 - Location info was not found because of invalid location syntax.
 *	- \ref CApplicationAPI::SetRoute "SetRoute"
 *		- -3 - Navigation not started. Drive is already navigating.
 *		- -5 - User canceled route computing.
 *		- -6 - Drive is waiting for valid GPS signal.
 *		- -7 - Itinerary is empty
 *      - -8 - Itinerary has invalid format (from version 15j)
 *      - -9 - One or more waypoints were not found (from version 15j)
 *      - -10 - Itinerary was not found (from version 15j)
 *	- \ref CApplicationAPI::StartNavigation "StartNavigation" and \ref CApplicationAPI::NavigateToAddress "NavigateToAddress"
 *		- -1 - Navigation not started because address was not found.
 *		- -3 - Navigation not started. Drive is already navigating.
 *		- -5 - User canceled route computing.
 *		- -6 - Drive is waiting for valid GPS signal.
 */
extern "C" struct SDK_API SError
{
	/*! \brief Error code*/
	int				nCode;

	/*! \brief Description of error code.*/
	TCHAR			szDescription[120];

	/*! \brief Constructor of SError*/
	SError();

	/*! \brief The function returns error code.*/
	int		GetCode();
	/*! \brief The function returns description of error code.*/
	LPCTSTR	GetDescription();
	/*! \brief The function clears message description.*/
	void	Clear();

};

typedef SError *LpError;

extern "C" struct SDK_API SRouteComputeSettings
{
	int nDestinationAngle;

	SRouteComputeSettings();
};

extern "C" void SDK_API  FreeMemory( LPVOID ptr );

/*! \brief Basic class providing set of functions to command Drive.*/
extern "C" class SDK_API CApplicationAPI
{
public:
	/*! \brief The function initializes ApplicationAPI and must be called at the very first place.
	 * \param lpszPath Full path to application Drive.exe.
	 * \param pfnApplicationEventHandler Delegate of APPLICATION_HANDLEPROC type. Can be used to process events generated by Drive. Supported events are enumerated in \ref events "ApplicationEvents".
	 * \param nLeft x-coordinate of Drive top left corner.
	 * \param nTop y-coordinate of Drive top left corner.
	 * \param nWidth Width of Drive in pixels.
	 * \param nHeight Height of Drive in pixels.
	 * \param bRunInForeground Indicates whether Drive shall be brought to foreground after initialization.
	 * \return 1 if successful, other value otherwise
	 *
	 * The function initializes ApplicationAPI and starts Drive.exe. \n \n
	 * This function should be called just once at the beginning. Before start Drive repeatedly use \ref CloseApi method first. \n\n
	 * If Handler is set to null events will not be processed.
	 */
    static int  InitApi( LPCTSTR lpszPath, APPLICATION_HANDLEPROC pfnApplicationEventHandler, int nLeft, int nTop, int nWidth, int nHeight,
			BOOL bRunInForeground = TRUE, BOOL bNoCaption = FALSE, HWND hParentWnd = NULL );

	/*! \brief The function uninitializes ApplicationAPI. No other API functions will be executed after this command. \n
	 * The function should be called at the end of SDK application. You can call function EndApplication before this one, if you wish to close navigation too.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	CloseApi();

	//////////////////
	// application
	/////////////////
	/*! \brief The function verifies whether Drive is running.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if Drive is running otherwise -1
	 */
	static int  IsApplicationRunning( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function ends Drive application.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  EndApplication( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function brings Drive window to foreground.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	BringApplicationToForeground( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function brings Drive window to background. The application is hidden and stops doing any graphic operations which results in less processor load. However, it continues to read GPS port.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	BringApplicationToBackground( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns device ID.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszDeviceID Device ID.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetUniqueDeviceId( LpError  lpError, LPTSTR lpszDeviceID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function returns, if the application is active in foreground or idle in background.
	 * \param lpError Additional error information returned from Drive.
	 * \param bApplicationInForeground Value with result.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.</returns>
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	IsApplicationInForeground( LpError lpError, BOOL &bApplicationInForeground, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function gets the map version of a given country's ISO code.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszIso Country's ISO code.
	 * \param lpszMapVersion The map version.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a> ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY. Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n \n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	GetMapVersion( LpError lpError, LPCTSTR lpszIso, LPTSTR lpszMapVersion, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function gets the Drive's version and build number.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszDriveVersion Drive's version.
	 * \param lpszBuildNumber Drive's build number.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetApplicationVersion( LpError lpError, LPTSTR lpszDriveVersion, LPTSTR lpszBuiltNumber, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Gets the SDK's version and its build number.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszSdkVersion SDK's version.
	 * \param lpszBuildNumber SDK's build number.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0, function execution is not time limited.
	 * \return 1 if successful, or else other values.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function has not succeeded.
	 *	- 1 - Function has succeeded.
	 *	- 2 - Drive has not succeeded.
	 *	- 3 - Function has reached timeout.
	 */

	static int  GetSdkVersion( LpError lpError, LPTSTR lpszSdkVersion, LPTSTR lpszBuiltNumber, DWORD dwMaxTime = DEFAULT_MAX_TIME );




	//////////////
	// options
	//////////////
	static int GetApplicationOptions(LpError lpError, LPTSTR &lpApplicationOptions, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int SetApplicationOptions(LpError lpError, LPCTSTR lpApplicationOptions, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	/*! \brief The function changes basic Drive settings.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpChangeOption Reference to instance of \ref SChangeOption "SChangeOption" type which contains new Drive settings.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Use ChangeOption to set new Drive settings. It is possible to change these characteristics:
	 *	- appearance for right or left handed user
	 *	- enable/disable sounds
	 *	- set maximum and minimum sound volume
	 *	  Sound volume is changed with changing of velocity. Maximum value is used with high speed and minimum with low speed.
	 *	- set clock format. It is possible to choose EUROPE, UK or US format.
	 *	- set distance units. User can choose kilometers or miles.
	 *	- set GPS units. User can choose degrees, minutes or seconds.
	 *	- set location of home position.
	 *	- set keyboard type which Drive uses.
	 * After function execution ChangeOption contains actual Drive settings. \n \n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  ChangeApplicationOptions( LpError  lpError, SChangeOption* lpChangeOption, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function sets default Drive settings.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum of time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  SetDefaultValues( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function change position and size of Drive application.
	 * \param lpError Additional error information returned from Drive.
	 * \param nLeft x-coordinate of Drive top left corner.
	 * \param nTop y-coordinate of Drive top left corner.
	 * \param nHeight Height of Drive in pixels.
	 * \param nWidth Width of Drive in pixels.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 */
	static int	ChangeAppRectangle( LpError  lpError, int nLeft, int nTop, int nWidth, int nHeight, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/////////////////
	// navigation
	////////////////
	/*! \brief The function returns informations about actual GPS position.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpGpsPosition Reference to instance of \ref SGpsPosition "SGpsPosition" enum which contains informations about GPS position.
	 * \param bSatellitesInfo Flag determining whether function should return satellites information.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The function GetActualGpsPosition needs Drive to have valid GPS position. If valid GPS position is not present GetActualGpsPosition returns 0 and GpsPosition (see \ref SGpsPosition "SGpsPosition" struct) members are set to 0. \n \n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - No fix.
	 *	- -2 - GPS position not available.
	 */
	static int  GetActualGpsPosition( LpError  lpError, SGpsPosition* lpGpsPosition, BOOL bSatellitesInfo, DWORD dwMaxTime = DEFAULT_MAX_TIME );
	static int  GetActualGpsPosition(LpError  lpError, LPTSTR &lpGpsPositionInfo, BOOL bSatellitesInfo, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	/*! \brief The function returns informations about computed route.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpRouteInfo Reference to instance of \ref SRouteInfo "SRouteInfo" type which contains informations about route after function execution.
	 * \param bExtended Flag determining whether the RouteInfo should have TimeToWP and DistToWP set. If the bExtended=true, TimeToWP contains estimated time arrival from actual position to each waypoint of the route and DistToWP contains estimated distance to each waypoint. The size of both arrays is stored in nWPArraySize. If bExtended=false, TimeToWP and DistToWP will remain empty.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If MaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * GetRouteInfo fills in RouteInfo members. \n
	 * Status member of RouteInfo determines status of the route. Possible values are:
	 *	- 0x0001 - Computing
	 *	- 0x0002 - Computed
	 *	- 0x0010 - EnumeratingJunctions
	 *	- 0x0020 - ReconstructRoute
	 *
	 * \b Only if Status=0x0002 (Computed) you can be sure that other members of SRouteInfo are valid.
	 * See \ref SRouteInfo "SRouteInfo" for information about other RouteInfo members. \n \n
	 * Destination of route is possible obtain from \ref GetItineraryList method. \n \n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetRouteInfo( LpError  lpError, SRouteInfo* lpRouteInfo, BOOL bExtended = FALSE, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns informations about computed route in json format.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpRouteStatus Reference to instance of json string.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If MaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetRouteStatus( LpError lpError, LPTSTR &lpRouteStatus, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function starts navigate to taken location.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpLocation Reference to instance of \ref SWayPoint "SWayPoint" type which contains informations about target.
	 * \param bSearchAddress Flag determining whether GetHistoryList searches for address or not. \n
	 * true - StartNavigation fills address member of each SHistoryRecord with corresponding address. \n
	 * false - StartNavigation does not search for address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param dwFlags Parameter Flags determines route computing properties. \n
	 * It should be value from \ref NavigationParams "NavigationParams".
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically. \n
	 * true - Drive will be brought to foreground \n
	 * false - Drive will stay in background
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and Location must be situated on loaded map. It is necessary to set Location member of Location. \n \n
	 * Parameter dwFlags determines some route computing properties. Possible values are enumerated in NavigationParams enum. \n
	 * For example it is possible notify user that not all toll roads can be avoided. \n \n
	 * To join more flags together use logical or operator (|). \n
	 * For more informations see \ref NavigationParams "NavigationParams" enum. \n
	 * It is possible to get returned (if address is returned) address by calling function. \n \n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled) Location. \ref=SWayPoint::GetAddress "GetAddress()". \n \n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page. \n \n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 */
	static int  StartNavigation( LpError  lpError, SLocation* lpLocation, DWORD dwFlags, BOOL bShowApplication, BOOL bSearchAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function starts navigate to taken location.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpLocation Reference to instance of \ref SWayPoint "SWayPoint" class which contains informations about target.
	 * \param bSearchAddress Flag determining whether GetHistoryList searches for address or not. \n
	 * true - StartNavigation fills address member of each SHistoryRecord with corresponding address. \n
	 * false - StartNavigation does not search for address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param dwFlags Parameter Flags determines route computing properties. \n
	 * It should be value from \ref=NavigationParams.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically. \n
	 * true - Drive will be brought to foreground \n
	 * false - Drive will stay in background
	 * \param bCloseDelivery Flag determining whether the delivery area is restricted or not. \n
	 * true - if waypoint is in delivery area, the route will be computed \n
	 * false - if waypoint is in delivery area, it will be considered restricted area
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and Location must be situated on loaded map. It is necessary to set Location member of Location.\n\n
	 * Parameter Flags determines some route computing properties. Possible values are enumerated in NavigationParams enum. For example it is possible notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|). For more informations see \refNavigationParams enum.\n\n
	 * It is possible to get returned (if address is returned) address by calling function \n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled) Location.\ref=SWayPoint::GetAddress "GetAddress()".\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found.
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 */
	static int  StartNavigation( LpError  lpError, SLocation* lpLocation, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, BOOL bSearchAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function starts navigate to taken location.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpLocation Reference to instance of \ref SWayPoint "SWayPoint" class which contains informations about target.
	 * \param bSearchAddress Flag determining whether GetHistoryList searches for address or not. \n
	 * true - StartNavigation fills address member of each SHistoryRecord with corresponding address. \n
	 * false - StartNavigation does not search for address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param dwFlags Parameter Flags determines route computing properties. \n
	 * It should be value from \ref=NavigationParams.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically. \n
	 * true - Drive will be brought to foreground \n
	 * false - Drive will stay in background
	 * \param bCloseDelivery Flag determining whether the delivery area is restricted or not. \n
	 * true - if waypoint is in delivery area, the route will be computed \n
	 * false - if waypoint is in delivery area, it will be considered restricted area
	 * \param special settings used for route computing
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and Location must be situated on loaded map. It is necessary to set Location member of Location.\n\n
	 * Parameter Flags determines some route computing properties. Possible values are enumerated in NavigationParams enum. For example it is possible notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|). For more informations see \refNavigationParams enum.\n\n
	 * It is possible to get returned (if address is returned) address by calling function \n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled) Location.\ref=SWayPoint::GetAddress "GetAddress()".\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found.
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 */
	static int  StartNavigation( LpError  lpError, SLocation* lpLocation, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, BOOL bSearchAddress, SRouteComputeSettings* lpCompSettings, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function starts navigate to taken location.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpLocation Reference to instance of \ref SWayPoint "SWayPoint" class which contains informations about target.
	 * \param bSearchAddress Flag determining whether GetHistoryList searches for address or not. \n
	 * true - StartNavigation fills address member of each SHistoryRecord with corresponding address. \n
	 * false - StartNavigation does not search for address.
	 * \param lpszCustomAddress Custom address string that will be used instead of a reverse geocoded address
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param dwFlags Parameter Flags determines route computing properties. \n
	 * It should be value from \ref=NavigationParams.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically. \n
	 * true - Drive will be brought to foreground \n
	 * false - Drive will stay in background
	 * \param bCloseDelivery Flag determining whether the delivery area is restricted or not. \n
	 * true - if waypoint is in delivery area, the route will be computed \n
	 * false - if waypoint is in delivery area, it will be considered restricted area
	 * \param special settings used for route computing
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and Location must be situated on loaded map. It is necessary to set Location member of Location.\n\n
	 * Parameter Flags determines some route computing properties. Possible values are enumerated in NavigationParams enum. For example it is possible notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|). For more informations see \refNavigationParams enum.\n\n
	 * It is possible to get returned (if address is returned) address by calling function \n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled) Location.\ref=SWayPoint::GetAddress "GetAddress()".\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found.
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 */
	static int  StartNavigation(LpError  lpError, SLocation* lpLocation, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, BOOL bSearchAddress, SRouteComputeSettings* lpCompSettings, LPCTSTR lpszCustomAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	/*! \brief The function stops navigation, cancels the route and returns Drive application to main screen.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  StopNavigation( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function computes route from actual GPS position to taken target and starts navigate to taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszAddress Specifies address of route target. Address must be in "ISO,city/ ZIP, street, house number" format.
	 * \param bPostal Flag determining whether second address parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param dwFlags Parameter Flags determines route computing properties.\n
	 * It should be value from \ref NavigationParams.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground\n
	 * false - Drive will stay in background
	 * \param dwMaxTime Maximum time (milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and address must be situated on loaded maps.\n\n
	 * Parameter Flags determines some route computing properties. Possible values are enumerated in NavigationParams enum. For example it is possible notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|). For more informations see \ref NavigationParams enum.\n\n
	 * Address parameter house number is optional. If you do not want to fill it write address like this:\n
	 * "SVK,Bratislava,Einsteinova,"\n\n
	 * Second address parameter can represent city name or ZIP code.\n
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a> ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY. Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found.
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal. This means, you don't have to call this funciton again, it will start to navigat automatically when the signal is acquired.
	 */
	static int	NavigateToAddress( LpError  lpError, LPCTSTR lpszAddress, BOOL bPostal, DWORD dwFlags, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function computes route from actual GPS position to taken target and starts navigate to taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszAddress Specifies address of route target. Address must be in "ISO,city/ ZIP, street, house number" format.
	 * \param bPostal Flag determining whether second address parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param dwFlags Parameter Flags determines route computing properties. It should be value from \ref NavigationParams.
	 * \param bCloseDelivery Flag determining whether the delivery area is restricted or not.\n
	 * true - if waypoint is in delivery area, the route will be computed\n
	 * false - if waypoint is in delivery area, it will be considered restricted area
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground\n
	 * false - Drive will stay in background
	 * \param dwMaxTime Maximum time (milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * To use this function it is necessary to have valid GPS signal and address must be situated on loaded maps.\n\n
	 * Parameter Flags determines some route computing properties. Possible values are enumerated in NavigationParams enum. For example it is possible notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|). For more informations see \ref NavigationParams enum.\n\n
	 * Address parameter house number is optional. If you do not want to fill it write address like this:\n
	 * "SVK,Bratislava,Einsteinova,"\n\n
	 * Second address parameter can represent city name or ZIP code.\n
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	 * Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found.
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal. This means, you don't have to call this funciton again, it will start to navigat automatically when the signal is acquired.
	 */
	static int	NavigateToAddress( LpError  lpError, LPCTSTR lpszAddress, BOOL bPostal, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function loads a pre-computed route from a file and starts navigation following that route.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszRoutePath Path and filename of the RSAV file, from which is the saved route loaded.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	LoadComputedRoute( LpError  lpError, LPCTSTR lpszRoutePath, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	static int	LoadComputedRoute( LpError  lpError, LPCTSTR lpszRoutePath, DWORD dwStartWaypointID, LPCTSTR lpszJsonParams, LPTSTR &lpszApproximationInfo, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function loads a pre-computed route from a file and starts navigation following that route.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszRoutePath Path and filename of the RSAV file, from which is the saved route loaded.
	 * \param dwStartWaypointID ID of start waypoint
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The StartWaypointID of the Start point is 1. The first waypoint has the ID 2 and so on.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	LoadComputedRoute( LpError  lpError, LPCTSTR lpszRoutePath, DWORD dwStartWaypointID, LPTSTR &lpszApproximationInfo, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function saves the current route in navigation to a file.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszRoutePath Path and filename where to save the current route as RSAV file.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	SaveComputedRoute( LpError  lpError, LPCTSTR lpszRoutePath, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	static int GetRoute(LpError lpError, int nFormat, int nDetail, LPTSTR &lpszRoute, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	/////////////////
	// favorites
	/////////////////
	/*! \brief The function returns list of POIs in Favorites category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lstFavoriteArr After function execution lstFavoriteArr contains list of retrieved favorites.
	 * \param nSize Size of the lstFavoriteArr
	 * \param bSearchAddress Specifies whether GetFavoritesList function searches for address or not. If bSearchAddress=true GetFavoritesList fills address member of each lstFavoriteArr item (see \ref SPoi "SPoi" type) with corresponding address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetFavoritesList( LpError  lpError, SFavorite* & lstFavoriteArr, int & nSize,
		BOOL bSearchAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function adds user defined POI to Favorites category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpStopOffPoint Reference to instance of \ref SPoi "SPoi" class which contains informations about POI to add.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * To add custom POI to Favorites category fill in StopOffPoint members and call AddStopOffPointsToFavorites function. It is not necessary to call SetCategory function because POI category will be set to Favorites automatically.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - POI was not added because of invalid location syntax.
	 */
	static int  AddStopOffPointsToFavorites( LpError  lpError, SPoi* lpStopOffPoint, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function removes POI from list of Favorites.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpFavorite Reference to instance of \ref SPoi "SPoi" type which contains informations about POI to remove.
	 * \param dwMaxTime Maximum of time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * It is necessary to fill in Location and Name members of Favorite (see \ref SPoi "SPoi" type).\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Favorite was not removed because of invalid location syntax.
	 *	- -2 - Favorite was not removed because of missing Favorite with given name.
	 */
	static int  RemoveFavoriteFromList( LpError  lpError, SFavorite* lpFavorite, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////
	// history
	/////////////////
	/*! \brief The function adds new item to History list.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpStopOffPoint Reference to instance of \ref SHistoryRecord "SHistoryRecord" type which contains informations about item to add.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * History list contains recent destinations. To add new item to History list fill in lpStopOffPoint members and call AddStopOffPointToHistory.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  AddStopOffPointToHistory( LpError  lpError, SHistoryRecord* lpStopOffPoint, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns the list of items in History.
	 * \param lpError Additional error information returned from Drive.
	 * \param lstHistoryArr Array of \ref SHistoryRecord "SHistoryRecord" which contains retrieved items.
	 * \param nSize Size of the lstHistoryArr array.
	 * \param bSearchAddress Specify whether GetHistoryList searches for address or not. If bSearchAddress=true GetHistoryList fills address member of each HistoryArr item (see \ref SHistoryRecord "SHistoryRecord" type) with corresponding address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetHistoryList( LpError  lpError, SHistoryRecord* & lstHistoryArr, int & nSize,
		BOOL bSearchAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////
	// poi
	//////////////////
	/*! \brief The function adds user POI to custom category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoi Reference to instance of \ref SPoi "SPoi" class which contains informations about POI to add.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * To add POI to custom category fill in Poi members and call AddPoi function. \n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -2 - POI was not added because of invalid location syntax.
	 */
	static int  AddPoi( LpError  lpError, SPoi* lpPoi, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function adds custom POI category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszCategory Name of category to add.
	 * \param lpszBitmapPath Path to icon of category. It is relative path from ($ResDir)\ icons\ poi\ directory.
	 * \param lpszIsoCode ISO code of map (country) for which category will be created. This parameter is obligatory.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Parameter lpszIsoCode is official ISO code of the country. The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	 * Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Icon of category will be displayed on the left of category name in POI categories list. Pictures for icons must be stored in ($ResDir)\ Icons\ directory and be in 32 bit bmp format.\n\n
	 * AddPoiCategory function adds new category just into datas of taken map. The category occurs in POI categories list if correspoinging map is loaded. When you add new item which is situated in other country to this category, category is automatically added to map of this country.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  AddPoiCategory( LpError  lpError, LPCTSTR lpszCategory,LPCTSTR lpszBitmapPath, LPCTSTR lpszIsoCode,
		DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function deletes custom POI category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszCategory Name of category to delete.
	 * \param lpszIso ISO code of map from which category will be deleted. If this parameter is not set category will be deleted from all loaded maps.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Parameter strIsoCode is official ISO code of the country. The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	 * Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  DeletePoiCategory( LpError  lpError, LPCTSTR lpszCategory, LPCTSTR lpszIso, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function deletes custom POI from custom category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoi Reference to instance of \ref SPoi "SPoi" type which contains POI to delete.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * It is necessary to fill Location and Name members of Poi (see \ref SPoi "SPoi" type).\n
	 * DeletePoi function deletes just item which has same value of Location and Name like taken Poi.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - POI was not deleted because of ambiguous location.
	 */
	static int  DeletePoi( LpError  lpError, SPoi* lpPoi, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows or hides POI category in POI category list.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwCategory Category ID. Possible values are enumerated in \ref PoiService enum.
	 * \param lpszCategory Custom category name to show/hide.
	 * \param bShow Flag determinig whether MakeUserPoiVisible shows or hides category. If bShow=true category will be shown if bShow=false category will be hidden.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * If MakeUserPoiVisible hides custom category the category does not occur in category list.\n\n
	 * If dwCategory=PoiService.USERDEFINE it is necessary to set also strCategory. Otherwise category name is obtained from category ID.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  MakeUserPoiVisible( LpError  lpError, DWORD dwCategory, LPCTSTR lpszCategory, BOOL bShow, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns list of POIs from selected category.
	 * \param lpError Additional error information returned from Drive.
	 * \param lstPoiArr Array of \ref SPoi "SPoi" which contains list of POIs after function execution.
	 * \param nSize Size of the lstPoiArr array.
	 * \param strCategory Category name. It is name of category we want to retrieve list of POIs from.
	 * \param bSearchAddress Specify whether GetPoiList searches for address or not. If bSearchAddress=true GetPoiList fills address member of each PoiArr item (see \ref SPoi "SPoi" type) with corresponding address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  GetPoiList( LpError  lpError, SPoi* &lstPoiArr, int & nSize, LPCTSTR lpszCategory, BOOL bSearchAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	static int  GetPoiOnRoute( LpError  lpError, int nGroup, int nCategory, int minDriveTime, int maxDriveTime, SPoiOnRoute* &lstPoiArr, int & nSize, DWORD dwMaxTime = DEFAULT_MAX_TIME );


	/*! \brief The function finds the nearest POI around given position. The POI may be from the original map POIs or it may be a custom POI.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoi Returned \ref SPoi "SPoi" class containing information about the found POI.
	 * \param dwCategoryNumber Category ID. If this value is filled with standard value, original POIs are found. Set to PoiService.USERDEFINE for custom POI. Possible values are enumerated in \ref PoiService enum.
	 * \param lpszCategoryName Custom POI category name, if custom POI is searched.
	 * \param lX X-coordinate of place, where to search.
	 * \param lY Y-coordinate of place, where to search.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Distance between taken position and POI is computed bee-line.\n\n
	 * If dwCategory=PoiService.USERDEFINE it is necessary to define also strCategory. Otherwise category name is obtained from category ID.\n\n
	 * X and Y coordinates are geographical longitude and latitude in degrees multiplied by 100000.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	FindNearbyPoi( LpError  lpError, SPoi* & lpPoi, DWORD dwCategoryNumber, LPCTSTR lpszCategoryName,
		long lX, long lY, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function finds the defined number of nearest POIs around given position. The POIs may be from the original map POIs or they may be some custom POIs.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoiList Returned array of <see cref="ApplicationAPI.h::SPoi">SPoi</see> classes containing information about the found POIs.
	 * \param nListSize Number of POIs to return.
	 * \param dwCategoryNumber Category ID. If this value is filled with standard value, original POIs are found. Set to PoiService.USERDEFINE for custom POI. Possible values are enumerated in \ref PoiService enum.
	 * \param lpszCategoryName Custom POI category name, if custom POI is searched.
	 * \param lX X-coordinate of place, where to search.
	 * \param lY Y-coordinate of place, where to search.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Distance between taken position and POI is computed bee-line.\n\n
	 * If dwCategoryNumber=PoiService.USERDEFINE it is necessary to define also lpszCategoryName. Otherwise category name is obtained from category ID.\n\n
	 * X and Y coordinates are geographical longitude and latitude in degrees multiplied by 100000.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	FindNearbyPoi( LpError  lpError, SPoi *&lpPoiList, int &nListSize, DWORD dwCategoryNumber, LPCTSTR lpszCategoryName,
		LONG lX, LONG lY, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns the list of POI categories
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoiCategories Array of objects of \ref SPoiCategory "SPoiCategory" class.
	 * \param nSize Size of the lpPoiCategories array.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetPoiCategoryList( LpError lpError, SPoiCategory *&lpPoiCategories, int &nSize, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function set the POI warning based on the attributes of the SPoiCategory instance.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpPoiCategory POI category, see \ref SPoiCategory "SPoiCategory" class.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int SetPoiWarning( LpError lpError, SPoiCategory *lpPoiCategory, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Highlight the POI
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPoiCategory User defined POI category name
	 * \param lpszPoiName POI name
	 * \param lpszSound Sound to play when Highlight POI
	 * \param cpPoiLocation Position of POI
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int HighlightPoi( LpError lpError, LPCTSTR lpszPoiCategory, LPCTSTR lpszPoiName, LPCTSTR lpszSound, LONGPOSITION cpPoiLocation, DWORD dwMaxTime = DEFAULT_MAX_TIME );


	static int UpdatePois( LpError lpError, LPCTSTR lpszText, INT nFormat, LPTSTR &lpszResult, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////
	// location
	//////////////////

	/*! \brief The function returns address corresponding to given location.
	 * \param lpError Additional error information returned from Drive.
	 * \param cpLocation Location for which is the address searched.
	 * \param lpszAddress Found address in format: "ISO,city,street,house number"
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Location info was not found because of invalid location syntax.
	 */
	static int  GetLocationInfo( LpError  lpError, LONGPOSITION cpLocation, LPTSTR lpszAddress, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This overloaded function returns address and road information corresponding to given location.
	 * \param lpError Additional error information returned from Drive.
	 * \param cpLocation Location for which we want to search for address.
	 * \param lpszAddress Found address in format: "ISO,city,street,house number"
	 * \param lpRoadInfo Class containing information about the road on that position.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Parameter strIsoCode is official ISO code of the country. The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a> ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY. Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Location info was not found because of invalid location syntax.
	 */
	static int  GetLocationInfo( LpError  lpError, LONGPOSITION cpLocation, LPTSTR lpszAddress, SRoadInfo *lpRoadInfo, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns location corresponding to taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param cpLocation Location corresponding to taken address.
	 * \param lpszAddress Address in "ISO,city/ ZIP,street,house number" format. If address is in "ISO,city/ZIP,street,street" format, function will return coordinates of intersection.
	 * \param bPostal Flag determining whether second address parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param bValueMatch Flag determining whether the result will be the exact match or the best value match (true for fuzzy search of address)
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Address parameter house number is optional. If you do not want to fill it write address like this:\n
	 * "SVK,Bratislava,Einsteinova,"\n\n
	 * Second address parameter can represent city name or ZIP code.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	 * Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  LocationFromAddress( LpError  lpError, LONGPOSITION & cpLocation, LPCTSTR lpszAddress, BOOL bPostal, BOOL bValueMatch, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns location corresponding to taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszAddress Address in "ISO,city/ ZIP,street,house number,extra city,extra street" format.
	 * \param bPostal Flag determining whether second address parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param lpPositions Array of \ref SWayPoint "SWayPoint" which contains retrieved items.
	 * \param nCount Size of the lpPositions array.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The function returns location corresponding to taken address. In some cases there can be more cities with the same name in one country or more streets with the some name in one city.\n
	 * If there are more results corresponding to taken address LocationFromAddressEx stores the results into array of SWayPoint.\n\n
	 * If you want to strictly specify address you can fill optional address parameters of address - extra city and extra street.\n\n
	 * Extra city strictly defines region in country where city is situated. It should be set to province or canton of the country.\n
	 * Extra street strictly defines part of city where street is situated so set this parameter to part of city.\n\n
	 * LocationFromAddressEx function always fills extra city and extra street parts of address so if there are more results you can choose which one is that you meant.\n\n
	 * If you do not want to fill optional street parameters make address like this:\n
	 * "SVK,Bratislava,Einsteinova,1,,".\n
	 * Optional address parameters are extra city, extra street and house number.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	 * Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	LocationFromAddressEx( LpError  lpError, LPCTSTR lpszAddress, BOOL bPostal, SWayPoint * &lpPositions,
		int &nCount, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns location corresponding to taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszAddress Address in "ISO,city/ ZIP,street,house number,extra city,extra street" format.
	 * \param bPostal Flag determining whether second address parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param bFuzzySearch Flag determining whether the result will be the exact match or the best value match (true for fuzzy search of address)
	 * \param lpPositions Array of \ref SWayPoint "SWayPoint" which contains retrieved items.
	 * \param nCount Size of the lpPositions array
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * The function returns location corresponding to taken address. In some cases there can be more cities with the same name in one country or more streets with the some name in one city.\n\n
	 * If there are more results corresponding to taken address LocationFromAddressEx stores the results into array of SWayPoint.\n\n
	 * If you want to strictly specify address you can fill optional address parameters of address - extra city and extra street.\n\n
	 * Extra city strictly defines region in country where city is situated. It should be set to province or canton of the country.\n
	 * Extra street strictly defines part of city where street is situated so set this parameter to part of city.\n\n
	 * LocationFromAddressEx function always fills extra city and extra street parts of address so if there are more results you can choose which one is that you meant.\n\n
	 * If you do not want to fill optional street parameters make address like this:\n
	 * "SVK,Bratislava,Einsteinova,1,,".\n
	 * Optional address parameters are extra city, extra street and house number.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n
	 * The list of ISO codes can be found at <a href="http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html">http://userpage.chemie.fu-berlin.de/diverse/doc/ISO_3166.html.</a>\n
	 * ISO code of United States of America consists of character "U" plus code of state. E.g New York has ISO code UNY.\n
	  Indian states ISO codes can be found at <a href="http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646">http://devforum.sygic.com/viewtopic.php?f=15&t=2925&p=3646&hilit=I01&sid=354efb86bb92dc0dcdfcc1bb8d656c20#p3646</a>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int	LocationFromAddressEx( LpError  lpError, LPCTSTR lpszAddress, BOOL bPostal, BOOL bFuzzySearch, SWayPoint * &lpPositions,
		int &nCount, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function starts Full text search for given text string.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszText Text string to search.
	 * \param nCallbackID the id of Callback. The results are provided via callback asynchronously 
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */

	static int SearchLocation( LpError lpError, LPCTSTR lpszText, INT &nCallbackID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows hierarchy dialog and returns location of taken address.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszIso ISO code of map (country) where address is located. This parameter is obligatory.
	 * \param lpszCity Name of city or postal code of the city in taken country.
	 * \param lpszStreet Street in taken city.
	 * \param bPostal Flag determining whether City parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param lpPosition Reference to instance of \ref SWayPoint "SWayPoint" type determining location of taken address.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */

	static int	ShowHierarchyDialog( LpError lpError, LPCTSTR lpszIso, LPCTSTR lpszCity, LPCTSTR lpszStreet, BOOL bPostal,
		SWayPoint * &lpPosition, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns list of founded items from NameHierarchy.
	 * \param lpError Additional error information returned from DriveMe.
	 * \param lpszAddress Address in format "Country,City/ ZIP,Street"
	 * \param bPostal Flag determining whether City parameter represents city or ZIP code.\n
	 * true  - ZIP code.\n
	 * false - City.
	 * \param nMaxCount Maximum count of founded items.
	 * \param lpList Array of \ref SWayPoint "SWayPoint" which contains retrieved items.
	 * \param nCount Size of the lpList array.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetAddressList( LpError lpError, LPCTSTR lpszAddress, BOOL bPostal, int nMaxCount, SWayPoint * &lpList, int &nCount, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Get coordinates of road given by map iso code and offset
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszIsoCode ISO code of map
	 * \param lRoadOffset Road offset
	 * \param cpPosition Coordinates of road position
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetCoordinatesFromOffset( LpError lpError, LPCTSTR lpszIso, LONG lRoadOffset, LONGPOSITION &cpPosition, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/////////////////////
	// maps
	/////////////////////

	/*! \brief The function loads map from .mlm file.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszLoadPath Full path to .mlm file.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  SwitchMap( LpError  lpError, LPCTSTR lpszLoadPath, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows taken location on BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param cpLocation Location which will be shown on BrowseMap.
	 * \param lZoom Distance (in meters) which will be shown between left and right border of the BrowseMap. Range of this parameter should be between 256 and 1000000.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Point with taken location will be shown in the middle of BrowseMap.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  ShowCoordinatesOnMap( LpError  lpError, LONGPOSITION cpLocation,
		LONG lZoom, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows specific piece of map on the BrowseMap according to your selected coordinates of top left and bottom right corner.
	 * \param lpError Additional error information returned from Drive.
	 * \param rcRect Rectangle to show on the BrowseMap.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * return 1 if successful, other value otherwise.
	 *
	 * Zoom will be adjusted so that entire rectangle will be shown.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  ShowRectangleOnMap( LpError  lpError, LONGRECT rcRect, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows picture on BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszBitmapPath Full path to desired picture.
	 * \param lX X-coordinate of picture position on BrowseMap.
	 * \param lY Y-coordinate of picture position on BrowseMap.
	 * \param nBitmapID Picture ID that can be used later to manipulate with picture. Value is set by AddBitmapToMap function.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Picture must be of 32 bit bmp format.\n\n
	 * X and Y coordinates represents geographical longitude and latitude taken in meters.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int AddBitmapToMap( LpError  lpError, LPCTSTR lpszBitmapPath, long lX, long lY,
		UINT &nBitmapID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function removes picture from BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param nBitmapID Picture ID retrived from function AddBitmapToMap. Identifies picture to be removed.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * RemoveBitmap function removes bitmap from BrowseMap and also deletes all allocated memory.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int RemoveBitmap( LpError  lpError, UINT nBitmapID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function removes all pictures from BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * RemoveAllBitmaps function removes bitmaps from BrowseMap and also deletes all allocated memory.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int RemoveAllBitmaps( LpError  lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows or hides picture on BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param nBitmapID Picture ID returned from function AddBitMapToMap. Identifies picture to be shown/hidden.
	 * \param bShow Flag determining whether picture will be shown or hidden.\n
	 * true - picture will be shown\n
	 * false - picture will be hidden
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int ShowBitmap( LpError  lpError, UINT nBitmapID, BOOL bShow, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function moves picture on BrowseMap.
	 * \param lpError Additional error information returned from Drive.
	 * \param nBitmapID Picture ID returned form function AddBitMapToMap. Identifies picture to be moved.
	 * \param lX X-coordinate of new picture position on BrowseMap.
	 * \param lY Y-coordinate of new picture position on BrowseMap.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * X and Y coordinates represents geographical longitude and latitude taken in meters.\n\n
	 * BrowseMap is map shown on after clicking Browse Map menu button. BrowseMap allows browse the loaded maps and change zoom.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int MoveBitmap( LpError  lpError, UINT nBitmapID, long lX, long lY, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/////////////////
	// dialogs
	/////////////////
	/*! \brief The function shows a dialog with a specified message.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszMessage Text of the message to show.
	 * \param nButtons Type of used buttons.\n
	 *	- 1 - MbOk\n
	 *	- 2 - MbOkCancel\n
	 *	- 3 - MbYesNo\n
	 * \param bWaitForFeedback Flag determining whether Drive returns reply before user click the button.\n
	 * true - Drive will return reply after user click the button\n
	 * false - Drive will return reply immediately.
	 * \param nUserFeedback nUserFeedback informs which button clicked.\n
	 * 101 - Cancel/No button\n
	 * 201 - Ok/Yes button
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * \return 1 if successful, other value otherwise.
	 *
	 * ShowMessage shows dialog over full device screen with take message.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  ShowMessage( LpError  lpError, LPCTSTR lpszMessage, int nButtons,
		BOOL bWaitForFeedback, BOOL bShowApplication, int & nUserFeedback, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function shows flash message.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszMessage Text of the message to be shown.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground\n
	 * false - Drive will stay in background
	 * \return 1 if successful, other value otherwise.
	 *
	 * FlashMessage shows flashing message with taken text in top-right corner.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int FlashMessage( LpError  lpError, LPCTSTR lpszMessage, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Close dialogs in Drive application
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int CloseDialogs( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	static int ErrorReport ( LpError lpError, DWORD &dwID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/////////////////////
	// itinerary
	/////////////////////
	/*! \brief The function creates itinerary and fills it with items from PointArr.
	 * \param lpError Additional error information returned from Drive.
	 * \param lstPointArr List of items which will be inserted into itinerary.
	 * \param nSize Size of the lstPointArr array.
	 * \param lpszItineraryName Itinerary name.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * AddItinerary creates itinerary and fills it with items from lstPointArr. lstPointArr array must contain at least one item otherwise itinerary will not be created. Existing itinerary with the same name will be overwriten.\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  AddItinerary( LpError  lpError, SStopOffPoint* lstPointArr, int nSize, LPCTSTR lpszItineraryName,
		DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function creates itinerary from the JSON string.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryJson Itinerary in JSON format.
	 * \param lpszItineraryName Itinerary name.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * AddItinerary creates itinerary from the JSON string. Existing itinerary with the same name will be overwriten.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int  AddItinerary( LpError  lpError, LPCTSTR lpszItineraryJson, LPCTSTR lpszItineraryName,
		DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function computes route based on taken itinerary. If Drive has valid GPS signal it starts navigation.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of the itinerary which will be used to compute route.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * \param dwFlags Parameter Flags determines route computing properties.\n
	 * Possible values are enumerated in:\n
	 * \ref NavigationParams.
	 * \return 1 if successful, other value otherwise.
	 *
	 * If Drive does not have valid GPS signal first waypoit in itinerary must be marked as START.\n\n
	 * Parameter dwFlags determines route computing properties.\n
	 * For example it is possible to ask user to avoid toll roads or (later) notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|).\n
	 * For more informations see \ref NavigationParams enum.\n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled)\n\n
	 * <b>Itinerary used to compute route must contain item of type "finish". If you do not have valid GPS position itinerary must contain also item of type "start".</b>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 *	- -7 - Itinerary is empty
     *  - -8 - Itinerary has invalid format (from version 15j)
     *  - -9 - One or more waypoints were not found (from version 15j)
     *  - -10 - Itinerary was not found (from version 15j)
	 */
	static int SetRoute( LpError  lpError, LPCTSTR lpszItineraryName, DWORD dwFlags, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function computes route based on taken itinerary. If Drive has valid GPS signal it starts navigation.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of the itinerary which will be used to compute route.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * \param dwFlags Parameter Flags determines route computing properties.\n
	 * Possible values are enumerated in:\n
	 * \ref NavigationParams.
	 * \param bCloseDelivery Parameter determining whether the waypoint is in restricted area or not\n
	 * true - if a waypoint is in delivery area, the route will be calculated\n
	 * false - if a waypoint is in delivery area, it will be considered restricted area
	 * \return 1 if successful, other value otherwise.
	 *
	 * If Drive does not have valid GPS signal first waypoint in itinerary must be marked as START.\n\n
	 * Parameter Flags determines route computing properties.\n
	 * For example it is possible to ask user to avoid toll roads or (later) notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|).\n
	 * For more informations see <see cref="ApplicationAPI.h::NavigationParams">NavigationParams</see> enum.\n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled)\n\n
	 * <b>Itinerary used to compute route must contain item of type "finish". If you do not have valid GPS position itinerary must contain also item of type "start".</b>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 *	- -7 - Itinerary is empty
     *  - -8 - Itinerary has invalid format (from version 15j)
     *  - -9 - One or more waypoints were not found (from version 15j)
     *  - -10 - Itinerary was not found (from version 15j)
	 */
	static int SetRoute( LpError  lpError, LPCTSTR lpszItineraryName, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function computes route based on taken itinerary. If Drive has valid GPS signal it starts navigation.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of the itinerary which will be used to compute route.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \param bShowApplication Flag determining whether Drive should be brought to foreground automatically.\n
	 * true - Drive will be brought to foreground.\n
	 * false - Drive will stay in background.
	 * \param dwFlags Parameter Flags determines route computing properties.\n
	 * Possible values are enumerated in:\n
	 * \ref NavigationParams.
	 * \param bCloseDelivery Parameter determining whether the waypoint is in restricted area or not\n
	 * true - if a waypoint is in delivery area, the route will be calculated\n
	 * false - if a waypoint is in delivery area, it will be considered restricted area
	 * \return 1 if successful, other value otherwise.
	 *
	 * If Drive does not have valid GPS signal first waypoint in itinerary must be marked as START.\n\n
	 * Parameter Flags determines route computing properties.\n
	 * For example it is possible to ask user to avoid toll roads or (later) notify user that not all toll roads can be avoided.\n\n
	 * To join more flags together use logical or operator (|).\n
	 * For more informations see <see cref="ApplicationAPI.h::NavigationParams">NavigationParams</see> enum.\n\n
	 * If waypoint is in restricted area , the function will return lX,lY coordinates of closest reached point in error description (truck attributes enabled)\n\n
	 * <b>Itinerary used to compute route must contain item of type "finish". If you do not have valid GPS position itinerary must contain also item of type "start".</b>\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 *	- -1 - Navigation not started because address was not found or closest reached point was found
	 *	- -3 - Navigation not started. Drive is already navigating.
	 *	- -5 - User canceled route computing.
	 *	- -6 - Drive is waiting for valid GPS signal.
	 *	- -7 - Itinerary is empty
     *  - -8 - Itinerary has invalid format (from version 15j)
     *  - -9 - One or more waypoints were not found (from version 15j)
     *  - -10 - Itinerary was not found (from version 15j)
	 */
	static int SetRoute( LpError  lpError, LPCTSTR lpszItineraryName, DWORD dwFlags, BOOL bCloseDelivery, BOOL bShowApplication, int &nWrongWaypointsCount, int *&lpWrongWaypoints, DWORD dwMaxTime = DEFAULT_MAX_TIME );


	/*! \brief The function adds new waypoint to taken itinerary.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of itinerary where new item will be added.
	 * \param lpStopOffPoint Reference to instance of SStopOffPoint class containing informations about waypoint to be added to itinerary.
	 * \param nIndex Index of position where new waypoint will be inserted.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * If nIndex is lower than 0 or higher than number of items in itinerary the waypoint will be added at the end of list.\n\n
	 * It is necessary to set Location, nPointType and Caption members of StopOffPoint (see \ref SStopOffPoint "SStopOffPoint" class).\n\n
	 * See <b>Coordinates conversion</b> section in <a href="trouble.htm">TROUBLESHOOTING</a> page.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int AddEntryToItinerary( LpError  lpError, LPCTSTR lpszItineraryName, SStopOffPoint* lpStopOffPoint, UINT nIndex,
		DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function deletes waypoint from itinerary at taken position.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of itinerary from which waypoint will be deleted.
	 * \param nIndex Index in itinerary list which defines which waypoint will be deleted.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int DeleteEntryInItinerary( LpError  lpError, LPCTSTR lpszItineraryName, UINT nIndex, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function deletes taken itinerary.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of itinerary to delete.
	 * \param dwMaxTime Maximum time (in milliseconds) which function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int DeleteItinerary( LpError lpError, LPCTSTR lpszItineraryName, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function returns list of waypoints in itinerary.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of itinerary from which waypoints will be retrieved. If the name of itinerary is "default", function returns the list of waypoints from current route.
	 * \param PointsArr Array of \ref SStopOffPoint "SStopOffPoint" which will contain waypoints of itinerary after function execution.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetItineraryList( LpError lpError, LPCTSTR lpszItineraryName, SStopOffPoint * &PointsArr, int &nWayPointsCount, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function optimizes taken itinerary.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszItineraryName Name of itinerary to optimize.
	 * \param dwMaxTime Maximum time (in milliseconds) which function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int OptimizeItinerary( LpError lpError, LPCTSTR lpszItineraryName, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function optimizes current route.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) which function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int OptimizeRoute( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function skips the waypoint, which is next when the function is called
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum of time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int SkipNextWaypoint( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );


	/////////////////////
	// gps input
	/////////////////////
	/*! \brief The function enables to send GPS data by \ref SendGpsData SDK function.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int EnableExternalGpsInput( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function disables to send GPS data by \ref SendGpsData SDK function.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int DisableExternalGpsInput( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function sends GPS data to Drive.
	 * \param lpszData Data string to send to Drive.
	 * \param nSize Size of the lpszData string.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Sent data must be in NMEA format. Data have to contain $GPGGA, $GPGSA, $GPRMC and $GPGSV strings.\n\n
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static BOOL SendGpsData( LPCTSTR lpszData, int nSize );

	/*! \brief The function turns Drive GPS module ON and OFF.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPort Name of port which is used to receive GPS signal.
	 * \param dwBaudRate Baude rate used in GPS port.
	 * \param bSwitchOn Flag determining whether GpsSwitchOn turns GPS module ON or OFF.\n
	 * true - GpsSwitchOn turns GPS module ON.\n
	 * false - GpsSwitchOn turns GPS module OFF.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	-3 - Function reached timeout.
	 */
	static int GpsSwitchOn( LpError lpError, LPCTSTR lpszPort, DWORD dwBaudRate, BOOL bSwitchOn, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////////////////////////////////////////////////////////////
	// info
	//////////////////////////////////////////////////////////////////////////
	/*! \brief The function returns the speed limit of the current road.
	 * \param lpError Additional error information returned from Drive.
	 * \param nSpeedLimit Speed limit
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetCurrentSpeedLimit ( LpError lpError, int &nSpeedLimit, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function returns the next turn instruction while navigating.
	 * \param lpError Additional error information returned from Drive.
	 * \param SRouteInstruction Next turn instruction on the route. See \ref tagRouteInstruction "SRouteInstruction" class.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GetNextInstruction ( LpError lpError, SRouteInstruction *lpInstruction, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////////////////////////////////////////////////////////////
	// online
	//////////////////////////////////////////////////////////////////////////
	/*! \brief Defines if the navigation has to connect to or disconnect from online services. The online services include functions as live traffic from the server and other.
	 * \param lpError Additional error information returned from Drive.
	 * \param bOnline Parameter which determines that connection to online services.\n
	 * true - connect\n
	 * false - disconnect
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int GoOnline( LpError lpError, BOOL bOnline, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Enters login credentials for online services, such as life traffic. If not credentials are given, the application logs in anonymously.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszUserName User name
	 * \param lpszPassword Password
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int OnlineServicesLogin( LpError lpError, LPCTSTR lpszUserName, LPCTSTR lpszPassword, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Adds a custom TMC event. This event is independent on the events received online.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpTmcEvent TMC event  defined in the STmcEvent class.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int AddTMCEvent( LpError lpError, STmcEvent *lpTmcEvent, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Removes a custom TMC event. Each custom event has an ID given to it by the navigation during creation.\n
	 * However, TMC events should be defined so that they expire with their validity time.
	 * \param lpError Additional error information returned from Drive.
	 * \param wTmcEventId The ID of the TMC event returned by AddTMCEvent function.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int RemoveTMCEvent( LpError lpError, WORD wTmcEventId, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Erases all the custom TMC events defined with AddTMCEvent function.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int ClearTMCTable( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Sets/gets online services settings
	 * \param lpError Additional error information returned from Drive.
	 * \param lpSettings Online services settings  defined in the \ref SOnlineServicesSettings "SOnlineServicesSettings" class.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int OnlineServicesSettings( LpError lpError, SOnlineServicesSettings *lpSettings, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////////////////////////////////////////////////////////////
	// TTS
	//////////////////////////////////////////////////////////////////////////
	/*! \brief Uses the TTS engine, if installed, to speak the given text message.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszText Text message to be read by TTS
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if successful, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int PlaySoundTTS( LpError lpError, LPCTSTR lpszText, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////////////////////////////////////////////////////////////
	// additional
	//////////////////////////////////////////////////////////////////////////
	/*! \brief The function loads GF file then draws GF data on map. See specification of GF files here <a href="gfspec.html">GF Files specification</a>
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPath GF file full path
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int LoadGFFile( LpError lpError, LPCTSTR lpszPath, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function unloads GF file and erases all the lines drawn before. See specification of GF files here <a href="gfspec.html">GF Files specification</a>
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPath GF file full path.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int UnloadGFFile( LpError lpError, LPCTSTR lpszPath, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function loads external file GF or TMC data.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPath External file full path.
	 * \param nFileType External file type\n
	 * 1 - GF file\n
	 * 2 - TMC file (xml format)
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found, other value otherwise.
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int LoadExternalFile( LpError lpError, LPCTSTR lpszPath, int nFileType, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function unloads external file GF or TMC data
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszPath External file full path
	 * \param nFileType External file type\n
	 * 1 - GF file
	 * 2 - TMC file
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and unloaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int UnloadExternalFile( LpError lpError, LPCTSTR lpszPath, int nFileType, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief The function reloads all external files stored in geofiles folder.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int ReloadExternalFiles( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	//////////////////////////////////////////////////////////////////////////
	// trip book
	//////////////////////////////////////////////////////////////////////////
	/*! \brief This function starts to record a new Trip Book.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszTripname Name of the Trip Book recording
	 * \param nDataMode Trip Data mode enumerated in \ref TripBookRecordDataMode enum.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int TripStart( LpError lpError, LPCTSTR lpszTripname, int nDataMode, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function inserts in the Trip Book an event created by user.
	 * \param lpError Additional error information returned from Drive.
	 * \param EventName Event name
	 * \param CustomID Event custom ID created by user
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * User in any moment of the Trip Book recording can create an event with custom ID, and to insert it in the Trip Book.
	 */
	static int TripAddUserEvent( LpError lpError, LPCTSTR lpszEventName, UINT nCustomID, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief This function stops the recording of the Trip Book.
	 * \param lpError Additional error information returned from Drive.
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int TripEnd( LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME );

	/*! \brief Loads an offroad guided route (OFG) and starts navigation following that route.
	 * \param lpError Additional error information returned from Drive.
	 * \param lpszFileName Path and file name of the OFG file to be loaded
	 * \param nStartFromIndex Start index of the route
	 * \param dwMaxTime Maximum time (in milliseconds) function can take. If dwMaxTime=0 function execution is not time limited.
	 * \return 1 if file was found and loaded, other value otherwise
	 *
	 * Possible error codes returned from Drive are:
	 *	- 0 - Function not succeeded.
	 *	- 1 - Function succeeded.
	 *	- 2 - Drive not succeeded.
	 *	- 3 - Function reached timeout.
	 */
	static int LoadOFGRoute( LpError lpError, LPCTSTR lpszFileName, int nStartFromIndex, int nFlags, DWORD dwMaxTime /*= DEFAULT_MAX_TIME*/ );

	static int GetOFGRouteStatus( LpError lpError, LPTSTR lpszStatus, DWORD dwMaxTime /*= DEFAULT_MAX_TIME*/ );

	static int SaveOFGRoute( LpError lpError, LPCTSTR lpszFileName, int nFromIndex, LONGPOSITION cpFrom, int nToIndex, LONGPOSITION cpTo, DWORD dwMaxTime /*= DEFAULT_MAX_TIME*/ );


	static int GetMobileData(LpError lpError, LPTSTR &lpMobileData, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int SetMobileData(LpError lpError, LPCTSTR lpMobileData, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int ResetMobileData(LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	
	static int GetMapCorrectionEvents(LpError lpError, LPTSTR &lpszTable, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int AddMapCorrectionEvents(LpError lpError, LPCTSTR lpszTable, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int ClearMapCorrectionEvents(LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int CalculateRoute(LpError lpError, LPCTSTR lpszWaypoints, LPTSTR &lpszResult, DWORD dwMaxTime = DEFAULT_MAX_TIME);

    static int RunTest(LpError lpError, LPCTSTR lpszJson, LPTSTR &lpszResult, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	// TODO dokumentacia
	static int ShowDialog(LpError lpError, INT nDialogID, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int LoadGeoFile(LpError lpError, LPCTSTR lpszGeoFileName, LPCTSTR lpszGeoJson,  DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int UnloadGeoFile(LpError lpError, LPCTSTR lpszGeoFileName, DWORD dwMaxTime = DEFAULT_MAX_TIME);

	static int UnloadGeoFiles(LpError lpError, DWORD dwMaxTime = DEFAULT_MAX_TIME);

public:
	/*! \brief This function transform actual time from milliseconds to year, month, day, hour, minute second type.
	 * \param lTime Time in milliseconds
	 * \param nYear Year
	 * \param nMonth Month
	 * \param nDay Day
	 * \param nHour Hour
	 * \param nMinute Minute
	 * \param nSecond Second
	 * \return 1 if time was transformed, other value otherwise
	 */
	static BOOL TimeGetTime ( LONG lTime, USHORT *nYear, BYTE *nMonth,
		BYTE *nDay, BYTE *nHour, BYTE *nMinute, BYTE *nSecond );
};

#endif // !defined __API_H__
