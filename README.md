# cs133u-project
This is for the final project in CS133U.


## Proposal:

## Game Description

### blurp
     play as a knight of old as you battle monsters to steal the goblin kings treasure

### game interface

This game will be similar to Dungeons and Dragons. A map will display on the screen for the user, there will be an area for player stats (e.g. health), and another area for the narrative output (e.g. "manster hit you -3hp"). A box with the commands the player can use should be displayed on the screen as well.

For this game, the user will use only their keyboard (no mouse). The player will have to use letter keys and arrow keys to navigate through the game and to access the functions (functions like pickup or attack).

    2d graphic / text based?
    keyboard, no mouse.

### rules and gameplay

This is a single player game. Both the player and the monsters will have health and when the health runs out, the character/monster is dead. The player can only carry one item at a time and that item will be either a sword or a shield. The player will have the opportunity to swap for the other weapon if they wish. There is a third item, which is a potion. This will increase the player's health. This has to be used immediately. These three items will have a description and an integer value. 

Items:

Actions:

Game Flow:

     move charecter, fight monster, save .. etc
     computer controls the monster
     game flow

## Components needed

### data types

##### game piece struct
 
    holds player pos, name and health
     used for main player and monsters

##### item struct

     type of item, value, name

### modules

##### graphics
 
    draw board, draw pieces
  
##### input

     handle key events


##### player movement 
    move player, jeck for boarders check for collision




