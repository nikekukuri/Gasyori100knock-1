# FILE = image_processing.cpp
# HDIR = -I /usr/local/opencv
# OPT = -lopencv_core -lopencv_imgproc -lopencv_imgcodecs
# 
# a.out: $(FILE)
# 	$(CXX) -Wall $(FILE) $(HDIR) $(OPT)
	
CXX = c++
CXXFLAGS =  -I/usr/local/Cellar/opencv/4.7.0_2/include/opencv4/
LDFLAGS = -L/usr/local/Cellar/opencv/4.7.0_2/lib/
LDLIBS =  -lopencv_core -lopencv_highgui -lopencv_imgcodecs
CXXVERSION = -std=c++11

main: question_17.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(CXXVERSION) $(LDFLAGS) $(LDLIBS)

clean :
	rm main
