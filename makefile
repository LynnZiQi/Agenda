CC := g++-4.8 -g
FLAGS := -std=c++11 -w

bin/Agenda : build/Agenda.o build/AgendaService.o build/AgendaUI.o build/Storage.o build/Meeting.o build/User.o build/Date.o
	@mkdir -p bin
	g++-4.8 -g -std=c++11 -w -I./include build/Agenda.o build/AgendaService.o build/AgendaUI.o build/Storage.o build/Meeting.o build/User.o build/Date.o -o $@

build/Date.o : src/Date.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/Date.cpp -o $@

build/User.o : src/User.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/User.cpp -o $@

build/Meeting.o : src/Meeting.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/Meeting.cpp -o $@

build/Storage.o : src/Storage.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/Storage.cpp -o $@

build/AgendaUI.o : src/AgendaUI.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/AgendaUI.cpp -o $@

build/AgendaService.o : src/AgendaService.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/AgendaService.cpp -o $@

build/Agenda.o : src/Agenda.cpp
	@mkdir -p build
	g++-4.8 -g -std=c++11 -w -I./include -c src/Agenda.cpp -o $@

clean:
	@rm -rf build
	@rm -rf bin
