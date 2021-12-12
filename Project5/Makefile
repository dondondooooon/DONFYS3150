allparallell: CompileParallell LinkParallell Execute

allseries: CompileSeries LinkSeries Execute

allsimple: SimpleCompileLink SimpleExecute

CompileParallell:
	g++ -c main.cpp quantum.cpp -I quantum.hpp -std=c++14 -Xpreprocessor -fopenmp

CompileSeries:
	g++ -c main.cpp quantum.cpp -I quantum.hpp -std=c++14

LinkParallell:
	g++ *.o -o main.exe -larmadillo -lomp

LinkSeries:
	g++ *.o -o main.exe -larmadillo

Execute:
	./main.exe

SimpleCompileLink:
	g++ simple_main.cpp -std=c++14 -o simple_main.exe -larmadillo

SimpleExecute:
	./simple_main.exe