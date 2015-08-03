byte ROW[] = { A3, A4, A1, A2, 12, 11, A5, 13};
byte SELECT[] = { 8, 9, 10 };
byte COL[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
byte ADDR[] = { 7, 4, 5, 6, 3, 0, 1, 2 };
byte data[][8] = { {0,0,0,0,0,0,0,0},
                   {255,255,255,255,255,255,255,255},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0} };
byte** ten();
void setup() {
  // put your setup code here, to run once:
  DDRB = B11111111;
  DDRD = B11111111;
  DDRC = B11111111;
  //frame(data);
}
int count = 0;
//int temp = 0;

void loop() {
  for(int i=0;i<8;i++)
    anim(rowsUp(i),1);
  for(int i=0;i<8;i++)
    anim(colsLeft(i,1),1);
  for(int i=0;i<8;i++)
    anim(edgesLeftRightUp(i),1);
  for(int i=0;i<8;i++)
    anim(edgesFrontBackUp(i),1);
  for(int i=0;i<8;i++)
    anim(colsLeft(i,1),1);
  for(int i=0;i<8;i++)
    anim(colsRight(i,1),1);
  for(int i=0;i<8;i++)
    anim(colsLeft(i,1),1);
  for(int i=0;i<8;i++)
    anim(outlineCube(i),2);
  for(int i=0;i<8;i++)
    anim(colsRight(i,1),1);
  for(int i=0;i<8;i++)
    anim(outlineCubeBuildFromBottom(i),1);
  for(int i=0;i<8;i++)
    anim(outlineCube(i),2);
}

void frame(byte **data){//data[][8]){
  for(int ROWCOUNT = 0; ROWCOUNT < 8; ROWCOUNT++){
    PORTC = 1;
    for(int i=0; i<8; i++){
      PORTB = ADDR[i];
      PORTD = data[ROWCOUNT][i];
    }
    //if(ROWCOUNT != 5)
  PORTB = 0;
  PORTC = 0;
  selectRow(ROWCOUNT);
  //selectRow(5);
  delayMicroseconds(1200);
  //delay(5);
  }
  PORTB = 0;
}

void selectRow(byte input){
  switch(input){
    case 0:
      PORTC = B00001000;
      break;
    case 1:
      PORTC = B00010000;
      break;
    case 2:
      PORTC = B00000010;
      break;
    case 3:
      PORTC = B00000100;
      break;
    case 4:
      PORTB = B00010000;
      PORTC = B00000000;
      break;
    case 5:
      PORTC = B00000000;
      PORTB = B00001000;
      break;
    case 6:
      PORTC = B00100000;
      break;
    case 7:
      PORTB = B00100000;
      PORTC = B00000000;
      break;
  }
}

struct temp {
  byte a[8][8];
};
struct temp risingPlanes(){
  struct temp b;
  //for(int i=0;i<8;i++)
    //for(int j=0;j<8;j++)
      //b[i][j] = 255;
      //temp b[0][0] = 255;
}
void anim(byte** data, byte temp){
  for(int i=0;i<8;i++){
    //temp = 1 << i;
    for(int i=0; i<temp;i++)
            frame(data);
  }
  for(int i=0;i<8;i++)
    free(data[i]);
  free(data);

}
byte** rowsUp(byte input){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(i==input)
      a[i][j] = 255;
      else
      a[i][j] = 0;
    }
  }
  return a;
}
byte** colsLeft(byte input, byte numCols){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      a[i][j] = numCols << input;//(int)pow(2,input);
    }
  }
  return a;
}
byte** edgesLeftRightUp(byte input){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(i <= input){
        a[i][j] = 129;
      }
      else
      a[i][j] = 0;//(int)pow(2,input);
    }
  }
  return a;
}
byte** edgesFrontBackUp(byte input){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(i <= input){
        if(j == 0 || j == 7)
          a[i][j] = 255;
        else
          a[i][j] = 0;
      }
      else
      a[i][j] = 0;//(int)pow(2,input);
    }
  }
  return a;
}
byte** outlineCube(byte input){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      //if(i <= input){
        if((i == 0 || i == 7))
           if(j==0 || j==7)
              a[i][j] = 255;
           else
              a[i][j] = 129;
        else
          if(j==0 || j==7)
            a[i][j] = 129;
          else
            a[i][j] = 0;
      //}
      //else
      //a[i][j] = 0;//(int)pow(2,input);
    }
  }
  return a;
}

byte** colsRight(byte input, byte numCols){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      a[i][j] = (numCols << (7 - input));//(int)pow(2,input);
    }
  }
  return a;
}
byte** outlineCubeBuildFromBottom(byte input){
  byte** a = (byte**)malloc(8 * sizeof(byte *));
  for(int i=0;i<8;i++)
   a[i] = (byte*)malloc(8 * sizeof(byte));
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(i <= input){
        if(i==0 || i==7)
          if(j==0 || j==7)
            a[i][j] = 255;
          else
            a[i][j] = 129;
        else
          if(j==0 || j==7)
            a[i][j] = 129;
          else
            a[i][j] = 0;
      }
      else
        a[i][j] = 0;
    }
  }
  return a;
}

