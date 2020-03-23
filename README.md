# EE P 520 A Wi 20 - Project

## Project Overview and Goal
This project creates a maze like environment. The maze is static. The project puts four robots at the start and have them explore until it finds the end of the maze. The robot will start over once it reaches to the end. The project is not perfect because the robot might get stuck sometimes.

## Project Installation 
This project needs to install Docker. 

To get started, first get the code for the porject:
```
$ git clone https://github.com/pinzhu/520-Project
```

Go to the directory: 
```
$ cd 520-Project
```

To start a Docker container with ENVIRO pre-loaded into it, do:
```
$ docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:alpha bash
```

To make the project:
```
cd my_project
make
```

## Project Running
To start the enviro server:
```
esm start
enviro
```

In a browser, open this link:
http://localhost

To stop the simulation, press control+C.

## Project Key Challenges and Addressed
The key challenges in this project is that it is time consuming to design, scale and draw blocks for the maze. It is hard to make the coordinates accurate and blocks algin. Later I decide to build a grid to make maze coordiates more visible and delete the grid after the maze is done.


## Project Acknowledgements
This project is built based on the enviro project: https://github.com/klavinslab/enviro
