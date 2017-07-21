#include <string.h>
#define x_lenth 45   //
#define y_lenth 24	 //
extern int maze[][y_lenth];


typedef enum _state
{
	beginstate = 0,
	processstate,
	endstate,
}stateenum;