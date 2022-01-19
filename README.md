# Hangtime

Hangtime is a game where two players compete to create a line of tokens, similar to connect-4. 
However, in Hangtime pieces defy the laws of gravity for a set amount of turns after they are placed. 
Those pieces will drop after "t" turns and any pieces that fall on top of those pieces will rest on top
the bottom one drops. 

## To run
- Run the make play command 
- Run ./play with the necessary flags. The necessary flags are 
  -w (width of the board) followed by an int 
  -h (height of the board) followed by an int
  -t (hangtime) followed by an int 
  -r (run, the connection length that you need to acheive to win) followed by an int 
  -b (runs the bit manipulation code)
  -m (runs the matrix based code)
  
  For example 
    ./play -w 5 -h 6 -t 2 -r 3 -m 
    
## To play 
- Input the coordinate that you want to play on in the format xy
- For example, 43 will play on the (4, 3) coordinate
- The game will continue until a player wins or the board is full
