#include <LedControl.h>


int state = 0;
LedControl lc(PIN_PB3, PIN_PB5, PIN_PB1, 4);
void setup() {
  pinMode(PIN_PB0, INPUT);
  pinMode(PIN_PB4, INPUT);
  pinMode(PIN_PD0, INPUT_PULLUP);
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }
}
void clearled()
{
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }
  for (int cs = 0; cs < 4; cs++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        lc.setLed(cs, row, col, true);
       
      }
    }
  }
}
void closeled(){
   for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }
}
void leftright()
{
  int LEFTRIGHT[5][8][8] = {{{1, 1, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 1, 1},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 1, 1}
    }
  };
  for (int cs = 0; cs < 4; cs++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (LEFTRIGHT[cs][row][col] == 1)
        {
          lc.setLed(cs, row, col, true);
        }
        else
        {
          lc.setLed(cs, row, col, false);
        }
      }
    }
  }

}
void right()
{
  int RIGHT[5][8][8] = {{{1, 1, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    }
  };
  for (int cs = 0; cs < 4; cs++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (RIGHT[cs][row][col] == 1)
        {
          lc.setLed(cs, row, col, true);
        }
        else
        {
          lc.setLed(cs, row, col, false);
        }
      }
    }
  }
}
void left()
{
  int LEFT[5][8][8] = {{{0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 1, 1},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 1, 1}
    }
  };
  for (int cs = 0; cs < 4; cs++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (LEFT[cs][row][col] == 1)
        {
          lc.setLed(cs, row, col, true);
        }
        else
        {
          lc.setLed(cs, row, col, false);
        }
      }
    }
  }
}
void kuy() {
  int LEFT[5][8][8] = {
    { {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 1, 0},
      {1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0}
    },

    { {1, 1, 1, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 0, 0, 0, 0, 0}
    }
  };
  for (int cs = 0; cs < 4; cs++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (LEFT[cs][row][col] == 1)
        {
          lc.setLed(cs, row, col, true);
        }
        else
        {
          lc.setLed(cs, row, col, false);
        }
      }
    }
  }

}
void loop()
{
  // put your main code here, to run repeatedly:
  int rightbut = digitalRead(PIN_PB0);
  int leftbut  = digitalRead(PIN_PB4);
  int talk = digitalRead(PIN_PD0);
  if (talk ==  HIGH) {
    state = 1;
  }
  else{
    state = 0;
    closeled();
  }

  
  if (state == 1) {
    if(rightbut== HIGH&&leftbut==HIGH)
    {
      leftright();
    }
    else if(rightbut == HIGH&&leftbut == LOW)
    {
      right();
    }
    else if(leftbut== HIGH&&rightbut == LOW)
    {
      left();
    }
    else if(rightbut == LOW&&leftbut == LOW)
    {
     clearled();
     
    }
 }
}
  
  /*
    if(rightbut== HIGH&&leftbut==HIGH)
    {
      leftright();
    }

    else if(rightbut == HIGH&&leftbut == LOW)
    {
      right();
    }

    else if(leftbut== HIGH&&rightbut == LOW)
    {
      left();
    }

    else if(rightbut == LOW&&leftbut == LOW)
    {
     clearled();
    }*/

