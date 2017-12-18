#include "HEADERS/START"

#define VIDEO "v.mp4"

/*
RECTS(X)
SCALE(DIM)
SCALE(FRAME,DIM)
*/


START{
	
}

LOOP{
	SCALE(0.5)
	
	return OK;
}

SHOW{
	
	
	imshow("img",frame);
}

KEYSPACE{

	
}








#include "HEADERS/END"
