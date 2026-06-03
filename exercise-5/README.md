# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- What's an easy way to identify the changes in source code from one exercise
  to another?
  By using standard linux diff command.
    
## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
  This way seems pretty good since the various modules are rightly grouped under net and general utils.h, and the main client and server logic is in their respective files. It seems to promote easy maintainability and readability.
- What are the advantages and disadvantages?
  Advantages: good modularity, readability, maintainability
  Disadvantages: requires definitions and declarations to be in separate files, which can be a bit more work to set up and manage, especially for smaller projects where the overhead of multiple files might not be justified.

## Introduction to Namespace

- There are different ways namespace is being used in this exercise
- Which way is better? What are the advantages and disadvantages?
  namespace ttc = tt::chat; creates unnecessary aliasing and can be confusing, while using namespace tt::chat; can lead to name clashes if there are multiple namespaces with similar names. It's generally better to use the full namespace when referring to classes and functions, as it promotes clarity and avoids potential conflicts.

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
  I have divided in 4 files: client.cpp, client.h, server.cpp, server.h.
- What namespace and directory structure should you use? Why?
  tt:chat seems like a good namespace for this project, i have just put client.cpp, client.h, server.cpp, server.h in the src directory since the project is small and doesn't require further sub-division into directories. If the project grows larger, we can consider further sub-dividing into directories like src/client and src/server for better organization.

## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory
  structure? 
  I would judge based on the clarity, maintainability, and scalability of the structure.
- How do you judge what makes a good naming convention or programming style?
  A good naming convention and programming style should promote readability, consistency, and clarity.

## "Senses" in Programming

- Have you ever heard of programmers referring to "code smells"? How can code
  smell?
  code can smell when fundamental design principles are violated.
- What does it mean to have a sense of taste in programming? How can code
  taste?
  A sense of taste in programming refers to the ability to make good design and implementation choices that lead to clean, efficient, and maintainable code. Code can taste good when it is well-structured, follows best practices, and is easy to understand and modify.
- Is there an analogue for every sense?
  Yes, i can think of sight as code readability, touch as code maintainability etc.
- What other code senses can you think of?
  Maybe hearing as well documented code
- How many senses do humans have?
  5 primary senses(sight, hearing, touch, taste, smell)
- When would you want to see something before you touch it?
  If you are not sure about the quality of the code, we would want to see and analyse it first before touching it(modifying it) so as to avoid potential issues.
- When would you want to touch something before you see it?
  This is less common, but might happen if you have a strong intuition about how to improve the code based on your experience, even if you haven't fully analyzed it yet.