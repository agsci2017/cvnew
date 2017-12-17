#include "HEADERS/START"

#define VIDEO "v.mp4"

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)

#define RECTS(X)  \
    for(int CONCAT(tmpvar, __LINE__)=0;CONCAT(tmpvar, __LINE__)<X.size();CONCAT(tmpvar, __LINE__)++){ rectangle( frame, X[CONCAT(tmpvar, __LINE__)], Scalar( 255, 0, 200 ), 2, 1 ); }


#define SCALE1ARG(DIM) {resize(frame, frame, Size(), DIM, DIM, INTER_NEAREST);}
#define SCALE2ARG(FRAME,DIM) {resize(FRAME, FRAME, Size(), DIM, DIM, INTER_NEAREST);}

#define GET_3TH_ARG(arg1, arg2, arg3, ...) arg3
#define MACRO_CHOOSER(...) \
    GET_3TH_ARG(__VA_ARGS__, SCALE2ARG, SCALE1ARG, )

#define SCALE(...) MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)






CascadeClassifier casc;
vector<Rect2i> cars;

START{
	casc.load("cascade.xml");
	
}

LOOP{
	SCALE(0.5)
	
	casc.detectMultiScale(frame, cars, 2, 7, 0,
			cv::Size(20, 20), cv::Size(48, 48));
	cout<<cars.size()<<endl;
	
	RECTS(cars)
	
	return OK;
}

SHOW{
	
	
	imshow("img",frame);
}

KEYSPACE{

	
}








#include "HEADERS/END"
