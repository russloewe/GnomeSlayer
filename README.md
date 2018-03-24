# cs133u-project
This is for the final project in CS133U.

workflow instructions here: https://github.com/githubuser476/cs133u-project/blob/master/workflow.md

official project channel: #pcc-c-project-2018 @ freenode.net (webchat.freenode.net for web interface)

# install

## Dependencies

Requries the SDL2 Library to compile and run. You can follow instructions here https://wiki.libsdl.org/Installation to 
install SDL2 from a package manager or compile from source.

  ## On a Local Linux machine
  
  Get the source with git:
  
          git clone git@github.com:githubuser476/cs133u-project.git
          git checkout origin/local Makefile
          
or download source from: https://github.com/githubuser476/cs133u-project/archive/local.zip

then build and run with:

          make all
          ./TrollHunter
          
## PCC Server

Get the source with git, 

          git clone git@github.com:githubuser476/cs133u-project.git
  
  or download from: https://github.com/githubuser476/cs133u-project/archive/master.zip

then build:

          make all
          
  To run the game remotely, enable X11 forwarding. For Windows you'll need to install an X server, like Xming.
  
  Then run with: 
  
          ./TrollHunter
  
       
  ## Testing
  
  Build and run unit tests with:
  
          make test
          ./test
  
          

## Game Description

 
The object of this game is to move through rooms and slay monsters until you beat the Goblin King in the final room. 
Use the arrow keys to move, attack or pass through doors. Space bar is used to pickup or swap items.




