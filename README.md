# Final-Project

My final project is going to consist of two data structures. One of them will be a chronological queue and the other will be a weighted graph. 
I will be working by myself. The main data that I am analyzing is going to be flight data of southwest flights within the United States for a specified amount of time. 
In the queue will be a flight log of all the flights that will happen during that time. The flight struct will include the time of flight, distance traveled, and the beginning and end locations. 
In the graph, each vertex will be a city. The edges between the cities will be different flights that occur. The edges struct will have a time, distance, and a end location. They will be weighted by 
the distance between the beginning and the end cities. The edges will also be only 1 directional because usually the flight is 1 direction and there is no immediate return flight. 
In terms of user interaction, there will be a option to add flights, cancel flight, and modify flights. As this is during the time of COVID, there will be a funtionality where you can infect 1 flight
(since there are no individual people the enitre flight will be infected) and then trace how the virus spreads throughout the time. For example, if a flight that entered DIA was infected, any flight leaving 
DIA after that flight arrived would be infected. At the end of the data set, you will able to see which citits were infected and what the effect of 1 infected flight had on other cities for the rest of the day. 
change 1