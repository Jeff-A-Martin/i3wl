all: out i3wl-server i3wl-client

out:
	mkdir -p obj/


i3wl-server: obj/i3wl-server.o
	g++ obj/i3wl-server.o -o i3wl-server
obj/i3wl-server.o: src/server/i3wl-server.cc
	g++ -c src/server/i3wl-server.cc -o obj/i3wl-server.o


i3wl-client: obj/i3wl-client.o
	g++ obj/i3wl-client.o -o i3wl-client
obj/i3wl-client.o: src/client/i3wl-client.cc
	g++ -c src/client/i3wl-client.cc -o obj/i3wl-client.o


clean:
	rm -r -f obj
	rm -f i3wl-server
	rm -f i3wl-client
