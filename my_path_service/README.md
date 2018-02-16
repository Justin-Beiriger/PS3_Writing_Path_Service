# my_path_service

The path client sends a list of poses to direct the STDR robot through the maze to the top left (finish). Each pose contains a destination (in x,y coordinates) and a desired heading (orientation defined by a quaternion). The service takes this variable-length message and executes the commands, ultimately publishing commands to the STDR simulation to move it through the maze. 

The most difficult part of this lab was debugging the global current position variable, which must be updated properly to track the robot's position. 

## Example usage

The STDR robot environment was first launched, then the path service was initialized, and finally the client was initialized to send the path messages to the service. The robot then traveled through the maze. 

## Running tests/demos
    
The video file showing the demo can be found at the following link:

https://youtu.be/gq2B30Ybt_s
