# cs133u-project
This is for the final project in CS133U.

workflow instructions here: https://github.com/githubuser476/cs133u-project/blob/master/workflow.md

official project channel: #pcc-c-project-2018 @ freenode.net (webchat.freenode.net for web interface)

# install

## PCC Server

Get the source with git, 

          git clone git@github.com:githubuser476/cs133u-project.git
  
  or download from: https://github.com/githubuser476/cs133u-project/archive/master.zip

then build:

          make all
          
  To run the game remotely, enable X11 forwarding. For Windows you'll need to install an X server, like Xming.
  
  Then run with: 
  
          ./TrollHunter
          
          
  ## On a Local Linux machine
  
  Get the source with git:
  
          git clone git@github.com:githubuser476/cs133u-project.git
          git checkout origin/local Makefile
          
or download source from: https://github.com/githubuser476/cs133u-project/archive/local.zip

then build and run with:

          make all
          ./TrollHunter
          
       
  ## Testing
  
  Build and run unit tests with:
  
          make test
          ./test
  
          

## Proposal:

## Game Description

### blurp
     Play as a knight of old as you battle monsters to steal the goblin kings treasure

### game interface

  This game will be similar to Dungeons and Dragons. A map or two will display on the screen for the user, there will be an area for player stats (e.g. health), and another area for the narrative output (e.g. "monster hit you -3hp"). A box with the commands the player can use should be displayed on the screen as well.

  For this game, the user will use only their keyboard (no mouse). The player will have to use letter keys and arrow keys to navigate through the game and to access the functions (functions like pickup or attack).

    2d graphic / text based?
    keyboard, no mouse.

### rules and gameplay

 This is a single player game. Both the player and the monsters will have health and when the health runs out, the character/monster is dead. The player can only carry two items at a time and one  sword and a shield. The player will have the opportunity to swap for the other weapon if they wish. There is a third item, which is a potion. This will increase the player's health by a fixed amount. It can only raise the health until it hits the max amount of health. The potion cannot be carried by the player. These three items will have a description and an integer value. 

To win the game, you will need to kill the boss monster and find his treasure. The treasure should be in the same room.

Objects:
- player
- monsters
- items
- walls
- doors

Player actions:
- move
- pick up
- fight

Monster actions:
- wander around
- fight

Mechanics:
- initial conditions
- win condition
- lose condition

Game Flow:

     move charecter, fight monster, save .. etc
     computer controls the monster
     game flow (how we'll add modules together to create the program)
     
     
     Loop through these steps:  
     1: draw board  
     2: get input  
     3: perform player action (get_input)
     4: perform monster action(AI)  
     5: check health of monster and player  
     6: check win condition  



## modules

The module parameters will be added later.

main();  
Begins the program and calls several functions including ai() and action(). Will contain variables that will be passed in and out of the called functions.


##### graphics
 
     init();

   start the graphics engine. 
    
    render_room(struct room * currentroom);  
    
   Call functions to draw the room and stuff in the room.
  
##### input

     
     get_input();  
Will generate a move for the player. Like if the player wants to go right, the get_input() function
will call move() or fight().

//BELOW NOT APPLICABLE ANYMORE
return MOVE_RIGHT, then that is passed to the action module as (PLAYER, MOVE_RIGHT), from there it
will call the subfunctions such as move_right(). The player will also be able to fight if there is 
something there to fight.
//ABOVE NOT APPLICABLE ANYMORE



##### player/ monster 
        enum PieceType{sword, potion, shield, treasure, wall, player, monster};
        
  type of piece
     
       struct player{
       char name[50];
       enum PieceTpye type;
       int x;
       int y;
       int val;
       struct item sword;
       struct item shield;
     }
     
    struct gamepiece{
        char name[50];
        int x;
        int y;
        SDL_Texture * img;
        enum piecetype type;
        union{
            struct Player player;
            struct Item item;
        } data;
    };

This struct contains all the attributes for a player or a monster or item. Val is health for monster or player, 
hp or def for sword and shield and healing power for potion.

   
    action();  
   
   Called by main(). Will receive whether to move or fight from main(). Will then call move() or fight(). 
   This is responsible for the both the player's and the monster's actions. 

     move();  
   Makes the player and the monsters move.

     fight();  
   Makes the player and the monsters fight.
   
     get_piece_x();
  return x position
  
     get_piece_y();
  return y position
  
     get_piece_image():
  return pointer to SDL_texture
     
##### AI
     
     ai();  
   Called by main(). Will decide action for monster to make then. Ai() will need to get a list of the monsters and player and room data to make a decision for each of the monsters in the room. Will generate an action and then call move() or fight().

//BELOW NOT ALL APPLICABLE
Called by main(). Will decide action for monster to make then pass that back to main(). Ai() will need to get a list of the monsters and player and room data to make a decision for each of the monsters in the room. Will generate an action and return (monster1, move_left). We're still trying to figure out a way to pass these but we have ideas.
//ABOVE NOT ALL APPLICABLE

##### Endgame

     check_state();  
   Check if the game is won or the player is dead.
     
     check_cond();  
   Checking conditions: win condition, if a player is next to a monters/wall/door, whether health is "dead". The win  condition is slaying the goblin king and taking his treasure.

     win();  
     
   If the win condition is true, print that the player won.

     end_game();  
     
   Finish up the game. Prints any last comments to be made.

##### Maps

     struct room{
       char name[50];
       item monsters[5];
       item bounty[10];
       item walls[1000];
       struct door * lastroom;
       s truct door * nextroom;
     }
   
   This struct contains info about the room. The monsters and items and walls are contained in arrays.
   
     struct door{
       int x;
       int y;
       struct room * room1;
       struct room * room2;
     }
     
  This struct shows the position of the door and points to the two rooms that it connects.
  
     generate_room();  
  Generates the room. Calls create_maps() or will deal with creating maps directly.  

  
### function prototypes

##### int main(void) //not a prototype

#### struct room creat_room(void);
     Creates a room and add the doors, items, players, etc to it.

#### void init(void);
     Init() starts the sdl graphics stuff. It opens a screen 640 x 480 pixels and creates:
     SDL_Window * Main_Screen = NULL;
     SDL_Renderer * Main_Renderer  = NULL;

#### void render_room(struct room * currentroom);
     Call functions to draw the room and stuff in the room.

#### void get_input(void);
     Gets input from user and will call move(the direction) or fight(player, monster);

#### ai() //Need to finish this prototype  
     Will generate an action and then call move(the direction) or call fight(monster, player).

#### void move(typedef enum direction);
     Will move the piece.

#### void fight(gamepiece * attacker, gamepiece * defender);
     Will attack or miss the defender.

#### int get_piece_x(gamepiece * piece);
     return x position
  
#### int get_piece_y(gamepiece * piece);
     return y position
  
#### SDL_Texture * get_piece_image(gamepiece * piece);
     return pointer to SDL_texture
  
#### check_state();  //Next prototype to work on
     Check if the game is won or the player is dead.
