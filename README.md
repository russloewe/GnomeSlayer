# cs133u-project
This is for the final project in CS133U.
Original fork for the CS133U project is located at https://github.com/githubuser476/cs133u-project

workflow instructions here: https://github.com/russloewe/GnomeSlayer/blob/master/workflow.md

official project IRC channel: #GnomeSlayer @ freenode.net (webchat.freenode.net for web interface)

[GAMEPLAY](https://russloewe.github.io/GnomeSlayer/pics/gameplay.jpg)

# install

## Dependencies

Requries the SDL2 Library to compile and run. You can follow instructions here https://wiki.libsdl.org/Installation to 
install SDL2 from a package manager or compile from source. If you do not have sudo rights on your 
workstation, put the SDL libs in your home directory and point the linker at them.

  ## On a Local Linux machine
  
  Get the source with git:
  
          git clone git@github.com:russloewe/GnomeSlayer.git
          git checkout origin/local Makefile
          
or download source from: https://github.com/russloewe/GnomeSlayer/archive/master.zip

then build and run with:

          cd GnomeSlayer
          make all
          ./GnomeSlayer
          
       
  ## Testing
  
  Build and run unit tests with:
  
          make test
          ./test
  
          

## Game Description

 
The object of this game is to move through rooms and slay monsters until you beat the Goblin King in the final room. 
Use the arrow keys to move, attack or pass through doors. Space bar is used to pickup or swap items.


## License

 This game is distributed with the MIT License described in the file "LICENSE".

