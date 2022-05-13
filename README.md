# Unix Systems Programming HomeWork 1 Spring 2022

Athors:
- Lionis Emmanouil Georgios(akis)

## Compile and Execution Commands: ##

### Compile and Ececute the C programs ##
The project contains a Makefile which is responsible for the compilation and execution of the program in c. So:

- compile : `make`
- compile and execution: `make run`
- compile and valgrind: `make valgrind`

In the Makefile you can *uncomment* or *change* the ARG section. The ARG section passes the arguments to the programm.
If the ARG section is commented, then the program will be executed without arguments and will listen to the same folder that the
program is in.

If the ARG section is not commented then the arguments have to be `ARGS= -p [path]` 
with [path] being the folder that you want the program to listen to.

### Compile and Execute the bash program ##
You will have to execute the bash program by writing: `./finder [args]` with args being all the TLD arguments that the user wants

If there is an execute permission error you will have to write: `chmod +x ./finder`

## Summary of the program: ##
The program in c hears if in a folder there is created or moved to that folder a <filesname> and then it checks if that file has any urls. It collects those urls and extracts the location and the appearance of the location. Later on it prints them in the folder *output* in a file <filename>.out (which is either created or written on).
  
The bash script sees all the files in folder *output* that have an ending *.out* and then sees if the TLD argument that it took is in there. It counts the appearance of it by seeing in how many locations it is on and how many times those locations have appeared and then echos the result.

## Explanation of the files: ##
There are 2 folders (include,modules), which help organize the files. The include folder has all the necessary .h files. The modules folder has all the executes of the listern,worker and the basic Data Structers Queue and List. 
  
## Explanation of the code: ##
The code has been separated into 3 parts. The manager, listener and worker.

### Listener ###
The listener function uses the inotifywait program through the use of execv with arguments `-m -e created -e moved_to`.
  
### Worker ###
The worker program takes as argument a path to a FIFO (named pipe) and then copies it. Then it puts itself on stop mode. When it is awakened, it opens 
the FIFO and reads a <filename>. After that, it opens that <filename> and reads each byte. It has to also connect the string if some words are cut. After the connection, it calls the function find location which checks if the string has a url and then it puts it in the List. Later on, it creates or writes in the ./output/<filename>.out the location and how many times it is acquired. Later, id deletes everything and is put to sleep on its own.
  
### Manager ###
The Manager program checks if the arguments are correct. If they are correct, it makes a pipe. Next it forks itself. 
  
The kid(listener) uses the pipe to output every message that it has with the use of dup2 and then calls the listern function.
  
The parent(Manager) creates a queue so it can store the workers. For everything that it hears from the read. it checks if there are any available workers. Available workers are those that are stopped. If there are none, it creates a new worker by fork. The child of the fork is the worker that is executed by excv. The parent of the the fork is the manager that waits the child to be stopped and checks if there is any other available worker. After it takes from the queue that stores the available workers and makes a FIFO(named pipe). Next it wakes the worker and passes the file that it heard from the listener. Then it closes the fifo. This is done infinitely until it hears a SGNINT that it has killed all the workers and the listener.
  
The manager has also a signal handler that hears if a worker is stopped and then it marks a flag1 to true.
The manager has also a signal handler that hears if SGNINT was given and marks a flag2 to true.
  
Also it has a function put workers that if the flag1 is true it sees which workers are stopped and puts them in the queue.
Finaly, it has a function that kills all childern if the flag2 is true.

## Bash ##
The finder.sh checks if the folder ./output exists. Then it takes all the files that have .out as ending. Then for all the arguments for each file it takes each string of that file and checks if the argument is inside and how many times it has appeared and it echos it.
  
## Necessary infrastructure ##
The program has to have the inotifywait bash script and then put the correct path in the listener. 
The default inotifywait path is made such so it can run in the Linux Computer of National and Kapodestrian University of Athens.
  
