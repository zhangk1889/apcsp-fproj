#include <stdio.h>
#include <string.h>

float areaOfCircle (float radius)
{
	printf("radius: %f\n", radius);
	return (3.14*radius*radius);
}

int main(int argc, char* argv[])
{
  float area;
  char smallStr[256], bigStr[256];
  int smallRad;
  int bigRad;
  int tempRad;

  if (argc != 3)
  {
	printf("Needs two radii.\n");

	  while (1)
  	  {
	  fgets(smallStr, 256, stdin);

   	  if (sscanf(smallStr, "%d", &smallRad) == 1) break;
	  printf("Invalid  radii size.\nPlease put in a number\n");

	  }

	  while (1)
  	  {

	  fgets(bigStr, 256, stdin);

	  	  if (sscanf(bigStr, "%d", &bigRad) == 1) break;
	  	  printf("Invalid radii size.\nPlease put in a number\n");
	  }

  if (smallRad > bigRad)
  {
	tempRad = smallRad;
	smallRad = bigRad;
	bigRad = tempRad;
  }

  for (int i = smallRad; i <= bigRad; i++)
  {
	area = areaOfCircle(i);
	printf("area: %f\n\n", area);
  }
  }
 
  else
  {
  int arg1;
  int arg2;
  int found = sscanf(argv[1], "%d", &arg1);
	if (found != 1)
	{
	  printf("First argument isn't float.\n");
	  return 1;
	}
  found = sscanf(argv[2], "%d", &arg2);
  if (found != 1)
  {
	printf("Second argument isn't float.\n");
	return 1;
  }
  if (arg2 > arg1)
  {
	bigRad = arg2;
	smallRad = arg1;
  }
  else
  {
	bigRad = arg1;
	smallRad = arg2;
  }

  for (float i = smallRad; i <= bigRad; i++)
  {
	area = areaOfCircle(i);
	printf("area: %f\n", area);
  }
}

}
