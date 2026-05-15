# Exercise 1

**Update this README with your answers to the questions below.**

## How to Approach This Exercise

Before you scroll down to the questions, try this:

1. **Don't peek at the questions yet.** Pretend you've just been handed a brief
   that says: *"Learn these topics as deeply as you can — g++ CLI, Make, Git,
   sockets, and memory management in C++."* That's the whole assignment.
   How would you go about it? What would you read, what would you try, in what
   order, and how would you know when you've understood something well enough?
   Write that plan down in this README, then actually follow it.

   I would first look up the provided reference manuals for g++, make, git and would research sources on web for sockets and memory management in C++. I have compiled all the relevant sources in Notes.

3. **Now go through the questions below and answer them like you're an LLM.**
   No live Googling, no Stack Overflow, no asking ChatGPT mid-question. You may
   refer to notes *you* took during step 1 — that's your context window. Answer
   from what you've internalised.

4. **Reflect on how it went.** Honestly:
   - Did your self-directed learning actually prepare you for the questions, or
     did you over-study things that never came up?
   - Which questions blindsided you? Why — was the topic missing from your
     plan, or did you skim past it?
   - Map your experience onto the *known knowns / known unknowns / unknown
     unknowns* idea. The interesting category is usually the last one: things
     you didn't even realise you should have learned. What were yours, and how
     could a better learning plan have surfaced them earlier?

The point of this exercise isn't to get the questions "right" — it's to notice
the gap between how you *think* you learn and how you actually do, so you can
close it.

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
-    I believe that official docs are the best source of truth, and in case of concepts like sockets and memory management, things referring to the official handbook.
- How can you tell if the source of your information is good?
-    As long as its a trusted source and has official sources backing, I believe its a "good" source of information 
- How would you define "good" in this situation?
-    Factually correct and comprehensive

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
  did using g++ -o <executable_name> <file_name>.cpp
- What are the most important command line arguments to learn for `g++`?
  I think --std(for directing which version of C++ to use), -c and -o are most important sincce -c is used in makefiles to just compile and assemble, not link, which ensures that if in a big project base, not all files change, we can simply use pre assembled versions of others(which dont depend on the changed file) and then link them all together for the final output. -W is also useful to enable various types of warnings(e.g. -Wall for all warnings, useful for analysing code quality)
- What is the difference between debug vs release versions?
  I honestly didn't expect this to be learnt for g++, thus had not included in my research. Though debug version usually is easier to troubleshoot, and thus has larger binaries, whereas release version is faster and smaller
- What are the tradeoffs between debug and release versions?
  The performance and ease of debugging tradeoff
- What arguments would you use in a debug build?
  Least optimizations, e.g. -O0
- What about for release?
  More optimizations, e.g. -O2
- What other kinds of build types are useful?
  -O1(-O) for basic optimizations

## Learn Basics of Make

- Create a Makefile that will speed up the process.
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
- How else can you learn about make?
  make -h
- How can you tell if the resource you are using is correct?
  official docs!
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables?
    By analysing timestamps of all code files and prerequisites
  - Change your Makefile such that `make clean` will remove `build/` and all
    its contents
- What are the most important command line arguments to learn for make?
  --always-make, -t
- What are the most important directives to learn about in Makefile?
  include
- What are the most important commands to implement in your Makefile?
  make all,  make clean
- Which ones are essential, which ones are nice to haves?
  clean, install etc. are essential,include is nice to have for convenience

## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?
  Traceability
- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?
  lots of small commits can be cluttering, but one big commit defeats the basic purpose of git as a version control system. Good enough number of commits with every meaningful feature addition help in debugging and easy clarity.
- What are the most important commands to know in git?
  git add, commit, push, pull, clone

## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- What do all these headers do?
- How do you find out which part of the below code comes from which header?
- How do you change the code so that you are sending messages to servers
  other than localhost?
- How do you change the code to send to a IPv6 address instead of IPv4?
- **Bonus**: How do you change the client code to connect by hostname instead
  of IP address?
  
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
- What is the difference between a pointer and a reference?
- When is it better to use a pointer?
- When is it better to use a reference?
- What is the difference between `std::string` and a C-style string?
- What type is a C-style string?
- What happens when you iterate a pointer?
- What are the most important safety tips to know when using pointers?

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
- What is the most authoritative source of information about the TCP and IP
  protocols?
- What is the most authoritative source of information about the C++
  programming language?
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
- What is the difference between LLM and AI?
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
