setup:
	./setup.sh

build:
	export LDFLAGS="-L/opt/homebrew/Cellar"
	export CPPFLAGS="-I/opt/homebrew/Cellar"
	g++ *.cc -o main -O3 -lpthread -std=c++11

run:
	./main
	. venv/bin/activate && ./render.py output
