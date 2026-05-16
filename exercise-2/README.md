# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?
  when we want full control on raw packets directly

### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
  no
- Where is the official C++23 spec?
  https://www.iso.org/standard/83626.html
- Why was this link chosen instead?
  this is available freely and is the closest to the official iso spec
- Is this a helpful reference for learning C++?
  surely, but for beginner and quick reference, sites like cppreference would be better
- Can the various implementations of C++ compilers be different from the
  C++ standard?
  yes
- What are the most widely used and most significant C++ compilers?
  g++ gnu, msvc(windows)
- Where is the equivalent spec for C++26?
  https://eel.is/c++draft/
- Where do you find the spec for the HTTP protocol?
  https://www.rfc-editor.org/rfc/rfc9110.html
- What about HTTPS? Is there a spec for that protocol?
  HTTPS simply stands for "HTTP over TLS", does its a combination of their specs.

## Introduction to C++ and Sockets Programming

- Read the code in `src/`
- Are there any bugs in this code? 
  The code seems to be working perfectly without any modifications on testing it out by compiling, thus there are no bugs in the code
- What can you do to identify if there are bugs in the code?
  We can use gdb debugger or use a c++ extension in the IDE

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
  The code is modular here, having easy to read function names for different purposews. In exercise 1, it was all in one big code, making it hard to debug/understand
- Is this code better or worse than exercise-1?
  Much better
- What are the tradeoffs compared to exercise-1?
  Slightly more calls(calling functions) and bigger code, but extremely enhanced readability.
- Are you able to spot any mistakes or inconsistencies in the changes?
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
  not much
- What do we mean when we say performance?
  mainly responsiveness(how fast) and efficient space utilisation
- How do we measure performance in a program?
  Measuring time taken for execution and space occupied in memory

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
  Simply add a breakpoint by clicking on line number and then start debug functionality.
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?