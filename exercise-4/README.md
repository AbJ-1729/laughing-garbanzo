# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files
- How would you compile from the command line?
  For client : g++ src/tcp_echo_client.cpp src/socket_utils.cpp -o client
  For server : g++ src/tcp_echo_server.cpp src/socket_utils.cpp -o server
- How would you compile using make?
  By creating a Makefile with the following content:
  ```
  all: client server
  client: src/tcp_echo_client.cpp src/socket_utils.cpp
  	g++ src/tcp_echo_client.cpp src/socket_utils.cpp -o client
  server: src/tcp_echo_server.cpp src/socket_utils.cpp
  	g++ src/tcp_echo_server.cpp src/socket_utils.cpp -o server
  clean:
  	rm -f client server
  ```
  Then running `make` will compile both client and server.
- How would you compile using VS Code?
  Create a `.vscode/tasks.json` file with build tasks for the client and server, then use `Terminal -> Run Build Task` in VS Code. The default build task can compile both into `build/tcp_echo_client` and `build/tcp_echo_server`, and we can run the individual `build client` or `build server` task if we only want one binary.
  

### Compiling vs Linking

- What is the difference between compiling and linking in C++?
  compiling converts source code into the object code, while linking combines object files and libraries into an executable.
- What is the difference between creating an executable and creating a 
  library?
  An executable is a standalone program that can be run, while a library is a collection of pre-compiled code that can be used by other programs. Libraries can be static (linked at compile time) or dynamic (linked at runtime).
- How do you compile a library, and then use that library to compile an
  executable?
  ```
  g++ -shared -fPIC -Wall -Wextra code.cpp -o libcode.so
  g++ code.cpp -L. -lcode -o executable
  ```
  Though in order to run we will need to specify this custom location of lib:
  ```
  export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
  ```
  This will look in current directory as well for shared libraries when running the executable.

  

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
  Many small files can seem cluttered but can be useful for dedicated small modular functionality. A few large files can be easier to navigate but can become extremely huge and difficult to manage. I would say it depends on the exact project and scenario.
- Is there a difference in compilation time between the two?
  Many small files should generally take more time to compile than a few large files, because the compiler has to open and read each file separately, but if they are well structured then in the long run when we make a change in one component, it will only require recompiling that component and not the entire codebase, which can save a lot of time.
- How can you assess performance other than compilation speed?
  Linker speed is also a factor, along with the runtime execution speed of the final executable.
  