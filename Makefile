build:
	export LDFLAGS="-L/opt/homebrew/Cellar"
	export CPPFLAGS="-I/opt/homebrew/Cellar"
	g++ *.cc -o main -O3 -lpthread -std=c++11

run:
	./main
	./load.py output
