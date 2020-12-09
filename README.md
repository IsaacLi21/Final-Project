# Final-Project

Project Summary

My final project is going to consist of two data structures. One of them will be a chronological queue and the other will be a weighted graph. I will be working by myself. The main data that I am analyzing is going to be flight data of southwest flights within the United States for a specified amount of time. In the queue will be a flight log of all the flights that will happen during that time. The flight struct will include the time of flight, distance traveled, and the beginning and end locations. In the graph, each vertex will be a city. The edges between the cities will be different flights that occur. The edges struct will have a time, distance, and a end location. They will be weighted by the distance between the beginning and the end cities. The edges will also be only 1 directional because usually the flight is 1 direction and there is no immediate return flight. In terms of user interaction, there will be a option to add flights, cancel flight, and search for flights that are going to happen. The user can also print the graph and print the queue. The user will be able to find the shortest distance to any airport from a certain point. The user can have a flight take off. The user can check if an ariport is visited. As this is during the time of COVID, there will be a funtionality where you can infect 1 flight (since there are no individual people the enitre flight will be infected) and then trace how the virus spreads throughout the time. For example, if a flight that entered DIA was infected, any flight leaving DIA after that flight arrived would be infected. At the end of the data set, you will able to see which citits were infected and what the effect of 1 infected flight had on other cities for the rest of the day. 


How	to	Run: 

1. In the terminal use to compile: g++ -std=c++11 graph.cpp queue.cpp finalProject.cpp -o finalProject
2. In the terminal use to run: ./finalProject finalProjectData.csv
3. Use the pop up menu to naviagte the program and manipulate the data structures

Use the menu to interact with the program and change the data structure. 

Dependencies: 
One possible external link that you will need is just a calculator to find the distances between two airports. 
This would happen if you wanted to add a flight that is not already in the flight graph (if the flight is already in the
graph, the program will find it for you and automatically assign the edge that weight).
The link to the website I used to find distance between airports is http://www.webflyer.com/travel/mileage_calculator/.
Simply enter the names or IATA code of the two airports that you want to find the distance between.  

Might need to google airport IATA codes in order to properly search for a airport.

System	Requirements: 
This progam works on VS Code on Windows, Mac, and Linux
There is no external requirements

Team Members: 
Isaac Li

Contributors: 
Isaac Li, 

Open	issues/bugs: 
Let me know if there are any other funtionalitites you think I should implement and any bugs that you find. 