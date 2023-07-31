# TechTask
Technical Task for Camp

This is a simple C++ application that searches for a file with a given name in the specified root directory and its subdirectories. The application creates multiple threads to perform the search concurrently for faster file lookup.

## Requirements

- C++ compiler that supports C++17
- CMake (version 3.23 or higher)

## Usage

1. Clone the repository to your local machine.

2. Navigate to the project directory.

3. Run the application.
   ./tech
   
The program will prompt you to enter the filename you want to search for.

The program will start searching for the file in the root directory ("/") and its subdirectories using multiple threads.

If the file is found, the program will display the full path to the file.

If the file is not found, the program will display a message: "File not found."

## Configuration

You can modify the following constants in the main.cpp file to configure the application:

MAX_THREADS: Maximum number of concurrent threads for file search. Adjust this value based on your system's capabilities.

