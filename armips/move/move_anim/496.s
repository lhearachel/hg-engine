.nds
.thumb

.include "armips/include/animscriptcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/itemnums.s"
.include "armips/include/monnums.s"
.include "armips/include/movenums.s"

.create "build/move/move_anim/0_496", 0

a010_496:
    loadparticlefromspa 0, 509
    waitparticle

    addparticle 0, 0, 4
    wait 5

    addparticle 0, 0, 4
    wait 5

    callfunction 34, 5, 8, 1, 1, 31 | 31 << 5 | 31 << 10, 10, "NaN", "NaN", "NaN", "NaN", "NaN" // shades target mon rgb555 color

    addparticle 0, 0, 4
    wait 5

    addparticle 0, 0, 4
    wait 5

    addparticle 0, 0, 4
    wait 5
    
    callfunction 33, 5, 0, 1, 12, 0, 31 | 31 << 5 | 31 << 10, "NaN", "NaN", "NaN", "NaN", "NaN" // flash screen rgb
    callfunction 36, 5, 3, 0, 1, 7, 264, "NaN", "NaN", "NaN", "NaN", "NaN" // shake target mon

    addparticle 0, 0, 4
    wait 5
    
    waitparticle

    unloadparticle 0
    waitstate
    end
    

.close
