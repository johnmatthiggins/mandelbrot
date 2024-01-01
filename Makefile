build:
	export LDFLAGS="-L/opt/homebrew/Cellar"
	export CPPFLAGS="-I/opt/homebrew/Cellar"
	g++ *.cc -o main
