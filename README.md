# cs133u-project
This is for the final project in CS133U.


## Proposal:

## Game Description

### blurp
     Play as a knight of old as you battle monsters to steal the goblin kings treasure

### game interface

This game will be similar to Dungeons and Dragons. A map or two will display on the screen for the user, there will be an area for player stats (e.g. health), and another area for the narrative output (e.g. "manster hit you -3hp"). A box with the commands the player can use should be displayed on the screen as well.

For this game, the user will use only their keyboard (no mouse). The player will have to use letter keys and arrow keys to navigate through the game and to access the functions (functions like pickup or attack).

    2d graphic / text based?
    keyboard, no mouse.

### rules and gameplay

This is a single player game. Both the player and the monsters will have health and when the health runs out, the character/monster is dead. The player can only carry one item at a time and that item will be either a sword or a shield. The player will have the opportunity to swap for the other weapon if they wish. There is a third item, which is a potion. This will increase the player's health by a fixed amount. It can only raise the health until it hits the max amount of health. The potion cannot be carried by the player. These three items will have a description and an integer value. 

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

## Components needed

### data types

##### game piece struct
 
    holds player pos, name and health
     used for main player and monsters

##### item struct

     type of item, value, name
     
##### room struct

     the room, the next room
     rooms will be stored in a linked list

### modules

The module parameters will be added later.

main();
Begins the program and calls several functions including ai() and action(). Will contain variables that will be passed in and out of the called functions.

draw();
Call functions to draw the room and stuff in the room.

generate_room();
Generates the room. Calls create_maps() or will deal with creating maps directly.

get_input();
Will generate a move for the player. Like if the player wants to go right, the input() function will return MOVE_RIGHT, then that is passed to the action module as (PLAYER, MOVE_RIGHT), from there it will call the subfunctions such as move_right(). The player will also be able to fight if there is something there to fight.

ai();
Called by main(). Will decide action for monster to make then pass that back to main(). Ai() will need to get a list of the monsters and player and room data to make a decision for each of the monsters in the room. Will generate an action and return (monster1, move_left). We're still trying to figure out a way to pass these but we have ideas.

action();
Called by main(). Will receive whether to move or fight from main(). Will then call move() or fight(). This is responsible for the both the player's and the monster's actions. 

move();
Makes the player and the monsters move.

fight();
Makes the player and the monsters fight.

check_health();
Checks the health of the player and monsters.

check_state();
Check if the game is won or the player is dead.

check_cond();
Checking conditions: win condition, if a player is next to a monters/wall/door, whether health is "dead". The win condition is slaying the goblin king and taking his treasure.

win();
If the win condition is true, print that the player won.

end_game();
Finish up the game. Prints any last comments to be made.

Loop through these steps:
1: draw board 
2: get input 
3: perform player action 
4: perform monster action(AI) 
5: check health of monster and player
6: check win condition

##### graphics
 
    draw room, player's character, and maybe doors, items, and monsters.
  
##### input

     handle key events


##### player movement 
    move player, jeck for boarders check for collision




