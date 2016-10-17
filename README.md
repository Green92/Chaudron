# Sifteo_bunker

## Get sources

    git clone https://github.com/Green92/Sifteo_bunker.git
    
## Update sources

    #inside the sources directory :
    git pull
    
## Build project

    #inside the project directory with the Sifteo SDK's shell :
    make
    
## Run game

    #inside the project directory with the Sifteo SDK's shell :
    #-n option allow to specify the number of cube in the simulation.
    Siftulator -n 9 proto.elf

## Developpement branch

Lastest modifications may not be immediately reported on the main branch (master).
It can be useful to check the developpement branch (dev).

    git checkout dev
    git pull
    
## Add cube roles :

You can easily add cube roles by modifying the following file :

    model/roles.hpp
    
## Add cube associations :

Same way you can add cube associations by modifying the following file :

    model/associations.hpp
    
