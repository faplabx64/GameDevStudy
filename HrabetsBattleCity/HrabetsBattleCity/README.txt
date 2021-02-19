Hello!

Your task is to implement *simple* BattleCity-like game
(please, see BattleCity (1985) game for a reference if you like - https://www.youtube.com/watch?v=MPsA5PtfdL0).

Game reference - https://strategywiki.org/wiki/Battle_City/How_to_play

Overview

The player controls a tank and shoot projectiles to destroy enemy tanks around the playfield. The enemy tanks enter from the top of the screen and attempt to destroy the player's base (represented on the screen as a phoenix symbol), as well as the player's tank itself. A level is completed when the player destroys 20 enemy tanks, but the game ends if the player's base is destroyed or the player loses all available lives. Note that the player can destroy the base as well, so the player can still lose even after all enemy tanks are destroyed.

Note: it is not required to make level switching for this task (only one game level is enough). However, you can make more if you want.

Player Tank

Player controls the yellow tank. Tank can only have one of its own shots on the screen at one time, and may not fire again until the shot hits an enemy or collides with a wall. The tank can be destroyed by one enemy bullet.

Note: the task requires single player implementation of the game. However, don't hesitate to implement multiplayer cooperative version of the game with two tanks which are controlled using different keyboard keys if you want.

Controls:
  - Left/Right/Up/Down - move tank
  - Mouse LeftButton - fire

Enemy Tanks

1. Basic Tank:
  - Health - 1
  - Movement Speed - 1 (slow)
  - Bullet Speed - 1 (slow)
  - Description - Generally poses little threat. Moves slower than players, fires at the same speed default power level (zero stars)
2. Optional: Fast Tank:
  - Health - 1
  - Movement Speed - 3 (fast)
  - Bullet Speed - 2 (normal)
  - Description - Generally more dangerous to the headquarters than a player; should be dispatched quickly
3. Optional: Power Tank:
  - Health - 1
  - Movement Speed - 2 (normal)
  - Bullet Speed - 3 (fast)
  - Description - Don't go to their line of fire
4. Optional: Armor Tank:
  - Health - 4
  - Movement Speed - 2 (normal)
  - Bullet Speed - 2 (normal)
  - Description - Start as green; gradually turns gray upon harm. Don't destroy them head-on until the 2nd Star powerup is collected

Power-Ups

A power-up will spawn in one of 16 random locations on the screen whenever one of the three flashing tanks (which appear in each stage as the 4th, 11th, and 18th tank to spawn) is hit. They will disappear when another flashing tank spawns. Touching a power-up will collect it (it will then disappear).

1. Tank - Gives an extra life
2. Optional: Star:
  - Increases your offensive power by one tier (tiers are: default, second, third, and fourth). Power level only resets to default when you die
  - First star (second tier): fired bullets are as fast as Power Tanks' bullets
  - Second star (third tier): two bullets can be fired on the screen at a time
  - Third star (fourth tier): fired bullets can destroy steel walls and are twice as effective against brick walls

Note: you can implement more power-ups according to original gameplay if you want.

Environment

There are a few different types of obstacles scattered around each stage. The key to surviving is knowing how to use them to your advantage.

1. Brick Wall:
  - Tanks and bullets cannot pass through this.
  - Can be destroyed by being shot four times (two times when offensive power is tier four/max) on the same side.
2. Optional: Steel Wall
  - Stops tanks and bullets completely.
  - Can only be destroyed if hit twice on the same side by maximum power level bullets (tier four).

Note: you can implement more environment types according to original gameplay if you want.

Assets

Assets for the game may be found here - https://www.spriters-resource.com/nes/batcity/sheet/60016/

Technical Requirements

Window size should be possible to set from the command-line, e.g.:

game -window 800x600 

Functionality provided by Framework should be enough to do all required drawing. You can load TGA, JPG and PNG images as sprites with it.
Please, see example project for a template implementation. When implementing application take special care about performance and memory usage.

Try to use data oriented programming approach.

In case of any questions please contact: l.kholodov@dragonlk.com

Good luck!
Bye.

--
