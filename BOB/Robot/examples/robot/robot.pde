#include <Robot.h>

Robot Robot(9,2,10,3);

void setup()
{
}

void loop()
{
  Robot.forward(500);
  Robot.backward(500);
  Robot.stop();
  Robot.left();
  Robot.right();
}
