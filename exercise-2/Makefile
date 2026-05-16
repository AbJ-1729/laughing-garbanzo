all: build/client build/server

build/client:
	mkdir build -p
	g++ -o build/client src/tcp_echo_client.cc

build/server:
	mkdir build -p
	g++ -o build/server src/tcp_echo_server.cc

clean:
	rm -f build/client build/server
	rmdir build