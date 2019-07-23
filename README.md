# 2048

Console C++ game, Inspired by famous game 2048. The original game consisted a 4x4 matrix. 
This project can go for n x n matrix based on user input.

Made with object oriented approach, a single class called CoreMatrix implements all the funtionality of the game which makes the code reusable.

I have used console handles to add colour to the game which I think is only for windows, that might make it unsable on Linux based devices.
So, I am adding another file without handles and changed system("cls") to system("clear") with 2048Linux.cpp

The most intuitive thing I think I did in this project was to design an algorithm which based on matrix size, generates a random number that is 
an exponent of 2 with having larger numbers much less chance of spawning than smaller exponents of 2.

Free for anyone to use.
