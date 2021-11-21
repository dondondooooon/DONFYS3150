allparallell: CompileParallell LinkParallell Execute

allseries: CompileSeries LinkSeries Execute

	
CompileParallell:
	g++ -c main.cpp src/*.cpp -I include -std=c++11 -Xpreprocessor -fopenmp

CompileSeries:
	g++ -c main.cpp src/*.cpp -I include -std=c++11

LinkParallell:
	g++ *.o -o main.exe -larmadillo -lomp

LinkSeries:
	g++ *.o -o main.exe -larmadillo

Execute:
	./main.exe
